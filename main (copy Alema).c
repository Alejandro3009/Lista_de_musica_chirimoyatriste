#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct Cancion {
    char nombre[20];
    char artista[20];
    List generos;
    unsigned int anno;
    unsigned int numLista;
} Cancion;

typedef struct ListaReproduccion {
    List canciones;
    unsigned int cantidad;
    int numero;
} ListaReproduccion;

void menuImportar();
{
  
}
void menuExportar();
void menuAgregarCancion(char *cNom,char *cArt,char **genero,int anno,int lista);
{
  int i;
  bool existe = false;
  Cancion *cancion;
  const char [2] delim = ",";
  char * tokem;
  
  strcpy(cancion->nombre,cNom);
  strcpy(cancion->Artista,cArt);
  tokem = strtok(genero, delim);
  cancion->anno = anno;
  cancion->numLista = lista
  
  for(i = 0; i < list->contador; i++)
  {
    if (strcmp(cNom, nombre) && strcmp(cArt, artista))
    {
      existe = true;
      printf("la cancion ya existe en la lista");
      break
    }
  }

  if(!existe)
  {
    pushBack(list, cancion);
    list->contador++;
  }
}
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

        switch(opcion)
          case 1:
            menuImportar();
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
        if (opcion == 10) menuMostrar(); // main.c hace falta una variable que lleve la cuenta de cuantas canciones hay en total
        if (opcion > 10){
            printf("Por favor introduzca un número entre 0 y 10");
        }
    }
    return 0;
}