#ifndef cpu_h
#define cpu_h

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Foo{
 public:
	static void int_disable(void);
	static void int_enable(void);  
};

class CPU: public Foo {
 public:
  MOCK_METHOD0(int_disable, void(void));
  MOCK_METHOD0(int_enable, void(void));
};

#endif
