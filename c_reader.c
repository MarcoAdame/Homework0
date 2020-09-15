#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "c_reader.h"
#include "LibraryListasLigadas.h"

//#define INPUT_FILE "NumerosAleatorios.txt"

//struct node *readFile(struct node *Lista);

int c_reader(int *arr, int m){
    struct node *Lista = NULL;
    int *p, i;
    for (i=0;i<m;i++){
        p=arr+i;
        Lista=addback(Lista,*p);
    }
    display(Lista);
    i = NumberElements(Lista); 
    return i;
}