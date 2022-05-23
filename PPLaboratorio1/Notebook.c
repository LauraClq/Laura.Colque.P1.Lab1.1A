#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebook.h"
#include "Menu.h"
#include "Informes.h"
#include "Utn.h"
#define ERROR_MESSAGE "\nDato ingresado invalido, solo permite letras: \n"
#define ERROR_LENGH "\nError se exedio del limite de caracteres"
#define ERROR_FLOAT "\nDato ingresado invalido, solo se permite numeros flotantes"
#define ERROR "Error, solo ingrese del 1000 al 15000\n"
#define LOW 1000
#define HIGH 15000
#define TAM_LENGH 20

int listaNotebooks(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int flag = 0;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        //system("cls");
        printf("\n                  *** LISTA DE NOTEBOOKS ***\n");
        printf("---------------------------------------------------------------\n");
        printf("| ID  |  MODELO  |  MARCA |    TIPO    |  PRECIO   | CLIENTE  |\n");
        printf("---------------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(!aNotebooks[i].isEmpty)
            {
                mostrarNotebook(aNotebooks[i],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                todoBien = 1;
                flag = 1;
            }
        }
        printf("|_____|__________|________|____________|___________|__________|\n");
        if(!flag)
        {
            printf("\n  NO HAY NOTEBOOKS REGISTRADAS");
        }
        printf("\n\n");
    }

    return todoBien;
}

int mostrarNotebook(eNotebook n, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    char descMarca[20];
    char descTipo[20];
    char descCliente[20];
    int retornoMarca;
    int retornoTipo;
    int retornoCliente;

    retornoMarca = cargarMarcaDescripcion(aMarcas,tamM,n.idMarca,descMarca);
    retornoTipo = cargarTipoDescripcion(aTipos,tamT,n.idTipo,descTipo);
    retornoCliente = cargarClienteDescripcion(aClientes,tamC,n.idCliente,descCliente);

    if(aMarcas != NULL && aTipos != NULL && aClientes != NULL && tamM > 0 && tamT > 0 && tamC > 0 && retornoMarca && retornoTipo && retornoCliente)
    {
        printf("| %3d | %8s | %6s | %10s |  %3.2f  | %7s  |\n",
               n.id,
               n.modelo,
               descMarca,
               descTipo,
               n.precio,
               descCliente);

        todoBien = 1;
    }

    return todoBien;
}

