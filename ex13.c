#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define vezes 1000
#define debug 0

int main(void)
{
	int vit, //numero de vitorias	
		j,i,// variavel auxiliar
		pri, seg; //primeira e segunda escolha do convidado
	
	srand(time(NULL));

	for(int cont = 0 ; cont < vezes ; cont++)
	{	
		int p[3] = {0};//as portas a serem escolhidas
		i = rand() % 3; // sorteia qual porta recebe o premio
		
		p[i] = 1; // a porta com o premio recebe 1 (verdadeiro)
		if(debug) printf("Premio na p = %d |", i);

		pri = rand() % 3;// indica a primeira escolha do convidado 
		if(debug) printf("Escolha: %d |", pri);

		while(1) // "abre" uma porta que nao foi escolhida e que nao possui o premio
		{
			j = rand() % 3;
			if(p[j] != 1 && j != pri)
				break;
		}	
		if(debug) printf("Porta aberta = %d |\n",j );

		seg = pri;//a escolha da porta nao eh trocada

		if(p[seg])// se a porta tem valor "verdadeiro" aumenta em 1 o numero de vitorias
			vit++;
	}

	printf("Ganhou %d de %d vezes .\n", vit, vezes);

	return 0;
}
