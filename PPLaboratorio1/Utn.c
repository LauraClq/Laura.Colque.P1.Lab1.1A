#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int longitud)
{
    int retorno = -1;
    char buffer[100];

    while(1) //intera infinitamente
    {
        if(!getStringLetras(requestMessage,buffer))
        {
            printf ("%s\n",errorMessage);//Error de que contiene numeros
            continue;
        }
        if(strlen(buffer) >= longitud)
        {
            printf ("%s",errorMessageLenght); //Error del tamanio
            continue;
        }
        retorno = 0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esLetras(char* cadena) //es letras
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int getValidFloat(char requestMessage[],char errorMessage[], char errorMessageLenght[], float lowLimit, float hiLimit, float* pResultado)
{
    char buffer[256];
    float auxFloat;
    int Retorno = -1;

    while(1)
    {
        if(!getStringFloat(requestMessage,buffer))
        {
            printf("%s\n",errorMessage);
            continue;
        }
        auxFloat = atof(buffer);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf("%s\n",errorMessageLenght);
            continue;
        }
        Retorno = 0;
        *pResultado = auxFloat;
        break;
    }

    return Retorno;
}

int getStringFloat(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esFlotante(char* cadena)
{
    int retorno = 1;
    int contadorPuntos = 0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(int i=0 ; cadena[i] != '\0'; i++)
        {
            if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
            {
                continue;
            }
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int getValidInt(char requestMessage[],char errorMessage[], char errorMessageLenght[], int lowLimit, int hiLimit,int* pResultado)
{
    char auxStr[256];
    int auxInt;
    int Retorno = -1;
    while(1)
    {
        if(!getStringEnteros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage); //Error de que contiene numeros
            continue;
        }

        auxInt = atoi(auxStr);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s\n",errorMessageLenght);
            continue;
        }

        Retorno = 0;
        *pResultado = auxInt;
        break;

    }

    return Retorno;
}

int getStringEnteros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumero(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumero(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

char confirmacion(char mensaje[])
{
    char confirma;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&confirma);

    confirma = tolower(confirma);

    while(confirma != 's' && confirma != 'n')
    {
        printf("Error. Ingrese s si desea continuar o n para salir: ");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma = tolower(confirma);
    }

    return confirma;
}
/*
int getValidChar(char requestMessage[],char errorMenssage[],char* input)
{
    int retorno = -1;
    char buffer;

    while(1) //intera infinitamente
    {
        if(!getChar(requestMessage,buffer))
        {
            printf ("%s\n",errorMenssage);//Error de que contiene numeros
            continue;
        }
        retorno = 0;
        *input = buffer;
        break;
    }
    return retorno;
}

int getChar(char mensaje[], char input)
{
    int Retorno = 1;

    printf("%s",mensaje);
    scanf("%c",&input);
    input = tolower(input);

    while(input != 's' || input != 'n')
    {
        Retorno = 0;
    }

    return Retorno;
}*/
