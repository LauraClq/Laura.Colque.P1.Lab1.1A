#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];

}eTipo;
#endif // TIPO_H_INCLUDED
int listarTipos(eTipo aTipos[], int tam);
int buscarTipoId(eTipo aTipos[], int tam, int idTipo, int* pIndice);
int cargarTipoDescripcion(eTipo aTipos[], int tam, int id, char descripcion[]);
int validarTipo(eTipo aTipos[], int tam, int id);
