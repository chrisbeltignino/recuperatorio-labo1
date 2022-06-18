#include "Consulta.h"

int iniciarConsulta(eConsulta list[], int len)
{
	int i;
	int index = -1;

	if(len == MAX)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = LIBRE;
			list[i].idDiagnostico = 0;
			list[i].idMecanico = 0;
			index = 0;
		}
	}
	return index;
}

int indicoLibre(eConsulta list[], int len)
{
	int i;
	int index=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == LIBRE && list[i].idDiagnostico == 0 && list[i].idMecanico == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

int buscarConsultaID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarConsultaConMecanicoID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].idMecanico >= 1 && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int buscarConsultaSinMecanicoID(eConsulta* list, int len)
{
	int i;
	int numero;
	int loEncontre=-1; //fuera de indice

	utn_getInt(&numero, "Ingrese el id a buscar: ", "ERROR, no se encontro la ID\n", 0, MAX, 3);
	for(i=0; i<len; i++)
	{
		if(numero == list[i].idConsulta && list[i].idMecanico == 0 && list[i].isEmpty == OCUPADO)
		{
			loEncontre=i;
		}
	}
	return loEncontre;
}

int verificarDiagnosticados(eConsulta* list, int len)
{
	int i;
	int seEncuentra=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idDiagnostico == 0)
		{
			seEncuentra=0;
		}
	}
	return seEncuentra;
}

int verificarMecanico(eConsulta* list, int len)
{
	int i;
	int seEncuentra=-1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idMecanico > 0)
		{
			seEncuentra=0;
			break;
		}
	}
	return seEncuentra;
}

void cargaForzada(eConsulta* list, int len, int* flag)
{
    int id[] = {1,2,3,4};
    char name[][51] = {"Christian","Matias","Juliana","Leo"};
    eFecha fechas[] = {{2,4,2022},{2,4,2022},{1,2,2023},{20,9,2022}};
    float price[] = {50000,25000,60000,30000};
    int idDiagnostico[] = {1,1,3,1};
    int idMecanico[] = {5,1,1,3};
    int isEmpty[]={1,1,1,1};

    for(int i=0;i<4;i++)
    {
    	list[i].idConsulta = id[i];
        strcpy(list[i].nombreCliente, name[i]);
        list[i].fecha = fechas[i];
        list[i].cotizacion = price[i];
        list[i].idDiagnostico = idDiagnostico[i];
        list[i].idMecanico = idMecanico[i];
        list[i].isEmpty = isEmpty[i];
    }
    *flag = 1;
    printf("Carga Forzada EXITOSA\n");
    system("pause");
}

void mostrarUnaConsulta(eConsulta list)
{
	printf("\n|%-5d|",list.idConsulta);
	printf("%-15s|",list.nombreCliente);
	printf("%d/%d/%-15d|",list.fecha.dia, list.fecha.mes, list.fecha.anio);
	printf("%-21d|",list.idDiagnostico);
	printf("%-20d|",list.idMecanico);
	printf("%-13.2f|",list.cotizacion);
}

void mostrarConsultasPorFecha(eConsulta* list, int len)
{
	eConsulta aux;

	for(int i = 0; i<len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
			if(list[i].fecha.anio > list[j].fecha.anio)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}else
			{
				if(list[i].fecha.anio == list[j].fecha.anio)
				{
					if(list[i].fecha.mes > list[j].fecha.mes)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}else
					{
						if(list[i].fecha.mes == list[j].fecha.mes)
						{
							if(list[i].fecha.dia > list[j].fecha.dia)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
				}
			}
		}
	}
}

void mostrarCotizacionPorFecha(eConsulta* list, int len)
{
	int i;
	int dia;
	int mes;
	int bandera = -1;
	float cotizacion = 0;
	pedirEntero(&mes, "Ingresar el mes: ", "ERROR, reingrese el mes: ", 1, 12);
	pedirEntero(&dia, "Ingresar dia que desea saber la cotizacion general: ", "ERROR, reingrese el dia", 1, 31);

	for(i=0;i<len;i++)
	{
		if(mes == list[i].fecha.mes && dia == list[i].fecha.dia && list[i].idDiagnostico == 1)
		{
			cotizacion = cotizacion + list[i].cotizacion;
			bandera = 0;
		}
	}
	if(bandera==-1)
	{
		printf("No existen servicios con Cambio de Aceite para esa fecha. \n");
	}
	if(cotizacion!=0)
	{
		printf("La cotizacion general de ese dia es %.2f: \n", cotizacion);
	}
}
