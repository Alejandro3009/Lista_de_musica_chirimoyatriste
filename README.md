# Lista_de_musica_chirimoyatriste
1° Tarea de estructura de datos

1.- ¿Como compilar la tarea?

    primero en la terminal de bash escribir gcc *.c -o Tarea1, esto creara un archivo llamado "Tarea1.exe" que abriremos en la
    terminal de bash con ./Tarea1.exe. Luego de ejecutar ese comando se nos mostraran 10 opciones para realizar desde un menu con el que abra que ingresar un numero para indicar la instruccion que se quiere realizar y seguir los pasos que se indican.

    Para la funcion de importancion de archivos:
        Se debe ingresar el nombre del archivo junto a la extension como por ejemplo "Canciones.csv" (Caps sensitive)
    
    Para la funcion de exportacion de archivos:
        Se debe ingresar el nombre del archivo donde se quiere exportar las canciones, si el archivo no existe se creara uno con el nombre indicado. Aqui se almacenaran todas las canciones que se encuentren ya ingresadas al programa, mediante un importar o manualmente con la funcion para agregar canciones. (si se trata de exportar mientras no hay canciones ingresadas el programa se cae)

    Para la funcion para agregar canciones:
        Se debe ingresar la cancion que se quiera introducir al programa mediante el siguiente formato:
        (Titulo,Artista,"Genero1,Genero2,....GeneroX",año,ListaDeReproduccion)
        Ej: (Light up the night,Jamie berry,"Electroswing,Electro",2019,Lista 2)

    Para la funcion para buscar por nombre:
        Se debe ingresar el nombre de una cancion (Caps Sensitive), el programa mostrara la cancion que tenga el mismo nombre con su artista,generos,año y lista en la que se encuentra, sino se indicara que no se encontro la cancion. 
        Ej "A Little Piece Of Heaven", "Numb", "Dear god"

    Para la funcion para buscar por artista:
        Se pide ingresar un artista y el programa mostrara todas las canciones con su informacion (nombre,generos,etc.) del mismo artista.
        Ej: "Avenged sevenfold"

    Para la funcion para buscar por genero:
        Ingresar el genero musical que se desea buscar y el programa mostrara todas las canciones de ese mismo genero.

    Para la funcion para eliminar canciones:
        Se debe ingresar el nombre y luego el artista correspondiente de la cancion que se desea eliminar. Se mostrara un mensaje en pantalla si se logro o no eliminar la cancion.
        
        Ej: "Numb (enter) Linkin park (enter)".

    Para la funcion de mostrado de listas:
        Se buscara automaticamente todas las listas existentes y se mostraran en pantalla indicando cuantas canciones contienen.

    Para la funcion para buscar una lista y sus canciones: 
        Se debe ingresar el nombre (o numero) de la lista y se mostraran todas las canciones pertenecientes.
        Ej: "Lista 1, Lista 2, Lista 3"

    Para la funcion de mostrado de canciones:
        Se mostraran automaticamente todas las canciones que existan dentro del programa.

    Para cerrar el programa se debe ingresar un 0 cuando se este en el menu.

2.- las opciones que funcionan correctamente y las que no lo hacen indicando posibles causas

Todas la funciones funcionan como deberian, aunque la funcion para agregar canciones va a tomar como valido si solamente se le entrega un dato.

3.- Coevaluacion

Fernando Arancibia: Participo activamente en el proyecto y contribuyo con la creación funciones necesarias.
Elias Bernales:     Contribuyo enormemente en el proyecto y ayudo muchisimo a los integrantes del grupo.
Alejandro Malvacias: Tuvo varios problemas para trabajar con las herramientas dispuestas y no contribuyo mucho en el proyecto

4.- Puntos premio/castigo

Fernando Arancibia: 0
Elias Bernales: 0
Alejandro Malvacias: 0