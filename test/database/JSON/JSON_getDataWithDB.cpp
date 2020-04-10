#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

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

TEST(JSON, emptyFileWithDBContent)
{
    FileManagement file;
    file.creteFile("test.json", "");
    Database::JSON json("test.json");
    nlohmann::json temp;
    temp = {{"one", 1}, {"two", 2}};
    EXPECT_EQ(json.getDataWithDB(), std::nullopt);
}