int ordenarNotebooks(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    eNotebook auxNotebook;

    if(aNotebooks != NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if( (!aNotebooks[i].isEmpty && aNotebooks[i].idMarca > aNotebooks[j].idMarca ) || (aNotebooks[i].idMarca == aNotebooks[j].idMarca && aNotebooks[i].precio > aNotebooks[j].precio) )
                {
                    auxNotebook = aNotebooks[i];
                    aNotebooks[i] = aNotebooks[j];
                    aNotebooks[j] = auxNotebook;
                }
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int initNotebooks(eNotebook aNotebooks[], int tam)
{
    int todoBien = 0;
    if(aNotebooks != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            aNotebooks[i].isEmpty = 1;
        }
        todoBien = 1;
    }

    return todoBien;
}

int buscarNotebookLibre(eNotebook aNotebooks[], int tam, int* pIndice)
{
    int todoBien = 0;

    if(aNotebooks != NULL && pIndice != NULL && tam > 0)
    {
        *pIndice = -1;

        for(int i=0; i<tam; i++)
        {
            if(aNotebooks[i].isEmpty)
            {
                *pIndice = i;
                break;
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int buscarNotebookId(eNotebook aNotebooks[], int tam, int id, int* pIndice)
{
    int todoBien = 0;

    if(aNotebooks != NULL && pIndice != NULL && tam > 0 && id > 0)
    {
        *pIndice = -1;
        for(int i=0; i<tam; i++)
        {
            if(!aNotebooks[i].isEmpty && aNotebooks[i].id == id)
            {
               *pIndice = i;
               break;
            }
        }
        todoBien = 1;
    }

    return todoBien;
}

int altaNotebook(eNotebook aNotebooks[], int tam, eMarca aMarca[], int tamM, eTipo aTipo[], int tamT, eCliente aClientes[], int tamC, int* pId)
{
    int todoBien = 0;
    int indice;
    int validString;
    int validFloat;
    int validIntM;
    int validIntT;
    int validIntC;

    eNotebook auxNote;

    if(aNotebooks != NULL && aMarca != NULL && aTipo != NULL && aClientes != NULL && pId != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** ALTA NOTEBOOK ***    \n");
        printf("-------------------------------------\n");
        if(buscarNotebookLibre(aNotebooks,tam,&indice))
        {
            if(indice != -1)
            {
                validString = getValidString("Ingrese el modelo: ",ERROR_MESSAGE,ERROR_LENGH,auxNote.modelo,TAM_LENGH);
                validFloat = getValidFloat("Ingrese el precio: ",ERROR_FLOAT,ERROR,LOW,HIGH,&auxNote.precio);

                listarMarcas(aMarca,tamM);
                validIntM = getValidInt("Ingrese el id de la marca: ","\nEl id es invalido.Reingrese el id de la marca.","Solo permite de (1000 a 1003)",1000,1003,&auxNote.idMarca);

                listarTipos(aTipo,tamT);
                validIntT = getValidInt("Ingrese el id del tipo: ","\nEl id es invalido.Reingrese el id del tipo.","Solo permite de (5000 a 5003)",5000,5003,&auxNote.idTipo);

                listarClientes(aClientes,tamC);
                validIntC = getValidInt("Ingrese el id del cliente: ","\nEl id es invalido.Reingrese el id del cliente.","Solo permite de (100 a 109)",100,109,&auxNote.idCliente);


                if(!validString && !validFloat && !validIntM && !validIntT && !validIntC)
                {
                    auxNote.isEmpty = 0;
                    auxNote.id = *pId;
                    (*pId)++;
                    aNotebooks[indice] = auxNote;
                }
            }
            else
            {
                printf("No hay lugar en el sistema\n");
            }
            todoBien = 1;
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return todoBien;
}

int modificarNotebook(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int idModificar;
    int indice;
    char salir;
    eNotebook auxNote;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0&& tamM > 0 && tamT > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** MODIFICAR NOTEBOOK ***    \n");
        printf("-------------------------------------\n");
        listaNotebooks(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);

        printf("Ingrese el id de la notebook a modificar: ");
        scanf("%d",&idModificar);

        if(buscarNotebookId(aNotebooks,tam,idModificar,&indice))
        {
            if(indice != -1)
            {
                printf("\n");
                mostrarNotebook(aNotebooks[indice],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                system("pause");
                do
                {
                    switch(subMenuOpciones())
                    {
                    case 1:
                        getValidFloat("Ingrese el precio: ",ERROR_FLOAT,ERROR,LOW,HIGH,&auxNote.precio);
                        aNotebooks[indice].precio = auxNote.precio;
                        todoBien = 1;
                        break;
                    case 2:
                        listarTipos(aTipos,tamT);
                        getValidInt("Ingrese el id del tipo: ","\nEl id es invalido.Reingrese el id del tipo.","Solo permite de (5000 a 5003)",5000,5003,&auxNote.idTipo);
                        aNotebooks[indice].idTipo = auxNote.idTipo;
                        todoBien = 1;
                        break;
                    case 3:
                        salir = confirmacion("Desea salir? s/n: ");
                        break;
                    default:
                        printf("Opcion invalida\n");
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');
            }
            else
            {
               printf("No se encontro el id de la notebook: %d\n",idModificar);
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar la notebook\n");
        }
    }

    return todoBien;
}

int bajaNotebook(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC)
{
    int todoBien = 0;
    int indice;
    int idBaja;
    char confirmar;

    if(aNotebooks != NULL && aMarcas != NULL && aTipos != NULL && aClientes != NULL && tam > 0 && tamM > 0 && tamT > 0 && tamC > 0)
    {
        system("cls");
        printf("    *** DAR DE BAJA NOTEBOOK ***    \n");
        printf("-------------------------------------\n");
        listaNotebooks(aNotebooks,tam,aMarcas,tamM,aTipos,tamT,aClientes,tamC);

        printf("Ingrese el id del notebook a dar de baja: ");
        scanf("%d",&idBaja);

        if(buscarNotebookId(aNotebooks,tam,idBaja,&indice))
        {
            if(indice != -1)
            {
                printf("\n");
                mostrarNotebook(aNotebooks[indice],aMarcas,tamM,aTipos,tamT,aClientes,tamC);
                confirmar = confirmacion("\nConfirma a dar de baja?: ");

                if(confirmar != 's')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    aNotebooks[indice].isEmpty = 1;
                    todoBien = 1;
                }
            }
            else
            {
                printf("No hay un notebook con ese id %d\n",idBaja);
            }

        }
        else
        {
            printf("Ocurrio un problema al buscar al id del notebook\n");
        }
    }
    return todoBien;
}

int hardcodearNotebooks(eNotebook aNotebooks[], int tam, int cant, int* pId)
{
    int todoBien = 0;
    eNotebook hardcodeo[] =
    {
        {0, "Lenovo",1003,5000,1000,100,0},
        {0, "Mac",1003,5000,1500,104,0},
        {0, "Asus",1001,5001,1000.34,101,0},
        {0, "Atari",1003,5002,7000,102,0},
        {0, "BBM",1000,5002,2000,103,0},
        {0, "Mac",1002,5003,11000,102,0},
        {0, "Asus",1002,5003,14000,104,0},
        {0, "Mac",1002,5002,12000,101,0}
    };

    if(aNotebooks != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            aNotebooks[i] = hardcodeo[i];
            aNotebooks[i].id = *pId;
            (*pId)++;

        }
        todoBien = 1;
    }
    return todoBien;
}

int cargarNotebookDescripcion(eNotebook aNotebooks[], int tam, int id, char descripcion[])
{
    int todoBien = 0;
    int indice;
    int retorno;

    retorno = buscarNotebookId(aNotebooks,tam,id,&indice);

    if(aNotebooks != NULL && descripcion != NULL && tam > 0 && id > 0 && retorno && indice != -1)
    {
       strcpy(descripcion,aNotebooks[indice].modelo);
       todoBien = 1;
    }

    return todoBien;
}

int validarNotebook(eNotebook aNotebooks[], int tam, int id)
{
    int todoBien = 0;
    int indice;
    int retorno;

    if(aNotebooks != NULL && tam > 0 && id > 0)
    {
        retorno = buscarNotebookId(aNotebooks,tam,id,&indice);
        if(retorno && indice != -1)
        {
            todoBien = 1;
        }
    }

    return todoBien;
}
