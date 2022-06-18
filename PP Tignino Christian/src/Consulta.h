#include "inputs.h"
#include "outputs.h"
#include "Fecha.h"

#define MAX 300
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int idConsulta;
	char nombreCliente[50];
	eFecha fecha;
	int idMecanico;
	int idDiagnostico;
	float cotizacion;
	int isEmpty;
}eConsulta;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int iniciarConsulta(eConsulta list[],int len);
/** \brief Indica la posicion del array del primer LIBRE
*
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int indicoLibre(eConsulta list[], int len);
/** \brief busca la consulta por ID y devuelve el inidice de la posicion del array.
*
* \param list eConsulta* puntero al array consulta
* \param len int
* \return Return inquiry index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarConsultaID(eConsulta* list, int len);
/** \brief busca una consulta con mecanico asignado por ID y devuelve el inidice de la posicion del array.
*
* \param list eEspecialidad* puntero al array especialidad
* \param len int
* \return Return inquiry index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarConsultaConMecanicoID(eConsulta* list, int len);
/** \brief busca una consulta sin mecanico asignado por ID y devuelve el inidice de la posicion del array.
*
* \param list eEspecialidad* puntero al array especialidad
* \param len int
* \return Return inquiry index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int buscarConsultaSinMecanicoID(eConsulta* list, int len);
/** \brief Verifica si existe una consulta OCUPADO sin DIAGNOSTICO
*
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (index) is ok.
*/
int verificarDiagnosticados(eConsulta* list, int len);
/** \brief Verifica si existe una consulta OCUPADO sin MECANICO
*
* \param list eConsulta[]
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (index) is ok.
*/
int verificarMecanico(eConsulta* list, int len);
/** \brief Harcodea las consultas con todos los datos ingresados en cada variable auxiliar y cambia el flag a 1
*
* \param list eConsulta* puntero al array consulta
* \param len int Array length
* \param flag int*
*
*/
void cargaForzada(eConsulta* list, int len, int* flag);
/** \brief Función para mostrar una consulta.
 *
 * \param list eConsulta
 *
*/
void mostrarUnaConsulta(eConsulta list);
/** \brief Listado de consultas ordenados por fecha, desde el más antiguo hasta el más reciente.
 *
 * \param list eConsulta* puntero al array consulta
 * \param mecanico eMecanico* puntero al array mecanico
 * \param len int
 *
*/
void mostrarConsultasPorFecha(eConsulta* list, int len);
/** \brief Listado de consultas con la suma de cotizacion por fecha y diagnostico "Cambio de Aceite".
 *
 * \param list eConsulta* puntero al array consulta
 * \param len int
 *
*/
void mostrarCotizacionPorFecha(eConsulta* list, int len);
