#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Mecanico.h"

int buscarMecanicoID(eMecanico* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAXM, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idMecanico)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

void mostrarMecanicoPorcentaje(eMecanico mecanico, int len, float porcentaje)
{
	printf("|%-5d|%-21s|%c %-14.2f|\n", mecanico.idMecanico, mecanico.nombreMecanico, '%', porcentaje);
}

void HardcodearMecanicos(eMecanico* mecanico, int tam)
{
	eMecanico listaMecanicos[]  =  {{0, "SIN Mecanico",  0},
									{1, "Pepe Argento",  3},
									{2, "Dario Peron",   2},
									{3, "Franco Allende",3},
									{4, "Ricky Ford",    2},
									{5, "Susana Gimena", 4},
									{6, "Tomas Sito",    3},
									{7, "Tatiana Gimenez",2}};

	for(int i=0; i<tam; i++)
	{
		mecanico[i] = listaMecanicos[i];
	}
}
