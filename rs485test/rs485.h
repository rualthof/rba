#ifndef RS485_H
#define RS485_H

#include <machine.h>
#include <gpio.h>
#include <alarm.h>
#include <utility/ostream.h>
#include <uart.h>

using namespace EPOS;
OStream cout;

/*
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockGPIO.h"
#include "mockUART.h"
*/

/* Classe utilizada para a criacao de 
 * objetos GPIO, passada como parametro template
 * para a classe SerialRS485
 */
class GPIOCreator {
	public:	
		GPIO * newGPIO(char port, int pin, GPIO_Common::Direction inout)
		{
			return new GPIO(port, pin, inout);
		}
};


/* Classe utilizada para a criacao de 
 * objetos UART, passada como parametro template
 * para a classe SerialRS485
 */
class UARTCreator {
	public:
	 UART * newUART(unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits){
		 return new UART(unit, baud_rate, data_bits, parity, stop_bits);
	 }
};

/* 
 * Esta classe utiliza a classe UART pois
 * DI ja esta conectado em TX da UART
 * e RO ja esta conectado no RX da UART
 * 
 * Como a classe UART1 ja implementa baudrate, paridade, numero de bits
 * basta extender a classe
 */  

template <class GPIOClass, class UARTClass>
class SerialRS485 {
		
	public:
	
		//PC5 - RS485 RE - Receiving Enable
		GPIO * nRE;
		//PC6 - RS485 DE - Driver Enable
		GPIO * DE; 		
		UART * uart;
		
		GPIOClass * gpioCreator;
		UARTClass * uartCreator;
		
		
		SerialRS485(unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits)
		{		
			gpioCreator = new GPIOClass();
			uartCreator = new UARTClass();
			
			nRE 	= gpioCreator->newGPIO('C',5, GPIO_Common::OUT);
			DE  	= gpioCreator->newGPIO('C',6, GPIO_Common::OUT);
			uart 	= uartCreator->newUART(1, baud_rate, data_bits, parity, stop_bits);
			shutdownState();	
		}
		
		~SerialRS485(){
			shutdownState();
			delete nRE;
			delete DE;
			delete uart;
			delete gpioCreator;
			delete uartCreator;
		}
		
		//DI ja esta conectado em TX da UART
		
		//Se char der overflow??		
		void writeWord(char i){			
			sendingState();
			uart->put(i);
		}		
		
		//RO ja esta conectado no RX da UART
		char readWord(){	
			receivingState();		
			char i = uart->get();
			return i;
		}
		
		
		/*/Se msg for null?
		//Se tamanho de msg for 0? 
		//Testar		
		void sendMessage(char msg [], unsigned int tam){
			//int j = strlen(msg);
			//cout<<endl<<"Escrevendo: "<<j<<" ";
			//writeWord(j);
			sendingState();
			for(int i=0;i<tam;i++){
				writeWord(msg[i]); 
				//cout<<msg[i]; 
			} 
		} 
	
		//Se msg for null?
		//Se tamanho de msg for 0? 
		//Testar
		int readMessage(char msg [], unsigned int tam){
			//cout<<endl<<"Tamanho da proxima mensagem: ";
			//int j = readWord();  
			//cout<<j<<endl;
       
			cout<<"Recebendo mensagem:";			
			for(int i=0;i<tam;i++){
				msg[i]=readWord(); 
				//cout<< char(msg[i]);
			}       
			
			return tam;       
		} 
	*/
	//private:
		
		void sendingState(){
			//cout<<"Sending: DE = 1"<<endl;
			DE->set(1);
		}
		
		void shutdownState(){
			//cout<<"Shutdown: DE = 0, nRE=1"<<endl;
			DE->set(0);
			nRE->set(1);		
		}
		
		void receivingState(){
			//cout<<"Receiving: DE = 0, nRE=0"<<endl;
			DE->set(0);
			nRE->set(0);		
		}	
};

#endif
