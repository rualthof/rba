#include "rs485.h"

void sleep(int n){
	for(int i=0;i<n;i++){
		for(volatile int t=0;t<0xfffff;t++);
	}
}

int main( int argc, char *argv[] ) {
	sleep(6);
    SerialRS485<GPIOCreator, UARTCreator> r(9600, 8, UART_Common::NONE, 1);	
    char arr [3] = " \0";
    const char * msg = "z Teste comunicacao rs485, Rodrigo voce esta ai? Z";
    int send = 1;
    int i =0;
    char m;
    while(1){
		//ENVIO DE MENSAGEM
		if (send){
			cout<<"\nEnviando mensagem no protocolo zZ:"<<endl;
			while(msg[i]!='Z'){
				r.writeWord(msg[i]);
				m = msg[i];
				cout<<m;
				i++;
			}
			r.writeWord(msg[i]);
			m = msg[i];
			cout<<m;
			cout<<"\n";
			sleep(1);
			i=0;
			send = 0;	
		}
		//RECEBIMENTO DE MENSAGEM
		else{
			m=r.readWord();
			while(m!='z'){				
				cout<<m;
				m=r.readWord();				
			}
			cout<<"\nIniciando leitura de mensagem no protocolo zZ:"<<endl;
			while(m!='Z'){
				cout<<m;
				m=r.readWord(); 
			}	
			cout<<m;		
		}
	}
}

