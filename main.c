#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <stdbool.h>

typedef struct Cancion {
    char *nombre;
    char *artista;
    List *generos;
    char *anno;
    char *numLista;
} Cancion;

typedef struct
{
    char *nombre;
    int cantidad;
}tipoArreglo;

tipoArreglo* aumentarMemoria(tipoArreglo*,int);
void menuImportar(List*);
void menuExportar(List*);
void menuAgregarCancion(List*);
void menuBuscarPorNombre(List*);
void menuBuscarPorArtista(List*);
void menuBuscarPorGenero(List*);
void menuEliminarCancion(List*);
void menuMostrarListas(List*);
void menuMostrarLista(List*);
void menuMostrarCanciones(List*);


int main()
{
    List *listaGlobal = createList(); // lista que guarda todas las canciones
    unsigned int opcion = 0;
    while (1) {
        printf("| Menu |\n");
        printf("Para elegir una opción introduzca el número correspondiente:\n");

        printf(" 1. Importar canciones desde un archivo CSV\n");
        printf(" 2. Exportar canciones a un archivo CSV\n");
        printf(" 3. Agregar canción\n");
        printf(" 4. Buscar canción por nombre\n");
        printf(" 5. Buscar canción por artista\n");
        printf(" 6. Buscar canción por género\n");
        printf(" 7. Eliminar canción\n");
        printf(" 8. Mostrar listas de reproducción\n");
        printf(" 9. Mostrar una lista de reproducción\n");
        printf(" 10. Mostrar todas las canciones\n");
        printf(" 0. Cerrar\n");

        scanf(" %u", &opcion);

        if (opcion == 0) break;
        if (opcion == 1) menuImportar(listaGlobal);
        if (opcion == 2) menuExportar(listaGlobal);
        if (opcion == 3) menuAgregarCancion(listaGlobal);
        if (opcion == 4) menuBuscarPorNombre(listaGlobal);
        if (opcion == 5) menuBuscarPorArtista(listaGlobal);
        if (opcion == 6) menuBuscarPorGenero(listaGlobal);
        if (opcion == 7) menuEliminarCancion(listaGlobal);
        if (opcion == 8) menuMostrarListas(listaGlobal);
        if (opcion == 9) menuMostrarLista(listaGlobal);
        if (opcion == 10) menuMostrarCanciones(listaGlobal);
        if (opcion > 10){
            printf("Por favor introduzca un número entre 0 y 10\n");
        }
    }
    return 0;
}

void esperarEnter()
{
    printf("Presione ENTER para continuar\n");
    getchar();getchar();
}

tipoArreglo* aumentarMemoria(tipoArreglo* arreglo, int tamano)
{
    arreglo = (tipoArreglo*) realloc (arreglo, tamano * sizeof(tipoArreglo));
    if(arreglo == NULL)return NULL;
    return arreglo;
}

void printCancion(Cancion *cancion)
{
    printf("%s, %s, \"",cancion->nombre,cancion->artista);
    char *genero = firstList(cancion->generos);
    while (1){
        printf("%s",genero);
        genero = nextList(cancion->generos);
        if (genero == NULL) break;
        printf(" ");
    }
    printf("\", %s, %s\n", cancion->anno,cancion->numLista);
    return;
}

Cancion *leerLinea (char *linea)
{
    Cancion *cancion = (Cancion*) malloc (sizeof(Cancion));
    List *generos = createList();

    char *lineaNueva = (char *)malloc(sizeof(char)*1024); // guarda la linea en el heap
    strcpy(lineaNueva, linea);
    
    // la función strtok separa la linea en strings más pequeños (tokens)
    cancion->nombre = strtok(lineaNueva, ",\"\n");
    cancion->artista = strtok(NULL, ",\"\n"); // la posición de la primera llamada está guardada

    char *token = strtok(NULL, ",\"\n");
    while (token != NULL) // mientras queden campos en la línea
    {
        if (token[0] == ' ') token++; // si el primer caracter es un espacio, lo elimina
        pushBack(generos, token);
        token = strtok(NULL, ",\"\n"); // géneros, usa " y \n como separador también
    }
    cancion->generos = generos;

    cancion->numLista = popBack(generos); // los 2 últimos elementos de la lista son el año y el n° de su lista

    cancion->anno = popBack(generos);
    return cancion;
}

