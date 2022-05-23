#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int idCliente;
    char nombre[20];
    char sexo;

}eCliente;
#endif // CLIENTE_H_INCLUDED
int listarClientes(eCliente aClientes[],int tam);
int cargarClienteDescripcion(eCliente aClientes[], int tam, int id, char descripcion[]);
int buscarClienteId(eCliente aClientes[], int tam, int id, int* pIndice);

