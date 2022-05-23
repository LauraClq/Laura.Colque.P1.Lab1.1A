#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Cliente.h"
#include "Informes.h"
#include "Menu.h"
#define TAM_N 10
#define TAM_TRAB 10
#define TAM_CLI 10
#define TAM_M 4
#define TAM_T 4
#define TAM_S 4
#define ALTA 1
#define NADA 0

int main()
{
    char opcion;
    char salir;
    int ingreso = NADA;
    int ingresoTrabajo = NADA;
    int nextIdNote = 100;
    int nextIdTra = 100;

    eNotebook listNote[TAM_N];
    eTrabajo listTrab[TAM_TRAB];

    eMarca listMarca[TAM_M] =
    {
        {1000,"Compaq"},
        {1001,"Asus"},
        {1002,"Acer"},
        {1003,"HP"}
    };

    eTipo listTipo[TAM_T] =
    {
        {5000,"Gamer"},
        {5001,"Disenio"},
        {5002,"Ultrabook"},
        {5003,"Normalita"}
    };

    eServicio listServ[TAM_S] =
    {
        {20000,"Bateria",2250},
        {20001,"Display",10300},
        {20002,"Mantenimiento",4400},
        {20003,"Fuente",5600}
    };

    eCliente listClientes[TAM_CLI] =
    {
        {100,"Laura",'f'},
        {101,"Marcos",'m'},
        {102,"Julian",'m'},
        {103,"Jules",'f'},
        {104,"Sofia",'f'},
        {105,"Bruno",'m'},
        {106,"Ariel",'m'},
        {107,"Demon",'m'},
        {108,"Zendaya",'f'},
        {109,"Margot",'f'}
    };

    initNotebooks(listNote,TAM_N);
    initTrabajos(listTrab,TAM_TRAB);

    hardcodearNotebooks(listNote,TAM_N,5,&nextIdNote);
    hardcodearTrabajos(listTrab,TAM_TRAB,4,&nextIdTra);

    do
    {
        opcion = menuOpciones();

        switch(opcion)
        {
        case 'A':
            if(altaNotebook(listNote,TAM_N,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI,&nextIdNote))
            {
                printf("Alta exitosa!!\n");
                ingreso = ALTA;
            }
            break;
        case 'B':
            if(ingreso)
            {
                if(modificarNotebook(listNote,TAM_N,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI))
                {
                    printf("Modificacion exitosa!!\n");
                }
            }
            else
            {
                printf("Para modificar primero dar de alta notebooks\n");
            }
            break;
        case 'C':
            if(ingreso)
            {
                if(bajaNotebook(listNote,TAM_N,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI))
                {
                    printf("Baja exitosa!!\n");
                }
            }
            else
            {
                printf("Para dar de baja primero dar de alta notebooks\n");
            }
            break;
        case 'D':
            if(ingreso)
            {
                system("cls");
                printf("---------------------------------------------------\n");
                printf("        Ordenar Notebook por Marca y Precio        \n");
                printf("---------------------------------------------------\n");
                ordenarNotebooks(listNote,TAM_N,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI);
                listaNotebooks(listNote,TAM_N,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI);
            }
            else
            {
                printf("Para informar primero dar de alta notebooks\n");
            }
            break;
        case 'E':
            listarMarcas(listMarca,TAM_M);
            break;
        case 'F':
            listarTipos(listTipo,TAM_T);
            break;
        case 'G':
            listarServicios(listServ,TAM_S);
            break;
        case 'H':
            if(ingreso)
            {
               if(altaTrabajo(listTrab,TAM_TRAB,listNote,TAM_N,listServ,TAM_S,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI,&nextIdTra))
               {
                  printf("Alta exitosa!!\n");
                  ingresoTrabajo = ALTA;
               }
            }
            else
            {
                printf("Para dar de alta trabajo primero dar de alta notebooks\n");
            }
            break;
        case 'I':
            if(ingresoTrabajo)
            {
               listarTrabajos(listTrab,TAM_TRAB,listNote,TAM_N,listServ,TAM_S);
            }
            else
            {
                printf("Para informar trabajos primero dar de alta un trabajo\n");
            }
            break;
        case 'J':
            if(ingreso)
            {
               InformesGenerales(listNote,TAM_N,listTrab,TAM_T,listServ,TAM_S,listMarca,TAM_M,listTipo,TAM_T,listClientes,TAM_CLI);
            }
            else
            {
                printf("Para informar primero dar de alta las notebooks\n");
            }
            break;
        case 'K':
            salir = confirmacion("Desea salir? s/n: ");
            break;
        default:
            printf("Opcion invalida solo (A - K)\n");
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}
