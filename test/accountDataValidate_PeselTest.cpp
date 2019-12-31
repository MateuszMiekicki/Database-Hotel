#include "lib/include/gtest/gtest.h"
#include "accountDataValidate/PeselValidation.hpp"

TEST(PeselValidation, passPesel_men20_25)
{
	EXPECT_TRUE(PeselValidation::validated(std::string("90090515836")));
}

TEST(PeselValidation, passPesel_women20_25)
{
	EXPECT_TRUE(PeselValidation::validated(std::string("92071314764")));
}

TEST(PeselValidation, passPesel_men30_35)
{
	EXPECT_TRUE(PeselValidation::validated(std::string("81100216357")));
}

TEST(PeselValidation, passPesel_women30_35)
{
	EXPECT_TRUE(PeselValidation::validated(std::string("80072909146")));
}

TEST(PeselValidation, incorectPesel_badControlNumberv1)
{
	EXPECT_FALSE(PeselValidation::validated(std::string("90022300612")));
}

TEST(PeselValidation, incorectPesel_badControlNumberv2)
{
	EXPECT_FALSE(PeselValidation::validated(std::string("90022355412")));
}