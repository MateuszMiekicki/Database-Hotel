#ifndef _INTERFACE_VALIDATION_HPP_
#define _INTERFACE_VALIDATION_HPP_

#include <string_view>

class iValidation
{
    public:
    virtual ~iValidation() {};
    virtual static bool validated(std::string_view) const noexcept;
}

#endif