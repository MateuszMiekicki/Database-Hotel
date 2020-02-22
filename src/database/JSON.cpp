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
        {
            session.first >> session.second;
            return true;
        }
        else
            return false;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

std::optional<nolhmalnn::json> Database::JSON::getDataWithDB() noexcept
{
    try
    {
    }
    catch (...)
    {
        return false;
    }
    return true;
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