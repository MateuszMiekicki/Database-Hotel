#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, successConnectWithConstructor)
{
    Utility::FileManagement file;
    file.createFile("test.json", "{ }");
    ASSERT_NO_THROW(Database::JSON("test.json"));
}

TEST(JSON, failedConnectionDueToMissingFileConstructor)
{
    try
    {
        Database::JSON json("thisFileDoesExist.json");
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Database::JSON::connect(std::string_view):"
                              " The file does not exist."));
    }
}

TEST(JSON, fileExistsButItHasBadExtension)
{
    try
    {
        Utility::FileManagement file;
        file.createFile("fileWithRheWrongExtension.txt");
        Database::JSON json;
        json.connect("fileWithRheWrongExtension.txt");
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Database::JSON::connect(std::string_view):"
                              " Wrong file extension."));
    }
}

TEST(JSON, downloadDataWithEmptyDBFile)
{
    Utility::FileManagement file;
    file.createFile("test.json");
    EXPECT_THROW(Database::JSON("test.json"), nlohmann::json::parse_error);
}

TEST(JSON, getDataWithDBSimpleTwoObject)
{
    Utility::FileManagement file;
    file.createFile("test.json", "{\"one\":1,\"two\":2}");
    Database::JSON json("test.json");
    nlohmann::json temp;
    temp = {{"one", 1}, {"two", 2}};
    EXPECT_EQ(json.getDataWithDB(), temp);
}