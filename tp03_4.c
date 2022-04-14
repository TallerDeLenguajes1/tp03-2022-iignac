#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

int main()
{
    char **V; // puntero doble que apunta a las filas de la matriz
    char *buff; 
    int cantNombres;

    printf("Indique la cantidad de nombres que ingresara: \n");
    scanf("%d",&cantNombres);
    fflush(stdin);

    V = (char **)malloc(cantNombres*sizeof(char*));
    // reservo memoria dinamica para la cantidad de filas
    // "cantNombres" = cantidad de filas. Las filas estan apuntadas por el puntero doble
    // cada fila es un puntero simple

    buff = (char *)malloc(50*sizeof(char));

    //CARGAR NOMBRES
    for (int i = 0; i < cantNombres; i++)
    {
        printf("Ingrese el nombre %d:\n",i+1);
        gets(buff);

        V[i] = (char *)malloc((strlen(buff)+1)*sizeof(char));
        // V[i] son las filas, los punteros simples
        // En cada puntero simple (fila) reservo memoria para las columnas
        // la cantidad de columnas es la cantidad de caracteres de cada nombre
    
        strcpy(V[i], buff);
    }
    ///////////
        
    printf("\n");

    //MOSTRAR NOMBRES
    for (int i = 0; i < cantNombres; i++)
    {   
        printf("Nombre %d: ",i+1);
        puts(V[i]);
    }
    ///////////

    
    //libero las memorias
    for (int i = 0; i < cantNombres; i++)
    {
        free(V[i]);
        //memoria de los punteros simples
    }   

    free(V);
    //memoria del puntero doble

    free(buff);
    //memoria del buff

    
    return 0;
}