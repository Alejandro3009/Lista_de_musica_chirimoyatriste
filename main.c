#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c"

typedef struct Cancion {
    char *nombre;
    char *artista;
    List *generos;
    char *anno;
    char *numLista;
    unsigned int numGeneros;
} Cancion;

typedef struct ListaReproduccion {
    List canciones;
} ListaReproduccion;

void menuImportar(List*);
void menuExportar(List*);
void menuAgregarCancion(List*);
void menuBuscarPorNombre(List*);
void menuBuscarPorArtista(List*);
void menuBuscarPorGenero(List*);
void menuEliminarCancion(List*);
void menuMostrarListas(List*);
void menuMostrarLista(List*);
void menuMostrar(List*);

int main()
{
    List *listaGlobal = createList();
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
        if (opcion == 1) menuImportar(listaGlobal); // manejoCSV.c
        if (opcion == 2) menuExportar(listaGlobal); // manejoCSV.c
        if (opcion == 3) menuAgregarCancion(listaGlobal); // manejoCanciones.c
        if (opcion == 4) menuBuscarPorNombre(listaGlobal); //buscar.c
        if (opcion == 5) menuBuscarPorArtista(listaGlobal); //buscar.c
        if (opcion == 6) menuBuscarPorGenero(listaGlobal); //buscar.c
        if (opcion == 7) menuEliminarCancion(listaGlobal); // manejoCanciones.c
        if (opcion == 8) menuMostrarListas(listaGlobal); // main.c
        if (opcion == 9) menuMostrarLista(listaGlobal); // main.c
        if (opcion == 10) menuMostrar(listaGlobal); // main.c
        if (opcion > 10){
            printf("Por favor introduzca un número entre 0 y 10\n");
        }
    }
    return 0;
}

Cancion *leerLineaCSV (char *linea)
{
    Cancion *cancion = (Cancion*) malloc (sizeof(Cancion));
    List *generos = createList();

    // la función strtok separa la linea en strings más pequeños (tokens)

    cancion->nombre = strtok(linea, ",\"\n");
    cancion->artista = strtok(NULL, ",\"\n"); // guarda la posición de la primera llamada
    cancion->numGeneros = 0;

    char *token = strtok(NULL, ",\"\n");
    while (token != NULL) // mientras queden campos en la línea
    {
        if (token[0] == ' ') token++; // si el primer caracter es un espacio, lo elimina
        pushBack(generos, token);
        cancion->numGeneros++;
        token = strtok(NULL, ",\"\n"); // géneros, usa " y \n como separador también
    }
    cancion->numLista = popBack(generos); // los 2 últimos elementos de la lista son el año y el n° de su lista

    cancion->anno = popBack(generos);
}

void menuImportar (List *listaGlobal)
{
    char nombreArchivo[24];

    printf("Introduzca el nombre del archivo CSV:\n");
    scanf("%s", &nombreArchivo);

    FILE *fp = fopen(nombreArchivo, "r");
    char linea[1024];

    fgets(linea, 1023, fp);
    while (linea)
    {
        Cancion *cancion = leerLineaCSV(linea);

        pushBack(listaGlobal, cancion);
        if (feof(fp)) break; // termina cuando encuentra un EOF
        fgets(linea, 1023, fp);
    }
    printf("El archivo %s ha sido importado exitosamente\nPresione Enter para continuar\n", nombreArchivo);
    getchar(); getchar();
}

void menuExportar(List *listaGlobal) {
    return;
}

void menuAgregarCancion(List *listaGlobal) {
    printf("Introduzca la canción que desea agregar utilizando el siguiente formato:\n");
    printf("\'Título,Artista,\"Género 1, Género 2 ...\",Fecha,N° lista de reproducción\'\n");

    char linea[1024];
    getchar(); // elimina el buffer
    scanf("%99[^\n]", linea); // lee todo hasta encontrar un \n
    Cancion *cancion = leerLineaCSV(linea); // leerLineaCSV lee la linea y retorna un dato tipo Cancion

    listaGlobal->head;
    while (nextList(listaGlobal) != NULL)
    {
        Cancion * cancionBusqueda = listaGlobal->current->data;
        if (strcmp(cancionBusqueda->nombre, cancion->nombre))
        {
            if (strcmp(cancionBusqueda->artista, cancion->artista))
            {
                printf("La canción ya existe en la lista\nPresione Enter para continuar\n");
                getchar(); getchar();
                return;
            }
        }
    }
    pushBack(listaGlobal, cancion);

    printf("Canción añadida exitosamente.\nPresione Enter para continuar\n");
    getchar(); getchar();
    return;
}

void menuBuscarPorNombre(List *listaGlobal) {
    return;
}

void menuBuscarPorArtista(List *listaGlobal) {
    return;
}

void menuBuscarPorGenero(List *listaGlobal) {
    return;
}

void menuEliminarCancion(List *listaGlobal) {
    return;
}

void menuMostrarListas(List *listaGlobal) {
    return;
}

void menuMostrarLista(List *listaGlobal) {
    return;
}

void menuMostrar(List *listaGlobal) {
    return;
}