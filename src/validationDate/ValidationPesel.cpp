#include <string>
#include <string_view>
#include <algorithm>
#include "../../header/validationDate/ValidationPesel.hpp"

bool Validation::ValidationPesel::validated(std::string_view pesel) const 
                                                                    noexcept
{
    bool numbersOnly = [](const std::string_view &s) -> bool 
                        { return !s.empty() && 
                                (std::find_if(s.begin(),
                                            s.end(), 
                                            [](unsigned char c) 
                                            {return !std::isdigit(c);}) == s.end()); 
                                            }(pesel);
    if (pesel.size() != 11 || !numbersOnly)
        return false;
    std::string controlNumber(pesel.begin() + 10, pesel.begin() + 11);
    if (std::stoi(controlNumber) != ((9 * (static_cast<int>(pesel[0]) - 48) +
                                      7 * (static_cast<int>(pesel[1]) - 48) +
                                      3 * (static_cast<int>(pesel[2]) - 48) +
                                      1 * (static_cast<int>(pesel[3]) - 48) +
                                      9 * (static_cast<int>(pesel[4]) - 48) +
                                      7 * (static_cast<int>(pesel[5]) - 48) +
                                      3 * (static_cast<int>(pesel[6]) - 48) +
                                      1 * (static_cast<int>(pesel[7]) - 48) +
                                      9 * (static_cast<int>(pesel[8]) - 48) +
                                      7 * (static_cast<int>(pesel[9]) - 48)) %
                                     10))
        return false;
    std::string year(pesel.begin(), pesel.begin() + 2);
    if (std::stoi(year) < 0 && std::stoi(year) > 99)
        return false;
    std::string month(pesel.begin() + 2, pesel.begin() + 4);
    if (std::stoi(month) < 1 && std::stoi(month) > 32)
        return false;
    std::string day(pesel.begin() + 4, pesel.begin() + 6);
    if (std::stoi(day) < 1 && std::stoi(day) > 31)
        return false;
    std::string seriaNumber(pesel.begin() + 5, pesel.begin() + 8);
    if (std::stoi(seriaNumber) < 0 && std::stoi(seriaNumber) > 999)
        return false;
    std::string gender(pesel.begin() + 9, pesel.begin() + 10);
    if (std::stoi(gender) < 0 && std::stoi(gender) > 999)
        return false;
    return true;
}