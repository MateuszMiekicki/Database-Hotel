#include "../../header/booking/Guest.hpp"
#include "../../header/dataValidate/IDCardValidation.hpp"
#include "../../header/dataValidate/PeselValidation.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include "../../lib/date/date.h"
#include <optional>
#include <sstream>

Guest::Guest(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_numberIDCard) : name{_name},
                                                                                                                                      secondName{_secondName},
                                                                                                                                      pesel{_pesel},
                                                                                                                                      numberIDCard{_numberIDCard} {}

std::optional<nlohmann::json> Guest::guestData() const
{
    if (name.size() < 2 || secondName.size() < 2 || !PeselValidation::validated(pesel) || !IDCardValidation::validated(numberIDCard))
        return std::nullopt;
    std::string temp = numberIDCard;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    nlohmann::json data = {
        {"name", name},
        {"secondName", secondName},
        {"pesel", pesel},
        {"numberIDCard", temp}};
    return data;
}