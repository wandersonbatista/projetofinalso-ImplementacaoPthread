#include <stdio.h>
#include <malloc.h>
#include "pokeLib.h"

void *multiplicaPor10(void *dta)
{
  int *n = (int *)dta;
  int *r = (int *)malloc(sizeof(int));
  *r = (*n) * 10;
  return r;
}

int main()
{
  int id, *r, param = 2;
  start(14, 1);

  Atrib escalonamento;
  escalonamento.p = 0;
  escalonamento.c = 0;

  id = spawn(&escalonamento, multiplicaPor10, &param);
  printf("spaw ID main: %d \n", id);
  sync(id, (void **)&r);
  finish();

  printf("R main : %d\n", *r);

  return 0;
}