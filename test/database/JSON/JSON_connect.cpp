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
    file.createFile("test.json");
    ASSERT_NO_THROW(Database::JSON json("test.json"));
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

TEST(JSON, failedConnectionDueToMissingFile)
{
    try
    {
        Database::JSON json;
        json.connect("thisFileDoesExist.json");
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(),
                  std::string("Database::JSON::connect(std::string_view):"
                              " The file does not exist."));
    }
}

TEST(JSON, theFileExistsButItHasBadExtension)
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