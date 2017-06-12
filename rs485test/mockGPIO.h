#ifndef MOCKGPIO_H
#define MOCKGPIO_H

class GPIO {
 public:
  GPIO(char port, int pin, int inout) {
	  
  }
  
  GPIO() {
	  
  }
  
  MOCK_CONST_METHOD1(set, 		void(bool bit));
  MOCK_CONST_METHOD0(get, 		int());
  
  enum {
        OUT = 0,
        IN = 1
    };
};


class MockGPIOTestWriteWord {	
	public:
		
		int counter;
		
		GPIO * nRE;
		GPIO * DE;
	
		MockGPIOTestWriteWord() {
			
			A = new GPIO();
			B = new GPIO();
			
			EXPECT_CALL(*this, get())
				.WillRepeatedly(Return(1));
		   
		   
			EXPECT_CALL(*nRE, set(_))
				.Times(1);
			
			//construtor -> shutdown state 
		    //writeWord 	-> 1x
			EXPECT_CALL(*DE, set(_))
				.Times(2);
			
			EXPECT_CALL(*this, newGPIO(_,_,_))
				.Times(2)
				.WillOnce(ReturnPointee(&nRE))
				.WillOnce(ReturnPointee(&DE));
			
		   			
		   //Uma vez em shutdown state
		   //EXPECT_CALL(*this, set(0))
			//	.Times(1);
		  }
		  
		MOCK_METHOD1(set, 		void(bool bit));
		MOCK_METHOD0(get, 		int());
		MOCK_CONST_METHOD3(newGPIO, 	GPIO * (char A, int B, int C));
		
		enum {
			OUT = 0,
			IN = 1
		};
}; 




class MockGPIOTestSend {	
	public:
		MockGPIOTestSend(char port, int pin, int inout) {
		   EXPECT_CALL(*this, get())
				.WillRepeatedly(Return(1));
		   EXPECT_CALL(*this, set(_))
				.Times(AnyNumber());
		  }
		  
		MOCK_CONST_METHOD1(set, 		void(bool bit));
		MOCK_CONST_METHOD0(get, 		int());
		
		enum {
			OUT = 0,
			IN = 1
		};
}; 

#endif
