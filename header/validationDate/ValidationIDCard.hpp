#ifndef ValidationIDCard_hpp
#define ValidationIDCard_hpp
#include "Validation.hpp"

namespace ValidationIDCard
{
class ValidationIDCard : public Validation
{
    public:
    bool validated(std::string_view) const noexcept override;
};
} // namespace ValidationIDCard

#endif