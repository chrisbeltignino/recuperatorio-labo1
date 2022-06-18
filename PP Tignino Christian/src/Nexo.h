/*
 * Nexo.h
 *
 *  Created on: 15 jun. 2022
 *      Author: 54115
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Consulta.h"
#include "Mecanico.h"
#include "Diagnostico.h"
#include "Especialidad.h"
#include "inputs.h"
#include "outputs.h"

/** \brief Valida la ALTA y cambia el flag a 1 una vez dada la primera alta
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array diagnostico
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param flag int*
*/
void altaConsulta(eConsulta* list, int len, eDiagnostico* diagnostico, eMecanico* mecanico, eFecha* fecha, int* flag);
/** \brief agrega en la listade consulta los valores que llega
 * por parametros en la primera posicion LIBRE.
 *
* \param list eConsulta* puntero al array consulta
* \param len int
* \param id int
* \param nombreCliente[] char
* \param cotizacion float
* \param dia int
* \param mes int
* \param anio int
* \param list eFecha* puntero al array fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
		  free space] - (0) if Ok
*/
int agregarConsulta(eConsulta* list, int len, int id, char nombreCliente[], float cotizacion, int dia, int mes, int anio, eFecha* fecha);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese
 * y lleva como parametro a la funcion "agregarConsulta()"
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param fecha eFecha* puntero al arrary fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int cargarConsulta(eConsulta* list, int len, eFecha* fecha);
/** \brief Valida la MODIFICACION una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void modificarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief Llena todas las variables auxiliares con los datos que el usuario ingrese y modifica los campos de la
 * posicion de la ID ingresada para cambiar
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int modificoConsulta(eConsulta* list, int len, eMecanico* mecanico, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Valida la BAJA una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void bajaConsulta(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, int* flag);
/** \brief hace la baja de la consulta por busqueda de ID, poniendo isEmpty en LIBRE
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int removerConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Valida el DIAGNOSTICO una vez que el flag es 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \param flag int*
*/
void diagnosticarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief diagnostica las consultas por ID y con diagnostico = 0, e ingresando por ID de mecanico y asignando al idMecanico del array eConsulta
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param diagnostico eDiagnostico* puntero al array consulta
* \param mecanico eMecanico* puntero al array mecanico
* \param fecha eFecha* puntero al array fecha
* \param especialidad eEspecialidad* puntero al array especialidad
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int diagnosticoConsulta(eConsulta* list, int len, eFecha* fecha, eMecanico* mecanico, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Valida el LISTADO una vez que el flag es 1
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 * \param especialidad eEspecialidad* puntero al array especialidad
 * \param flag int*
 *
*/
void mostrarListados(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag);
/** \brief Función para mostrar todas las consultas con las cadenas de careacteres en lugar de los ID de diagnostico y mecanico.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
int mostrarListaConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Función para mostrar una consultas con las cadenas de careacteres en lugar de los ID de diagnostico y mecanico.
 *
 * \param list eConsulta* puntero al array consulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarConsultaConTodo(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief Función para devolver la posicion del indice de la estructura eDiagnostico.
 *
 * \param list eConsulta
 * \param tam int
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \return int posicion del indice
*/
int descripcionDiagnostico(eConsulta list, eDiagnostico* diagnostico, int tam);
/** \brief Función para devolver la posicion del indice de la estructura eMecanico.
 *
 * \param list eConsulta
 * \param tam int
 * \param mecanico eMecanico* puntero al array mecanico
 * \return int posicion del indice
*/
int descripcionMecanico(eConsulta list, eMecanico* mecanico, int tam);
/** \brief Función para mostrar todos los mecanicos.
 *
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarMecanicos(eMecanico* mecanico, eEspecialidad* especialidad, int len);
/** \brief Función para mostrar una mecanico.
 *
 * \param mecanico eMecanico
 *
*/
void mostrarUnMecanico(eMecanico mecanico, eEspecialidad* especialidad);

void mostrarUnMecanicoConCotizacion(eMecanico mecanico, eEspecialidad* especialidad, float cotizacion);
/** \brief Función para devolver la posicion del indice de la estructura eEspecialidad.
 *
 * \param list eMecanico
 * \param tam int
 * \param especialidad eEspecialidad* puntero al array especialidad
 * \return int posicion del indice
*/
int descripcionEspecialidad(eMecanico mecanico, eEspecialidad* especialidad, int tam);
/** \brief Función para mostrar un mecanico sin consultas asignadas.
 *
 * \param list eConsulta* puntero al array consulta
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarMecanicosSinConsultas(eConsulta* list, eMecanico* mecanico, eEspecialidad* especialidad, int len);

int compararMecanico(eConsulta* list, eMecanico mecanico, int len);
/** \brief Listado de consultas con promedio de cotizacion de cada uno de los mecánicos.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 *
*/
void mostrarCotizacionPorMecanico(eConsulta* list, int len, eMecanico* mecanico, eEspecialidad* especialidad, int lenM);

int contMasPrecioTotal(eConsulta* list, int len, eMecanico mecanico, float* precio);
/** \brief Listado de mecanicos que se hayan asignado consultas.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 *
*/
void mostrarMecanicosConConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM);

