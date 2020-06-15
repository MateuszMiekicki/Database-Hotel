#include <string_view>
#include <fstream>
#include <optional>
#include "../../gtest/include/gtest/gtest.h"
#include "../../Utility/FileManagement.hpp"
#include "../../../lib/nlohmannjson/json.hpp"
#include "../../../header/database/JSON/JSON.hpp"

TEST(JSON, findInDBFile)
{
    Utility::FileManagement file;
    file.createFile("test.json",
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