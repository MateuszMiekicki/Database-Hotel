#ifndef Staff_hpp
#define Staff_hpp
#include "Permissions.hpp"

namespace Staff
{
class Staff
{
public:
    Staff() = default;
    explicit Staff(std::string_view, 
                    std::string_view, 
                    std::string_view) noexcept;
    void set(std::string_view, std::string_view, std::string_view);
    std::optional<std::tuple<std::string, 
                            std::string, 
                            std::string>> get() const noexcept;

private:
    std::optional<std::tuple<std::string, 
                            std::string, 
                            std::string>> worker = std::nullopt;
};
} // namespace Staff
#endif