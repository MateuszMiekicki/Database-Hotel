#include <fstream>
#include <string_view>
#include <stdexcept>
#include <optional>
#include <filesystem>
#include "../../lib/nlohmannjson/json.hpp"
#include "../../header/database/Database.hpp"
#include "../../header/database/JSON.hpp"

Database::JSON::JSON(std::string_view addres)
{
    if (connect(addres) == false)
        throw std::invalid_argument("JSON ctor: Bad addres database.");
}

bool Database::JSON::connect(std::string_view addres) noexcept
{
    try
    {
        if (std::filesystem::exists(addres))
        {
            session.first.open(std::string(addres),
                               std::fstream::in |
                                   std::fstream::out |
                                   std::fstream::app);
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
    return true;
}

std::optional<nlohmann::json> Database::JSON::getDataWithDB() noexcept
{
    try
    {
        session.first >> session.second;
    }
    catch (...)
    {
        return std::nullopt;
    }
    return session.second;
}

bool Database::JSON::disconnect() noexcept
{
    session.first.close();
    session.second.clear();
    return ((session.first.is_open() == 0) &&
            (session.second.size() == 0))
               ? true
               : false;
}

std::optional<nlohmann::json> Database::JSON::find(const std::string &key) const
    noexcept
{
    if (session.second.find(key) != session.second.end())
    {
        return session.second.at(key);
    }
    return std::nullopt;
}

Database::JSON::~JSON()
{
    disconnect();
}