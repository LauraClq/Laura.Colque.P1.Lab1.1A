#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "Menu.h"
#include "Utn.h"

int InformesGenerales(eNotebook aNotebooks[], int tam, eTrabajo aTrabajos[], int tamTrab, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    char salir;

    do
    {
        switch(menuInformes())
        {
        case 1:
            listarNotebookTipo(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 2:
            listarNotebookMarca(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 3:
            listarNotebookMasBarata(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 4:
            listarNotebooksPorMarcas(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 5:
            listarCantidadMarcaTipo(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 6:
            listarMarcaMasElegida(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 7:
            listarNoteboksTrabajo(aNotebooks,tam,aTrabajos,tamTrab,aServicios,tamS,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
            break;
        case 8:
            salir = confirmacion("Desea salir? s/n: ");
            break;
        default:
            printf("Opcion invalida, solo de (1 - 6)\n");
            break;
        }

        system("pause");

    }
    while(salir != 's');


    return todoBien;
}

int listarNotebookTipo(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int flag = 0;
    int idTipo;
    char descripcion[20];

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        listarTipos(aTipos,tamT);
        getValidInt("Ingrese el id del tipo: ","\nEl id es invalido.Reingrese el id del tipo.","Solo permite de (5000 a 5003)",5000,5003,&idTipo);

        if(validarTipo(aTipos,tamT,idTipo))
        {
            cargarTipoDescripcion(aTipos,tamT,idTipo,descripcion);
            printf("\n          *** LISTA DE NOTEBOOKS DE TIPO %s ***\n\n",descripcion);
            printf("---------------------------------------------------------------\n");
            printf("| ID  |  MODELO  |  MARCA |    TIPO    |  PRECIO   | CLIENTE  |\n");
            printf("---------------------------------------------------------------\n");

            for(int e; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idTipo == idTipo)
                {
                    mostrarNotebook(aNotebooks[e],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                    flag = 1;
                }
            }
        }
        else
        {
            printf("No se encontro el id del tipo\n");
        }
        printf("|_____|__________|________|____________|___________|__________|\n");
        if(!flag)
        {
            printf("\n          NO EXISTEN NOTEBOOKS DE ESE TIPO");
        }
        printf("\n\n");
        todoBien = 1;
    }

    return todoBien;

}

int listarNotebookMarca(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int flag = 0;
    int idMarca;
    char descripcion[20];

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        listarMarcas(aMarcas,tamM);
        getValidInt("Ingrese el id de la marca: ","\nEl id es invalido.Reingrese el id de la marca.","Solo permite de (1000 a 1003)",1000,1003,&idMarca);

        if(validarMarca(aMarcas,tamM,idMarca))
        {
            cargarMarcaDescripcion(aMarcas,tamM,idMarca,descripcion);
            printf("\n          *** LISTA DE NOTEBOOKS DE MARCA %s ***\n\n",descripcion);
            printf("---------------------------------------------------------------\n");
            printf("| ID  |  MODELO  |  MARCA |    TIPO    |  PRECIO   | CLIENTE  |\n");
            printf("---------------------------------------------------------------\n");
            for(int e; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idMarca == idMarca)
                {
                    mostrarNotebook(aNotebooks[e],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                    flag = 1;
                }
            }
        }
        else
        {
            printf("No se encontro el id de la marca\n");
        }
        printf("|_____|__________|________|____________|___________|__________|\n");
        if(!flag)
        {
            printf("\n          NO EXISTEN NOTEBOOKS DE ESA MARCA");
        }
        printf("\n\n");
        todoBien = 1;
    }

    return todoBien;

}

int listarNotebookMasBarata(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int masBarata = 0;
    int flag = 0;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        for(int e=0; e<tam; e++)
        {
            if(!aNotebooks[e].isEmpty && (aNotebooks[e].precio < masBarata || !flag))
            {
                masBarata = aNotebooks[e].precio;
                flag = 1;
            }

        }
        if(flag)
        {
            printf("\n            *** LISTA DE NOTEBOOKS CON MENOR PRECIO ***\n\n");
            printf("---------------------------------------------------------------\n");
            printf("| ID  |  MODELO  |  MARCA |    TIPO    |  PRECIO   | CLIENTE  |\n");
            printf("---------------------------------------------------------------\n");
            for(int e=0; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].precio == masBarata )
                {
                    mostrarNotebook(aNotebooks[e],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                }
            }
            printf("|_____|__________|________|____________|___________|__________|\n");
            printf("\n\n");
        }
        todoBien = 1;
    }

    return todoBien;
}

int listarNotebooksPorMarcas(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int flag;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        system("cls");
        printf("   *** LISTA DE NOTEBOOKS POR MARCA *** \n\n");

        for(int m=0; m<tamM; m++)
        {
            printf("La marca: %s \n\n",aMarcas[m].descripcion);
            printf("---------------------------------------------------------------\n");
            printf("| ID  |  MODELO  |  MARCA |    TIPO    |  PRECIO   | CLIENTE  |\n");
            printf("---------------------------------------------------------------\n");
            flag = 0;
            for(int e=0; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idMarca == aMarcas[m].id)
                {
                    mostrarNotebook(aNotebooks[e],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                    flag = 1;
                }
            }
            if(!flag)
            {
                printf("         NO EXISTEN NOTEBOOKS DE ESA MARCA\n\n");
            }
            printf("|_____|__________|________|____________|___________|__________|\n");
            printf("\n\n");
        }
        todoBien = 1;
    }

    return todoBien;
}

int listarCantidadMarcaTipo(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int idMarca;
    int idTipo;
    char descMarca[20];
    char descTipo[20];
    int contCantidadTipo = 0;
    int contCantidadMarca = 0;
    int flag = 0;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        listarMarcas(aMarcas,tamM);
        getValidInt("Ingrese el id de la marca: ","\nEl id es invalido.Reingrese el id de la marca.","Solo permite de (1000 a 1003)",1000,1003,&idMarca);

        listarTipos(aTipos,tamT);
        getValidInt("Ingrese el id del tipo: ","\nEl id es invalido.Reingrese el id del tipo.","Solo permite de (5000 a 5003)",5000,5003,&idTipo);

        if(validarMarca(aMarcas,tamM,idMarca) && validarTipo(aTipos,tamT,idTipo))
        {
            for(int e; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idMarca == idMarca)
                {
                    contCantidadMarca++;
                    flag = 1;
                }
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idTipo == idTipo)
                {
                    contCantidadTipo++;
                    flag  = 1;
                }
            }
        }
        if(!flag)
        {

            printf("\nNo hay una notebook con esa marca y tipo.\n");
        }
        else
        {
            cargarMarcaDescripcion(aMarcas,tamM,idMarca,descMarca);
            cargarTipoDescripcion(aTipos,tamT,idTipo,descTipo);
            printf("\nLa Notebook de la marca %s hay %d en total.\n",descMarca,contCantidadMarca);
            printf("\nLa Notebook del tipo %s hay %d en total.\n",descTipo,contCantidadTipo);
        }
        todoBien = 1;
    }

    return todoBien;
}

