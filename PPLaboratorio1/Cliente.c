#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Utn.h"

int listarClientes(eCliente aClientes[],int tam)
{
    int todoBien = 0;

    if(aClientes != NULL && tam > 0)
    {
        system("cls");
        printf("  *** LISTA DE CLIENTES ***\n");
        printf("  -------------------------\n");
        printf("  | ID  |  NOMBRE  | SEXO |\n");
        printf("  -------------------------\n");

        for(int i=0; i<tam; i++)
        {
            printf("  | %3d | %7s  | %3c  |\n",aClientes[i].idCliente,aClientes[i].nombre,aClientes[i].sexo);
        }
        printf("  |_____|__________|______|\n");
        printf("\n\n");
        todoBien = 1;
    }

    return todoBien;
}

int cargarClienteDescripcion(eCliente aClientes[], int tam, int id, char descripcion[])
{
    int todoBien = 0;
    int indice;
    int retorno;

    retorno = buscarClienteId(aClientes,tam,id,&indice);

    if(aClientes != NULL && tam > 0 && id > 0 && descripcion != NULL && retorno && indice != -1)
    {
       strcpy(descripcion,aClientes[indice].nombre);
       todoBien = 1;
    }

    return todoBien;
}

int buscarClienteId(eCliente aClientes[], int tam, int id, int* pIndice)
{
    int todoBien = 0;

    if(aClientes != NULL && pIndice != NULL && tam > 0 && id > 0)
    {
        *pIndice = -1;

        for(int i=0; i<tam; i++)
        {
            if(aClientes[i].idCliente == id)
            {
                *pIndice = i;
                todoBien = 1;
            }
        }
    }

    return todoBien;
}
