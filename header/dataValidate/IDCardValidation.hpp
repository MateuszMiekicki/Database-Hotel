#ifndef _ID_CARD_VALIDATION_HPP_
#define _ID_CARD_VALIDATION_HPP_
#include <string_view>

class IDCardValidation
{
public:
    static bool validated(std::string_view) noexcept;
};

#endif