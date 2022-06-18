#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Nexo.h"

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    int flag = 0;

    eFecha fecha[MAX];
    eConsulta list[MAX];
    eMecanico mecanico[MAXM];
    eDiagnostico diagnostico[MAXD] = {{0,"NO diagnosticado"},{1,"Cambio de aceite"},{2,"Reparación de motor"},{3,"Suspensión"}};
    eEspecialidad especialidad[MAXE] = {{0,"Sin especialidad"},{1,"Tecnico electronico"},{2,"Experto en carroceria"},{3,"Mecatronica automotriz"},{4,"Experto en todo"}};

    HardcodearMecanicos(mecanico, MAXM);
    iniciarConsulta(list, MAX);
    do
    {
    	mostrarMenu(&opcion);
        switch(opcion)
        {
            case 1:
            	altaConsulta(list, MAX, diagnostico, mecanico, fecha, &flag);
            break;
            case 2:
            	modificarConsultas(list, MAX, mecanico, diagnostico, fecha, especialidad, &flag);
            break;
            case 3:
            	bajaConsulta(list, MAX, mecanico, diagnostico, fecha, &flag);
            break;
            case 4:
            	diagnosticarConsultas(list, MAX, mecanico, diagnostico, fecha, especialidad, &flag);
            break;
            case 5:
            	cargaForzada(list, MAX, &flag);
            break;
            case 6:
            	mostrarListados(list, MAX, mecanico, diagnostico, fecha, especialidad, &flag);
            	system("pause");
            break;
            case 7:
            	limpiarConsola();
            	printf("Saliendo...\n");
            break;

            default:
            	limpiarConsola();
                printf("Ingrese una opcion valida\n");
        }
    }while(opcion!=7);
}

