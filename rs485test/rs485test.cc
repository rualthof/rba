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


void sleep(int n){
	for(int i=0;i<n;i++){
		for(volatile int t=0;t<0xfffff;t++);
	}
}


TEST(SerialTest, testWriteWord){	
		
	SerialRS485 <MockGPIOTestWriteWord, MockUART> r(9600, 8, UART_Common::NONE, 1);	
	
	char msg []={"Mensagem de teste\0"}; 
    int tam = strlen(msg);
   	r.writeWord(2);    	
}


int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}




