#ifndef _EMAIL_VALIDATION_HPP_
#define _EMAIL_VALIDATION_HPP_

#include "iValidation.hpp"
#include <string_view>

class EmailValidation : public iValidation
{
    public:
    static bool validated(std::string_view) const noexcept;
}

#endif