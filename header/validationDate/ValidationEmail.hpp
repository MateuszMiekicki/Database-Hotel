#ifndef ValidationEmail_hpp
#define ValidationEmail_hpp
#include "Validation.hpp"

namespace Validation
{
    class ValidationEmail : public Validation::Validation
    {
    public:
        bool validated(std::string_view) const noexcept override;
    };
} // namespace Validation

#endif