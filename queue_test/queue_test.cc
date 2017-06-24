// EPOS Queue Utility Test Program

#include <iostream>
#include "queue.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#define DEBUG 0

using namespace std;

struct Inteiro {    
    //Construtor
    //e._object = this; e.rank = _r;
    Inteiro(int valor, int rank) : 	e(this, rank), i(valor) 		
	{} 
	
    int i; //valor do elemento
    Ordered_Queue<Inteiro>::Element e;
};

TEST(Inteiro, CriacaoDeInteiro) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE CRIACAO DE INTEIRO --------"<<endl;
	
	//Ordered_Queue<Inteiro> q1;
	Inteiro i1(1,1), i2(-2,2), i3(9999,3);
	
	EXPECT_EQ(1, i1.i)  		<< "Elemento nao possui o mesmo  da sua criacao";
	EXPECT_EQ(1, i1.e.rank())  	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(-2, i2.i) 		<< "Elemento nao possui o mesmo  da sua criacao";
	EXPECT_EQ(2, i2.e.rank()) 	<< "Elemento nao possui o mesmo rank da sua criacao";
	
	EXPECT_EQ(9999, i3.i) 		<< "Elemento nao possui o mesmo  da sua criacao";
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
		 int nvals;
		 		 
		 virtual void SetUp()
		 {    
			 nvals=0;
			 //q1 = new Ordered_Queue;         
		 }

		 virtual void TearDown()
		 {
			 if(DEBUG) cout<<"Limpando "<<nvals<<" inteiros"<<endl;
			 for(int i=1;i<nvals;i++)
				delete ivec[i];        
		 }
		 
		 /* 
		  * Insere nvalues valores com rank sequenciais
		  * Os valores sao aleatorios e estao entre min e max
		  */ 
		 void FillVectorOrderedRank(int nvalues=100, int min =0, int max = 100){			 
			
			nvals=nvalues; //Para propositos de liberacao de memoria
			
			 //Inserindo valores
			if(DEBUG) cout<<"Inserindo: ";
			for(int i=0;i<nvalues;i++){
				//gerando valores aleatorios
				int value = rand()%(max-min + 1) + min;
				if(DEBUG) cout<<endl<<"("<<value<<","<<i<<") ";
				ivec[i]= new Inteiro(value, i); 
				
				//inserindo na fila
				q1.insert(&(ivec[i]->e));
			}			 
		 }
		
		/* 
		  * Insere nvalues valores com rank aleatorios
		  * e valores sao aleatorios, entre min e max
		  */
		 void FillVectorRandomRank(int nvalues=100, int min =0, int max = 100){
			 			 
			 nvals=nvalues; //Para propositos de liberacao de memoria
			 
			 //Inserindo valores
			if(DEBUG) cout<<"Inserindo: ";
			for(int i=0;i<nvalues;i++){
				//gerando valores aleatorios
				int value = rand()%(max-min + 1) + min;
				if(DEBUG) cout<<endl<<"("<<value<<","<<value<<") ";
				ivec[i]= new Inteiro(value, value); 
				
				//inserindo na fila
				q1.insert(&(ivec[i]->e));
			}			 
		 }
};

/*
 * Neste teste, faz-se a insersao de valores com rank aleatorios
 * e espera-se que cada numero seja maior ou igual o anterior.
 */ 
