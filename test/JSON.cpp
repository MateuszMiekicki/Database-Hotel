#include "../gtest/include/gtest/gtest.h"
#include "../header/database/JSON.hpp"
#include "Utility/FileManagement.hpp"

TEST(JSON, successConnect)
{
    FileManagement file;
    file.creteFile("test.json");
    Database::JSON json;
    ASSERT_TRUE(json.connect("test.json"));
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

TEST(JSON, noFileDB)
{
    Database::JSON json;
    EXPECT_FALSE(json.connect("test.json"));
}