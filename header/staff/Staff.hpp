#ifndef Staff_hpp
#define Staff_hpp
#include <string_view>
#include "StaffPosition.hpp"
#include <optional>
#include <tuple>

namespace Staff
{
class Staff
{
public:
    Staff() = default;
    explicit Staff(std::string_view, std::string_view, std::string_view, std::string_view, std::string_view, Position) noexcept;
    void set(std::string_view, std::string_view, std::string_view, std::string_view, std::string_view, Position) noexcept;
    std::optional<std::tuple<std::string, std::string, std::string, std::string, std::string, Position>> get() const noexcept;

private:
    std::optional<std::tuple<std::string, std::string, std::string, std::string, std::string, Position>> worker = std::nullopt;
};
} // namespace Staff
#endif