/*
 * Mecanico.h
 *
 *  Created on: 15 jun. 2022
 *      Author: 54115
 */

#ifndef MECANICO_H_
#define MECANICO_H_

#include "inputs.h"
#include "outputs.h"

#define MAXM 8

typedef struct
{
	int idMecanico;
	char nombreMecanico[50];
	int idEspecialidad;
}eMecanico;

/** \brief busca el mecanico por ID y devuelve el inidice de la posicion del array.
*
* \param list eMecanico* puntero al array mecanico
* \param len int
* \return Return mechanical index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarMecanicoID(eMecanico* list, int len);
/** \brief Listado de consultas con el porcentaje.
 *
 * \param mecanico eMecanico
 * \param len int
 * \param porcentaje float
 *
*/
void mostrarMecanicoPorcentaje(eMecanico mecanico, int len, float porcentaje);
/** \brief Harcodea todos los campos con los datos ingresados en cada variable y cambia el flag a 1
*
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \param flag int*
*
*/
void HardcodearMecanicos(eMecanico* mecanico, int tam);

#endif /* MECANICO_H_ */
