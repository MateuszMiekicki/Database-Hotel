#include "../../lib/nlohmannjson/json.hpp"
#include "../../header/database/Database.hpp"
#include "../../header/database/JSON.hpp"
#include <fstream>
#include <string_view>
#include <stdexcept>
#include <optional>

Database::JSON::JSON(std::string_view addres)
{
    if (!connect(addres))
        throw std::invalid_argument("JSON ctor: Bad addres database.");
}

bool Database::JSON::connect(std::string_view addres) noexcept
{
    try
    {
        session.first.open(std::string(addres), std::fstream::in | std::fstream::out | std::fstream::app);
        if (session.first.is_open())
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
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
    return true;
}

Database::JSON::~JSON()
{
    disconnect();
}