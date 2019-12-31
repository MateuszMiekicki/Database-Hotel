#ifndef _EMAIL_VALIDATION_HPP_
#define _EMAIL_VALIDATION_HPP_

#include <string_view>

class EmailValidation
{
    public:
    static bool validated(std::string_view) noexcept;
};

#endif