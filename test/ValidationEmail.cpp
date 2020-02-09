#include "../gtest/include/gtest/gtest.h"
#include "../header/validationDate/ValidationEmail.hpp"

ValidationEmail::ValidationEmail email;

TEST(ValidationEmail, passEmail)
{
	EXPECT_TRUE(email.validated(std::string("ala@email.com")));
}
TEST(ValidationEmail, invalidEmailNoDot)
{
	EXPECT_FALSE(email.validated(std::string("ala@emailcom")));
}
TEST(ValidationEmail, invalidEmailNoAfterDot)
{
	EXPECT_FALSE(email.validated(std::string("ala@email.")));
}
TEST(ValidationEmail, invalidEmailNoDomenAddres)
{
	EXPECT_FALSE(email.validated(std::string("ala@.com")));
}

