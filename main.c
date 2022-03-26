#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c"

typedef struct Cancion {
    char nombre[20];
    char artista[20];
    List generos;
    char anno[5];
    char numLista[5];
} Cancion;

typedef struct ListaReproduccion {
    List canciones;
} ListaReproduccion;

void menuImportar();
void menuExportar();
void menuAgregarCancion();
void menuBuscarPorNombre();
void menuBuscarPorArtista();
void menuBuscarPorGenero();
void menuEliminarCancion();
void menuMostrarListas();
void menuMostrarLista();
void menuMostrar();

int main()
{
    unsigned int opcion = 0;
    while (1) {
        printf("| Menu |\n");
        printf("Para elegir una opción introduzca el número correspondiente:\n");

        printf("1. Importar canciones desde un archivo CSV\n");
        printf("2. Exportar canciones a un archivo CSV\n");
        printf("3. Agregar canción\n");
        printf("4. Buscar canción por nombre\n");
        printf("5. Buscar canción por artista\n");
        printf("6. Buscar canción por género\n");
        printf("7. Eliminar canción\n");
        printf("8. Mostrar listas de reproducción\n");
        printf("9. Mostrar una lista de reproducción\n");
        printf("10. Mostrar todas las canciones\n");
        printf("0. Cerrar\n");

        scanf("%u", &opcion);

        if (opcion == 0) break;
        if (opcion == 1) menuImportar(); // manejoCSV.c
        if (opcion == 2) menuExportar(); // manejoCSV.c
        if (opcion == 3) menuAgregarCancion(); // manejoCanciones.c
        if (opcion == 4) menuBuscarPorNombre(); //buscar.c
        if (opcion == 5) menuBuscarPorArtista(); //buscar.c
        if (opcion == 6) menuBuscarPorGenero(); //buscar.c
        if (opcion == 7) menuEliminarCancion(); // manejoCanciones.c
        if (opcion == 8) menuMostrarListas(); // main.c
        if (opcion == 9) menuMostrarLista(); // main.c
        if (opcion == 10) menuMostrar(); // main.c
        if (opcion > 10){
            printf("Por favor introduzca un número entre 0 y 10\n");
        }
    }
    return 0;
}

// falta caso géneros
const char *get_csv_field (char * tmp, int k) {
    int open_mark = 0;
    char* ret=(char*) malloc (100*sizeof(char));
    int ini_i=0, i=0;
    int j=0;
    while(tmp[i+1]!='\0'){

        if(tmp[i]== '\"'){
            open_mark = 1-open_mark;
            if(open_mark) ini_i = i+1;
            i++;
            continue;
        }

        if(open_mark || tmp[i]!= ','){
            if(k==j) ret[i-ini_i] = tmp[i];
            i++;
            continue;
        }

        if(tmp[i]== ','){
            if(k==j) {
               ret[i-ini_i] = 0;
               return ret;
            }
            j++; ini_i = i+1;
        }

        i++;
    }

    if(k==j) {
       ret[i-ini_i] = 0;
       return ret;
    }


    return NULL;
}

List crearListaGeneros() {

}

void menuImportar ()
{
    char nombreArchivo[20];
    List *listaCanciones = createList();

    printf("Introduzca el nombre del archivo CSV:\n");
    scanf("%s", &nombreArchivo);

    FILE *fp = fopen(nombreArchivo, "r");
    char linea[1024] = "inicio";
    char *campo;


    fgets (linea, 1023, fp);
    while (linea)
    {
        Cancion *cancion;

        // 0 = nombre, 1 = artista, 2 = generos, 3 = año, 4 = num lista
        strcpy(cancion->nombre, get_csv_field(linea, 0));
        strcpy(cancion->artista, get_csv_field(linea, 1));
        cancion->generos = crearListaGeneros(get_csv_field(linea, 2));//strcpy(cancion->nombre, get_csv_field(linea, 0));
        strcpy(cancion->anno, get_csv_field(linea, 3));
        strcpy(cancion->numLista, get_csv_field(linea, 4));
        
        pushBack(listaCanciones, cancion);

        fgets (linea, 1023, fp);
    }
    


}

void menuExportar() {
    return;
}

void menuAgregarCancion() {
    return;
}

void menuBuscarPorNombre() {
    return;
}

void menuBuscarPorArtista() {
    return;
}

void menuBuscarPorGenero() {
    return;
}

void menuEliminarCancion() {
    return;
}

void menuMostrarListas() {
    return;
}

void menuMostrarLista() {
    return;
}

void menuMostrar() {
    return;
}