void menuImportar (List *listaGlobal)
{
    char nombreArchivo[24];

    printf("Introduzca el nombre del archivo CSV:\n");
    scanf("%s", &nombreArchivo);

    FILE *fp = fopen(nombreArchivo, "r");
    char linea[1024];
    char *extension = strrchr(nombreArchivo, '.'); // retorna la posición del ultimo '.'
    if (strcmp(extension, ".csv") != 0 || !fp)
    {
        printf("El archivo introducido no es válido.\n");
        esperarEnter();
        return;
    }

    fgets(linea, 1023, fp);
    while (linea)
    {
        Cancion *cancion = leerLinea(linea);

        pushBack(listaGlobal, cancion);
        if (feof(fp)) break; // termina cuando encuentra un EOF
        fgets(linea, 1023, fp);
    }
    fclose(fp);
    printf("Archivo importado exitosamente.\n");
    esperarEnter();
}

void menuExportar(List *listaGlobal) {
    char nombreArchivo[64];

    printf("Escriba el nombre del archivo a exportar: ");
    scanf("%s",&nombreArchivo);

    FILE *fp = fopen(nombreArchivo,"w");
    Cancion *cancion = firstList(listaGlobal);
    while(1){
        fputs(cancion->nombre, fp);
        fputs(",", fp);
        fputs(cancion->artista, fp);
        fputs(",\"", fp);

        char *genero = firstList(cancion->generos);
        while (1)
        {
            fputs(genero, fp);
            genero = nextList(cancion->generos);
            if (genero == NULL) break;
            fputs(", ", fp);
        }
        fputs("\",", fp);
        fputs(cancion->anno, fp);
        fputs(",", fp);
        fputs(cancion->numLista, fp);   
        cancion = nextList(listaGlobal);

        if (cancion == NULL) break;
        fputs("\n", fp);
    }
    fclose(fp);
    esperarEnter();
    return;
}

void menuAgregarCancion(List *listaGlobal) {
    printf("Introduzca la canción que desea agregar utilizando el siguiente formato:\n");
    printf("\'Título,Artista,\"Género 1, Género 2 ...\",Fecha,N° lista de reproducción\'\n");

    char linea[1024];
    getchar(); // elimina el buffer
    scanf("%99[^\n]", linea); // lee todo hasta encontrar un \n
    Cancion *cancion = leerLinea(linea); // leerLinea lee la linea y retorna un dato tipo Cancion

    Cancion* C = firstList(listaGlobal);
    while (C != NULL)
    {
        if (strcmp(C->nombre, cancion->nombre) == 0)
        {
            if (strcmp(C->artista, cancion->artista) == 0)
            {
                printf("La canción ya existe en la lista\n");
                esperarEnter();
                return;
            }
        }
        C = nextList(listaGlobal);
    }
    pushBack(listaGlobal, cancion);

    printf("Canción añadida exitosamente.\n");
    esperarEnter();
    return;
}

void menuBuscarPorNombre(List *listaGlobal) {
    char busqueda[64];
    Cancion* cancion;
    bool existe = false;

    printf("Ingrese el nombre de la canción a buscar: ");
    getchar();

    scanf("%99[^\n]", busqueda);
    cancion = firstList(listaGlobal);
    while(cancion != NULL){ // recorre la lista comparando el nombre de la canción actual con el string busqueda
        if(strcmp(cancion->nombre,busqueda) == 0){
            existe = true;
            printf("Canción encontrada\n");
            printCancion(cancion);
            break;
        }
        cancion = nextList(listaGlobal);
    }

     if(!existe){
        printf("No se ha encontrado una cancion con el nombre: %s\n\n", busqueda);
    }

    esperarEnter();
    return;

   
}

