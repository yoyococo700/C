#include <math.h>
#include <stdio.h>
#include <string.h>
#define taille 3000
#define nUE 50


struct tableau {
  char nomUE[8][taille];
  int numetu[taille];
  float note1[taille];
  float note2[taille];
  float coeff[taille];
  int i;
};

struct classement {
  char UE[8][nUE];
  int classement1[nUE];
  int classement2[nUE];
  int classement[nUE];
  int ntotal[nUE];
  int ntotalS2[nUE];
};

float max(float a, float b) { return (a + b + fabs(a - b)) / 2; }

int powe(int x,int y){
  int somme = 1;
  for (int i = 0; i < y; i++)
  {
    somme*=x;
  }
  return somme;
};

int studentIdToInt(char id[8]){
  int res =0 ;
  int temp;
  for(int i=0; i<8; i++){
    temp = id[i]-'0';
    res+= temp * powe(10,7-i);
  };
  return res;
}




struct tableau fillTab(){
  int i=0;
  struct tableau csv;
  FILE *open = fopen("output2.csv", "r");
  while (fscanf(open, "%c%c%c%c%c%c%c%c;%d;%f;%f;%f\n", &csv.nomUE[0][i],
                &csv.nomUE[1][i], &csv.nomUE[2][i], &csv.nomUE[3][i],
                &csv.nomUE[4][i], &csv.nomUE[5][i], &csv.nomUE[6][i],
                &csv.nomUE[7][i], &csv.numetu[i], &csv.note1[i], &csv.note2[i],
                &csv.coeff[i]) != EOF) {
    i = i + 1;
  }
  csv.i = i;
  fclose(open);
  return csv;
}




