#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
typedef struct
{
   int id;
   char descripcion[25];
   float precio;

}eServicio;
#endif // SERVICIO_H_INCLUDED
int listarServicios(eServicio aServicios[], int tam);
int buscarServicioId(eServicio aServicios[], int tam, int id, int* pIndice);
int cargarServicioDescripcion(eServicio aServicios[], int tam, int id, char descripcion[]);
int validarServicio(eServicio aServicios[], int tam, int id);
