#include <gtest/gtest.h>
// #include "../includes/Zombie.hpp"

TEST(HelloTest, BasicAssertions){
	EXPECT_STRNE("sapo", "gordo");
	EXPECT_EQ(5 + 5, 10);
}
