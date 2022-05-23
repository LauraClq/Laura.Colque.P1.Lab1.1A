#include "Notebook.h"
#include "Servicio.h"
#include "Fecha.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
typedef struct
{
   int id;
   int idNotebook;
   int idServicio;
   eFecha fecha;
   int isEmpty;

}eTrabajo;
#endif // TRABAJO_H_INCLUDED
int listarTrabajos(eTrabajo aTrabajos[], int tam, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS);
int mostrarTrabajo(eTrabajo unTrabajo, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS);
int initTrabajos(eTrabajo aTrabajos[], int tam);
int buscarTrabajoLibre(eTrabajo aTrabajos[], int tam, int* pIndex);
int altaTrabajo(eTrabajo aTrabajos[], int tam, eNotebook aNotebooks[], int tamN, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC, int* pId);
int hardcodearTrabajos(eTrabajo aTrabajos[], int tam, int cant, int* pId);
