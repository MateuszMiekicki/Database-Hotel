#ifndef Staff_hpp
#define Staff_hpp
#include <string_view>
#include "Permissions.hpp"
#include <optional>
#include <tuple>

namespace Staff
{
class Staff
{
public:
    Staff() = default;
    explicit Staff(std::string_view, std::string_view, std::string_view, std::string_view, std::string_view, Permissions) noexcept;
    void set(std::string_view, std::string_view, std::string_view, std::string_view, std::string_view, Permissions) noexcept;
    std::optional<std::tuple<std::string, std::string, std::string, std::string, std::string, Permissions>> get() const noexcept;

private:
    std::optional<std::tuple<std::string, std::string, std::string, std::string, std::string, Permissions>> worker = std::nullopt;
};
} // namespace Staff
#endif