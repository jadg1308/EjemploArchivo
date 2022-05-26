#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"

int menuPrincipal()
{
    int op;
    system("cls");
    printf("\t M E N U \n");
    printf("1. Agregar Libro \n");
    printf("2. Editar Libro \n");
    printf("3. Mostrar \n");
    printf("4. Salir\n");
    printf("Opcion: ");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
        printf("Agregar Libro \n");
        agregarLibro();
        break;
    case 2:
        printf("Editar Libro \n");
        modificarLibro();
        break;
    case 3:
         mostrarRegistro();
        system("pause");
        break;
    case 4:
        
        break;
    default:
        break;
    }
    return op;
}

void agregarLibro()
{
    Libro lib;
    system("cls");
    printf("Digite los siguientes datos \n");
    printf("Codigo: ");
    scanf("%i", &lib.id);
    printf("Titulo del libro: ");
    scanf(" %[^\n]", lib.titulo);
    printf("Autor del libro: ");
    scanf(" %[^\n]", lib.autor);
    printf("Existencia: ");
    scanf("%i", &lib.cantidad);

    FILE *libros;
    libros = fopen("libros.bin", "a");
    fwrite(&lib, sizeof(Libro), 1, libros);
    fclose(libros);
}

void modificarLibro()
{
    int id;
    printf("Digite el codigo del libro: ");
    scanf("%i", &id);

    FILE *libros, *temporal;
    Libro temp, lib;

    libros = fopen("libros.bin", "r");
    temporal = fopen("temporal.bin", "a");

    while (feof(libros) == 0)
    {
        fread(&temp, sizeof(Libro), 1, libros);
        if (temp.id == id)
        {
            lib.id = id;
            printf("Titulo Actual: %s. Nuevo Titulo: ", temp.titulo);
            scanf(" %[^\n]", lib.titulo);
            printf("Autor Actual: %s. Nuevo Autor: ", temp.autor);
            scanf(" %[^\n]", lib.autor);
            printf("Existencia Actual: %i. Nueva Existencia: ", temp.cantidad);
            scanf("%i", &lib.cantidad);

            fwrite(&lib, sizeof(Libro), 1, temporal);

            printf("Cambios realizados...\n");
        }
        else
        {
            fwrite(&temp, sizeof(Libro), 1, temporal);
        }
        fread(&temp, sizeof(Libro), 1, libros);
    }
    fclose(libros);
    fclose(temporal);
    remove("libros.bin");
    rename("temporal.bin", "usuarios.bin");
}

void mostrarRegistro()
{
    FILE *libros;
    Libro lib;

    libros = fopen("libros.bin", "r");

    if(libros == NULL) {
        printf("Archivo vacío...\n");
        return 0;
    }
    while (feof(libros) == 0)
    {
        fread(&lib, sizeof(Libro), 1, libros);
        printf("Codigo: %i\n", lib.id);
        printf("Titulo Actual: %s. \n ", lib.titulo);
        printf("Autor Actual: %s. \n", lib.autor);
        printf("Existencia Actual: %i. \n", lib.cantidad);
    }
    fclose(libros);
}