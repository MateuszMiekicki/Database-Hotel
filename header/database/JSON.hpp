#ifndef JSON_hpp
#define JSON_hpp
#include <string_view>
#include <fstream>
#include <utility>
#include <optional>
#include "Database.hpp"
#include "../../lib/nlohmannjson/json.hpp"

namespace Database
{
class JSON : public Database
{
public:
    JSON() = default;
    explicit JSON(std::string_view);
    bool connect(std::string_view) noexcept override;
    bool addNewGuest() const noexcept;
    std::optional<nlohmann::json> getDataWithDB() noexcept;
    std::optional<nlohmann::json> find(const std::string &) const noexcept;
    bool disconnect() noexcept override;
    ~JSON();

private:
    std::pair<std::fstream, nlohmann::json> session;
};
} // namespace Database

#endif