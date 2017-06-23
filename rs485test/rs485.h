#ifndef RS485_H
#define RS485_H

/* 
 * Esta classe deriva de UART pois
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
			
			nRE 	= gpioCreator->newGPIO('C',5, GPIOClass::OUT);
			DE  	= gpioCreator->newGPIO('C',6, GPIOClass::OUT);
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
		int readWord(){	
			receivingState();		
			int i = uart->get();
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
	
		GPIOClass * newGPIO(char port, int pin, unsigned int inout){
			return new GPIOClass(port, pin, inout);
		}
	
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
