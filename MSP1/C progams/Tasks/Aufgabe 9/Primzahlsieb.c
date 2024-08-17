//Author Philipp Fiedler

//Rekursionen
//Fak
//Fibona

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//Variante (a)
bool *Primzahlen_a (int lower_bound, int upper_bound){
    bool *Primzahlen = (bool *)malloc((upper_bound+1)* sizeof(bool));
    //Makiere 0 und 1 nicht als Primzahlen 
    *(Primzahlen+0)= false;         //funktioniert an stelle 0
    *(Primzahlen+1)= false;         //fkt an stelle 1   
    
    //Sieb des Eratosthenes 
    for (int p = 2; p * p <= upper_bound; p++) {        //Geht nur bis zur Hälfte da über der Hälfte immer nur Kommazahlen entstehen 
        if (Primzahlen[p] == true) {
            for (int i = p * 2; i <= upper_bound; i += p) {         //Multipliziert immer mit Variable p und Vielfache werden rausgeschmissen.
                Primzahlen[i] = false;
            }
        }
    }

    return Primzahlen;
}

//Variante b
bool *Primzahlen_b_odd (int lower_bound, int upper_bound){
    bool *Primzahlen = (bool *)malloc((upper_bound+1)* sizeof(bool));
    //Makiere 0 und 1 nicht als Primzahlen 
    *(Primzahlen+0)= false;         //funktioniert an stelle 0
    *(Primzahlen+1)= false;         //fkt an stelle 1   
    *(Primzahlen+1)= false;         //fkt an stelle 2

    //Sieb des Eratosthenes   
    for (int p = 2; p * p <= upper_bound; p++) {        //Geht nur bis zur Hälfte da über der Hälfte immer nur Kommazahlen entstehen 
        if (Primzahlen[p] == true) {
            for (int i = p * 2; i <= upper_bound; i += p) {         //Multipliziert immer mit Variable p und Vielfache werden rausgeschmissen.
                Primzahlen[i] = false;
            }
        }
    }
    return Primzahlen;
}

//Variante c
bool *Primzahlen_c_variabel (int lower_bound, int upper_bound){
    bool *Primzahlen = (bool *)malloc((upper_bound+1)* sizeof(bool));
    //Makiere 0 und 1 nicht als Primzahlen 
    *(Primzahlen+0)= false;         //funktioniert an stelle 0
    *(Primzahlen+1)= false;         //fkt an stelle 1   
    *(Primzahlen+1)= false;         //fkt an stelle 2

    //Sieb des Eratosthenes 
   
    for (int p = 2; p * p <= upper_bound; p++) {        //Geht nur bis zur Hälfte da über der Hälfte immer nur Kommazahlen entstehen 
        if (Primzahlen[p] == true) {
            for (int i = p * 2; i <= upper_bound; i += p) {         //Multipliziert immer mit Variable p und Vielfache werden rausgeschmissen.
                Primzahlen[i] = false;
            }
        }
    }
    return Primzahlen;
}

//Aktin Sieb
bool *atkin_sieve(int lower_bound, int upper_bound) {
    bool *prime_candidates = (bool *)malloc((upper_bound + 1) * sizeof(bool));

    // Alle Zahlen initialisieren als potenzielle Primzahlen
    for (int i = 0; i <= upper_bound; i++) {
        prime_candidates[i] = false;
    }

    // Sieb des Atkin Algorithmus
    int limit = sqrt(upper_bound);
    for (int x = 1; x <= limit; x++) {
        for (int y = 1; y <= limit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= upper_bound && (n % 12 == 1 || n % 12 == 5)) {
                prime_candidates[n] ^= true;
            }

            n = (3 * x * x) + (y * y);
            if (n <= upper_bound && n % 12 == 7) {
                prime_candidates[n] ^= true;
            }

            n = (3 * x * x) - (y * y);
            if (x > y && n <= upper_bound && n % 12 == 11) {
                prime_candidates[n] ^= true;
            }
        }
    }

    for (int n = 5; n <= limit; n++) {
        if (prime_candidates[n]) {
            for (int k = n * n; k <= upper_bound; k += n * n) {
                prime_candidates[k] = false;
            }
        }
    }

    // Markiere 2 und 3 als Primzahlen
    prime_candidates[2] = true;
    prime_candidates[3] = true;

    return prime_candidates;
}



int main() {
    int lower_bound = 10;
    int upper_bound = 30;


    //Variante a
    printf("Alle Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);
    bool *prime_candidates_a = Primzahlen_a(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_a[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_a);


   //Variante b
    printf("Ungerade Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);
    bool *prime_candidates_b = Primzahlen_a(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_b[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_b);


    //Variante c
    printf("Ungerade Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);
    bool *prime_candidates_c = Primzahlen_c_variabel(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_c[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_c);


    //Aktin Sieb
    bool *Aktinprimes = atkin_sieve(lower_bound, 200);
    printf("Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);
    for (int i = lower_bound; i <= 200; i++) {
        if (Aktinprimes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(Aktinprimes);


    return 0;
}
