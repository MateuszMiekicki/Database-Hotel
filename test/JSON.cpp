#include "../gtest/include/gtest/gtest.h"
#include "../header/database/JSON.hpp"
#include "Utility/FileManagement.hpp"

TEST(JSON, successConnect)
{
    FileManagement file;
    file.creteFile("test.json");
    Database::JSON json;
    ASSERT_TRUE(json.connect("test.json"));
    file.deleteFile("test.json");
}
