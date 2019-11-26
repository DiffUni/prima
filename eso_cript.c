//NOME: CARLO MARIA
//COGNOME: CASINI
//MATRICOLA:324995
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void cifrario_cesare(char alfabeto[30]) {
  int chiave_ces=0;      //definisco e chiedo la chiave di criptaggio
  char fraseChiaro[256]; //definisco la stringa per la frase in chiaro
  char fraseCript[256];  //definisco la stringa per la frase criptata
  int carattereCript=0;
printf("cifrario di cesare\n");



  do {                  //con questo do controllo se il valore che mi verrà fornito sia maggiore di 0
      printf("dammi la chiave di criptaggio (valore intero positivo, minore di 26 e maggiore di 0)\n");
      scanf("%d", &chiave_ces);
      if (chiave_ces<=0) {
        printf("il valore fornito è minore o uguale a 0!\n");
      } else if (chiave_ces>=26) {
                printf("il valore fornito è maggiore o uguale a 26, nel caso sia solo maggiore verrà ricondotto ad il valore accettabile corrispondente, nel caso sia =0 le verrà chiesto di riinserire il valore.\n");
                while (chiave_ces>=26) {    //questo loop mi permette di prendere il valore della chiave all'interno del range dei valori accettabili attraverso una sottrazione ripetuta senza che l'utente lo debba riimmettere
                  chiave_ces=chiave_ces-26;
                }
                printf("il valore che verra preso in considerazione della chiave è questo --> %d\n", chiave_ces);
      }
  } while(chiave_ces<=0);





printf("ora dammi la frase in chiaro (solo minuscole, le maiuscole e i numeri non verranno criptati)\n");
while (getc(stdin)!='\n') {
}
fgets(fraseChiaro, sizeof(fraseChiaro), stdin);
printf("ecco la tua frase in chiaro '%s' \n", fraseChiaro);
printf("ecco cosa c'e' in fraseCript '%s' \n", fraseCript);
for (int i = 0; i < sizeof(fraseChiaro) ; i++) {    //inizio il ciclo for che mi permette di scorrere la stringa, ho messo come condizione necessaria che la stringa sia diversa dal carattere null
  fraseCript[i]=fraseChiaro[i];                 //con questa riga di condice, nell'eventualità che nella stringa ci siano valori diffrenti da quelli prestabiliti essi rimangono tali anche nella stringa criptata
  for (int j = 0; j < 26; j++) {                //con questo for controllo che l'elemento nella stringa sia uno dei contemplati dall'algoritmo di criptaggio confrontandolo con la stringa alfabeto contenente tutti i caratteri che il programma cripta.
    if (fraseChiaro[i]==alfabeto[j]) {          //con questo if controllo se l'elemento di fraseChiaro[i] sia un elemento da criptare oppure no
      carattereCript=j+chiave_ces;              //per evitare di fare calcoli all'interno delle [] del vettore ho vuluto utilizzare una variabile ausiliaria che prenda il valore dell'indice della lettera criptata
        while (carattereCript>=26) {            //questo ciclo while mi permette di
          carattereCript=carattereCript-26;
        }
      fraseCript[i]=alfabeto[carattereCript];
    }
  }

}
printf("ecco la frase criptata \n");
printf("%s\n", fraseCript);
}


void cifrario_sost(char alfabetoSTD[30]){
  char alfabetoUSR[27];
  char fraseChiaro[256];
  char fraseCript[256];
  int  lettere_controllo=0, occorrenze=0;
  printf("cifrario a sostituzione \n");
  printf("\n");
do {
  if(lettere_controllo!=0 || occorrenze!=0){
    lettere_controllo=0;
    occorrenze=0;
  }
  printf("ora dammi l'alfabeto mescolato\n");
  printf("ATTENZIONE L'ALFABETO MESCOLATO DEVE CONTENERE SOLO LETTERE MINUSCOLE, NO NUMERI NE MAIUSCOLE NE PUNTEGGIATURA O CARATTERI SPECIALI, E PGNI CARATTERE DEVE ESSERE USATO UNA SOLA VOLTA!! \n");
  printf("NOTARE CHE L'ALFABETO CONTIENE 26 LETTERE, DUNQUE QUALUNQUE CARATTERE CHE VENGA INSERITO OLTRE IL 26esimo NON SARÀ CONTEGGIATO!!\n");
  while (getc(stdin)!='\n') {                                   //|qui
  }                                                             //|prendo
  fgets(alfabetoUSR, sizeof(alfabetoUSR), stdin);               //|l'imput


  for(char c='a'; (occorrenze<=1 && c<='z'); c++){              //con questi for controllo che :
    occorrenze=0;                                               //1) ogni elemento minuscolo è presente nell'alfabetoUSR
    for (int i = 0; (occorrenze<=1 && i<26); i++) {             //2) in esso ogni elemento si ripeta una volta sola
      if(c==alfabetoUSR[i]){                                    //
        lettere_controllo++;                                    //
        occorrenze++;                                           //
      }
    }
  }
  printf("ecco il contenuto di lettere_controllo furoi dai cicli for= %d\n", lettere_controllo);
} while(lettere_controllo!=26);
printf("ora dammi la frase in chiaro: nota bene che solo i caratteri in minuscoloverrano criptati e non numeri, punti, spazi e maiuscole.\n");
  while (getc(stdin)!='\n') {
  }
  fgets(fraseChiaro, sizeof(fraseChiaro), stdin);
  printf("ecco la tua frase in chiaro '%s' \n", fraseChiaro);
   for (int i = 0; i < sizeof(fraseChiaro); i++) {
    fraseCript[i]=fraseChiaro[i];
    for(int j=0; j<26; j++){
      if (alfabetoSTD[j]==fraseChiaro[i]) {
        fraseCript[i]=alfabetoUSR[j];
      }
    }
   }
printf("ecco la frase criptata '%s' \n", fraseCript);

}


int main() {
  char alfabeto[30] = "abcdefghijklmnopqrstuvwxyz";
  int scelta=0;
  //creo un loop con controllo in fondo per far in modo che se il valore di "scelta" non sia uno dei designati allora esso gli venga richiesto.
  do {
    printf("per prima cosa scegli in quale modo vuoi criptare il tuo messaggio:\n");
    printf("1)cifrario di cesare (input: chiave int, frase in chiaro);\n");
    printf("2)cifrario a sostituzione (input: alfabeto mescolato, frase in chiaro);\n");
    scanf("%d", &scelta);
    printf("hai scelto: %d\n", scelta);

    switch (scelta) {
      case 1: cifrario_cesare(alfabeto);
        break;
      case 2: cifrario_sost(alfabeto);
        break;
      default: printf("ATTENZIONE NON È STATA FATTA UNA SCELTA VALIDA, DEVI RIPETERE LA SCELTA!\n");
    }
  } while(scelta!=1 && scelta!=2);
  return 0;
