#ifndef ValidationPassword_hpp
#define ValidationPassword_hpp
#include "Validation.hpp"

namespace Validation
{
    class ValidationPassword : public Validation::Validation
    {
    public:
        bool validated(std::string_view) const noexcept override;
    };
} // namespace Validation

#endif