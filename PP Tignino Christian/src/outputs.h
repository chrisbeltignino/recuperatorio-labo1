#include "inputs.h"

/** \brief Función para "limpar" consola con "\n".
*/
void limpiarConsola(void);
/** \brief Función para separar el menu de la consola con "----".
*/
void mostrarSeparador(void);
/** \brief Función para encapsular el submenu de opciones.
 *
 * \param opcion que el usuario ingrese.
*/
void mostrarMenu(int* opcion);

void headerConsulta();

void pieConsulta();

void subMenuModificar(int* opcion);

void subMenuDiagnosticar(int* opcion);

void subMenuListados(int* opcion);
