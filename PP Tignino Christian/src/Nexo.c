#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Nexo.h"

void altaConsulta(eConsulta* list, int len, eDiagnostico* diagnostico, eMecanico* mecanico, eFecha* fecha, int* flag)
{
	int respuestaCargar;
	respuestaCargar = cargarConsulta(list, MAX, fecha);

	if(respuestaCargar==-1)
	{
		printf("No se pudo cargar la consulta\n");
		system("pause");
	}
	else
	{
		printf("Carga realizada con exito\n");
		*flag=1;
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int agregarConsulta(eConsulta* list, int len, int id, char nombreCliente[], float cotizacion, int dia, int mes, int anio, eFecha* fecha)
{
	int retorno = -1;
	int indice;

	if(list!= NULL && len > 0)
	{
		indice = indicoLibre(list,len);
		if(indice != -1)
		{
			list[indice].idConsulta = id;
			SizeString(nombreCliente);
			strcpy(list[indice].nombreCliente, nombreCliente);
			list[indice].cotizacion = cotizacion;
			list[indice].fecha.dia = dia;
			list[indice].fecha.mes = mes;
			list[indice].fecha.anio = anio;

			printf("\nLa Consulta a AGREGAR es...\n\n"
				   " _______________________________________________________\n"
				   "|%-5s|%-15s|%-19s|%-13s|\n"
				   "|=====|===============|===================|=============|",
				     "ID",     "Nombre",    "Fecha de Consulta",   "Precio");
			mostrarUnaConsultaCSinDiagnostico(list[indice], fecha);
			printf("\n|_____|_______________|___________________|_____________|\n");

			if(!verificarConfirmacion("\nIngrese 's' para confirmar el alta de la Consulta: "))
			{
				list[indice].isEmpty = OCUPADO;
				retorno = 0;
			}else
			{
				retorno = -1;
			}
		}
	}else
	{
		retorno = -1;
	}

	return retorno;
}

int cargarConsulta(eConsulta* list, int len, eFecha* fecha)
{
	int id;
	char nombre[50];
	float cotizacion;
	int dia;
	int mes;
	int anio;
	int retorno;

	if(list!= NULL && len > 0)
	{
		retorno = indicoLibre(list,len);
		if (retorno != -1)
		{
			id = retorno + 1;
			utn_getString(nombre, "Ingrese nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 50, 3);
			cotizacion = 2000;
			ingresarFecha(&dia, &mes, &anio);
			fflush(stdin);
			retorno = agregarConsulta(list,len,id,nombre,cotizacion,dia,mes,anio, fecha);
		}
	}
	return retorno;
}

void modificarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int respuestaModificar;
	if(*flag==1 && !(verificarMecanico(list, len)))
	{
		respuestaModificar = modificoConsulta(list, MAX, mecanico, fecha, diagnostico, especialidad);
		if(respuestaModificar == -1)
		{
			printf("No se pudo realizar la modificacion\n");
			system("pause");
		}
		else if(respuestaModificar == 1)
		{
			printf("Se cancelo la modificacion\n");
			system("pause");
		}
		else
		{
			printf("Modificacion realizada correctamente\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 CONSULTA o teneruna CONSULTA CON MECANICO.\n");
		system("pause");
	}
}

int modificoConsulta(eConsulta* list, int len, eMecanico* mecanico, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int retorno = -1;
	int opcion;
	int index;
	char nombre[50];
	int dia;
	int mes;
	int anio;
	int idMecanico;
	eConsulta aux;

	if (list != NULL && len > 0)
	{
		mostrarListaConsultaConMecanico(list, len, fecha, diagnostico, mecanico);
		index = buscarConsultaConMecanicoID(list, len);
		aux = list[index];
		if(index!=-1)
		{
			printf("\nLa Consulta a MODIFICAR es...\n\n"
				   " _________________________________________________________\n"
				   "|%-5s|%-15s|%-15s|%-13s|\n"
				   "|=====|===============|=====================|=============|",
					 "ID",     "Nombre",    "Fecha de Consulta",   "Mecanico");
			mostrarConsultaConMecanico(list[index], fecha, mecanico);
			printf("\n|_____|_______________|____________________|_____________|\n");

			do
			{
				subMenuModificar(&opcion);
				switch(opcion)
				{
					case 1:
						limpiarConsola();
						utn_getString(nombre, "Ingrese un nuevo nombre: ", "ERROR. Ingrese nombre nuevamente, hasta 51 caracteres, reingrese: ", 51, 3);
						SizeString(nombre);
						strcpy(aux.nombreCliente, nombre);
						retorno=0;
					break;
					case 2:
						limpiarConsola();
						ingresarFecha(&dia, &mes, &anio);
						aux.fecha.dia = dia;
						aux.fecha.mes = mes;
						aux.fecha.anio = anio;
						retorno=0;
					break;
					case 3:
						limpiarConsola();
						mostrarMecanicos(mecanico, especialidad, MAXM);
						utn_getInt(&idMecanico, "Ingrese el Mecanico: ", "ERROR. Ingrese el Mecanico nuevamente: ", 0, MAXM, 3);
						idMecanico = buscarMecanicoID(mecanico, MAXM);
						aux.idMecanico = idMecanico;
						retorno=0;
					break;
					case 4:
						printf("Saliendo");
					break;
					default:
						printf("Opcion no valida");
				}
			}while(opcion!=4);

			if(retorno==0)
			{
				printf("\nLa Consulta a MODIFICADA es...\n\n"
					   " _________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-13s|\n"
					   "|=====|===============|=====================|=============|",
						 "ID",     "Nombre",    "Fecha de Consulta",   "Mecanico");
				mostrarConsultaConMecanico(aux, fecha, mecanico);
				printf("\n|_____|_______________|____________________|_____________|\n");

				if(!verificarConfirmacion("\nIngrese 's' para confirmar la modificacion de la Consulta: "))
				{
					list[index]=aux;
				}else
				{
					printf("\nNo se realizo la modificacion");
					retorno = 1;
				}
			}
		}else
		{
			printf("\nNo se encontro la Consulta");
			retorno = -1;
		}
	}else
	{
		retorno = -1;
	}

	return retorno;
}

void bajaConsulta(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, int* flag)
{
	int respuestaBorrar;
	if(*flag == 1)
	{
		respuestaBorrar = removerConsulta(list, MAX, fecha, diagnostico, mecanico);
		if(respuestaBorrar == -1)
		{
			printf("No se pudo Borrar al pasajero\n");
			system("pause");
		}
		else
		{
			printf("Pasajero borrado con exito\n");
			system("pause");
		}
	}
	else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
	system("pause");
	limpiarConsola();
}

int removerConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int retorno=-1;
	int index;

	mostrarListaConsulta(list, len ,fecha, diagnostico, mecanico);
	index = buscarConsultaID(list,len);

	if(index!=-1)
	{
		printf("\nLa Consulta a MODIFICAR es...\n\n"
			   " ______________________________________________________________________________________________\n"
			   "|%-5s|%-15s|%-15s|%-13s|%-13s|%-13s|\n"
			   "|=====|===============|=====================|================|================|================|",
				 "ID",     "Nombre",    "Fecha de Consulta",   "Diagnostico",    "Mecanico",        "Precio");
		mostrarConsultaConTodo(list[index], fecha, diagnostico, mecanico);
		printf("\n|_____|_______________|____________________|________________|________________|________________|\n");
		if(!verificarConfirmacion("\nIngrese 's' para confirmar la BAJA de la Consulta: "))
		{
			retorno = 0;
			list[index].isEmpty = LIBRE;
		}else
		{
			printf("\nNo se realizo la baja");
			retorno = -1;
		}
	}
	return retorno;
}

void diagnosticarConsultas(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int respuestaDiagnosticar;
	if(*flag==1 && !(verificarDiagnosticados(list,len)))
	{
		respuestaDiagnosticar = diagnosticoConsulta(list, MAX, fecha, mecanico, diagnostico, especialidad);
		if(respuestaDiagnosticar == -1)
		{
			printf("No se pudo realizar el diagnostico\n");
			system("pause");
		}else if(respuestaDiagnosticar == 1)
		{
			printf("Se cancelo el diagnostico\n");
			system("pause");
		}else
		{
			printf("Diagnostico realizado correctamente\n");
			system("pause");
		}
	}else
	{
		printf("Error, debe tener cargado minimo 1 CONSULTA o tener CONSULTAS SIN DIAGNOSTICOS.\n");
		system("pause");
	}
}

int diagnosticoConsulta(eConsulta* list, int len, eFecha* fecha, eMecanico* mecanico, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int retorno = -1;
	int opcion;
	int index;
	int indexC;
	float precio;
	int idDiagnostico;
	eConsulta aux;


	if (list != NULL && len > 0)
	{
		mostrarMecanicos(mecanico, especialidad, MAXM);
		index = buscarMecanicoID(mecanico, MAXM);
		if(index!=-1)
		{
			mostrarListaConsultaSinDiagnostico(list, len, fecha, diagnostico);
			indexC = buscarConsultaSinMecanicoID(list, len);
			aux = list[indexC];
			if(indexC!=-1)
			{
				printf("\nLa Consulta a DIAGNOSTICAR es...\n\n"
					   " ___________________________________________________________________________\n"
					   "|%-5s|%-15s|%-15s|%-15s|%-15s|\n"
					   "|=====|===============|=====================|===============|===============|",
						 "ID",     "Nombre",    "Fecha de Consulta",  "Diagnostico",    "Precio");
				mostrarConsultaCSinDiagnostico(list[indexC], fecha, diagnostico);
				printf("\n|_____|_______________|____________________|_______________|_______________|\n");

				do
				{
					subMenuDiagnosticar(&opcion);
					switch(opcion)
					{
						case 1:
							limpiarConsola();
							mostrarDiagnosticos(diagnostico, MAXD);
							utn_getInt(&idDiagnostico, "Ingrese el Diagnostico: ", "ERROR. Ingrese el Mecanico nuevamente: ", 1, MAXD, 3);
							aux.idDiagnostico = idDiagnostico;
							utn_getFloat(&precio, "Ingrese un nuevo precio: ", "ERROR. Ingrese precio nuevamente : ", 1, 1000000000, 3);
							aux.cotizacion = aux.cotizacion +  precio;
							retorno=0;
						break;
						case 2:
							printf("Saliendo");
						break;
					}
				}while(opcion!=2);

				if(retorno==0)
				{
					printf("\nLa Consulta a DIAGNOSTICAR es...\n\n"
						   " ___________________________________________________________________________\n"
						   "|%-5s|%-15s|%-15s|%-15s|%-15s|\n"
						   "|=====|===============|=====================|===============|===============|",
							 "ID",     "Nombre",    "Fecha de Consulta",  "Diagnostico",    "Precio");
					mostrarConsultaConDiagnostico(aux, fecha, diagnostico);
					printf("\n|_____|_______________|____________________|_______________|_______________|\n");

					if(!verificarConfirmacion("\nIngrese 's' para confirmar el DIAGNOSTICO de la Consulta: "))
					{
						aux.idMecanico = index;
						list[indexC]=aux;
					}else
					{
						printf("\nNo se realizo el DIAGNOSTICO");
						retorno = 1;
					}
				}
			}else
			{
				printf("\nNo se encontro la Consulta");
				retorno = -1;
			}
		}else
		{
			printf("\nNo se encontro el Mecanico");
			retorno = -1;
		}
	}else
	{
		retorno=-1;
	}

	return retorno;
}

void mostrarListados(eConsulta* list, int len, eMecanico* mecanico, eDiagnostico* diagnostico, eFecha* fecha, eEspecialidad* especialidad, int* flag)
{
	int opcionListado;

	if(*flag==1)
	{
		do
		{
			subMenuListados(&opcionListado);
			switch(opcionListado)
			{
				case 1:
					mostrarMecanicos(mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 2:
					mostrarListaConsulta(list, MAX, fecha, diagnostico, mecanico);
					system("pause");
				break;
				case 3:
					mostrarMecanicosSinConsultas(list, mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 4:
					mostrarConsultasPorFecha(list, MAX);
					mostrarListaConsulta(list, MAX, fecha, diagnostico, mecanico);
					system("pause");
				break;
				case 5:
					mostrarCotizacionPorFecha(list, MAX);
					system("pause");
				break;
				case 6:
					mostrarCotizacionPorMecanico(list, MAX, mecanico, especialidad, MAXM);
					system("pause");
				break;
				case 7:
					mostrarMecanicosConConsultas(list, MAX, mecanico, MAXM);
					system("pause");
				break;
				case 8:
					ordenarEspecialidadAlfabeticamente(list, MAX, mecanico, MAXM, fecha, diagnostico, especialidad);
					system("pause");
				break;
				case 9:
					mostrarListadoConsultaPorMes(list, MAX, mecanico, MAXM, fecha, diagnostico, especialidad);
					system("pause");
				break;
				case 10:
					porcentajeConsultas(list, MAX, mecanico, MAXM, diagnostico);
					system("pause");
				break;
				case 11:
					topTresMasEstudidadas(mecanico, MAXM, especialidad, MAXE);
					system("pause");
				break;
				case 12:
					printf("Saliendo del LISTADO\n");
				break;

			}
		}while(opcionListado!=12);
	}else
	{
		printf("Error, debe tener cargado minimo 1 pasajero para ingresar a esta opcion.\n");
		system("pause");
	}
}

int mostrarListaConsulta(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-15s|\n"
		   "|=====|===============|==========|=====================|=====================|====================|",
		      "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			mostrarConsultaConTodo(list[i], fecha, diagnostico, mecanico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
	return 0;
}

void mostrarConsultaConTodo(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
    int idDiagnostico;
    int idMecanico;

    if(list.isEmpty == OCUPADO)
	{
    	idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
    	idMecanico = descripcionMecanico(list, mecanico, MAXM);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-5d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-20s|",mecanico[idMecanico].nombreMecanico);
		printf("%-13.2f|",list.cotizacion);
	}
}

int descripcionDiagnostico(eConsulta list, eDiagnostico* diagnostico, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idDiagnostico == diagnostico[i].idDiagnostico)
        {
            index=i;
            break;
        }
    }
    return index;
}

int descripcionMecanico(eConsulta list, eMecanico* mecanico, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(list.idMecanico == mecanico[i].idMecanico)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarMecanicos(eMecanico* mecanico, eEspecialidad* especialidad, int len)
{
    int i;

    printf(" __________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|\n"
		   "|=====|=====================|==============================|\n",
			 "ID",      "Mecanico",               "Especialidad");

    for(i=1;i<len;i++)
    {
    	mostrarUnMecanico(mecanico[i], especialidad);
    }
	printf("|_____|_____________________|______________________________|\n");
}

void mostrarUnMecanico(eMecanico mecanico, eEspecialidad* especialidad)
{
	int idEspecialidad;

	idEspecialidad = descripcionEspecialidad(mecanico, especialidad, MAXE);
	printf("|%-5d|%-21s|%-30s|\n", mecanico.idMecanico, mecanico.nombreMecanico, especialidad[idEspecialidad].especialidad);
}

void mostrarUnMecanicoConCotizacion(eMecanico mecanico, eEspecialidad* especialidad, float cotizacion)
{
	int idEspecialidad;

	idEspecialidad = descripcionEspecialidad(mecanico, especialidad, MAXE);
	printf("|%-5d|%-21s|%-30s|%-18.2f|\n", mecanico.idMecanico, mecanico.nombreMecanico, especialidad[idEspecialidad].especialidad, cotizacion);
}


int descripcionEspecialidad(eMecanico mecanico, eEspecialidad* especialidad, int tam)
{
    int index;

    for(int i=0;i<tam;i++)
    {
        if(mecanico.idEspecialidad == especialidad[i].idEspecialidad)
        {
            index=i;
            break;
        }
    }
    return index;
}

void mostrarMecanicosSinConsultas(eConsulta* list, eMecanico* mecanico, eEspecialidad* especialidad, int len)
{
	int bandera;
    int j;

    printf(" __________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|\n"
		   "|=====|=====================|==============================|\n",
			 "ID",      "Mecanico",               "Especialidad");
	for(j=0;j<len;j++)
	{
		bandera = 0;
		bandera = compararMecanico(list,mecanico[j],MAX);
		if(bandera == 0)
		{
			mostrarUnMecanico(mecanico[j], especialidad);
		}
	}
	printf("|_____|_____________________|______________________________|\n");;

}

int compararMecanico(eConsulta* list, eMecanico mecanico, int len)
{
	int bandera = 0;
	for(int i=0;i<len;i++)
	{
		if(list[i].idMecanico == mecanico.idMecanico)
		{
			bandera = 1;
		}
	}
	return bandera;
}

void mostrarCotizacionPorMecanico(eConsulta* list, int len, eMecanico* mecanico, eEspecialidad* especialidad, int lenM)
{
	int cont = 0;
	float precio = 0;
	float promedio = 0;

	printf(" _____________________________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|%-18s|\n"
		   "|=====|=====================|==============================|==================|\n",
			 "ID",      "Mecanico",               "Especialidad",          "Cotizacion");
	for(int i=0;i<lenM;i++)
	{
		precio = 0;
		cont = 0;
		cont = contMasPrecioTotal(list, MAX, mecanico[i], &precio);

		if(mecanico[i].idMecanico > 0 && precio > 0)
		{
			promedio = precio/cont;
			mostrarUnMecanicoConCotizacion(mecanico[i], especialidad, promedio);
		}else
			if(mecanico[i].idMecanico > 0 && precio == 0)
			{
				promedio = 0;
				mostrarUnMecanicoConCotizacion(mecanico[i], especialidad, promedio);
			}
	}
	printf("|_____|_____________________|______________________________|__________________|\n");
}

int contMasPrecioTotal(eConsulta* list, int len, eMecanico mecanico, float* precio)
{
	int cont = 0;

	for(int j=0;j<len;j++)
	{
		if(list[j].idMecanico == mecanico.idMecanico)
		{
			cont++;
			*precio = *precio + list[j].cotizacion;
		}
	}
	return cont;
}

void mostrarMecanicosConConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM)
{
	int i;
	int cont;
	int cantConsultas;
	int bandera=1;

	for(i=0;i<lenM;i++)
	{
		cont = 0;
		cont = contConsultaPorMecanico(list, MAX, mecanico[i]);
		if(cont > cantConsultas || bandera == 1)
		{
			cantConsultas = cont;
			bandera = 0;
		}
	}

	printf("----------------------Cantidad de Consulta por Mecanico-----------------------\n");
	printf(" _____________________________________________________________________________\n"
		   "|%-5s|%-21s|%-30s|%-18s|\n"
		   "|=====|=====================|==============================|==================|\n",
			 "ID",      "Mecanico",               "Especialidad",        "Cant. Consultas");
	for(i=0;i<lenM;i++)
	{
		cont = 0;
		cont = contConsultaPorMecanico(list, MAX, mecanico[i]);
		if(cont == cantConsultas)
		{
			printf("|%-5d|%-21s|%-30d|%-18d|\n", mecanico[i].idMecanico, mecanico[i].nombreMecanico, mecanico[i].idEspecialidad, cantConsultas);
		}
	}
	printf("|_____|_____________________|______________________________|__________________|\n");
}

int contConsultaPorMecanico(eConsulta* list, int len, eMecanico mecanico)
{
	int cont = 0;
	for(int j=0;j<len;j++)
	{
		if(mecanico.idMecanico == list[j].idMecanico && mecanico.idMecanico > 0)
		{
			cont++;
		}
	}
	return cont;
}

void ordenarEspecialidadAlfabeticamente(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int i;
	int j;
	eConsulta aux;


	for(i=0; i<lenM-1; i++)
	{
		for(j=i+1; j<lenM; j++)
		{
			if(strcmp(especialidad[i].especialidad, especialidad[j].especialidad) > 0)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
	printf("\nMostrando lista de Consultas ordenadada ALFABETICAMENTE...\n\n"
		   " ________________________________________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-10s|%-21s|%-21s|%-20s|%-15s|\n"
		   "|=====|===============|==========|=====================|=====================|==============================|====================|",
			  "ID",    "Nombre",    "Fecha",     "Diagnostico",        "Mecanico",                "Especialidad",               "Precio");
	for(int i=0;i<len;i++)
	{
		imprimirAlfabeticamente(list[i], mecanico, MAXM, fecha, diagnostico, especialidad);
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|______________________________|____________________|\n");
}

void imprimirAlfabeticamente(eConsulta list, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int idDiagnostico;
	int idMecanico;
	int idEspecialidad;

	for(int j=0;j<lenM;j++)
	{
		if(list.isEmpty == OCUPADO && mecanico[j].idMecanico == list.idMecanico)
		{
			idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
			idMecanico = descripcionMecanico(list, mecanico, MAXM);
			idEspecialidad = descripcionEspecialidad(mecanico[j], especialidad, MAXE);
			printf("\n|%-5d|",list.idConsulta);
			printf("%-15s|",list.nombreCliente);
			printf("%d/%d/%-5d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
			printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
			printf("%-20s|",mecanico[idMecanico].nombreMecanico);
			printf("%-20s|",especialidad[idEspecialidad].especialidad);
			printf("%-13.2f|",list.cotizacion);
		}
	}
}

int mostrarListadoConsultaPorMes(eConsulta* list, int len, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad)
{
	int retorno = -1;
	int idEspecialidad;

	printf("Busque la especialidad entre Marzo y Mayo\n");
	idEspecialidad = buscarEspecialidad(especialidad, MAXE);

	if(idEspecialidad!=-1)
	{
		for(int i=0;i<len;i++)
		{
			imprimirConsultaPorMes(list[i], mecanico, lenM, fecha, diagnostico, especialidad, idEspecialidad);
			retorno = 0;
		}
	}else
	{
		retorno = -1;
		printf("No existe ningún servicio asignado a un mecanico con esa especialidad");
	}
	return retorno;
}

void imprimirConsultaPorMes(eConsulta list, eMecanico* mecanico, int lenM, eFecha* fecha, eDiagnostico* diagnostico, eEspecialidad* especialidad, int idEspecialidad)
{
	int idDiagnostico;
	int idMecanico;

	for(int j=0;j<lenM;j++)
	{
		if(mecanico[j].idEspecialidad == idEspecialidad)
		{
			if((list.fecha.mes >= 3 && list.fecha.mes <= 5) && (mecanico[j].idMecanico == list.idMecanico))
			{
				idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
				idMecanico = descripcionMecanico(list, mecanico, MAXM);
				printf("\n|%-5d|",list.idConsulta);
				printf("%-15s|",list.nombreCliente);
				printf("%d/%d/%-5d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
				printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
				printf("%-20s|",mecanico[idMecanico].nombreMecanico);
				printf("%-20s|",especialidad[idEspecialidad].especialidad);
				printf("%-13.2f|",list.cotizacion);
			}
		}
	}
}

void porcentajeConsultas(eConsulta* list, int len, eMecanico* mecanico, int lenM, eDiagnostico* diagnostico)
{
	float contDiagnostico;
	float contMecanico;
	float porcentaje;

	contDiagnostico = contDiagnosticos(list, len);

	printf("PORCENTAJE DE DIAGNOSTICOS POR MECANICO: \n");
	printf(" _________________________________________\n"
		   "|%-5s|%-21s|%-14s|\n"
		   "|=====|=====================|=============|\n",
			 "ID",      "Mecanico",       "Porcentaje");
	for(int i=1; i<lenM; i++)
	{
		contMecanico = 0;
		contMecanico = contConsultaPorMecanico(list, len, mecanico[i]);
		if(contMecanico > 0)
		{
			porcentaje = (contMecanico/contDiagnostico)*100;
		}else
		{
			porcentaje = 0;
		}

		mostrarMecanicoPorcentaje(mecanico[i], len, porcentaje);
	}
	printf("|_____|_____________________|______________|\n");
}

float contDiagnosticos(eConsulta* list, int len)
{
	float contDiagnostico = 0;

	for(int i=1;i<len;i++)
	{
		if(list[i].idDiagnostico > 0)
		{
			contDiagnostico++;
		}
	}
	return contDiagnostico;
}


void mostrarListaConsultaConMecanico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico, eMecanico* mecanico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idMecanico >= 1)
		{
			mostrarConsultaConTodo(list[i], fecha, diagnostico, mecanico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}


void mostrarConsultaConMecanico(eConsulta list, eFecha* fecha, eMecanico* mecanico)
{
	int idMecanico;

	if(list.isEmpty == OCUPADO)
	{
		idMecanico = descripcionMecanico(list, mecanico, MAXM);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-20s|",mecanico[idMecanico].nombreMecanico);
		printf("%-13.2f|",list.cotizacion);
	}
}

void mostrarListaConsultaSinDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idDiagnostico <=0)
		{
			mostrarConsultaCSinDiagnostico(list[i], fecha, diagnostico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}

void mostrarUnaConsultaCSinDiagnostico(eConsulta list, eFecha* fecha)
{
	printf("\n|%-5d|",list.idConsulta);
	printf("%-15s|",list.nombreCliente);
	printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
	printf("%-13.2f|",list.cotizacion);
}

void mostrarConsultaCSinDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico)
{
	int idDiagnostico;

	if(list.isEmpty == OCUPADO)
	{
		idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-13.2f|",list.cotizacion);
	}
}

void mostrarListaConsultaConDiagnostico(eConsulta* list, int len, eFecha* fecha, eDiagnostico* diagnostico)
{
	int i;
	printf("\nMostrando lista de Consultas...\n\n"
		   " _________________________________________________________________________________________________\n"
		   "|%-5s|%-15s|%-15s|%-13s|%-21s|%-20s|\n"
		   "|=====|===============|===============|================|=====================|====================|",
			  "ID",    "Nombre",      "Fecha",      "Diagnostico",        "Mecanico",            "Precio");
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idDiagnostico >=1)
		{
			mostrarConsultaConDiagnostico(list[i], fecha, diagnostico);
		}
	}
	printf("\n|_____|_______________|_______________|________________|_____________________|____________________|\n");
}


void mostrarConsultaConDiagnostico(eConsulta list, eFecha* fecha, eDiagnostico* diagnostico)
{
	int idDiagnostico;

	if(list.isEmpty == OCUPADO)
	{
		idDiagnostico = descripcionDiagnostico(list, diagnostico, MAXD);
		printf("\n|%-5d|",list.idConsulta);
		printf("%-15s|",list.nombreCliente);
		printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
		printf("%-21s|",diagnostico[idDiagnostico].nombreDiagnostico);
		printf("%-13.2f|",list.cotizacion);
	}
}

void topTresMasEstudidadas(eMecanico* mecanico, int lenM, eEspecialidad* especialidades, int lenE)
{
    int contEspecialidad;
    int bandera = 0;
    int mayorEspecialidad;

    for(int i = 0;i<lenE;i++)
    {
    	contEspecialidad = contEspecialidades(especialidades[i],mecanico,lenM);
        if(bandera == 0 || contEspecialidad > mayorEspecialidad)
        {
        	mayorEspecialidad = contEspecialidad;
            bandera = 1;
        }
    }

    printf("----------------------TOP 3-----------------------\n");
	printf(" _________________________________________________\n"
		   "|%-5s|%-21s|%-21s|\n"
		   "|=====|=====================|=====================|\n",
		   "  ID",  "Especialidad",      "Cant. de Estudiados");

	//burbujeoTopTres(especialidades,lenE,contEspecialidad,mayorEspecialidad);
	imprimirEspecialidadConCont(especialidades,lenE,mecanico,lenM,mayorEspecialidad);

    printf("|_____|_____________________|_____________________|\n");
}

int contEspecialidades(eEspecialidad especialidades,eMecanico* mecanico,int lenM)
{
    int contador = 0;

    for(int j = 0; j<lenM;j++)
	{
		if(mecanico[j].idEspecialidad == especialidades.idEspecialidad && mecanico[j].idEspecialidad > 0 && especialidades.idEspecialidad > 0)
		{
			contador++;
		}
	}
    return contador;
}

void imprimirUnaEspecialidad(eEspecialidad especialidades,int lenE, int contEspecialidad)
{
	printf("|%-5d|%-21s|%-21d|\n",especialidades.idEspecialidad, especialidades.especialidad, contEspecialidad);
}

void imprimirEspecialidadConCont(eEspecialidad* especialidades,int lenE,eMecanico* mecanico,int lenM,int mayorEspecialidad)
{
    int contEspecialidad;
    int contEspecialidadAux;

    for(int i = 0;i<lenE;i++)
    {
    	contEspecialidad = contEspecialidades(especialidades[i],mecanico,lenM);

    	if(contEspecialidad != 0)
		{
			for(int j=0;j<lenE;j++)
			{
				contEspecialidadAux = contEspecialidades(especialidades[j],mecanico,lenM);
				if(contEspecialidad == contEspecialidadAux && especialidades[i].idEspecialidad == especialidades[j].idEspecialidad && contEspecialidad >= mayorEspecialidad)
				{
					imprimirUnaEspecialidad(especialidades[i],lenE,contEspecialidad);
					break;
				}else{
					imprimirUnaEspecialidad(especialidades[i],lenE,contEspecialidad);
					mayorEspecialidad--;
					break;
				}
			}
		}
	}
}
