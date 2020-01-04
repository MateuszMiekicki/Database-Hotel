#include "../../header/booking/Guest.hpp"
#include "../../header/dataValidate/IDCardValidation.hpp"
#include "../../header/dataValidate/PeselValidation.hpp"
#include <optional>

Guest::Guest(const std::string &_name, const std::string &_secondName, const std::string &_pesel, const std::string &_numberIDCard) : name{_name},
                                                                                                                                      secondName{_secondName},
                                                                                                                                      pesel{_pesel},
                                                                                                                                      numberIDCard{_numberIDCard}
{
}

std::optional<nlohmann::json> Guest::guestData() const
{
    if (name.size() < 2 || secondName.size() < 2 || !PeselValidation::validated(pesel) || !IDCardValidation::validated(numberIDCard))
        return std::nullopt;
    nlohmann::json data = {
        {"name", name},
        {"secondName", secondName},
        {"pesel", pesel},
        {"numberIDCard", numberIDCard}};
    return data;
}