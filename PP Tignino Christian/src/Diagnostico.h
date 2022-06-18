/*
 * Diagnostico.h
 *
 *  Created on: 15 jun. 2022
 *      Author: 54115
 */

#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_
#define MAXD 4

typedef struct
{
	int idDiagnostico;
	char nombreDiagnostico[50];
}eDiagnostico;


/** \brief Listado de diagnosticos.
 *
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param len int
 *
*/
void mostrarDiagnosticos(eDiagnostico* diagnostico, int len);

#endif /* DIAGNOSTICO_H_ */
