//#include <gpio.h>
//#include <alarm.h>

//#include <utility/ostream.h>
#include <iostream>
#define RS_485_TEST
#include "rs485.h"


	TEST(SerialRS485Test, testWriteChar){	
		
		
		const int nWrites=6; //apenas 6 validas
		const int nReads=0;	
		SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	
		
		int i = 0;
		//Leituras invalidas
		EXPECT_EQ(-1,  r.writeChar(-3));
		EXPECT_EQ(-1,  r.writeChar(-2));
		EXPECT_EQ(-1,  r.writeChar(-1));	
		//Leituras validas
		EXPECT_EQ(0,   r.writeChar(0));
		EXPECT_EQ(1,   r.writeChar(1));
		EXPECT_EQ(2,   r.writeChar(2));		
		EXPECT_EQ(3,   r.writeChar(3));
		
		EXPECT_EQ(126, r.writeChar(126));
		EXPECT_EQ(127, r.writeChar(127));	
		//Leituras invalidas
		EXPECT_EQ(-1,  r.writeChar(128));
		EXPECT_EQ(-1,  r.writeChar(129));
		EXPECT_EQ(-1,  r.writeChar(130));	  	
	}

/*
 * Testa a leitura de uma sequencia de caracteres
 * bem definido. Verificando o valor recebido a cada
 * chamada do metodo readChar()
 */

TEST(SerialRS485Test, testReadChar){		
	const int nWrites=0;
	const int nReads=12;
	SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	
	
	//Leituras invalidas
	EXPECT_EQ(-1,  r.readChar());
	EXPECT_EQ(-1,  r.readChar());
	EXPECT_EQ(-1,  r.readChar());	
	//Leituras validas
	EXPECT_EQ(0,   r.readChar());
	EXPECT_EQ(1,   r.readChar());
	EXPECT_EQ(2,   r.readChar());
	
	EXPECT_EQ(3,   r.readChar());
	EXPECT_EQ(126, r.readChar());
	EXPECT_EQ(127, r.readChar());	
	//Leituras invalidas
	EXPECT_EQ(-1,  r.readChar());
	EXPECT_EQ(-1,  r.readChar());
	EXPECT_EQ(-1,  r.readChar());	
	
	cout<<endl;
	
	/* 
	 * Esta implementacao se faz possivel pois a classe MockUARTCreator
	 * retorna um array com chars cobrindo as classes de equivalencia e analises de limite.
	 */ 
	
}

/*
TEST(SerialRS485Test, testFailExample){	
	 
	const int nWrites=2;
	const int nReads=1;	
	SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	

    r.writeWord('1');    	
    r.writeWord('2');    	
}
*/

int main( int argc, char *argv[] ) {
	
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}




