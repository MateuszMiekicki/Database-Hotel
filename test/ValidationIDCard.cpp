#include "../gtest/include/gtest/gtest.h"
#include "../header/validationDate/ValidationIDCard.hpp"

ValidationIDCard::ValidationIDCard IDCard;

TEST(ValidationIDCard, correctNumber)
{
    EXPECT_TRUE(IDCard.validated(std::string("ABS123456")));
}

TEST(ValidationIDCard, correctNumberWithSpaceAndLettersOfdifferentSizes)
{
    EXPECT_TRUE(IDCard.validated(std::string("abS 123456")));
}

TEST(ValidationIDCard, incorrectNumberBadChecksum)
{
    EXPECT_FALSE(IDCard.validated(std::string("ABS223456")));
}

TEST(ValidationIDCard, incorrectTooShort)
{
    EXPECT_FALSE(IDCard.validated(std::string("ABS22345")));
}

TEST(ValidationIDCard, incorrectTooLong)
{
    EXPECT_FALSE(IDCard.validated(std::string("ABS2232345")));
}