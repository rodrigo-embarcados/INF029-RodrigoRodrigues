#include <stdio.h>
#include <string.h>

int main()
{
  int achou, indice;
  char busca[] = "ola";
  char texto[] = "foi utilizado cola de sapateiro";
  for(int i = 0; i < strlen(texto) - strlen(busca); i++)
  {
    achou = 1;
    if(texto[i] == busca[0])
    {
      for(int j = 1; j < strlen(busca); j++)
      {
        if(texto[i+j] == busca[j]) continue;
        else 
	    {
	      achou = 0;
	      break;
	    }
      }
    indice = i;
    }
  }  
 if(achou) printf("Palavra encontrada no índice %d!\n", indice);
 else printf("Palavra não encontrada!\n");
}