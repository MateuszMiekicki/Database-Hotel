#ifndef JSON_hpp
#define JSON_hpp
#include "../Database.hpp"

namespace Database
{
class JSON : public Database
{
public:
    JSON() = default;
    explicit JSON(std::string_view);
    bool connect(std::string_view) noexcept override;
    std::optional<nlohmann::json> getDataWithDB() noexcept;
    bool sync(std::filesystem::path) noexcept override;
    std::optional<nlohmann::json> find(const std::string &) const noexcept;
    bool disconnect() noexcept override;
    ~JSON();

private:
    std::pair<std::fstream, nlohmann::json> session;
};
} // namespace Database

#endif