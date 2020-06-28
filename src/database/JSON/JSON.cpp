#include <string_view>
#include <fstream>
#include <utility>
#include <optional>
#include <filesystem>
#include <iostream>
#include <exception>
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

Database::JSON::JSON(std::string_view addres)
{
    connect(addres);
}

void Database::JSON::connect(std::string_view addres)
{
    if (!std::filesystem::exists(addres))
    {
        throw std::invalid_argument("Database::JSON::connect(std::string_view):"
                                    " The file does not exist.");
    }
    if (std::filesystem::path(addres).extension() != ".json")
    {
        throw std::invalid_argument("Database::JSON::connect(std::string_view):"
                                    " Wrong file extension.");
    }
    session.first.open(std::string(addres),
                       std::fstream::in |
                           std::fstream::out |
                           std::fstream::app);
    session.first >> session.second;
}

nlohmann::json Database::JSON::getDataWithDB() const noexcept
{
    return session.second;
}

void Database::JSON::sync(std::filesystem::path path)
{
    session.second.update(nlohmann::json::parse(std::fstream(path)));
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

bool Database::JSON::operator==(const JSON &objectToCompare) const noexcept
{
    return (this->session.second == objectToCompare.session.second);
}

bool Database::JSON::operator==(const nlohmann::json &objectToCompare) const
                                                                       noexcept
{
    return (this->session.second == objectToCompare);
}