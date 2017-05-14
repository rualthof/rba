//http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html

#include "t5.h"
 #include <limits.h>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
