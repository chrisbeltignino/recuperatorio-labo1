#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Especialidad.h"

int buscarEspecialidad(eEspecialidad* list, int len)
{
	int i;
	int numero;
	int loEncontre = -1;

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAXE, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idEspecialidad)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}
