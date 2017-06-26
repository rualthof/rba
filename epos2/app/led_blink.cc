#include <gpio.h>
#include <alarm.h>
#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

void delay(int max){	
	for(volatile int t=0;t<max;t++);
}

int main()
{
	
	
    GPIO uart1rx('C',3, GPIO::OUT);
    GPIO uart1tx('C',4, GPIO::OUT);
    GPIO RE('C',5, GPIO::OUT);
    GPIO DE('C',6, GPIO::OUT);
    
    GPIO uart0tx('A',1, GPIO::OUT);
    GPIO uart0rx('A',0, GPIO::OUT);
    
    int max = 0x2ffff;
    
    for(bool b=false;;b=(b+1)%2)
    {
        cout << "teste\n";
        uart1rx.set(b); 	delay(max);
        uart1rx.set(!b);
        
        uart1tx.set(b); 	delay(max);
        uart1tx.set(!b);        
        
        RE.set(b); 	delay(max);
        RE.set(!b);
        
        DE.set(b); 	delay(max);
        DE.set(!b);
        
        uart0rx.set(b);		delay(max);
        uart0rx.set(!b);
        
        uart0tx.set(b); 	delay(max);
        uart0tx.set(!b);        
        
        max = max-10000;
        
        if(max<=30000)
			max = 0x2ffff;
        
    }
    return 0;
}