void menuBuscarPorArtista(List *listaGlobal) {
    char busqueda[64];
    Cancion* cancion;
    bool existe = false;

    printf("Ingrese el artista de la canción a buscar: ");
    getchar();

    scanf("%99[^\n]", busqueda);
    cancion = firstList(listaGlobal);
    while(cancion != NULL){
        if(strcmp(cancion->artista,busqueda) == 0){
            existe = true;
            printCancion(cancion);
        }
        cancion = nextList(listaGlobal);
    }

    if(!existe){
        printf("No se ha encontrado el artista: %s\n",busqueda);
    }

    printf("Fin de búsqueda\n");
    esperarEnter();
    return;
}


void menuBuscarPorGenero(List *listaGlobal) {
    char busqueda[64];
    Cancion* cancion;
    bool existe = false;

    printf("Ingrese el género por buscar: ");
    getchar();

    scanf("%99[^\n]", busqueda);
    cancion = firstList(listaGlobal);

    while(cancion != NULL){
        char *genero = firstList(cancion->generos);
        while(genero != NULL){
            if(strcmp(genero,busqueda) == 0){
                existe = true;
                printCancion(cancion);
                break;
            }
            genero = nextList(cancion->generos);
        }
        cancion = nextList(listaGlobal);
    }

    if(!existe){
        printf("No se ha encontrado el genero: %s\n",busqueda);
    }

    esperarEnter();
}

void menuEliminarCancion(List *listaGlobal) {
    char nombre[64];
    char artista[64];
    Cancion* cancion;

    
    printf("Ingrese el nombre de la canción a eliminar: ");
    getchar();
    scanf("%99[^\n]", nombre);
    printf("Ingrese el artista: ");
    getchar();
    scanf("%99[^\n]", artista);

    cancion = firstList(listaGlobal);

    while(cancion != NULL){
        if(strcmp(cancion->nombre,nombre) == 0 && strcmp(cancion->artista,artista) == 0){
            popCurrent(listaGlobal);
            printf("Cancion eliminada con exito\n"); 
            esperarEnter();
            break;
        }
        cancion = nextList(listaGlobal);
        if (cancion == NULL)
        {
            printf("No se encontro la cancion\n");
            esperarEnter();
        }
    }
    return;
}

void menuMostrarListas(List *listaGlobal) {
    tipoArreglo *arreglo = (tipoArreglo*) malloc (sizeof(tipoArreglo));
    int i;
    int tamano = 0;
    Cancion *c = firstList(listaGlobal);
    bool mismoNombre = false;

    while(c != NULL)
    {
        for(i=0; i < tamano; i++)
        {
            if(strcmp(c->numLista,arreglo[i].nombre) == 0)
            {
                mismoNombre = true;
                break;
            }
        }

        if (mismoNombre) arreglo[i].cantidad++;
        else
        {
            tamano++;
            arreglo = aumentarMemoria(arreglo,tamano);
            arreglo[tamano-1].nombre = c->numLista;
            arreglo[tamano-1].cantidad = 1;
        }
        c = nextList(listaGlobal);
        mismoNombre = false;
    }

    for(i=0; i<tamano; i++)
    {
        printf("%s       %i canciones\n", arreglo[i].nombre, arreglo[i].cantidad);
    }

    esperarEnter();
    return;
}

void menuMostrarLista(List *listaGlobal) {
    char nomIngresado[16];
    Cancion *c;
    bool listFound = false;

    getchar();
    printf("Introduzca el nombre de la lista que desea buscar: ");
    scanf("%99[^\n]",&nomIngresado);
    c = firstList(listaGlobal);
    int cont = 0;

    while(c != NULL)
    {
        if (strcmp(nomIngresado,c->numLista) == 0)
        {
            listFound = true;
            printCancion(c);
            cont++;
        }
        c = nextList(listaGlobal);
    }

    if(!listFound)
        printf("La lista buscada no existe\n");

    esperarEnter();
    return;
}

void menuMostrarCanciones(List *listaGlobal) {
    Cancion *cancionzasa = firstList(listaGlobal);
    while (cancionzasa != NULL)
    {
        printCancion(cancionzasa);
        cancionzasa = nextList(listaGlobal);
    }
    esperarEnter();
    return;
}