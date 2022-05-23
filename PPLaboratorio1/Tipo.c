#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"

int listarTipos(eTipo aTipos[], int tam)
{
    int todoBien = 0;

    if(aTipos != NULL && tam > 0)
    {
        system("cls");
        printf("   ** LISTA DE TIPOS **\n");
        printf("  -----------------------\n");
        printf("  | ID   |  Descripcion |\n");
        printf("  -----------------------\n");

        for(int i=0; i < tam; i++)
        {
            printf("  | %3d |   %9s  |\n", aTipos[i].id, aTipos[i].descripcion);
        }
        printf("  |______|______________|\n");
        printf("\n\n");
        todoBien = 1;
    }
    return todoBien;
}

int buscarTipoId(eTipo aTipos[], int tam, int idTipo, int* pIndice)
{
    int todoBien = 0;

    if(aTipos != NULL && pIndice != NULL && tam > 0 && idTipo > 0)
    {
        *pIndice = -1;

        for(int i=0; i<tam; i++)
        {
            if(aTipos[i].id == idTipo)
            {
                *pIndice = i;
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int cargarTipoDescripcion(eTipo aTipos[], int tam, int id, char descripcion[])
{
    int todoBien = 0;
    int indice;
    int retorno;

    retorno = buscarTipoId(aTipos,tam,id,&indice);

    if(aTipos != NULL && descripcion != NULL && tam > 0 && id > 0 && retorno && indice != -1)
    {
       strcpy(descripcion,aTipos[indice].descripcion);
       todoBien = 1;
    }

    return todoBien;
}

int validarTipo(eTipo aTipos[], int tam, int id)
{
    int todoBien = 0;
    int indice;
    int retorno;

    if(aTipos != NULL && tam > 0 && id > 0)
    {
        retorno = buscarTipoId(aTipos,tam,id,&indice);
        if(retorno && indice != -1)
        {
           todoBien = 1;
        }
    }

    return todoBien;
}
