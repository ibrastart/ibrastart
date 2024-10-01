// Online C compiler to run C program online
#include <stdio.h>

int main() 
{
     int s,n,minimum;
   printf("entre la taille de tablaux : ");
   scanf("%d", &s);
   int tab[s];
   for(int i = 0; i < s; i++){
  printf("entre le nomber : ");
    scanf("%d", &n);
       tab[i] = n;
       }
      minimum = tab[0];
      for(int i = 0; i < s; i++){
    if (tab[i]<minimum){
       minimum = tab[i];    }
       }
   printf("le minimum de  nomber est : %d ", minimum);
    return 0;
}