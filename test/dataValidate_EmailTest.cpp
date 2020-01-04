#include "lib/include/gtest/gtest.h"
#include "dataValidate/EmailValidation.hpp"
#include <string>

TEST(EmailValidation, passEmail)
{
	EXPECT_TRUE(EmailValidation::validated(std::string("ala@email.com")));
}
TEST(EmailValidation, invalidEmail_noDot)
{
	EXPECT_FALSE(EmailValidation::validated(std::string("ala@emailcom")));
}
TEST(EmailValidation, invalidEmail_noAfterDot)
{
	EXPECT_FALSE(EmailValidation::validated(std::string("ala@email.")));
}
TEST(EmailValidation, invalidEmail_noDomenAddres)
{
	EXPECT_FALSE(EmailValidation::validated(std::string("ala@.com")));
}
