#include "lib/include/gtest/gtest.h"
#include "../header/dataValidate/PasswordValidation.hpp"

TEST(PasswordValidation, passPassword_8Char2Big_3Number)
{
	EXPECT_TRUE(PasswordValidation::validated(std::string("KotekALi123")));
}

TEST(PasswordValidation, passPassword_19Char3Big_5Number)
{
	EXPECT_TRUE(PasswordValidation::validated(std::string("SuperTrudneHASLO12345")));
}

TEST(PasswordValidation, badPassword_19Char3Big)
{
	EXPECT_FALSE(PasswordValidation::validated(std::string("SuperTrudneHASLO")));
}

TEST(PasswordValidation, badPassword_smallChar_3Char)
{
	EXPECT_FALSE(PasswordValidation::validated(std::string("ala")));
}

TEST(PasswordValidation, badPassword_noSpecialChar)
{
	EXPECT_FALSE(PasswordValidation::validated(std::string("akotekala")));
}

TEST(PasswordValidation, badPassword_onlySmallCharWithNumberAndSpecialChar)
{
	EXPECT_FALSE(PasswordValidation::validated(std::string("alamakotaka1234!@")));
}