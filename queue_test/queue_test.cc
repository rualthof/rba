// EPOS Queue Utility Test Program

#include <iostream>
#include "queue.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::Return;

struct Inteiro {
    Inteiro(int _i, int _r) : i(_i), e(this, _r) {}

    int i;
    Ordered_Queue<Inteiro>::Element e;
};


TEST(Inteiro, ValorDaCriacao) {
	//Ordered_Queue<Inteiro> q1;
	Inteiro i1(1,1), i2(-2,2), i3(9999,3);
	
	EXPECT_EQ(1, i1.i)  		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(1, i1.e.rank())  	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(-2, i2.i) 		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(2, i2.e.rank()) 	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(9999, i3.i) 		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(3, i3.e.rank()) 	<< "Elemento nao possui o mesmo rank da sua criacao";
}

TEST(Ordered_Queue, RetornoOrdenado) {
	Ordered_Queue<Inteiro> q1;
	Inteiro i1(7,7), i2(10,10), i3(5,5);
	q1.insert(&i1.e);
	q1.insert(&i2.e);
	q1.insert(&i3.e);
	
	
	int head;
	for(int i=0;i<3;i++){
		//head = q1.remove()->object()->i;
		
		//cout <<"Head: "<<head<<endl;
	}
	
	EXPECT_EQ(5,  q1.remove()->object()->i);
	EXPECT_EQ(7,  q1.remove()->object()->i);
	EXPECT_EQ(10, q1.remove()->object()->i);
	EXPECT_EQ(0,  q1.remove());
	
	
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}

/*
 * 
struct Integer1 {
    Integer1(int _i) : i(_i), e(this) {}

    int i;
    Queue<Integer1>::Element e;
};

struct Integer2 {
    Integer2(int _i, int _r) : i(_i), e(this, _r) {}

    int i;
    Ordered_Queue<Integer2>::Element e;
};

struct Integer3 {
    Integer3(int _i, int _r) : i(_i), e(this, _r) {}

    int i;
    Relative_Queue<Integer3>::Element e;
}; 
 
int main()
{
    //OStream cout;

    cout << "Queue Utility Test" << endl;
    
    

    cout << "\nThis is an integer queue:" << endl;
    Integer1 i1(1), i2(2), i3(3), i4(4);
    Queue<Integer1> q1;
    cout << "Inserting the integer " << i1.i << "" << endl;
    q1.insert(&i1.e);
    
    
    cout << "Inserting the integer " << i2.i << "" << endl;
    q1.insert(&i2.e);
    cout << "Inserting the integer " << i3.i << "" << endl;
    q1.insert(&i3.e);
    cout << "Inserting the integer " << i4.i << "" << endl;
    q1.insert(&i4.e);
    cout << "The queue has now " << q1.size() << " elements." << endl;
    cout << "Removing the element whose value is " << i2.i << " => "
         << q1.remove(&i2)->object()->i << "" << endl;
    cout << "Removing the queue's head => " << q1.remove()->object()->i
         << "" << endl;
    cout << "Removing the element whose value is " << i4.i << " => "
         << q1.remove(&i4)->object()->i << "" << endl;
    cout << "Removing the queue's head =>" << q1.remove()->object()->i
         << "" << endl;
    cout << "The queue has now " << q1.size() << " elements." << endl;

    cout << "\nThis is an ordered integer queue:" << endl;
    Integer2 j1(1, 2), j2(2, 3), j3(3, 4), j4(4, 1);
    Ordered_Queue<Integer2> q2;
    cout << "Inserting the integer " << j1.i
         << " with rank " << j1.e.rank() << "." << endl;
    q2.insert(&j1.e);
    cout << "Inserting the integer " << j2.i
         << " with rank " << j2.e.rank() << "." << endl;
    q2.insert(&j2.e);
    cout << "Inserting the integer " << j3.i
         << " with rank " << j3.e.rank() << "." << endl;
    q2.insert(&j3.e);
    cout << "Inserting the integer " << j4.i
         << " with rank " << j4.e.rank() << "." << endl;
    q2.insert(&j4.e);
    cout << "The queue has now " << q2.size() << " elements." << endl;
    cout << "Removing the element whose value is " << j2.i << " => "
         << q2.remove(&j2)->object()->i << "" << endl;
    cout << "Removing the queue's head => " << q2.remove()->object()->i
         << "" << endl;
    cout << "Removing the queue's head => " << q2.remove()->object()->i
         << "" << endl;
    cout << "Removing the queue's head => " << q2.remove()->object()->i
         << "" << endl;
    cout << "The queue has now " << q2.size() << " elements." << endl;


    cout << "\nThis is an integer queue with relative ordering:" << endl;
    Integer3 k1(1, 2), k2(2, 3), k3(3, 4), k4(4, 1);
    Relative_Queue<Integer3> q3;
    cout << "Inserting the integer " << k1.i
         << " with relative order " << k1.e.rank() << "." << endl;
    q3.insert(&k1.e);
    cout << "Inserting the integer " << k2.i
         << " with relative order " << k2.e.rank() << "." << endl;
    q3.insert(&k2.e);
    cout << "Inserting the integer " << k3.i
         << " with relative order " << k3.e.rank() << "." << endl;
    q3.insert(&k3.e);
    cout << "Inserting the integer " << k4.i
         << " with relative order " << k4.e.rank() << "." << endl;
    q3.insert(&k4.e);
    cout << "The queue has now " << q3.size() << " elements." << endl;
    cout << "Removing the element whose value is " << j2.i << " => "
         << q3.remove(&k2)->object()->i << "" << endl;
    cout << "Removing the queue's head => " << q3.remove()->object()->i
         << "" << endl;
    cout << "Removing the queue's head => " << q3.remove()->object()->i
         << "" << endl;
    cout << "Removing the queue's head => " << q3.remove()->object()->i
         << "" << endl;
    cout << "The queue has now " << q3.size() << " elements." << endl;

    return 0;
}


	*/
