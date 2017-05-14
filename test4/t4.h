#ifndef t4_h
#define t4_h

#include <iostream>

class Counter {
	private:
		int counter_;
	
	public:
		Counter() : counter_(0){}

		int Increment(){
			return counter_++;
		}
		void Print() const {			
			std::cout<<counter_<<std::endl;
		}
};

#endif
