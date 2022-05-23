#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"

int listarServicios(eServicio aServicios[], int tam)
{
    int todoBien = 0;

    if(aServicios != NULL && tam > 0)
    {
        system("cls");
        printf("    *** LISTA DE SERVICIOS  ***\n\n");
        printf("  ------------------------------------\n");
        printf("  |  ID   |  Descripcion   |  Precio |\n");
        printf("  ------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            printf("  | %3d | %-10s     | %3.2f |\n", aServicios[i].id, aServicios[i].descripcion, aServicios[i].precio);
        }
         printf("  |_______|________________|_________|\n");
        printf("\n\n");
        todoBien = 1;
    }
    return todoBien;
}

int buscarServicioId(eServicio aServicios[], int tam, int id, int* pIndice)
{
    int todoBien = 0;

    if(aServicios != NULL && pIndice != NULL && tam > 0 && id > 0)
    {
        *pIndice = -1;
        for(int i=0; i<tam; i++)
        {
            if(aServicios[i].id == id)
            {
                *pIndice = i;
                break;
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int cargarServicioDescripcion(eServicio aServicios[], int tam, int id, char descripcion[])
{
    int todoBien = 0;
    int indice;
    int retorno;

    retorno = buscarServicioId(aServicios,tam,id,&indice);

    if(aServicios != NULL && descripcion != NULL && tam > 0 && id > 0 && retorno && indice != -1)
    {
        strcpy(descripcion,aServicios[indice].descripcion);
        todoBien = 1;
    }

    return todoBien;
}

int validarServicio(eServicio aServicios[], int tam, int id)
{
    int todoBien = 0;
    int indice;
    int retorno;

    if(aServicios != NULL && tam > 0 && id > 0)
    {
        retorno = buscarServicioId(aServicios,tam,id,&indice);
        if(retorno && indice != -1)
        {
            todoBien = 1;
        }
    }

    return todoBien;
}
