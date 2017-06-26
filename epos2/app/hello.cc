 
#include <utility/ostream.h>

using namespace EPOS;

OStream cout;

int main(){
    
    int a = 10;
    while(a--){
      for(int i = 0; i < 100000000; i++);
    
        cout << "Hello World" << endl;  
    }
    
    return 0;
}
