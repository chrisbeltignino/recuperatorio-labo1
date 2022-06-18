#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outputs.h"

void limpiarConsola(void)
{
	printf("\n\n\n\n");
}

void mostrarSeparador(void)
{
	printf("--------------\n");
}

void mostrarMenu(int* opcion)
{
	pedirEntero(opcion, "-------------------------------------\n"
						"1. ALTA Consulta\n"
						"2. MODIFICAR Consulta\n"
						"3. BAJA Consulta\n"
						"4. DIAGNOSTICO Consulta\n"
						"5. CARGA FORAZADA\n"
						"6. LISTADO Consulta\n"
						"7. SALIR\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
						"1. ALTA Consulta\n"
						"2. MODIFICAR Consulta\n"
						"3. BAJA Consulta\n"
						"4. DIAGNOSTICO Consulta\n"
						"5. CARGA FORAZADA\n"
						"6. LISTADO Consulta\n"
						"7. SALIR\n"
						"-------------------------------------\n"
						"Opcion invalida, reingrese: ", 1, 7);
}

void headerConsulta()
{
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-15s|\n"
		   "|=====|===============|==========|=====================|=====================|====================|",
			  "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",            "Precio");
}

void pieConsulta()
{
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}

void subMenuModificar(int* opcion)
{
	pedirEntero(opcion, "-------------------------------------\n"
						 "1. Nombre Cliente\n"
						 "2. Fecha de Consulta\n"
						 "3. Mecanico\n"
						 "4. No quiero modificar nada\n"
						 "-------------------------------------\n"
						 "Ingrese que desea modificar: ",
						 "-------------------------------------\n"
						 "1. Nombre Cliente\n"
						 "2. Fecha de Consulta\n"
						 "3. Mecanico\n"
						 "4. No quiero modificar nada\n"
						 "-------------------------------------\n"
						 "Opcion invalida, reingrese: ", 1, 4);
}

void subMenuDiagnosticar(int* opcion)
{
	pedirEntero(opcion, "-------------------------------------\n"
						 "1. Elegir DIAGNOSTICO\n"
						 "2. No quiero Diagnosticar NADA\n"
						 "-------------------------------------\n"
						 "Ingrese que desea Diagnosticar: ",
						 "-------------------------------------\n"
						 "1. Elegir DIAGNOSTICO\n"
						 "2. No quiero Diagnosticar NADA\n"
						 "-------------------------------------\n"
						 "Opcion invalida, reingrese: ", 1, 2);
}

void subMenuListados(int* opcion)
{
	pedirEntero(opcion,"----------------LISTADO-----------------\n"
						"1. Todos los mec�nicos.\n"
						"2. Todos los servicios.\n"
						"3. Todos los mec�nicos a los cuales no se les haya asignado ning�n servicio.\n"
						"4. Listado de servicios ordenados por fecha, desde el m�s antiguo hasta el m�s reciente.\n"
						"5. Para una fecha determinada se necesita saber cu�l fue la suma de cotizaciones en concepto de cambio de aceite.\n"
						"6. Cotizaci�n promedio de cada uno de los mec�nicos.\n"
						"7. Determinar cu�l/cu�les son los mec�nicos que diagnosticaron m�s servicios.\n"
						"8. Listado de servicios ordenados por especialidad del mec�nico alfab�ticamente\n"
						"9. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.\n"
						"10. Porcentaje de servicio diagnosticados que atiende cada mec�nico en funci�n del total de diagn�sticos.\n"
						"11. Top 3 de especialidades m�s estudiadas por los mec�nicos.\n"
						"12. SALIR\n"
						"-------------------------------------\n"
						"Ingrese una opcion: ",
						"-------------------------------------\n"
						"1. Todos los mec�nicos.\n"
						"2. Todos los servicios.\n"
						"3. Todos los mec�nicos a los cuales no se les haya asignado ning�n servicio.\n"
						"4. Listado de servicios ordenados por fecha, desde el m�s antiguo hasta el m�s reciente.\n"
						"5. Para una fecha determinada se necesita saber cu�l fue la suma de cotizaciones en concepto de cambio de aceite.\n"
						"6. Cotizaci�n promedio de cada uno de los mec�nicos.\n"
						"7. Determinar cu�l/cu�les son los mec�nicos que diagnosticaron m�s servicios.\n"
						"8. Listado de servicios ordenados por especialidad del mec�nico alfab�ticamente\n"
						"9. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada.\n"
						"10. Porcentaje de servicio diagnosticados que atiende cada mec�nico en funci�n del total de diagn�sticos.\n"
						"11. Top 3 de especialidades m�s estudiadas por los mec�nicos.\n"
						"12. SALIR\n"
						"-------------------------------------\n"
						"Opcion invalida, reingrese: ", 1, 12);
}
