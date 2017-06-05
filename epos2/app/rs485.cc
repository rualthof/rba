#include <gpio.h>
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
		GPIO * RO; //PC3 - RS485 RO - Receptor Output
		GPIO * DI; //PC4 - RS485 DI - Driver Input
		GPIO * nRE;//PC5 - RS485 RE - Receiving Enable
		GPIO * DE; //PC6 - RS485 DE - Driver Enable
		
		int _unit;
		
		SerialRS485(unsigned int unit, unsigned int baud_rate, unsigned int data_bits, unsigned int parity, unsigned int stop_bits)
		: UART(unit, baud_rate, data_bits, parity, stop_bits)
		{	
			
			_unit = unit;
			nRE = new GPIO('C',5, GPIO::OUT);
			DE = new  GPIO('C',6, GPIO::OUT);	
		}
		
		//DI ja esta conectado em TX da UART		
		void writeWord(int i){
			sendingState();
			cout<<"Uart "<<_unit<<" enviando "<<i<<endl;
			//put(i);
		}		
		
		//RO ja esta conectado no RX da UART
		int readWord(){	
			receivingState();		
			int i = get();
			cout<<"Uart "<<_unit<<" recebendo "<<i<<endl;
			return i;
		}
	
	private:
	
		void sendingState(){
			DE->set(1);
		}
		
		void shutdownState(){
			DE->set(0);
			nRE->set(1);		
		}
		
		void receivingState(){
			DE->set(0);
			nRE->set(0);		
		}	
			
};


int main()
{
	cout << "Iniciando programa\n";
	SerialRS485 s(0, 9600, 8, UART_Common::NONE, 1);
	//SerialRS485 r(1, 9600, 8, UART_Common::NONE, 1);
	//SerialRS485 t(2, 9600, 8, UART_Common::NONE, 1);
	cout << "Entrando no loop\n";
    for(bool b=false;;b=(b+1)%2)
    {
        
        s.writeWord(0b101010101);  
        
     
        //s.readWord();
       
        for(volatile int t=0;t<0xfffff;t++);

        s.writeWord(0);  
        for(volatile int t=0;t<0xfffff;t++);
        

    }
    return 0;
}

