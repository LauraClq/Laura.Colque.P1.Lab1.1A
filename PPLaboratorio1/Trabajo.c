#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"
#include "Utn.h"

int listarTrabajos(eTrabajo aTrabajos[], int tam, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS)
{
    int todoBien = 0;
    int flag = 0;

    if(aTrabajos != NULL && aNotebooks != NULL && aServicios != NULL && tam > 0 && tamN > 0 && tamS > 0)
    {
        system("cls");
        printf("         *** LISTA DE TRABAJOS  ***\n");
        printf("--------------------------------------------\n");
        printf("| ID  |  Notebook |  Servicio |   Fecha    |\n");
        printf("--------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if(!aTrabajos[i].isEmpty)
            {
                mostrarTrabajo(aTrabajos[i],aNotebooks,tamN,aServicios,tamS);
                todoBien = 1;
                flag = 1;
            }
        }
        printf("|_____|___________|___________|____________|\n");
        if(!flag)
        {
            printf("\n  NO HAY TRABAJOS REGISTRADOS");
        }
        printf("\n\n");
        todoBien = 1;
    }
    return todoBien;
}

int mostrarTrabajo(eTrabajo unTrabajo, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS)
{
    int todoBien = 0;
    char descNote[20];
    char descServ[20];
    int retornoNote;
    int retornoServ;

    retornoNote = cargarNotebookDescripcion(aNotebooks,tamN,unTrabajo.idNotebook,descNote);
    retornoServ = cargarServicioDescripcion(aServicios,tamS,unTrabajo.idServicio,descServ);

    if(aNotebooks != NULL && aServicios != NULL && tamN > 0 && tamS > 0 && retornoServ && retornoNote)
    {
        printf("| %3d | %7s   | %8s  | %02d/%02d/%02d |\n",unTrabajo.id,descNote,descServ,unTrabajo.fecha.dia,unTrabajo.fecha.mes,unTrabajo.fecha.anio);

        todoBien = 1;
    }

    return todoBien;
}

int initTrabajos(eTrabajo aTrabajos[], int tam)
{
    int todoBien = 0;
    if(aTrabajos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            aTrabajos[i].isEmpty = 1;
        }
        todoBien = 1;
    }

    return todoBien;
}

int buscarTrabajoLibre(eTrabajo aTrabajos[], int tam, int* pIndex)
{
    int todoBien = 0;

    if(aTrabajos != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;

        for(int i=0; i<tam; i++)
        {
            if(aTrabajos[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoBien = 1;
    }
    return todoBien;
}

int altaTrabajo(eTrabajo aTrabajos[], int tam, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC, int* pId)
{
    int todoBien = 0;
    int indiceN;
    int indice = 0;
    int validDia;
    int validMes;
    int validAnio;

    eTrabajo auxTrabajo;
    eFecha auxFecha;

    if(aTrabajos != NULL && aNotebooks != NULL && aServicios != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamN > 0 && tamS > 0 && tamM > 0 && tamT > 0 && tamC > 0 && pId != NULL)
    {
        system("cls");
        printf("    *** ALTA TRABAJO ***    \n");
        printf("-----------------------------\n");

        if(buscarTrabajoLibre(aTrabajos,tam,&indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                listaNotebooks(aNotebooks,tamN,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                printf("Ingrese el id del Notebook: ");
                scanf("%d",&auxTrabajo.idNotebook);
                buscarNotebookId(aNotebooks,tamN,auxTrabajo.idNotebook,&indiceN);

                while(indiceN == -1)
                {
                    printf("El id del empleado es invalido. Ingrese el id notebook: ");
                    scanf("%d",&auxTrabajo.idNotebook);
                    buscarNotebookId(aNotebooks,tamN,auxTrabajo.idNotebook,&indiceN);
                }

                listarServicios(aServicios,tamS);
                getValidInt("Ingrese el id del servicio: ","\nError. El id ingresado es invalido.","Solo permite de (20000 - 20003).",20000,20003,&auxTrabajo.idServicio);

                validDia = getValidInt("Ingrese el dia: ","Error. Solo se permite numeros.","Solo permite de (1 - 31)",1,31,&auxFecha.dia);
                validMes = getValidInt("Ingrese el mes: ","Error. Solo se permite numeros.","Solo permite de (1 - 12)",1,12,&auxFecha.mes);
                validAnio = getValidInt("Ingrese el anio: ","Error. Solo se permite numeros.","Solo permite de (2010 - 2022)",2010,2022,&auxFecha.anio);

                if(validarServicio(aServicios,tamS,auxTrabajo.idServicio) && !validDia && !validMes && !validAnio)
                {
                    auxTrabajo.fecha = auxFecha;
                    auxTrabajo.id = *pId;
                    (*pId)++;
                    auxTrabajo.isEmpty = 0;
                    aTrabajos[indice] = auxTrabajo;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros");
        }
        todoBien = 1;
    }
    else
    {
        printf("Ocurrio un error al validar");
    }
    return todoBien;
}

int hardcodearTrabajos(eTrabajo aTrabajos[], int tam, int cant, int* pId)
{
    int todoBien = 0;
    eTrabajo harcodeoT[] =
    {
        {0,100,20000,{2,2,2020},0},
        {0,100,20001,{3,3,2020},0},
        {0,102,20003,{10,12,2020},0},
        {0,101,20003,{1,12,2021},0},
        {0,103,20002,{4,5,2021},0}
    };

    if(aTrabajos != NULL && pId != NULL && tam > 0 && cant > 0 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            aTrabajos[i] = harcodeoT[i];
            aTrabajos[i].id = *pId;
            (*pId)++;
        }
        todoBien = 1;
    }

    return todoBien;
}
