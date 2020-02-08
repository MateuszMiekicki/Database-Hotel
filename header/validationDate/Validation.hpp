#ifndef interfaceValidation
#define interfaceValidation
#include <string_view>

class Validation
{
public:
    virtual bool validated(std::string_view) const noexcept = 0;
    virtual ~Validation(){};
};

#endif