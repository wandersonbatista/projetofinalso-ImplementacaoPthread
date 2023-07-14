#include <stdio.h>
#include <malloc.h>
#include "pokeLib.h"

void *fatorial(void *dta)
{
    int *fat = (int *)dta; 
    int* resultado = (int *)malloc(sizeof(int)); 
    struct Atrib a1, a2;
    
    if(*fat <= 1){
        *resultado = 1;
    }else{
        
    }


}

int fat (n) {
//Função que calcula, recursivamente, o fatorial de n.
if ((n==1) || (n==0)) return 1;               
   else
      return fat(n-1)*n;
      }

int main()
{
    int id, *r, param = 2,fat;
	struct Atrib a;
	start(4);
	//n = 3;
	printf("Digite o Valor do Fatorial a ser calculado: ");
	scanf("%d",&fat);
	a.p = 0;
	a.c = fat;
	id = spawn(&a, fatorial, &fat);
	sync(id, (void **)&r);
	finish();
	printf("Fatorial(%d) = %d \n", fat, *r);

	return 0;
}