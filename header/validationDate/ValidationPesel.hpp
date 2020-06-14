#ifndef ValidationPesel_hpp
#define ValidationPesel_hpp
#include "Validation.hpp"

namespace Validation
{
    class ValidationPesel : public Validation::Validation
    {
    public:
        bool validated(std::string_view) const noexcept override;
    };
} // namespace Validation

#endif