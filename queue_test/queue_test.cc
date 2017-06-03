// EPOS Queue Utility Test Program

#include <iostream>
#include "queue.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#define DEBUG 0

using namespace std;
using ::testing::Return;

struct Inteiro {
    Inteiro(int _i, int _r) : i(_i), e(this, _r) {}

    int i;
    Ordered_Queue<Inteiro>::Element e;
};

TEST(Inteiro, CriacaoDeInteiro) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE CRIACAO DE INTEIRO --------"<<endl;
	
	//Ordered_Queue<Inteiro> q1;
	Inteiro i1(1,1), i2(-2,2), i3(9999,3);
	
	EXPECT_EQ(1, i1.i)  		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(1, i1.e.rank())  	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(-2, i2.i) 		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(2, i2.e.rank()) 	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(9999, i3.i) 		<< "Elemento nao possui o mesmo valor da sua criacao";
	EXPECT_EQ(3, i3.e.rank()) 	<< "Elemento nao possui o mesmo rank da sua criacao";
}

/* 
 * Fixture utilizada para todos os testes, cria automaticamente uma fila
 * ordenada, um vetor de dados, e tambem libera a memoria no final do teste
 */ 
class Ordered_Queue_Test : public ::testing::Test
{
	protected:
		 Ordered_Queue<Inteiro> q1;     
		 Inteiro * ivec [100];
		 Inteiro * removido;
		 int nvalues;		 
		 
		 virtual void SetUp()
		 {   
			 nvalues = 0;   
			 //q1 = new Ordered_Queue;         
		 }

		 virtual void TearDown()
		 {
			 if(DEBUG) cout<<"Limpando "<<nvalues<<" inteiros"<<endl;
			 for(int i=1;i<nvalues;i++)
				delete ivec[i];        
		 }
};

/*
 * Neste teste, faz-se a insersao de valores com rank aleatorios
 * e espera-se que cada numero seja maior ou igual o anterior.
 */ 
TEST_F(Ordered_Queue_Test, RetornoOrdenado) {	
	if(DEBUG) cout<<"\n\n------ TESTE DE ORDENACAO --------"<<endl;
	nvalues=10;		
	int max = 100;
	int min = 0;			
					
	//Inserindo valores
	if(DEBUG) cout<<"Inserindo: ";
	for(int i=0;i<nvalues;i++){
		//gerando valores aleatorios
		int value = rand()%(max-min + 1) + min;
		if(DEBUG) cout<<endl<<"("<<value<<","<<i<<") ";
		ivec[i]= new Inteiro(value, value); 
		
		//inserindo na fila
		q1.insert(&(ivec[i]->e));
	}	
		
	if(DEBUG) cout <<"\nRemovendo: ";
	int head=0, head_rank=0, last_head=0, last_head_rank=0;
	
	removido = q1.remove()->object();
	last_head=removido->i;	
	last_head_rank=removido->e.rank();	
	
	for(int i=1;i<nvalues;i++){
		
		if(DEBUG) cout<<endl<<"("<<last_head<<","<<last_head_rank<<") ";
		
		//Removendo o primeiro elemento
		removido = q1.remove()->object();
		head = removido->i;
		head_rank = removido->e.rank();
		
		//Verificando ordem
		EXPECT_GE(head_rank,  last_head_rank);
		
		//atualizando valores
		last_head=head;
		last_head_rank=head_rank;
	}	
}

/*
 * Neste teste, faz-se a insersao de valores com diferentes ranks.
 * Verifica-se se a fila retorna nulo ao se tentar remover algum valor quando
 * a mesma esta vazia.
 * Tambem vefica-se o metodo empty()
 */ 
TEST_F(Ordered_Queue_Test, RetornoVazia) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE RETORNO DE FILA VAZIA --------"<<endl;
	
	//verificando o metodo empty
	EXPECT_EQ(1,  q1.empty());	
		
	//tentando remover antes de inserir
	EXPECT_EQ(0,  q1.remove());	

	Inteiro i1(1,7), i2(4,10), i3(10,5);
	q1.insert(&i1.e); 
	q1.insert(&i2.e); 
	q1.insert(&i3.e);
	
	//verificando o metodo empty
	EXPECT_EQ(0,  q1.empty());
	
	q1.remove();  
	q1.remove();  
	q1.remove();
		
	//tentando remover apos a fila ter sido esvaziada
	EXPECT_EQ(0,  q1.remove());	
	
	//verificando o metodo empty
	EXPECT_EQ(1,  q1.empty());
}

/*
 * Neste teste, faz-se a insersao de valores com ranks conhecidos.
 * Testa-se se apos a remocao do elemento atraves da funcao search ele foi 
 * de fato removido da fila.
 */ 
TEST_F(Ordered_Queue_Test, RemocaoElemento) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE REMOCAO DE ELEMENTO --------"<<endl;
		
	nvalues = 100;	
	int max = 100;
	int min = 0;
					
	//Inserindo valores
	if(DEBUG) cout<<"Inserindo: ";
	for(int i=0;i<nvalues;i++){
		int value = rand()%(max-min + 1) + min;
		if(DEBUG) cout<<endl<<"("<<value<<","<<i<<") ";
		ivec[i]= new Inteiro(value, i); 
		q1.insert(&(ivec[i]->e));
	}
		
	//Removendo dois valores
	q1.remove(ivec[10]);
	q1.remove(ivec[15]);
	
	//Testando com elemento que ja nao esta na fila
	EXPECT_EQ(0,  q1.remove(ivec[15]));		
	
	//Removendo valores da fila, que nao podem ser 
	//iguais aos removidos anteriormente
	while(!q1.empty()){
		removido = q1.remove()->object();
		EXPECT_NE(ivec[10], removido);
		EXPECT_NE(ivec[15], removido);
	}	
}

/*
 * Neste teste faz-se a insersao de valores com ranks conhecidos, valores impares.
 * Testa-se se o metodo search para verificar se todos os valores inseridos sao
 * encontrados
 */ 
TEST_F(Ordered_Queue_Test, EncontraElemento) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE REMOCAO DE ELEMENTO --------"<<endl;
		
	nvalues = 100;	
	int max = 100;
	int min = 0;
					
	//Inserindo valores impares
	if(DEBUG) cout<<"Inserindo ranks impares: ";
	for(int i=0;i<nvalues;i++){
		int value = rand()%(max-min + 1) + min;
		ivec[i]= new Inteiro(value, i); 
		//Apenas insere se for impar
		if(i%1==0){
			if(DEBUG) cout<<endl<<"("<<value<<","<<i<<") ";			
			q1.insert(&(ivec[i]->e));
		}
	}
	
	//Testando o metodo search
	for(int i=0;i<nvalues;i++){
		if(i%1==0) //Se or impar, deve estar
			EXPECT_EQ(ivec[i], q1.search(ivec[i])->object());
		else //Se for par, nao esta na fila
			EXPECT_EQ(NULL, q1.search(ivec[i])->object());		
	}
}



int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}

