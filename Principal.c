#include <stdio.h>
#include <stdlib.h>
#include "RegistroLibros.c"

int menuPrincipal();

int main(int argc, char const *argv[])
{
    int op;
    do{
        op = menuPrincipal();
    }while(op != 5);
    
    return 0;
}
