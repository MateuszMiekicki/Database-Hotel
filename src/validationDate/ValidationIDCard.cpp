#include "../../header/validationDate/ValidationIDCard.hpp"
#include <string_view>
#include <string>
#include <cctype>
#include <algorithm>

bool ValidationIDCard::ValidationIDCard::validated(std::string_view IDCard) const noexcept
{
    std::string temp(IDCard);
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    if (temp.size() > 9)
        return false;
    std::string letters(temp.begin(), temp.begin() + 3);
    std::string number(temp.begin() + 3, temp.end());
    for (const auto &i : letters)
    {
        if (!std::isalpha(i))
        {
            return false;
        }
    }
    for (const auto &i : number)
    {
        if (std::isalpha(i))
        {
            return false;
        }
    }
    std::transform(letters.begin(), letters.end(), letters.begin(), ::toupper);
    unsigned checksum{0};
    checksum = (7 * (static_cast<unsigned>(letters[0]) - 55)) + (3 * (static_cast<unsigned>(letters[1]) - 55)) + (static_cast<unsigned>(letters[2]) - 55);
    checksum += ((7 * (static_cast<unsigned>(number[1]) - 48)) + (3 * (static_cast<unsigned>(number[2]) - 48)) + (static_cast<unsigned>(number[3]) - 48) + (7 * (static_cast<unsigned>(number[4]) - 48)) + (3 * (static_cast<unsigned>(number[5]) - 48)));
    if ((checksum % 10) == (static_cast<unsigned>(number[0]) - 48))
    {
        return true;
    }
    return false;
}