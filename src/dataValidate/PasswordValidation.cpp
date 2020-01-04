#include "../../header/dataValidate/PasswordValidation.hpp"
#include <string_view>
#include <regex>

bool PasswordValidation::validated(std::string_view password) noexcept
{
    const std::regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
    std::string input{password};
    if (std::regex_match(input, passwordRegex))
        return true;
    return false;
}