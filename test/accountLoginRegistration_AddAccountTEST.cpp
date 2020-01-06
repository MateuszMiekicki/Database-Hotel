#include "lib/include/gtest/gtest.h"
#include "../header/accountLoginRegistration/AddAccount.hpp"
#include "../header/accountLoginRegistration/AccountRegistration.hpp"
#include <string>
#include <filesystem>
#include <fstream>

TEST(AddAccount, addingUserWhenFileDoesNotExist)
{
    if (std::filesystem::exists("user.json"))
    {
        std::filesystem::remove("user.json");
    }
    AccountRegistration user(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@com.pl"), std::string("KotekALi123"), Permissions::read);
    AddAccount registration(user);
    ASSERT_TRUE(registration.add());
}

TEST(AddAccount, addingUserWhenFileExistsWithIncorrectFormatting)
{
    if (std::filesystem::exists("user.json"))
    {
        std::filesystem::remove("user.json");
        std::ifstream("user.json");
    }
    try
    {
        AccountRegistration user(std::string("ala"), std::string("kot"), std::string("92071314764"), std::string("ala@com.pl"), std::string("KotekALi123"), Permissions::read);
        AddAccount registration(user);
    }
    catch (const std::exception &e)
    {
        EXPECT_EQ(e.what(), std::string(e.what()));
    }
}

TEST(AddAccount, addingAnExistingAccount)
{
    if (std::filesystem::exists("user.json"))
    {
        std::filesystem::remove("user.json");
    }
    AccountRegistration user(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@com.pl"), std::string("KotekALi123"), Permissions::read);
    AddAccount registration(user);
    registration.add();
    ASSERT_EQ(registration.add(), false);
}