#ifndef JSON_hpp
#define JSON_hpp
#include "Database.hpp"
#include "../../lib/nlohmannjson/json.hpp"
#include <string_view>
#include <fstream>
#include <utility>

namespace Database
{
class JSON : public Database
{
public:
    JSON() = default;
    explicit JSON(std::string_view);
    virtual bool connect(std::string_view) noexcept override;
    virtual bool disconnect() noexcept override;
    nlohmann::json getDataWithDB() noexcept;
    ~JSON();

private:
    std::pair<std::fstream, nlohmann::json> session;
};
} // namespace Database

#endif