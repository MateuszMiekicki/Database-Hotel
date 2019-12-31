#include "../../header/accountDataValidate/EmailValidation.hpp"
#include <string_view>
#include <regex>

bool EmailValidation::validated(std::string_view email) noexcept
{
    const std::regex emailRegex("^[a-zA-Z]{1,}@[a-zA-Z]{1,}\\.[a-zA-Z]{1,}");
    std::string input{email};
    if(std::regex_match(input, emailRegex))
        return true;
    return false;
}