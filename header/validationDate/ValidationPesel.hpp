#ifndef ValidationPesel_hpp
#define ValidationPesel_hpp
#include "Validation.hpp"

namespace ValidationPesel
{
class ValidationPesel : public Validation
{
    public:
    bool validated(std::string_view) const noexcept override;
};
} // namespace ValidationPesel

#endif