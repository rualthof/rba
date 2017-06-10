#include <gpio.h>
#include <alarm.h>
#include <utility/ostream.h>
#include <uart.h>

using namespace EPOS;
OStream cout;


void sleep(int n){
	for(int i=0;i<n;i++){
		for(volatile int t=0;t<0x3ffff;t++);
	}
}


int uartSend(int uart)
{    
    UART r(uart, 9600, 8, UART_Common::NONE, 1);    
    int i=0;  
    while(1){
		//sleep(1);
		cout<<"Escrevendo na uart "<<uart<<": "<<i<<endl;
		r.put(i++);
		if(i>=120)
			i=0;
	}    
    return 1;
}

int uartReceive(int uart)
{
    UART s(uart, 9600, 8, UART_Common::NONE, 1);
    while(1){		
		int val = s.get();
		cout << "Lendo na uart "<<uart<<": " << val << "." <<endl;		
	}	    
    return 1;
}		


Thread * uarts[2];	

int main()
{
	cout<<"Criando uarts"<<endl;
	uarts[0] = new Thread(&uartSend, 1);
	//uarts[1] = new Thread(&uartReceive, 1);
	
	cout<<"Join nas uarts"<<endl;
	for(int i = 0; i < 2; i++)
        int ret = uarts[i]->join();
		
    return 0;
}


