#include "../../header/staff/Staff.hpp"
#include "../../header/staff/Permissions.hpp"
#include "../../header/validationDate/ValidationEmail.hpp"
#include "../../header/validationDate/ValidationIDCard.hpp"
#include "../../header/validationDate/ValidationPassword.hpp"
#include "../../header/validationDate/ValidationPesel.hpp"
#include <string_view>
#include <optional>
#include <tuple>

Staff::Staff::Staff(std::string_view name, 
                    std::string_view secondName, 
                    std::string_view peselOrPersonalID) noexcept
{
    set(name, secondName, peselOrPersonalID);
}

std::optional<std::tuple<std::string, 
                        std::string, 
                        std::string>> Staff::Staff::get() const noexcept
{
    return worker;
}

void Staff::Staff::set(std::string_view name, 
                        std::string_view secondName, 
                        std::string_view peselOrPersonalID) noexcept
{
    Validation::ValidationIDCard validationIDCard;
    Validation::ValidationPesel validationPesel;
    if ((name.size() != 0) && 
        (secondName.size() != 0) && 
        (validationIDCard.validated(peselOrPersonalID) || 
        validationPesel.validated(peselOrPersonalID)))
        {
            worker = std::make_tuple(name, secondName, peselOrPersonalID);
        }
    else
    {
        worker = std::nullopt;
    }
}
