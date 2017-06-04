#include <gpio.h>
#include <alarm.h>
#include <utility/ostream.h>

using namespace EPOS;
OStream cout;

class SerialRS485  {
	
	protected:
	
		//------ Pinos de acesso ao chip -------
		GPIO * RO; //PC3 - RS485 RO - Receptor Output
		GPIO * DI; //PC4 - RS485 DI - Driver Input
		GPIO * nRE;//PC5 - RS485 RE - Receiving Enable
		GPIO * DE; //PC6 - RS485 DE - Driver Enable
		
		ISL83483(){		
			RO = new GPIO('C',3, GPIO::OUT);
			DI = new GPIO('C',3, GPIO::OUT);
			nRE = new GPIO('C',3, GPIO::OUT);
			DE = new GPIO('C',3, GPIO::OUT);	
		}
		
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
		
		void setBit(bool bit){
			DI->set(bit);	
		}
		
		bool getBit(bool bit){
			return DI->get(bit);	
		}
			
}


int main()
{
    for(bool b=false;;b=(b+1)%2)
    {
        cout << "teste\n";
        g.set(b);
        for(volatile int t=0;t<0xfffff;t++);
    }
    return 0;
}
