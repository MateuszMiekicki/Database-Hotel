#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, equalEmptyFiles)
{
    Utility::FileManagement file;
    file.createFile("test.json", "{}");
    file.createFile("testTwo.json", "{}");
    Database::JSON test("test.json");
    Database::JSON testTwo("testTwo.json");
    ASSERT_TRUE(test == testTwo);
}

TEST(JSON, equalSameContent)
{
    Utility::FileManagement file;
    file.createFile("test.json", "[{\"one\":1}, {\"two\": 2}]");
    file.createFile("testTwo.json", "[{\"one\":1}, {\"two\": 2}]");
    Database::JSON test("test.json");
    Database::JSON testTwo("testTwo.json");
    ASSERT_TRUE(test == testTwo);
}

TEST(JSON, equalSameContentButInDifferentOrder)
{
    Utility::FileManagement file;
    file.createFile("test.json", "[{\"one\":1}, {\"two\": 2}]");
    file.createFile("testTwo.json", "[{\"two\": 2}], {\"one\":1}");
    Database::JSON test("test.json");
    Database::JSON testTwo("testTwo.json");
    ASSERT_TRUE(test == testTwo);
}

TEST(JSON, dontEqualAnotherFileOneEmptyOtherNot)
{
    Utility::FileManagement file;
    file.createFile("test.json", "{}");
    file.createFile("testTwo.json", "[{\"one\":1}, {\"two\": 2}]");
    Database::JSON test("test.json");
    test.getDataWithDB();
    Database::JSON testTwo("testTwo.json");
    testTwo.getDataWithDB();
    ASSERT_FALSE(test == testTwo);
}

TEST(JSON, dontEqualAnotherFileObjectAndArray)
{
    Utility::FileManagement file;
    file.createFile("test.json", "[]");
    file.createFile("testTwo.json", "{}");
    Database::JSON test("test.json");
    test.getDataWithDB();
    Database::JSON testTwo("testTwo.json");
    testTwo.getDataWithDB();
    ASSERT_FALSE(test == testTwo);
}