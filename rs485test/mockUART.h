#ifndef MOCKUART_H
#define MOCKUART_H

using ::testing::Return;
using ::testing::ReturnPointee;
using ::testing::_;
using namespace std;

class UART_Common
{
protected:
    UART_Common() {}

public:
    // Parity
    enum {
        NONE = 0,
        ODD = 1,
        EVEN = 2
    };
};

class UART {
 public:
	
  int counter;
 
  UART() {}	
  UART(unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits){}
    
  MOCK_CONST_METHOD1(put, 		void(int word));
  MOCK_CONST_METHOD0(get, 		int());
  
};

/*
 * Passa como parametro template o valor 'n'
 * que refere-se ao numero de vezes que o metodo
 * put sera chamado. 
 */ 
template <int nWrites=0, int nReads=0>
class MockUARTCreator {
 
 public:
	
	UART * uart1;
 
	MockUARTCreator(){
		
		uart1 = new UART();
		 
		EXPECT_CALL(*this, newUART(_,_,_,_,_))
				.Times(1)
				.WillOnce(ReturnPointee(&uart1));
		
		EXPECT_CALL(*uart1, put(_))	
			.Times(nWrites);
			
		/*
		 * Define uma expectiva por leitura a ser efetuada
		 * desta forma permite que se definam 0 leituras
		 * para testes que usam apenas escrita.
		 * A ultima expectativa criada eh a primeira atendida,
		 * desta forma, a orderm de retorno sera: -3,-2,-1, ... nReads-1.
		 */ 
		if(nReads){
			char limits_array []= {-3,-2,-1,0,1,2,3,126,127,128,129,130};
			for (int i = sizeof(limits_array); i > 0 ; ) {
				EXPECT_CALL(*uart1, get())
					.WillOnce(Return(limits_array[--i]))
					.RetiresOnSaturation();
			}	
		}		
		
	}
 
	MOCK_CONST_METHOD5(newUART, UART * (unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits));
	
	
	
};	


#endif
