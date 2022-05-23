#include "Marca.h"
#include "Tipo.h"
#include "Cliente.h"
#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED
typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int idCliente;
    int isEmpty;

}eNotebook;

#endif // NOTEBOOK_H_INCLUDED

char menuOpciones();
int subMenuOpciones();

int listaNotebooks(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int mostrarNotebook(eNotebook n, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int ordenarNotebooks(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
/*------------------------------------------ABM-------------------------------------------------*/
int hardcodearNotebooks(eNotebook aNotebooks[], int tam, int cant, int* pId);
int initNotebooks(eNotebook aNotebooks[], int tam);
int buscarNotebookLibre(eNotebook aNotebooks[], int tam, int* pIndice);
int buscarNotebookId(eNotebook aNotebooks[], int tam, int id, int* pIndice);
int altaNotebook(eNotebook aNotebooks[], int tam, eMarca aMarca[], int tamM, eTipo aTipo[], int tamT, eCliente aClientes[], int tamC, int* pId);
int modificarNotebook(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int bajaNotebook(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int cargarNotebookDescripcion(eNotebook aNotebooks[], int tam, int id, char descripcion[]);
int validarNotebook(eNotebook aNotebooks[], int tam, int id);
