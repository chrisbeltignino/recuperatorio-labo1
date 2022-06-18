/*
 * Fecha.h
 *
 *  Created on: 15 jun. 2022
 *      Author: 54115
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

/**
 * @fn int ingresarFecha(int*, int*, int*)
 * @brief funcion que valida la fecha ingresada
 *
 * @param dia, recibe por puntero el dia
 * @param mes, recibe por puntero el mes
 * @param anio, recibe por puntero el año
 * @return devuelve -1 si salio todo mal, devuelve 0 si salio todo bien
 */
int ingresarFecha(int* dia, int* mes, int* anio);

#endif /* FECHA_H_ */
