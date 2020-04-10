#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, disconnect)
{
    FileManagement file;
    file.creteFile("test.json", "{\"one\":1,\"two\":2}");
    Database::JSON json("test.json");
    ASSERT_TRUE(json.disconnect());
}