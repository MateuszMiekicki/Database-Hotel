#include "../gtest/include/gtest/gtest.h"
#include "../../header/validationDate/ValidationEmail.hpp"

Validation::ValidationEmail email;

TEST(ValidationEmail, passEmail)
{
	EXPECT_TRUE(email.validated(std::string("ala@email.com")));
}

TEST(ValidationEmail, passEmailWithDotBetwenWords)
{
	EXPECT_TRUE(email.validated(std::string("jan.kowalski@gmail.com")));
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

TEST(ValidationEmail, emptyEmail)
{
	EXPECT_FALSE(email.validated(std::string("")));
}

TEST(ValidationEmail, withSpaceBetwenAt)
{
	EXPECT_FALSE(email.validated(std::string("ala @email.com")));
}

TEST(ValidationEmail, withSpaceOnEnd)
{
	EXPECT_FALSE(email.validated(std::string("ala@email.com ")));
}

TEST(ValidationEmail, withSpaceOnBegin)
{
	EXPECT_FALSE(email.validated(std::string("ala@email.com ")));
}