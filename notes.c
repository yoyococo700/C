#include "lib.h"

int main(int argc, char *argv[]) {
  int i = 0, n = 0;
  float moyenne = 0;
  float total = 0;
  struct classement resultats;
  struct tableau csv = fillTab();
  i = csv.i;  
  

  int eleve = studentIdToInt(argv[1]);
  printf("[");
  for (int j = 0; j < taille; j++) {
    if (csv.numetu[j] == eleve) {
      int l = 0;
      moyenne += max(csv.note1[j], csv.note2[j]) * csv.coeff[j];
      total += csv.coeff[j] * 100;
      printf("{\"UE\":\"");
      for (int k = 0; k < 8; k++) {
        resultats.UE[k][n] = csv.nomUE[k][j];
        printf("%c", resultats.UE[k][n]);
      }
      printf("\",");
      resultats.classement[n] = 1;
      resultats.classement1[n] = 1;
      resultats.classement2[n] = 1;
      while (l <= taille) {
        if (csv.nomUE[3][l] == resultats.UE[3][n] &&
            csv.nomUE[4][l] == resultats.UE[4][n] &&
            csv.nomUE[5][l] == resultats.UE[5][n] &&
            csv.nomUE[6][l] == resultats.UE[6][n] &&
            csv.nomUE[7][l] == resultats.UE[7][n]) {
          if (max(csv.note1[l], csv.note2[l]) >
              max(csv.note1[j], csv.note2[j])) {
            resultats.classement[n] += 1;
          }
          if (csv.note1[l] > csv.note1[j]) {
            resultats.classement1[n] += 1;
          }
          if (csv.note2[l] > csv.note2[j]) {
            resultats.classement2[n] += 1;
          }
          resultats.ntotal[n] += 1;
        }
        l = l + 1;
      }
      printf("\"Note session 1 /100\":\"%f\",\"Rang\":\"%d\",", csv.note1[j], resultats.classement1[n]);
      printf("\"Note session 2 /100\":\"%f\",\"Rang\":\"%d\",", csv.note2[j], resultats.classement2[n]);
      printf("\"Rang global\":\"%d\",", resultats.classement[n]);
      printf("\"Total\":\"%d\"}", resultats.ntotal[n]);
      n = n + 1;
      printf(",");
    }
  }
  moyenne *= 20 / total;
  printf("{\"Votre moyenne /20\":\"%f\"}", moyenne);
  printf("]");
  return 0;
}