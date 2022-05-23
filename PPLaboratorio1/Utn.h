#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

void getString(char mensaje[],char input[]);

int getValidString(char requestMessage[],char errorMessage[],char errorMessageLenght[],char input[], int longitud);
int getStringLetras(char mensaje[],char input[]);
int esLetras(char* cadena);

int getValidFloat(char requestMessage[],char errorMessage[], char errorMessageLenght[], float lowLimit, float hiLimit, float* pResultado);
int getStringFloat(char mensaje[],char input[]);
int esFlotante(char* cadena);

int getValidInt(char requestMessage[],char errorMessage[], char errorMessageLenght[], int lowLimit, int hiLimit,int* pResultado);
int getStringEnteros(char mensaje[],char input[]);
int esNumero(char str[]);

char confirmacion(char mensaje[]);
//int getValidChar(char requestMessage[],char errorMenssage[],char* input);
//int getChar(char mensaje[], char input);

#endif // UTN_H_INCLUDED
