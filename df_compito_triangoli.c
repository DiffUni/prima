#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int InputLatoA()
{
  int p;
  printf("dammi la lungezza del primo lato (A)\n");
  scanf("%d", &p);
  return p;
}

int InputLatoB(){
  int e;
  printf("dammi la lungezza del secondo lato (B)\n");
  scanf("%d", &e);
  return e;
}

int InputLatoC(){
  int f;
  printf("dammi la lungezza del terzo lato (C)\n");
  scanf("%d", &f);
  return f;
}

int main() {

 int a=0,b=0,c=0;
do {
 a=InputLatoA();
 b=InputLatoB();
 c=InputLatoC();

 printf("a= %d\n", a);
 printf("b= %d\n", b);
 printf("c= %d\n", c);

    //prendo i valori del triangolo e controllo che essi non siano <0

    if (a<0 || b<0 || c<0 ) {
         printf("uno dei lati non è maggiore di 0, perfavore sceliere valori adeguati.\n");
    }

    //controllo che i valori siano minori della somma degli altri 2 e maggiori della loro differenza
    while(a<abs(b-c)||a>b+c){
      printf("questo 'A' non va bene!\n");
      a=InputLatoA();
    }
    while(b<abs(a-c)||b>a+c){
      printf("questo 'B' non va bene!\n");
      a=InputLatoB();
    }
    while(c<abs(a-b)||c>a+b){
      printf("questo 'B' non va bene!\n");
      a=InputLatoC();
    }

  } while(a<0 || b<0 || c<0);

//controllo che tipo di triangolo è

  if (a==b && a==c) {
    printf("equilatero\n");
  }else if(a==b||b==c||a==c){
    printf("isoscele\n");
  } else{
    printf("scaleno\n");
  }

//controllo se è rettangolo
if(a*a==b*b+c*c || b*b==c*c+a*a || c*c==a*a+b*b)                      //senza dover riordinare controllo (attraverso piatgora) se uno dei lati è un ipotenusa.
{
  printf("I lati forniti sono di un triangolo rettangolo.\n");
}

  return 0;
}
