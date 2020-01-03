#include "lib/include/gtest/gtest.h"
#include "accountLoginRegistration/AccountRegistration.hpp"
#include <string>

TEST(AccountRegistration, invalidPesel)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90022355412"), std::string("ala@com.pl"), std::string("KotekALi123"), Permissions::read);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(), std::string("Invalid pesel."));
    }
}

TEST(AccountRegistration, invalidEmail)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@compl"), std::string("KotekALi123"), Permissions::read);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(), std::string("Invalid email."));
    }
}

TEST(AccountRegistration, invalidPassword)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@com.pl"), std::string("Kotek"), Permissions::read);
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_EQ(e.what(), std::string("Invalid password."));
    }
}
