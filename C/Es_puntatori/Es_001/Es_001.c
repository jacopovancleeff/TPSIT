#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//lunghezza pre stabilita di tutte le stringhe
#define STRINGA 1000
// n giochi che si vogliono leggere
#define NUMGIOCHI 17000
// carattere separatore
#define SEPARATORE ","

/*stringhe dichiarate come puntatore*/
typedef struct tabella{
    int rank;
    char* name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float naSales;
    float euSales;
    float jpSales;
    float otherSales;
    float globalSales;
} Tabella;

int leggiFile(Tabella giochi[], int max, int *numeroGiochi, char file[], int lungStr);
void stampaTabella(Tabella giochi[], int numeroGiochi);

int main(){
  /*code*/
  Tabella giochi[NUMGIOCHI];
  char nomeFile[]="vgsales.csv";
  int numGiochi=0;
  int err;
  /*
  -passo la tabella;
  -il numero massimo di giochi che voglio leggere;
  -numGiochi per indirizzo, in cui mi memorizzerà il numero effettivo di giochi letti;
  -il nome del file da cui leggo i giochi;
  -la dimensione massima delle stringhe che poi utilizzerò;
  */
  err=leggiFile(giochi, NUMGIOCHI, &numGiochi, nomeFile, STRINGA);
  stampaTabella(giochi, numGiochi);
  return 0;
}

int leggiFile(Tabella giochi[], int max, int *numeroGiochi, char file[], int lungStr){
  /*code*/
  FILE *fp;
  char str[lungStr];
  char primaRiga[lungStr];
  char *pch;
  int k=0;
  int error;
  fp = fopen(file, "r");

  if (fp==NULL){
    printf("Il file '%s' non esiste.\n", file);
    error=-1;
    return error;
  }
  else{
    fgets(primaRiga, lungStr, fp);
    printf("%s\n", primaRiga);
    while(k<max && fgets(str, lungStr, fp)!=NULL){
      pch = strtok (str, "SEPARATORE");
      giochi[k].rank=atoi(pch);
      pch = strtok (NULL, "SEPARATORE");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].name = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].name,pch);
      pch = strtok (NULL, "SEPARATORE");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].platform = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].platform,pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].year=atoi(pch);
      pch = strtok (NULL, "SEPARATORE");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].genre = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].genre,pch);
      pch = strtok (NULL, "SEPARATORE");
      /*con questa operazione definisco la grandezza della stringa in memoria*/
      giochi[k].publisher = malloc((strlen(pch) + 1)*sizeof(char));
      strcpy(giochi[k].publisher,pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].naSales=atof(pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].euSales=atof(pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].jpSales=atof(pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].otherSales=atof(pch);
      pch = strtok (NULL, "SEPARATORE");
      giochi[k].globalSales=atof(pch);
      k++;
    }
  }
  fclose(fp);
  *numeroGiochi=k;
  return 0;
}

void stampaTabella(Tabella giochi[], int numeroGiochi){
  /*code*/
  for(int k=0;k<numeroGiochi;k++){
    printf("%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f\n", giochi[k].rank, giochi[k].name, giochi[k].platform, giochi[k].year, giochi[k].genre, giochi[k].publisher, giochi[k].naSales, giochi[k].euSales, giochi[k].jpSales, giochi[k].otherSales, giochi[k].globalSales);
  }
}
