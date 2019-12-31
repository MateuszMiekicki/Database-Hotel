#include "lib/include/gtest/gtest.h"
#include "accountLoginRegistration/AccountRegistration.hpp"
#include <string>

TEST(accountLoginRegistration, invalidPesel)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90022355412"), std::string("ala@com.pl"), std::string("KotekALi123"), AccountRegistration::Permissions::read);
    }
    catch(const std::invalid_argument& e)
    {
        EXPECT_EQ(e.what(),std::string("Invalid pesel."));
    }
}

TEST(accountLoginRegistration, invalidEmail)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@compl"), std::string("KotekALi123"), AccountRegistration::Permissions::read);
    }
    catch(const std::invalid_argument& e)
    {
        EXPECT_EQ(e.what(),std::string("Invalid email."));
    }
}


TEST(accountLoginRegistration, invalidPassword)
{
    try
    {
        AccountRegistration test(std::string("ala"), std::string("kot"), std::string("90090515836"), std::string("ala@com.pl"), std::string("Kotek"), AccountRegistration::Permissions::read);
    }
    catch(const std::invalid_argument& e)
    {
        EXPECT_EQ(e.what(),std::string("Invalid password."));
    }
}
