#ifndef ValidationEmail_hpp
#define ValidationEmail_hpp
#include "Validation.hpp"

namespace ValidationEmail
{
class ValidationEmail : public Validation
{
    public:
    bool validated(std::string_view) const noexcept override;
};
} // namespace ValidationEmail

#endif