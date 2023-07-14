#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include "pokeLib.h"


#define MAX 30
void* mergeSort( void* dta )//int *vetor, int posicaoInicio, int posicaoFim)
{
  int *vetor = (int*)(dta + (2*sizeof(int)));
  int *aux = (int*)dta;
  int posicaoInicio = aux[0];
  int posicaoFim = aux[1];

  struct Atrib a1, a2;
  int t1, t2;
  int *r = (int *)malloc(sizeof(int));

  int i, j, k, metadeTamanho, *vetorTemp;
  if (posicaoInicio == posicaoFim)
    return 0;
  metadeTamanho = (posicaoInicio + (posicaoFim)) / 2;
  aux[1] = metadeTamanho;
  
  t1 = spawn(&a1, mergeSort, (void *)dta);
  sync(t1, (void **)&r);

  aux[0] = metadeTamanho + 1 ;
  aux[1] = posicaoFim;

  t2 = spawn(&a2, mergeSort, (void *)dta);
  sync(t2, (void **)&r);
  //mergeSort(vetor, metadeTamanho + 1, posicaoFim);
  printf("R1 : %d\n", r);
  //free(r);
  i = posicaoInicio;
  j = metadeTamanho + 1;
  k = 0;
  vetorTemp = (int *)malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));

  while (i < metadeTamanho + 1 || j < posicaoFim + 1)
  {
    if (i == metadeTamanho + 1)
    {
      vetorTemp[k] = vetor[j];
      j++;
      k++;
    }
    else
    {
      if (j == posicaoFim + 1)
      {
        vetorTemp[k] = vetor[i];
        i++;
        k++;
      }
      else
      {
        if (vetor[i] < vetor[j])
        {
          vetorTemp[k] = vetor[i];
          i++;
          k++;
        }
        else
        {
          vetorTemp[k] = vetor[j];
          j++;
          k++;
        }
      }
    }
  }
  for (i = posicaoInicio; i <= posicaoFim; i++)
  {
    vetor[i] = vetorTemp[i - posicaoInicio];
  }
  free(vetorTemp);
}

int main()
{
  int *vetor = (int *)malloc((MAX+2) * (sizeof(int)));
  vetor[0] = 0;
  vetor[1] = MAX;

  for (int i = 2; i < MAX+2; i++)
  {
    vetor[i]= rand() % 100;
  }
  for (int i = 0; i < MAX+2; i++)
  {
    printf("%d, ", vetor[i]);
   
  }
  printf("\n");
  int id, *r;
  start(4,0);

  Atrib escalonamento;
  escalonamento.p = 0;
  escalonamento.c = 0;

  id = spawn(&escalonamento, mergeSort, vetor);
  printf("spaw ID main: %d \n", id);
  sync(id, (void **)&r);
  finish();



  for (int i = 0; i < MAX+2; i++)
  {
    printf("%d, ", vetor[i]);
   
  }
  printf("\n");
  free(vetor);
  free(r);

  return 0;
}