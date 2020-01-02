#ifndef _PESEL_VALIDATION_HPP_
#define _PESEL_VALIDATION_HPP_

#include <string_view>

class PeselValidation
{
public:
    static bool validated(std::string_view) noexcept;
};

#endif