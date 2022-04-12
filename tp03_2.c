#include<stdio.h>
#include<stdlib.h> //libreria para usar malloc
#include<string.h> //libreria para usar strlen y strcpy

int main()
{
    char *V[5]; //vector de punteros char
    char *buff; //puntero (variable) auxiliar que recibe los nombres que se ingresan

    buff = (char *)malloc(50*sizeof(char)); //aux apunta al primer elemento de donde se hizo la reserva dinamica

    //cargar vector de punteros con nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d:\n",i+1);
        
        gets(buff);

        //reservo memoria dinamica tomando en cuenta la longitud de la cadena buff
        V[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));
        //strlen devuelve la longitud de la cadena sin tomar en cuenta el caracter de final de cadena '\0'
        //sumo 1 para dejar lugar para el caracter de final de cadena
        
        strcpy(V[i], buff);
        //copio el contenido de buff a uno de los elementos del vector V. Se incluye el terminador '\0'. Retorna V[i]
    }

    printf("\n");

    //muestro los nombres del vector de punteros
    for (int i = 0; i < 5; i++)
    {   
        printf("Nombre %d: ",i+1); // printf("Nombre %d: %s",i+1,V[i]) y no poner el puts debajo
        puts(V[i]);
    }

    //libero la memoria reservada para los nombres
    for (int i = 0; i < 5; i++)
    {
        free(V[i]);
    }   

    //libero la memoria reservada para buff
    free(buff);
    
    return 0;
}
