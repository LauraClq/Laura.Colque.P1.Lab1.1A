#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Notebook.h"
#include "Trabajo.h"
int InformesGenerales(eNotebook aNotebooks[], int tam, eTrabajo aTrabajos[], int tamTrab, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
//--------------------------------------------INFORMES------------------------------------------------------------------//
int listarNotebookTipo(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarNotebookMarca(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarNotebookMasBarata(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarNotebooksPorMarcas(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarCantidadMarcaTipo(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarMarcaMasElegida(eNotebook aNotebooks[], int tam, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
int listarNoteboksTrabajo(eNotebook aNotebooks[], int tam, eTrabajo aTrabajos[], int tamTrab, eServicio aServicios[], int tamS, eMarca aMarcas[], int tamM, eTipo aTipos[], int tamT, eCliente aClientes[], int tamC);
#endif // INFORMES_H_INCLUDED
