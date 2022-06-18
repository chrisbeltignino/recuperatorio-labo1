#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Diagnostico.h"

void mostrarDiagnosticos(eDiagnostico* diagnostico, int len)
{
    int i;
	printf(" __________________________\n"
		   "|%-5s|%-20s|\n"
		   "|=====|====================|\n",
		      "ID",   "Diagnostico");

    for(i=0;i<len;i++)
    {
        printf("|%-5d|%-20s|\n", diagnostico[i].idDiagnostico, diagnostico[i].nombreDiagnostico);
    }
    printf("|_____|____________________|\n");
}
