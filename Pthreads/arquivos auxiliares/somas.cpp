#include <stdio.h>
#include <malloc.h>
#include "pokeLib.h"


int contador = 0;
void multiSomaRecursiva(int x, int y, int * resposta){
    
    int maior, menor;
    int result;
    
    if(x>y){
        maior = x;
        menor = y;
    }else{
        maior = y;
        menor = x;
    }

    if(menor >= 2){
        multiSomaRecursiva(maior,menor-1,resposta);
        multiSomaRecursiva(maior,menor-2,resposta);
    }else{
        if(menor>0){
            *resposta += maior;
        }
    }
}


int main()
{
    int id, *r, param = 2, fat, *resp;
    resp = (int *) malloc(sizeof(int));
    *resp=0;
    int args[2] = {2,15};
	struct Atrib a;
    multiSomaRecursiva(8, 4, resp);
    printf("%d", *resp);
   // multiSoma((void*) args);
	//start(4);
	//n = 3;
	//printf("Digite o Valor do Fatorial a ser calculado: ");
	//scanf("%d",&fat);
   /* printf("Digite o Valor do Fatorial a ser calculado: ");
	scanf("%d",&fat);
	a.p = 0;
	a.c = fat;
	id = spawn(&a, fatorial, &fat);
	sync(id, (void **)&r);
	finish();
	printf("Fatorial(%d) = %d \n", fat, *r);
*/
	return 0;
}