#include "gtest/gtest.h"
#include "t4.h"

TEST(Counter, Increment){

	Counter c;
	EXPECT_EQ(0,c.Increment());
	EXPECT_EQ(1,c.Increment());
	EXPECT_EQ(2,c.Increment());
}

int main(int argc,char**argv){

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
