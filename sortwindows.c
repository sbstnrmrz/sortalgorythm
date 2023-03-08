#include <stdio.h>
#include <stdlib.h>

int i, j;
int temp;
int menor = 99;
int posmenor;
int mayor = 0; 
int posmayor;

// Funcion para ordenar los numeros de menor a mayor
void menormayor(int vector[]){ 

    for(i=1; i<9; i++){
        temp = vector[i]; // Almacena el valor que se encuentra en la posicion indicada del vector
        int j = i-1; // 'j' equivale a la posicion del valor de la izquierda
        while(j >=0 && vector[j] > temp) { // Si el numero en la posicion indicada del vector es mayor al valor temporal
            vector[j + 1] = vector[j]; // El vector en la posicion indicada va a ser igual a el valor a el valor de j
            j--;
        }
        vector[j+1] = temp; // Si se cumple la condicion, el nuevo valor en la posicion del vector va a ser igual al temporal
    }

}

// Funcion para ordenar los numeros de mayor a menor
void mayormenor(int vector[]){ 

    for(i=1; i<9; i++){
        temp = vector[i]; // Almacena el valor que se encuentra en la posicion indicada del vector
        int j = i-1; // 'j' equivale a la posicion del valor a la la izquierda
        while(j >= 0 && vector[j] < temp) { // Si el numero en la posicion indicada del vector es menor que el valor temporal  
            vector[j + 1] = vector[j]; // El vector en la posicion indicada va a ser igual vector a el valor de j
            j--; 
        }
        vector[j+1] = temp; // Si se cumple la condicion, el nuevo valor en la posicion del vector va a ser igual al temporal
    }
}

// Funcion para halla el numero menor del vector
void numMenor(int vector[]){ 

    for(i=0; i<9; i++){ // Itera desde el principio hasta el final del vector(0 a 9)
        if(vector[i] < menor ){ // Si el numero en el indice es menor que 99 
            menor = vector[i]; // Almacena el numero menor de la comparacion en la variable 'menor' 
            posmenor = i; // Almacena la posicion del numero menor en el vector
        }
    }
    if(i == 9){
        printf("\nEl numero menor en el vector es: %d\n", menor);
    }
}

// Funcion para hallar el numero mayor del vector
void numMayor(int vector[]){

    for(i=0; i<9; i++){ // Itera desde el principio hasta el final del vector(0 a 9)
        if(vector[i] > mayor){ // Si el numero en el indice es mayor que 0
            mayor = vector[i]; // Almacena el numero mayor de la comparacion en la variable 'mayor'
            posmayor = i; // Almacena la posicion del numero mayor en el vector
        }
    }
    if(i == 9){
        printf("\nEl numero mayor en el vector es: %d \n", mayor);
    }
}

// Funcion para mostrar los elementos del vector
void mostrar(int vector[]){ 
    int i;
    for(i=0; i<9; i++){ /* Muestra el index correspondiente de los numeros del vector */
        printf("\nEl index de %d es %d\n", i, vector[i]);
    }
    printf("\nEl vector es: ");
    for(i=0; i<9; i++){
        printf("%d ", vector[i]);
        if(i == 8){printf("\n");}
    }

}

int main(){
    int sel;
    char retry;
    int vector[] = {20, 16, 42, 32, 15, 17, 45, 33, 11};

    printf("      /\\  \n");
    printf("     /  \\ \n");
    printf("    /____\\ \n");
    printf("   /\\    /\\ \n");
    printf("  /  \\  /  \\ \n");
    printf(" /____\\/____\\ \n");

    system("timeout /t 1 /nobreak");
    system("cls");

    while(1){
        while(1){
            printf("Seleccione una opcion:\n1) Hallar el numero menor dentro del vector\n2) Hallar el numero mayor dentro del vector\n3) Ordenar el vector de menor a mayor\n4) Ordenar el vector de mayor a menor\n\nSu opcion: ");
            scanf("%d", &sel);

                if(sel == 1){
                    system("cls");

                    mostrar(vector); // Muestra el vector
                    numMenor(vector); // Muestra el numero menor del vector
                    break;
                    
                }
                if(sel == 2){
                    system("cls");

                    mostrar(vector); // Muestra el vector
                    numMayor(vector); // Muestra el numero mayor del vector
                    break;

                }
                if(sel == 3){
                    system("cls");

                    for(i=0; i<9; i++){ // Muestra el index correspondiente de los numeros del vector
                    printf("\nEl index de %d es %d\n", i, vector[i]);
                    }

                    printf("\nVector original: ");
                    for(i=0; i<9; i++){
                        printf("%d ", vector[i]);
                    }
                    printf("\n\nVector ordenado de menor a mayor: ");
                    menormayor(vector); // Ordena los valores del vector de menor a mayor
                    mostrar(vector); // Muestra el vector ordenado
                    break;
                }
                if(sel == 4){
                    system("cls");

                    for(i=0; i<9; i++){ /* Muestra el index correspondiente de los numeros del vector */
                    printf("\nEl index de %d es %d\n", i, vector[i]);
                    }

                    printf("\nVector original: ");
                    for(i=0; i<9; i++){
                        printf("%d ", vector[i]);
                    }
                    printf("\n\nVector ordenado de mayor a menor: ");
                    mayormenor(vector); // Ordena los valores del vector de mayor a menor
                    mostrar(vector); // Muestra el vector ordenado
                    break;

                }else if(sel != 1 && sel != 2 && sel != 3 && sel != 4){ // Si el usuario no introduce ni 1, 2, 3, 4: no continua
                    system("cls");
                    printf("\nSeleccione una opcion valida\n");
                    system("timeout /t 1 /nobreak");
                    system("cls");
                }
            }

            printf("Desea reiniciar el programa? Si(s) No(n): ");
            scanf(" %c", &retry);

            if(retry == 's'){
                system("cls");
                continue;
            }
            if(retry == 'n'){
                system("cls");
                break;
            }
    }
}
