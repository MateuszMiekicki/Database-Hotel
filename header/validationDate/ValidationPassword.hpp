#ifndef ValidationPassword_hpp
#define ValidationPassword_hpp
#include "Validation.hpp"

namespace ValidationPassword
{
class ValidationPassword : public Validation
{
    public:
    bool validated(std::string_view) const noexcept override;
};
} // namespace ValidationPassword

#endif