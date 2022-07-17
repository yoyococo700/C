#include <stdio.h>
#include "lib.h"
#define SUB 50

void printData(int data[SUB]){
    printf("[");
    for (int i = 0; i < SUB; i++)
    {
        printf("%d",data[i]);
        if (i!=SUB-1)
            printf(",");    
    }
    printf("]"); 
}

void printLabel(){
    printf("[");
    for (int i = 0; i < SUB; i++)
    {
        printf("\"%d\"",i*(100/SUB));
        if (i!=SUB-1)
            printf(",");    
    }
    printf("]\n"); 
}

void printnomUE(char UE[8]) {
    printf("\"nom\":");
    printf("\"");
    for (int i = 0; i < 8; i++)
    {
        printf("%c", UE[i]);
    }
    printf("\",");
}

void outputJSON(char UE[8], int dataS1[SUB], int dataS2[SUB]) {
    printf("{");
    printnomUE(UE);
    printf("\"label\":");
    printLabel();
    printf(",\"dataS1\":");
    printData(dataS1);
    printf(",\"dataS2\":");
    printData(dataS2);
    printf("}\n");
}
//return 0 if UE1 differents from UE2, 1 else
int compareUEs(char UE1[8],char UE2[8]){
    for (int i = 0; i < 8; i++)
    {
        if (UE1[i] != UE2[i] )
        {
            return (0);
        }
        
    }
    return (1);
}

void returnStrUE(struct tableau csv, int pos, char res[8]) {

    for (int i = 0; i < 8; i++)
    {
        res[i]=csv.nomUE[i][pos];
    }

}



int main(int argc, char* argv[]) {
    struct tableau csv = fillTab(); 
    int dataS1[SUB] = {0};
    int dataS2[SUB] = {0};
    char UE[8];
    for (int i = 0; i < csv.i; i++)
    {   
        returnStrUE(csv, i, UE);
        if (compareUEs(UE, argv[1]))
        {
            dataS1[(int)csv.note1[i] / (100/SUB)] += 1;
            if ((int)csv.note2[i]!=-0)
            {
                dataS2[(int)csv.note2[i] / (100/SUB)] += 1;
            }
        } 
    }
    outputJSON(argv[1], dataS1, dataS2);
}