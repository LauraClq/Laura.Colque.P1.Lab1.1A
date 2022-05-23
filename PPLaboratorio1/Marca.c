#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marca.h"

int listarMarcas(eMarca aMarcas[], int tam)
{
    int todoBien = 0;

    if(aMarcas != NULL && tam > 0)
    {
        system("cls");
        printf("  ** LISTA DE MARCAS  **\n");
        printf("  -----------------------\n");
        printf("  | ID   |  Descripcion |\n");
        printf("  -----------------------\n");

        for(int i=0; i < tam; i++)
        {
            printf("  | %3d |   %8s   |\n", aMarcas[i].id, aMarcas[i].descripcion);
        }
        printf("  |______|______________|\n");
        printf("\n\n");
        todoBien = 1;
    }
    return todoBien;
}

int buscarMarcaId(eMarca aMarcas[], int tam, int idMarca, int* pIndice)
{
    int todoBien = 0;

    if(aMarcas != NULL && pIndice != NULL && tam > 0 && idMarca > 0)
    {
        *pIndice = -1;

        for(int i=0; i<tam; i++)
        {
            if(aMarcas[i].id == idMarca)
            {
                *pIndice = i;
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int cargarMarcaDescripcion(eMarca aMarcas[], int tam, int id, char descripcion[])
{
    int todoBien = 0;
    int indice;
    int retorno;

    retorno = buscarMarcaId(aMarcas,tam,id,&indice);

    if(aMarcas != NULL && descripcion != NULL && tam > 0 && id > 0 && retorno && indice != -1)
    {
       strcpy(descripcion,aMarcas[indice].descripcion);
       todoBien = 1;
    }

    return todoBien;
}

int validarMarca(eMarca aMarcas[], int tam, int id)
{
    int todoBien = 0;
    int indice;
    int retorno;

    if(aMarcas != NULL && tam > 0 && id > 0)
    {
        retorno = buscarMarcaId(aMarcas,tam,id,&indice);
        if(retorno && indice != -1)
        {
           todoBien = 1;
        }
    }

    return todoBien;
}
