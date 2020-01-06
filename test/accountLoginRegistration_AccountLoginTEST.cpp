#include "lib/include/gtest/gtest.h"
#include "../header/accountLoginRegistration/AccountLogin.hpp"
#include <string>

TEST(AccountLogin, correctPeselAndPassword)
{
    AccountLogin account(std::string("90090515836"), std::string("KotekALi123"));
    ASSERT_TRUE(account.login());
}

TEST(AccountLogin, validPeselIncorrectPassword)
{
    AccountLogin account(std::string("90090515836"), std::string("Kotek"));
    ASSERT_FALSE(account.login());
}

TEST(AccountLogin, validPasswordIncorrectPesel)
{
    AccountLogin account(std::string("90090515812"), std::string("KotekALi123"));
    ASSERT_FALSE(account.login());
}