TEST_F(Ordered_Queue_Test, RetornoOrdenado) {	
	if(DEBUG) cout<<"\n\n------ TESTE DE ORDENACAO --------"<<endl;
					
	//Inserindo valores
	FillVectorRandomRank();
		
	if(DEBUG) cout <<"\nRemovendo: ";
	int head=0, head_rank=0, last_head=0, last_head_rank=0;
	
	removido = q1.remove()->object();
	last_head=removido->i;	
	last_head_rank=removido->e.rank();	
	
	for(int i=1;i<nvals;i++){
		
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
 * Neste teste, faz-se a insersao de valores com ranks conhecidos.
 * Testa-se se apos a remocao do elemento atraves da funcao search ele foi 
 * de fato removido da fila.
 */ 
TEST_F(Ordered_Queue_Test, RemocaoElemento) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE REMOCAO DE ELEMENTO --------"<<endl;
	
	//Inserindo valroes de rank conhecido	
	FillVectorOrderedRank();
		
	//Removendo dois valores
	q1.remove(ivec[10]);
	q1.remove(ivec[15]);
	
	//Testando com elemento que ja nao esta na fila
	EXPECT_FALSE(q1.remove(ivec[15]));		
	
	//Removendo valores da fila, que nao podem ser 
	//iguais aos removidos anteriormente
	while(!q1.empty()){
		removido = q1.remove()->object();
		EXPECT_NE(ivec[10], removido);
		EXPECT_NE(ivec[15], removido);
	}	
}

/*
 * Neste teste, faz-se a insersao de valores com diferentes ranks.
 * Verifica-se se a fila retorna nulo ao se tentar remover algum  quando
 * a mesma esta vazia.
 * Tambem vefica-se o metodo empty()
 */ 
TEST_F(Ordered_Queue_Test, RetornoVazia) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DE RETORNO DE FILA VAZIA --------"<<endl;
	
	//verificando o metodo empty
	EXPECT_TRUE(q1.empty());	
		
	//tentando remover antes de inserir
	EXPECT_FALSE(q1.remove());	
	
	Inteiro i1(1,7), i2(4,10), i3(10,5);
	q1.insert(&i1.e); 
	q1.insert(&i2.e); 
	q1.insert(&i3.e);
	
	//verificando o metodo empty
	EXPECT_FALSE(q1.empty());
	
	q1.remove();  
	q1.remove();  
	q1.remove();
		
	//tentando remover apos a fila ter sido esvaziada
	EXPECT_FALSE(q1.remove());	
	
	//verificando o metodo empty
	EXPECT_TRUE(q1.empty());
}



/*
 * Neste teste faz-se a insersao de valores com ranks conhecidos, valores impares.
 * Testa-se se o metodo search para verificar se todos os valores inseridos sao
 * encontrados
 */ 
TEST_F(Ordered_Queue_Test, EncontraElemento) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DO METODO SEARCH --------"<<endl;
		
	int nvalues = 100;	
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
			EXPECT_FALSE(q1.search(ivec[i]));		
	}
}

/*
 * Neste teste faz-se o teste do metodo tail, removendo-se sempre o ultimo
 * elemento e verificando se o  de tail eh o mesmo que o esperado
 */ 
TEST_F(Ordered_Queue_Test, TailTest) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DO METODO TAIL --------"<<endl;
		
	//Inserindo valroes de rank conhecido	
	FillVectorOrderedRank();
	
	//Testando o metodo search
	for(int i=nvals-1;i>0;i--){
		EXPECT_EQ(ivec[i], q1.tail()->object());
		q1.remove(ivec[i]);
	}
	
	EXPECT_EQ(q1.head(), q1.tail());
	q1.remove(ivec[0]);
	
	EXPECT_FALSE(q1.tail());
}

/*
 * Neste teste faz-se o teste do metodo head, removendo-se sempre o primeiro
 * elemento e verificando se o  de tail eh o mesmo que o esperado
 */ 
TEST_F(Ordered_Queue_Test, HeadTest) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DO METODO TAIL --------"<<endl;
					
	//Inserindo valroes de rank conhecido	
	FillVectorOrderedRank();
	
	//Testando o metodo search
	for(int i=0;i<nvals;i++){
		EXPECT_EQ(ivec[i], q1.head()->object());
		q1.remove(ivec[i]);
	}
	
	EXPECT_FALSE(q1.head());
}

/*
 * Neste teste faz-se o teste do metodo size. Insere-se um numero conhecido de valores
 * e verifica-se o tamanho apos a remocao de cada elemento.
 */ 
TEST_F(Ordered_Queue_Test, SizeTest) {
	
	if(DEBUG) cout<<"\n\n------ TESTE DO METODO SIZE --------"<<endl;
		
	//Inserindo valroes de rank conhecido	
	FillVectorOrderedRank();
	
	//Testando o metodo search
	for(int i=nvals;i>0;i--){
		EXPECT_EQ(i, q1.size());
		q1.remove();
	}
	
	EXPECT_FALSE(q1.size());
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleMock( &argc, argv );
    return RUN_ALL_TESTS( );
}

