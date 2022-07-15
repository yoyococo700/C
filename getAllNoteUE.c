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
    printf("]\n"); 
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
    int data[SUB] = {0};
    char UE[8];
    for (int i = 0; i < csv.i; i++)
    {   
        returnStrUE(csv, i, UE);
        if (compareUEs(UE, argv[1]))
        {
            data[(int)csv.note1[i] / (100/SUB)] += 1;
        }
        
    }
    printData(data);
}