#ifndef spin_h
#define spin_h
class Spin{
 public:
	static void release(void);
	static void acquire(void);  
};
#endif

/*
#include "gtest/gtest.h"
#include "gmock/gmock.h"
class Spin: public FooSpin {
 public:
  MOCK_METHOD0(release, void(void));
  MOCK_METHOD0(acquire, void(void));
};
*/ 


