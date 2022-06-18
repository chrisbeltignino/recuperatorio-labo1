#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "Fecha.h"

int ingresarFecha(int* dia, int* mes, int* anio)
{
	int fecha_correcta;
	int dia_maximo;

	fecha_correcta = 0;

    do
    {
		utn_getInt(dia, "Ingrese el dia: ", "ERROR. Ingrese el dia de nuevo: ", 1, 31, 3);
		utn_getInt(mes, "Ingrese el mes: ", "ERROR. Ingrese el mes de nuevo: ", 1, 12, 3);
		utn_getInt(anio, "Ingrese el año: ", "ERROR. Ingrese el año de nuevo: ", 2022, 2023, 3);


		if (*mes >= 1 && *mes <= 12)
		{
			switch (*mes)
			{
				case  1 :
				case  3 :
				case  5 :
				case  7 :
				case  8 :
				case 10 :
				case 12 : dia_maximo = 31;
						  break;
				case  4 :
				case  6 :
				case  9 :
				case 11 : dia_maximo = 30;
						  break;
				case  2 :
					if ((*anio % 4 == 0 && *anio % 100 != 0) || *anio % 400 == 0)
					{
						dia_maximo = 29;
					}else
					{
						dia_maximo = 28;
					}
			}
			if(*dia >= 1 && *dia <= dia_maximo)
			{
				fecha_correcta = 1;
			}
		}
		if(fecha_correcta)
		{
			printf("\n   FECHA CORRECTA\n");
			fecha_correcta = 1;
		}else
		{
			printf("\n   FECHA INCORRECTA\n");
			fecha_correcta = 0;
		}
    }while(fecha_correcta!=1);
    return 0;
}
