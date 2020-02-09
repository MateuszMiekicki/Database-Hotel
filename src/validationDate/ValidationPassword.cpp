#include "../../header/validationDate/ValidationPassword.hpp"
#include <regex>

bool ValidationPassword::ValidationPassword::validated(std::string_view password) const noexcept
{
    const std::regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
    std::string input{password};
    if (std::regex_match(input, passwordRegex))
        return true;
    return false;
}