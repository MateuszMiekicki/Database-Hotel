#include <string_view>
#include <optional>
#include <tuple>
#include <stdexcept>
#include "../../header/staff/Staff.hpp"
#include "../../header/staff/Permissions.hpp"
#include "../../header/validationDate/ValidationEmail.hpp"
#include "../../header/validationDate/ValidationIDCard.hpp"
#include "../../header/validationDate/ValidationPassword.hpp"
#include "../../header/validationDate/ValidationPesel.hpp"

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
                        std::string_view peselOrPersonalID)
{
    if (name.size() == 0)
    {
        throw std::invalid_argument("Setting up staff data: "
                                    "the name must not be empty.");
    }
    if(secondName.size() == 0)
    {
        throw std::invalid_argument("Setting up staff data: "
                                    "the second name must not be empty.");
    }
    Validation::ValidationPesel validationPesel;
    Validation::ValidationIDCard validationIDCard;
    if((validationPesel.validated(peselOrPersonalID) == false) && 
        (validationIDCard.validated(peselOrPersonalID) == false))
    {
        throw std::invalid_argument("Setting up staff data: "
                                    "the wrong identification number (pesel or id) is given.");
    }
    worker = std::make_tuple(name, secondName, peselOrPersonalID);
}