int contConsultaPorMecanico(eConsulta* list, int len, eMecanico mecanico);
/** \brief Listado de mecanicos ordenados por especialidad del	 alfabéticamente.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param especialidad eEspecialidad* puntero al array especialidad
 *
*/
void ordenarEspecialidadAlfabeticamente(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Listado de consultas entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param especialidad eEspecialidad* puntero al array especialidad
 *
*/
int mostrarListadoConsultaPorMes(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);

void imprimirConsultaPorMes(eConsulta list, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad, int idEspecialidad);

void imprimirAlfabeticamente(eConsulta list, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad);
/** \brief Saca el porcentaje de consultas diagnosticados que atiende cada mecánico en función del total de diagnósticos..
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param mecanico eMecanico* puntero al array mecanico
 * \param lenM int
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void porcentajeConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM, eDiagnostico* diagnostico);

float contDiagnosticos(eConsulta* list, int len);

/** \brief Listado de consultas con mecanico asignado.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarListaConsultaConMecanico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico);
/** \brief funcion para asignar la cadena de caracter de "nombreMecanico" a la consulta llamada en "mostrarListaConsultaConMecanico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 * \param mecanico eMecanico* puntero al array mecanico
 *
*/
void mostrarConsultaConMecanico(eConsulta list, eFecha* fecha, eMecanico* mecanico);
/** \brief Listado de consultas sin diagnosticos asignados.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarListaConsultaSinDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico);

void mostrarUnaConsultaCSinDiagnostico(eConsulta list, eFecha* fecha);
/** \brief funcion para asignar la cadena de caracter de "nombreDiagnostico" a la consulta llamada en "mostrarListaConsultaSinDiagnostico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarConsultaCSinDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico);
/** \brief Listado de consultas con diagnosticos asignados.
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarListaConsultaConDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico);
/** \brief funcion para asignar la cadena de caracter de "nombreDiagnostico" a la consulta llamada en "mostrarListaConsultaSinDiagnostico".
 *
 * \param list eConsulta
 * \param fecha eFecha* puntero al array fecha
 * \param diagnostico eDiagnostico* puntero al array diagnostico
 *
*/
void mostrarConsultaConDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico);
/** \brief Función para listar los top 3 especialidades mas estudiadas por mecanico.
 *
 * \param mecanico eMecanico* puntero al array especialidad
 * \param lenM int
 * \param especialidad eEspecialidad* puntero al array especialidad
*/
void topTresMasEstudidadas(eMecanico* mecanico, int lenM, eEspecialidad* especialidades, int lenE);
/** \brief Función para devolver el conteo de las especialidades que tiene cada mecanico.
 *
 * \param mecanico eMecanico
 * \param especialidad eEspecialidad* puntero al array especialidad
 * \param lenM int
 * \return cont int
*/
int contEspecialidades(eEspecialidad especialidades,eMecanico* mecanico,int lenM);

void imprimirUnaEspecialidad(eEspecialidad especialidades,int lenE, int contEspecialidad);

void imprimirEspecialidadConCont(eEspecialidad* especialidades,int lenE,eMecanico* mecanico,int lenM,int mayorEspecialidad);

#endif /* NEXO_H_ */
