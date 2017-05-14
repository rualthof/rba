#include "ex2.h"
#include"gtest/gtest.h" 


//Test the defalt constructor
TEST(MyString, DefaultConstructor){
	const MyString s;
	EXPECT_STREQ(NULL, s.c_string());	
	EXPECT_EQ(0u,s.Length());
}

const char hs [] = "Hello, world!";

//Test constructor that accepts a C string
TEST(MyString, ConstructorFromCString){
	const MyString s(hs);
	EXPECT_EQ(0,strcmp(s.c_string(),hs));
	EXPECT_EQ(sizeof(hs)/sizeof(hs[0])-1, s.Length());
}

//Test the copy constructor
TEST(MyString, ConstructorFromString){
	const MyString s1(hs);
	const MyString s2 = s1;
	EXPECT_EQ(0,strcmp(s2.c_string(), hs));
}

//Test the set method
TEST(MyString, Set){
	MyString s;

	s.Set(hs);
	EXPECT_EQ(0,strcmp(s.c_string(), hs));
	//Show work when the input pointer is the same as the one already
	//in the MyString object
	EXPECT_EQ(0,strcmp(s.c_string(), hs));
	//Can we set the MyString to NULL?	
	s.Set(NULL);
	EXPECT_STREQ(NULL,s.c_string());
}
	
	

int main(int argc, char ** argv){ 
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}





