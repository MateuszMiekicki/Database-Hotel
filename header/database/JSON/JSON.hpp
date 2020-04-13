#ifndef JSON_hpp
#define JSON_hpp

namespace Database
{
class JSON
{
public:
    JSON() = default;
    explicit JSON(std::string_view);
    bool connect(std::string_view) noexcept;
    std::optional<nlohmann::json> getDataWithDB() noexcept;
    bool sync(std::filesystem::path) noexcept;
    std::optional<nlohmann::json> find(const std::string &) const noexcept;
    bool disconnect() noexcept;
    ~JSON();

private:
    std::pair<std::fstream, nlohmann::json> session;
};
} // namespace Database

#endif