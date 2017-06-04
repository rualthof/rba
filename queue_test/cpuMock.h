#ifndef cpu_h
#define cpu_h
class CPU{
 public:
	static void int_disable(void);
	static void int_enable(void);  
};
#endif

/*
#include "gtest/gtest.h"
#include "gmock/gmock.h"
class CPU: public Foo {
 public:
  MOCK_METHOD0(int_disable, void(void));
  MOCK_METHOD0(int_enable, void(void));
};
*/


