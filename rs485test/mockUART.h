#ifndef MOCKUART_H
#define MOCKUART_H


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


class MockUART {
 public:
  MockUART(unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits){
	  EXPECT_CALL(*this, put(_))
			.Times(AnyNumber());
  }
  MOCK_CONST_METHOD1(put, void(int bit));
  MOCK_CONST_METHOD0(get, int(void));
};	


#endif
