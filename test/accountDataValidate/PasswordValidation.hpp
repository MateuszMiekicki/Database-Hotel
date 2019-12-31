#ifndef _PASSWORD_VALIDATION_HPP_
#define _PASSWORD_VALIDATION_HPP_

#include <string_view>

class PasswordValidation
{
    public:
    static bool validated(std::string_view) noexcept;
};

#endif