#ifndef MOCKGPIO_H
#define MOCKGPIO_H

using ::testing::Return;
using ::testing::ReturnPointee;
using ::testing::_;
using namespace std;	

class GPIO_Common
{
protected:
    GPIO_Common() {}

public:
    enum Level {
        HIGH,
        LOW
    };

    enum Edge {
        RISING,
        FALLING,
        BOTH
    };

    enum Direction {
        IN,
        OUT,
        INOUT
    };

    enum Pull {
        UP,
        DOWN,
        FLOATING
    };
};


/*
 * Mock da classe GPIO para simular os 
 * metodos set, get e construtor.
 */ 
class GPIO {
 public:
	
  int counter;
  
  GPIO() {}
  GPIO(char port, int pin, int inout) {}  
  
  MOCK_CONST_METHOD1(set, 		void(bool bit));
  MOCK_CONST_METHOD0(get, 		int());
 
};

/*
 * Passa como parametro template os valores 'nWrites' e 'nReads'
 * e com base nestes parametros cria as expectativas para cada
 * chamada dos metodos da GPIO
 */ 
template <int nWrites=0, int nReads=0>
class MockGPIOCreator {	
	public:
		
		GPIO * nRE;
		GPIO * DE;
	
		MockGPIOCreator() {
			
			/*
			 * Espera apenas duas chamadas e retorna 
			 * os enderecos de nRE e DE, nesta ordem.
			 */
			 
			nRE = new GPIO();
			DE = new GPIO();
			 
			EXPECT_CALL(*this, newGPIO(_,_,_))
				.Times(2)
				.WillOnce(ReturnPointee(&nRE))
				.WillOnce(ReturnPointee(&DE));						
			
		    /*
		     * construtor -> shutdown state 
		     * destructor -> shutdown state 
		     */ 
			EXPECT_CALL(*nRE, set(1))
				.Times(1+1);
			
			/*
			 * readWord 	-> nReads vezes
			 */ 
			EXPECT_CALL(*nRE, set(0))
				.Times(nReads);
			
			/*
			 * constructor 	-> shutdown state
			 * receiving 	-> nReads vezes
			 * destructor	-> shutdown state
			 */
			EXPECT_CALL(*DE, set(0))
				.Times(nReads+1+1);
			
			/* 
			 * writeWord  -> nWrites vezes	
			 */
			EXPECT_CALL(*DE, set(1))
				.Times(nWrites);
			
		}
		  
		MOCK_CONST_METHOD3(newGPIO, 	GPIO * (char A, int B, int C));
}; 

#endif
