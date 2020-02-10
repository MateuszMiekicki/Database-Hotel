#include "../../header/validationDate/ValidationEmail.hpp"
#include <regex>

bool Validation::ValidationEmail::validated(std::string_view email) const noexcept
{
    const std::regex emailRegex("^[a-zA-Z.]{1,}@[a-zA-Z]{1,}\\.[a-zA-Z]{1,}");
    std::string input{email};
    if (std::regex_match(input, emailRegex))
        return true;
    return false;
}