#include "../gtest/include/gtest/gtest.h"
#include "../header/validationDate/ValidationPesel.hpp"

ValidationPesel::ValidationPesel pesel;

TEST(ValidationPesel, passPeselMen20_25Age)
{
	EXPECT_TRUE(pesel.validated(std::string("90090515836")));
}

TEST(ValidationPesel, passPeselWomen20_25Age)
{
	EXPECT_TRUE(pesel.validated(std::string("92071314764")));
}

TEST(ValidationPesel, passPeselMen30_35Age)
{
	EXPECT_TRUE(pesel.validated(std::string("81100216357")));
}

TEST(ValidationPesel, passPeselWomen30_35Age)
{
	EXPECT_TRUE(pesel.validated(std::string("80072909146")));
}

TEST(ValidationPesel, incorectPeselBadControlNumberv1)
{
	EXPECT_FALSE(pesel.validated(std::string("90022300612")));
}

TEST(ValidationPesel, incorectPeselBadControlNumberv2)
{
	EXPECT_FALSE(pesel.validated(std::string("90022355412")));
}

TEST(ValidationPesel, incorectPeselTooShort)
{
	EXPECT_FALSE(pesel.validated(std::string("900223554")));
}

TEST(ValidationPesel, incorectPeselWithLetter)
{
	EXPECT_FALSE(pesel.validated(std::string("900223554aa")));
}