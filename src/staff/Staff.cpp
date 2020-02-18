#include "../../header/staff/Staff.hpp"
#include "../../header/staff/Permissions.hpp"
#include "../../header/validationDate/ValidationEmail.hpp"
#include "../../header/validationDate/ValidationIDCard.hpp"
#include "../../header/validationDate/ValidationPassword.hpp"
#include "../../header/validationDate/ValidationPesel.hpp"
#include <string_view>
#include <optional>
#include <tuple>

Staff::Staff::Staff(std::string_view name, std::string_view secondName, std::string_view email, std::string_view password, std::string_view peselOrPersonalID, Permissions permissions) noexcept
{
    set(name, secondName, email, password, peselOrPersonalID, permissions);
}

std::optional<std::tuple<std::string, std::string, std::string, std::string, std::string, Staff::Permissions>> Staff::Staff::get() const noexcept
{
    return worker;
}

void Staff::Staff::set(std::string_view name, std::string_view secondName, std::string_view email, std::string_view password, std::string_view peselOrPersonalID, Permissions permissions) noexcept
{
    Validation::ValidationEmail validationEmail;
    Validation::ValidationIDCard validationIDCard;
    Validation::ValidationPassword validationPassword;
    Validation::ValidationPesel validationPesel;
    if (name.size() != 0 && secondName.size() != 0 && validationEmail.validated(email) && validationPassword.validated(password) && (validationIDCard.validated(peselOrPersonalID) || validationPesel.validated(peselOrPersonalID)))
        worker = std::make_tuple(name, secondName, email, password, peselOrPersonalID, permissions);
    else
        worker = std::nullopt;
}
