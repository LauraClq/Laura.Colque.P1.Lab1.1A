#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eMarca;
#endif // MARCA_H_INCLUDED
int listarMarcas(eMarca aMarcas[], int tam);
int buscarMarcaId(eMarca aMarcas[], int tam, int idMarca, int* pIndice);
int cargarMarcaDescripcion(eMarca aMarcas[], int tam, int id, char descripcion[]);
int validarMarca(eMarca aMarcas[], int tam, int id);
