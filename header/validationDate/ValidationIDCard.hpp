#ifndef ValidationIDCard_hpp
#define ValidationIDCard_hpp
#include "Validation.hpp"

namespace Validation
{
class ValidationIDCard : public Validation::Validation
{
    public:
    bool validated(std::string_view) const noexcept override;
};
} // namespace Validation

#endif