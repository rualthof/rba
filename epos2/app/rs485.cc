o#include <gpio.h>
#include <alarm.h>
#include <utility/ostream.h>
#include <uart.h>

using namespace EPOS;
OStream cout;


/* 
 * Esta classe deriva de UART pois
 * DI ja esta conectado em TX da UART
 * e RO ja esta conectado no RX da UART
 * 
 * Como a classe UART1 ja implementa baudrate, paridade, numero de bits
 * basta extender a classe
 */ 
 
class SerialRS485 : public UART {
		
	public:
	
		//------ Pinos de acesso ao chip -------
		GPIO * nRE;//PC5 - RS485 RE - Receiving Enable
		GPIO * DE; //PC6 - RS485 DE - Driver Enable
		
		int uartNumber;
		
		//Mock da UART para simular put, get.
			
		SerialRS485(unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits)
		: UART(unit, baud_rate, data_bits, parity, stop_bits)
		{		
			uartNumber = unit;
			nRE = new GPIO('C',5, GPIO::OUT);
			DE = new  GPIO('C',6, GPIO::OUT);	
		}
		
		//DI ja esta conectado em TX da UART
		
		//Se char der overflow??		
		void writeWord(char i){
			sendingState();
			put(i);
		}		
		
		//RO ja esta conectado no RX da UART
		int readWord(){	
			receivingState();		
			int i = get();
			return i;
		}
		
		
		//Se msg for null?
		//Se tamanho de msg for 0? 
		//Testar
		
		void sendMessage(char msg [], uint tam){
			//int j = strlen(msg);
			//cout<<endl<<"Escrevendo: "<<j<<" ";
			//writeWord(j);
			for(int i=0;i<tam;i++){
				writeWord(msg[i]); 
				cout<<msg[i]; 
			} 
		} 
	
		//Se msg for null?
		//Se tamanho de msg for 0? 
		//Testar
		int readMessage(char msg [], uint tam){
			//cout<<endl<<"Tamanho da proxima mensagem: ";
			//int j = readWord();  
			//cout<<j<<endl;
       
			cout<<"Recebendo mensagem:";			
			for(int i=0;i<tam;i++){
				msg[i]=readWord(); 
				cout<< char(msg[i]);
			}       
			
			return j;       
		} 
	
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

void sleep(int n){
	for(int i=0;i<n;i++){
		for(volatile int t=0;t<0xfffff;t++);
	}
}




int main()
{
	sleep(3);
	cout << "Iniciando RS485\n";
	SerialRS485 r(1, 9600, 8, UART_Common::NONE, 1);
	sleep(3);
    char msg []={"Tenis top demais"}; //Para receber a mensagem
    unsigned char j=10; 
    sleep(3);
    cout << "Entrando no loop\n";
    while(1)
    {
		r.sendMessage(msg); 
		sleep(1);	
		j = r.readMessage(msg);	 
		sleep(1);  
    }
    
        
    
    return 0;
}

