//#include <gpio.h>
//#include <alarm.h>

//#include <utility/ostream.h>
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::ReturnPointee;
using ::testing::AnyNumber;
using ::testing::_;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using namespace std;


#include "mockGPIO.h"
#include "mockUART.h"
#include "rs485.h"


TEST(SerialRS485Test, testWriteWord){	
	
	const int nWrites=100;
	const int nReads=0;	
	SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	

    for(int i=0;i<nWrites;i++)
		r.writeWord(i);    	
}

/*
 * Testa a leitura de uma sequencia de caracteres
 * bem definido. Verificando o valor recebido a cada
 * chamada do metodo readWord()
 */

TEST(SerialRS485Test, testReadWord){		
	const int nWrites=0;
	const int nReads=100;	
	SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	

	int leitura;
    for(int i=0;i<nReads;i++){
		leitura = r.readWord();
		EXPECT_EQ(i, leitura);
		//cout<<leitura<<" ";
	}
	cout<<endl;
}

TEST(SerialRS485Test, testWriteWordOverfolow){	
	
	const int nWrites=10;
	const int nReads=0;	
	SerialRS485 < MockGPIOCreator<nWrites, nReads>, MockUARTCreator<nWrites, nReads> > r(9600, 8, UART_Common::NONE, 1);	

    for(int i=80000;i<80000+nWrites;i++)
		r.writeWord(i);    	
}



int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}




