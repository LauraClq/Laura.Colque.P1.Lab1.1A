#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"

char menuOpciones()
{
    char opcion;

    system("cls");
    printf("    *** MENU DE OPCIONES ***\n");
    printf("A. ALTA NOTEBOOK\n");
    printf("B. MODIFICAR NOTEBOOK\n");
    printf("C. BAJA NOTEBOOK\n");
    printf("D. LISTAR NOTEBOOK\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR TIPOS\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. INFORMES\n");
    printf("K. SALIR\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion = toupper(opcion);
    return opcion;
}

int subMenuOpciones()
{
    int opcion;
    system("cls");
    printf("  ** Menu de campos a modificar **\n");
    printf("1. Precio\n");
    printf("2. Tipo\n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ** Menu de Informes**\n");
    printf("1. Lista de notebooks por tipo seleccionado\n");
    printf("2. Lista de notebooks por marca seleccionada\n");
    printf("3. Lista de notebooks por el precio mas barato\n");
    printf("4. Listas de notebooks por cada marca\n");
    printf("5. Cantidad de notebooks por marca y tipo\n");
    printf("6. Marca mas elegida\n");
    printf("7. Lista de trabajos por id notebook seleccionado\n");
    printf("8. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
