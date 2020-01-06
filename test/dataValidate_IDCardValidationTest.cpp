#include "lib/include/gtest/gtest.h"
#include "../header/dataValidate/IDCardValidation.hpp"
#include <string>

TEST(IDCardValidation, correctNumber)
{
    EXPECT_TRUE(IDCardValidation::validated(std::string("ABS123456")));
}

TEST(IDCardValidation, correctNumberWithSpaceAndLettersOfdifferentSizes)
{
    EXPECT_TRUE(IDCardValidation::validated(std::string("abS 123456")));
}

TEST(IDCardValidation, incorrectNumberBadChecksum)
{
    EXPECT_FALSE(IDCardValidation::validated(std::string("ABS223456")));
}

TEST(IDCardValidation, incorrectTooShort)
{
    EXPECT_FALSE(IDCardValidation::validated(std::string("ABS22345")));
}