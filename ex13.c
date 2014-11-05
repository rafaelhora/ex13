#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define vezes 1000
#define debug 0

int main(void)
{
	int vit, //numero de vitorias	
		j,i,// variavel auxiliar
		esc, seg; //escolhas do convidado
	
	srand(time(NULL));

	for(int cont = 0 ; cont < vezes ; cont++)
	{	
		int p[3] = {0};//as portas a serem escolhidas
		i = rand() % 3; // sorteia qual porta recebe o premio
		
		p[i] = 1; // a porta com o premio recebe 1 (verdadeiro)
		if(debug) printf("Premio na p = %d |", i);

		esc = rand() % 3;// indica a primeira escolha do convidado 
		if(debug) printf("Escolha: %d |", esc);

		while(1) // "abre" uma porta que nao foi escolhida e que nao possui o premio
		{
			j = rand() % 3;
			if(p[j] != 1 && j != esc)
				break;
		}
		
		if(debug) printf("Porta aberta = %d |",j );

		while(1)// A segunda escolha nao pode ser uma porta "aberta" e tem que ser diferente da primeira
		{
			seg = rand() % 3;
			if(seg != j && seg != esc)
				break;
		}
		if(debug) printf("Segunda esc = %d \n", seg);

		if(p[seg])// se a porta tem valor "verdadeiro" aumenta em 1 o numero de vitorias
			vit++;
	}

	printf("Ganhou %d de %d vezes .\n", vit, vezes);

	return 0;
}
