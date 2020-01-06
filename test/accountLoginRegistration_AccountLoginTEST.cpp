#include "lib/include/gtest/gtest.h"
#include "../header/accountLoginRegistration/AccountLogin.hpp"
#include <string>

TEST(AccountLogin, correctPeselAndPassword)
{
    AccountLogin account(std::string("90090515836"), std::string("KotekALi123"));
    EXPECT_EQ(account.login(), Permissions::read);
}

TEST(AccountLogin, validPeselIncorrectPassword)
{
    AccountLogin account(std::string("90090515836"), std::string("Kotek"));
    EXPECT_EQ(account.login(), std::nullopt);
}

TEST(AccountLogin, validPasswordIncorrectPesel)
{
    AccountLogin account(std::string("90090515812"), std::string("KotekALi123"));
    EXPECT_EQ(account.login(), std::nullopt);
}