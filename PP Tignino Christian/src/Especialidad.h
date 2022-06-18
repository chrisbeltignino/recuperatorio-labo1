/*
 * Especialidad.h
 *
 *  Created on: 15 jun. 2022
 *      Author: 54115
 */

#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_

#include "inputs.h"
#define MAXE 5

typedef struct
{
	int idEspecialidad;
	char especialidad[50];
}eEspecialidad;

/** \brief busca la Especialidad por ID y devuelve el inidice de la posicion del array.
*
* \param list eEspecialidad* puntero al array especialidad
* \param len int
* \return Return specialty index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarEspecialidad(eEspecialidad* list, int len);

#endif /* ESPECIALIDAD_H_ */
