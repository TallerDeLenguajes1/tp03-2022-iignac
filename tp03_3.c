#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}typedef Cliente;

void MostrarClientes(Cliente *PuntClientes, int CantidadClientes); //muestra todos los clientes y sus productos
float TotalProducto(Producto Prod); //calcula el costo total de un producto
void LiberarMemoria(Cliente *PuntClientes, int CantidadClientes); //liberar memoria dinamica

void main()
{   srand((float)time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    char *Buff = (char *)malloc(50*sizeof(char)); //puntero auxiliar de tipo char

    int CantidadClientes;
    printf("==== Ingrese la cantidad de clientes (<=5) ====\n");
    scanf("%d",&CantidadClientes);
    fflush(stdin);

    //reservo memoria dinamica para el arreglo de esctucturas, segun la cantidad de clientes
    Cliente *PuntClientes = (Cliente *)malloc(CantidadClientes*sizeof(Cliente));

   
    //CARGO LOS CLIENTES Y SUS PRODUCTOS
    for (int i = 0; i < CantidadClientes; i++)
    {   
        printf("===== Cargue los datos del cliente %d =====\n",i+1);
        
        PuntClientes[i].ClienteID = i+1;
        
        printf("Ingrese el nombre del cliente %d:\n");
        gets(Buff);
        
        //reservo memoria dinamica para guardar el nombre del cliente
        PuntClientes[i].NombreCliente = (char *)malloc((strlen(Buff)+1)*sizeof(char)); 
        strcpy(PuntClientes[i].NombreCliente, Buff);

        PuntClientes[i].CantidadProductosAPedir = 1+(rand()%5);

        //reservo memoria dinamica (apuntada por el puntero "Productos") para guardar los productos del cliente
        PuntClientes[i].Productos = (Producto *)malloc(PuntClientes[i].CantidadProductosAPedir*sizeof(Producto));

        
        //CARGO LOS PRODUCTOS DEL CLIENTE
        for (int j = 0; j < PuntClientes[i].CantidadProductosAPedir; j++)
        {
            PuntClientes[i].Productos[j].ProductoID = j+1;
            PuntClientes[i].Productos[j].Cantidad = 1+(rand()%10);

            
            ////////CARGAR "TipoProducto"

            //copio el nombre de un tipo de producto aleatorio en "Buff"
            strcpy(Buff, TiposProductos[rand()%5]); 

            //reservo memoria dinamica para guardar el nombre del tipo de producto en "TipoProducto"
            PuntClientes[i].Productos[j].TipoProducto = (char *)malloc((strlen(Buff)+1)*sizeof(char)); 
            
            ////copio el nombre del tipo de producto en "TipoProducto"
            strcpy(PuntClientes[i].Productos[j].TipoProducto, Buff);
            
            //////////////////

            PuntClientes[i].Productos[j].PrecioUnitario = 10+(rand()%91);
        }        
    }

    printf("\n");
    
    //mostrar todos los clientes y sus productos
    MostrarClientes(PuntClientes, CantidadClientes);

    //Liberar memoria dinamica
    LiberarMemoria(PuntClientes, CantidadClientes);

    //liberar memoria dinamica reservada para el Buff
    free(Buff);
}

void MostrarClientes(Cliente *PuntClientes, int CantidadClientes)
{
    float TotalProductos;
    printf("-------------------------\n");
    printf("CLIENTES Y SUS PRODUCTOS\n");
    printf("-------------------------\n");
    for (int i = 0; i < CantidadClientes; i++)
    {
        printf("**** Datos del cliente %d ****\n",i+1);
        printf("Cliente ID: %d\n",PuntClientes[i].ClienteID);
        printf("Nombre: %s\n",PuntClientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n",PuntClientes[i].CantidadProductosAPedir);
        printf("\n");

        printf("**** Productos del cliente %d ****\n",i+1);
        TotalProductos = 0;
        for (int j = 0; j < PuntClientes[i].CantidadProductosAPedir; j++)
        {  
            printf("--- Producto %d ---\n",j+1);
            printf("Producto ID: %d\n",PuntClientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n",PuntClientes[i].Productos[j].Cantidad);
            printf("Tipo: %s\n",PuntClientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n",PuntClientes[i].Productos[j].PrecioUnitario);
            TotalProductos += TotalProducto(PuntClientes[i].Productos[j]);
            printf("\n");
        }
        printf("Total a pagar del cliente %d: %.2f\n",i+1,TotalProductos);
        printf("\n");
    }
}

float TotalProducto(Producto Prod) // recibe una estructura producto
{
    return Prod.Cantidad * Prod.PrecioUnitario;
}

void LiberarMemoria(Cliente *PuntClientes, int CantidadClientes)
{
    for (int i = 0; i < CantidadClientes; i++)
    {
        for (int j = 0; i < PuntClientes[i].CantidadProductosAPedir; j++)
        {
            free(PuntClientes[i].Productos[j].TipoProducto);
        }
        
        free(PuntClientes[i].Productos);

        free(PuntClientes[i].NombreCliente);
    }
    free(PuntClientes);
}