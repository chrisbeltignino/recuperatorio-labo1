#include "inputs.h"

/** \brief Funci�n para "limpar" consola con "\n".
*/
void limpiarConsola(void);
/** \brief Funci�n para separar el menu de la consola con "----".
*/
void mostrarSeparador(void);
/** \brief Funci�n para encapsular el submenu de opciones.
 *
 * \param opcion que el usuario ingrese.
*/
void mostrarMenu(int* opcion);

void headerConsulta();

void pieConsulta();

void subMenuModificar(int* opcion);

void subMenuDiagnosticar(int* opcion);

void subMenuListados(int* opcion);
