#ifndef interfaceValidation_hpp
#define interfaceValidation_hpp

namespace Validation
{
class Validation
{
public:
    virtual bool validated(std::string_view) const noexcept = 0;
    virtual ~Validation(){};
};
} // namespace Validation
#endif