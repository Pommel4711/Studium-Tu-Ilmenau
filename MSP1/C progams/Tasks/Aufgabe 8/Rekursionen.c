//Author Philipp Fiedler

//Rekursionen
//Fak
//Fibona

#include <stdio.h>

unsigned long Fakultat (int n){
   // Basisfall: Fakultät von 0 und 1 ist 1
    if (n == 0 || n == 1) {
        return 1;
    }     
    else {
        // Rekursiver Fall: Fakultät von n ist n * Fakultät von (n-1)
        return n * Fakultat(n - 1);
    }
}

unsigned long Fibonacci (int n){
   // Basisfall: Fakultät von 0 und 1 ist 1
    if (n == 0 || n == 1) {
        return 1;
    }     
    else {
        // Rekursiver Fall: Fakultät von n ist n * Fakultät von (n-1)
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main() {
    int Fakvon = 5;
    int Fibonacci_Zahl = 6;
    printf("Fakutät von: %d ist : %d\n",Fakvon,Fakultat(Fakvon));
    printf("Fibona von: %d ist : %d\n",Fibonacci_Zahl,Fibonacci(Fibonacci_Zahl));

    return 0;
}
