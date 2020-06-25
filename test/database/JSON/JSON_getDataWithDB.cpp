#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, successGetDataWithDB)
{
    Utility::FileManagement file;
    file.createFile("test.json", "{\"one\": 1, \"two\": 2}");
    Database::JSON json("test.json");
    nlohmann::json temp = nlohmann::json::parse("{\"one\": 1, \"two\": 2}");
    EXPECT_EQ(json.getDataWithDB(), temp);
}