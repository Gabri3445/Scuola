//area del quadrato solo con numero pari
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
  int lato;
  int area;
  bool cond = true;
  
  printf("Inserisci il lato ");
  scanf("%d", lato);
  while(cond == true)
  {
    if(lato%2 != 0)
    {
      printf("\nIl numero non e pari. Inserisci di nuovo ");
      scanf("d", lato);
    }
    else 
    {
      cond = true;
    }
  }
  area = pow(lato, 2);
  printf("\nL'area e' %d", area);
  system("pause");
}
