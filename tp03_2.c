#include<stdio.h>
#include<stdlib.h> //libreria para usar malloc
#include<string.h> //libreria para usar strlen y strcpy

int main()
{
    char *V[5]; //vector de punteros char
    char *buff; //puntero (variable) auxiliar que recibe los nombres que se ingresan

    //reservo memoria dinamica para buff. buff apunta a la primera direccion reservada
    buff = (char *)malloc(50*sizeof(char));

    //cargar vector de punteros con nombres
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d:\n",i+1);
        
        gets(buff);

        //reservo memoria dinamica tomando en cuenta la "longitud de la cadena buff"
        //y "sumo 1" (para dejar lugar al caracter de final de cadena '\0')
        //strlen devuelve la longitud de la cadena sin tomar en cuenta el caracter de final de cadena
        V[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));
        
        //copio el contenido de buff a uno de los elementos del vector V
        //strcpy incluye el terminador '\0'. Retorna V[i]
        strcpy(V[i], buff);
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


/* VERSION USANDO FUNCIONES

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cargarNombres(char *V[], char *buff);
void mostrarNombres(char *V[]);
void liberarMemoria(char *V[], char *buff);

void main()
{
    char *V[5];
    char *buff;
    buff = (char *)malloc(50*sizeof(char));

    cargarNombres(V, buff);

    printf("\n");

    mostrarNombres(V);

    liberarMemoria(V, buff);
}

void cargarNombres(char *V[], char *buff)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d:\n",i+1);
        gets(buff);

        V[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));

        strcpy(V[i], buff);
    }
}

void mostrarNombres(char *V[])
{
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: ",i+1);
        puts(V[i]);
    }
}

void liberarMemoria(char *V[], char *buff)
{
    for (int i = 0; i < 5; i++)
    {
        free(V[i]);
    }
    
    free(buff);
}
*/