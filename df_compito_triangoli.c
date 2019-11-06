#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int InputLatoA()
{
  int d;
  printf("dammi la lungezza del primo lato (A)\n");
  scanf("%d\n", &d);
  return d;
}

int InputLatoB(){
  int e;
  printf("dammi la lungezza del secondo lato (B)\n");
  scanf("%d\n", &e);
  return e;
}

int InputLatoC(){
  int f;
  printf("dammi la lungezza del secondo lato (C)\n");
  scanf("%d\n", &f);
  return f;
}

int main(void) {

 int a=0,b=0,c=0;

 b=InputLatoB();
 c=InputLatoC();
 a=InputLatoA();
 printf("a= %d\n", a);
 printf("b= %d\n", b);
 printf("c= %d\n", c);
/*do {
  do {
    //prendo i valori del triangolo e controllo che essi non siano <0

    if (a<0 || b<0 || c<0 ) {
         printf("uno dei lati non è maggiore di 0, perfavore sceliere valori adeguati.\n", );
    }
  } while(a<0 || b<0 || c<0);
*/


  return 0;
}
