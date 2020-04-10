#include <string_view>
#include <fstream>
#include <optional>
#include "gtest/include/gtest/gtest.h"
#include "Utility/FileManagement.hpp"
#include "../lib/nlohmannjson/json.hpp"
#include "../header/database/JSON.hpp"

TEST(JSON, successConnect)
{
    FileManagement file;
    file.creteFile("test.json");
    Database::JSON json;
    ASSERT_TRUE(json.connect("test.json"));
}

TEST(JSON, successConnectWithConstructor)
{
    FileManagement file;
    file.creteFile("test.json");
    ASSERT_NO_THROW(Database::JSON json("test.json"));
}

TEST(JSON, wrongConnectWithConstructor)
{
    try
    {
        Database::JSON json("test.json");
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(), std::string("JSON ctor: Bad addres database."));
    }
}

TEST(JSON, getDataWithDBEmptyDB)
{
    FileManagement file;
    file.creteFile("test.json", "{}");
    Database::JSON json("test.json");
    nlohmann::json temp;
    temp = {{"one", 1}, {"two", 2}};
    temp.clear();
    EXPECT_EQ(json.getDataWithDB(), temp);
}

TEST(JSON, getDataWithDBSimpleTwoObject)
{
    FileManagement file;
    file.creteFile("test.json", "{\"one\":1,\"two\":2}");
    Database::JSON json("test.json");
    nlohmann::json temp;
    temp = {{"one", 1}, {"two", 2}};
    EXPECT_EQ(json.getDataWithDB(), temp);
}

TEST(JSON, disconeted)
{
    FileManagement file;
    file.creteFile("test.json", "{\"one\":1,\"two\":2}");
    Database::JSON json("test.json");
    ASSERT_TRUE(json.disconnect());
}

TEST(JSON, emptyFileWithDBContent)
{
    FileManagement file;
    file.creteFile("test.json", "");
    Database::JSON json("test.json");
    nlohmann::json temp;
    temp = {{"one", 1}, {"two", 2}};
    EXPECT_EQ(json.getDataWithDB(), std::nullopt);
}

TEST(JSON, findInDBFile)
{
    FileManagement file;
    file.creteFile("test.json",
                   "{\"test1\": [\"name\",10,true,\"poland\"],"
                   "\"test2\": [\"name\",10,true,\"poland\"],"
                   "\"test3\": [\"name\",10,true,\"poland\"],"
                   "\"test4\": [\"name\",10,true,\"poland\"]}");
    Database::JSON json("test.json");
    json.getDataWithDB();
    auto returnValue = json.find("test2");
    nlohmann::json fileToCompare;
    fileToCompare["test2"].push_back("name");
    fileToCompare["test2"].push_back(10);
    fileToCompare["test2"].push_back(true);
    fileToCompare["test2"].push_back("poland");
    ASSERT_EQ(returnValue.value(), fileToCompare.at("test2"));
}