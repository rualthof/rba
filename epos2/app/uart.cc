
#include <uart.h>
#include <utility/ostream.h>

using namespace EPOS;

OStream cout;
 
int main(){
    
    // RX - PA0
    // TX - PA1
    UART u(1, 9600, 8, 0, 1);
    
    while(1){
        
        for(volatile int i = 0; i < 255; i++){
            u.put(i);
            
            cout << "enviou: " << i << endl;
            
            int value = u.get();
            
            cout << "recebeu: " << value << endl;
            
            for(volatile int j = 0; j < 0xfffff; j++);
            
            u.put(0);
             cout << "enviou: " << 0 << endl;
            value = u.get();
            
            for(volatile int j = 0; j < 0xfffff; j++);
            
        }
        
    }
    
}
