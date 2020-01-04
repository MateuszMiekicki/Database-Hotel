#include "../../header/booking/Guest.hpp"
#include "../../header/dataValidate/IDCardValidation.hpp"
#include "../../header/dataValidate/PeselValidation.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include "../../lib/date/date.h"
#include <optional>
#include <sstream>

Guest::Guest(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_numberIDCard, const date::year_month_day& _untilWhenHired) : name{_name},
                                                                                                                                                                                  secondName{_secondName},
                                                                                                                                                                                  pesel{_pesel},
                                                                                                                                                                                  numberIDCard{_numberIDCard},
                                                                                                                                                                                  untilWhenHired{_untilWhenHired}
{
    sinceHired = date::floor<date::days>(std::chrono::system_clock::now());
}

Guest::Guest(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_numberIDCard, const date::year_month_day &_sinceHired, const date::year_month_day &_untilWhenHired) : name{_name},
                                                                                                                                                                                                                            secondName{_secondName},
                                                                                                                                                                                                                            pesel{_pesel},
                                                                                                                                                                                                                            numberIDCard{_numberIDCard},
                                                                                                                                                                                                                            sinceHired{_sinceHired},
                                                                                                                                                                                                                            untilWhenHired{_untilWhenHired} {}
std::optional<nlohmann::json> Guest::guestData() const
{
    if (name.size() < 2 || secondName.size() < 2 || !PeselValidation::validated(pesel) || !IDCardValidation::validated(numberIDCard))
        return std::nullopt;
    std::stringstream tempStream;
    tempStream << sinceHired;
    std::stringstream tempStream2;
    tempStream2 << untilWhenHired;
    nlohmann::json data = {
        {"name", name},
        {"secondName", secondName},
        {"pesel", pesel},
        {"numberIDCard", numberIDCard},
        {"sinceHired", tempStream.str()},
        {"untilWhenHired", tempStream2.str()}};
    return data;
}