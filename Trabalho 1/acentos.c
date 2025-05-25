#include <stdio.h>
#include <string.h>

int main()
{
  char acentos [] = "áâàéêíóôúü";
  char semacentos [] = "aeiou";

  for(int i = 0; i < strlen(acentos); i++)
  {
    printf("%c : %i\n", acentos[i], acentos[i]);
  } 
  for(int i = 0; i < strlen(semacentos); i++)
  {
    printf("%c : %i\n", semacentos[i], semacentos[i]);
  }
}