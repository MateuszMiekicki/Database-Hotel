#include "gtest/include/gtest/gtest.h"
#include "../header/validationDate/ValidationPassword.hpp"

Validation::ValidationPassword password;

TEST(ValidationPassword, passPassword8Char2Big_3Number)
{
	EXPECT_TRUE(password.validated(std::string("KotekALi123")));
}

TEST(ValidationPassword, passPassword19Char3Big_5Number)
{
	EXPECT_TRUE(password.validated(std::string("SuperTrudneHASLO12345")));
}

TEST(ValidationPassword, badPassword19Char3Big)
{
	EXPECT_FALSE(password.validated(std::string("SuperTrudneHASLO")));
}

TEST(ValidationPassword, badPasswordSmallChar_3Char)
{
	EXPECT_FALSE(password.validated(std::string("ala")));
}

TEST(ValidationPassword, badPasswordNoSpecialChar)
{
	EXPECT_FALSE(password.validated(std::string("akotekala")));
}

TEST(ValidationPassword, badPasswordOnlySmallCharWithNumberAndSpecialChar)
{
	EXPECT_FALSE(password.validated(std::string("alamakotaka1234!@")));
}