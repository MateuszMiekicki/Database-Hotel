#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, successSyncWithEmptyBaseDatabase)
{
    Utility::FileManagement file;
    file.createFile("base.json", "{}");
    file.createFile("toSync.json", "{\"00000000000\":{\"imie\":\"ala\"}}");
    Database::JSON test("base.json");
    test.sync("toSync.json");
    ASSERT_EQ(test.getDataWithDB(),
              nlohmann::json::parse("{\"00000000000\":{\"imie\":\"ala\"}}"));
}

TEST(JSON, successUpdataDifferentContent)
{
    Utility::FileManagement file;
    file.createFile("base.json", "{\"00000000000\":{\"imie\":\"antek\"}}");
    file.createFile("toSync.json", "{\"00000000000\":{\"imie\":\"ala\"}}");
    Database::JSON test("base.json");
    test.sync("toSync.json");
    ASSERT_EQ(test.getDataWithDB(),
              nlohmann::json::parse("{\"00000000000\":{\"imie\":\"ala\"}}"));
}

TEST(JSON, successUpdataAddedRecord)
{
    Utility::FileManagement file;
    file.createFile("base.json", "{\"00000000000\":{\"imie\":\"antek\"}}");
    file.createFile("toSync.json", "{\"00000000001\":{\"imie\":\"ala\"}}");
    Database::JSON test("base.json");
    test.sync("toSync.json");
    ASSERT_EQ(test.getDataWithDB(),
              nlohmann::json::parse("{\"00000000000\":{\"imie\":\"antek\"},"
                                    "\"00000000001\":{\"imie\":\"ala\"}}"));
}

TEST(JSON, successSyncWithFileWithTXTExtension)
{
    Utility::FileManagement file;
    file.createFile("base.json", "{\"00000000000\":{\"imie\":\"antek\"}}");
    file.createFile("toSync.txt", "{\"00000000001\":{\"imie\":\"ala\"}}");
    Database::JSON test("base.json");
    test.sync("toSync.txt");
    ASSERT_EQ(test.getDataWithDB(),
              nlohmann::json::parse("{\"00000000000\":{\"imie\":\"antek\"},"
                                    "\"00000000001\":{\"imie\":\"ala\"}}"));
}

TEST(JSON, failedSyncWithEmptyFileToSync)
{
    Utility::FileManagement file;
    file.createFile("base.json", "{\"00000000000\":{\"imie\":\"antek\"}}");
    file.createFile("toSync.txt", "");
    Database::JSON test("base.json");
    ASSERT_THROW(test.sync("toSync.txt"), nlohmann::json::parse_error);
}