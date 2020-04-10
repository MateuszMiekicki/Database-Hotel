#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

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