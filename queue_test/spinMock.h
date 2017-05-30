#ifndef spin_h
#define spin_h

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class FooSpin{
 public:
	static void release(void);
	static void acquire(void);  
};


class Spin: public FooSpin {
 public:
  MOCK_METHOD0(release, void(void));
  MOCK_METHOD0(acquire, void(void));
};

#endif