int listarMarcaMasElegida(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int masElegido = 0;
    int flag = 0;
    int totalElegido[tamM];

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        for(int m=0; m<tamM; m++)
        {
            totalElegido[m] = 0;
        }

        for(int m=0; m<tamM; m++)
        {
            for(int e=0; e<tam; e++)
            {
                if(!aNotebooks[e].isEmpty && aNotebooks[e].idMarca == aMarcas[m].id)
                {
                    totalElegido[m]+=1;
                }
            }
        }

        for(int m=0; m<tamM; m++)
        {
            if(!flag || totalElegido[m] > masElegido)
            {
                masElegido = totalElegido[m];
                flag = 1;
            }
        }
        printf("\n");
        for(int m=0; m<tamM; m++)
        {
            if(totalElegido[m] == masElegido)
            {
                printf("La marca mas elegida por los clientes es %s\n",aMarcas[m].descripcion);
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int listarNoteboksTrabajo(eNotebook aNotebooks[], int tam, eTrabajo aTrabajos[], int tamTrab, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int idNotebook;
    char descripcion[20];
    int flag = 0;

    if(aNotebooks != NULL && aTrabajos != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamTrab > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        listaNotebooks(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);
        printf("Elija un id de la Notebook: ");
        scanf("%d",&idNotebook);

        if(validarNotebook(aNotebooks,tam,idNotebook))
        {
            cargarNotebookDescripcion(aNotebooks,tam,idNotebook,descripcion);
            printf("\n  *** LISTA DE NOTEBOOKS DE MODELO %s ***\n\n",descripcion);
            printf("--------------------------------------------\n");
            printf("| ID  |  Notebook |  Servicio |   Fecha    |\n");
            printf("--------------------------------------------\n");

            for(int t=0 ; t<tamTrab; t++)
            {
                if(!aTrabajos[t].isEmpty && aTrabajos[t].idNotebook == idNotebook)
                {
                    mostrarTrabajo(aTrabajos[t],aNotebooks,tam,aServicios,tamS);
                    flag = 1;
                }
            }

        }
        else
        {
            printf("No se encontro el id de esa notebook\n");
        }
        printf("|_____|___________|_________|____________|\n");
        if(!flag)
        {
            printf("\nLA NOTEBOOK SELECIONADA NO TIENE UN TRABAJO REALIZADO\n");
        }
        printf("\n\n");
        todoBien = 1;

        todoBien = 1;
    }

    return todoBien;
}
