// Online C compiler to run C program online
#include <stdio.h>

int main() 
{
     int s,n,max;
   printf("entre la taille de tablaux : ");
   scanf("%d", &s);
   int tab[s];
   for(int i = 0; i < s; i++){
  printf("entre le nomber : ");
    scanf("%d", &n);
       tab[i] = n;
       }
      max = tab[0];
      for(int i = 0; i < s; i++){
    if (tab[i]>max){
       max = tab[i];    }
       }
   printf("la max de  nomber est : %d ", max);
    return 0;
}