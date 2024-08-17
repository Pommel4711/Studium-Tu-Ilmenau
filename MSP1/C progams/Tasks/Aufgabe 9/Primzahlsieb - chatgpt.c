#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Variante (a): Liste aller Zahlen im Suchbereich
bool *create_prime_candidates(int lower_bound, int upper_bound) {
    bool *candidates = (bool *)malloc((upper_bound + 1) * sizeof(bool));

    // Initialisiere alle Zahlen als potenzielle Primzahlen
    for (int i = 0; i <= upper_bound; i++) {
        candidates[i] = true;
    }

    // Markiere 0 und 1 als nicht prim
    candidates[0] = false;
    candidates[1] = false;

    // Sieb des Eratosthenes
    for (int p = 2; p * p <= upper_bound; p++) {
        if (candidates[p] == true) {
            for (int i = p * 2; i <= upper_bound; i += p) {
                candidates[i] = false;
            }
        }
    }

    return candidates;
}

// Variante (b): Liste aller ungeraden Zahlen im Suchbereich
bool *create_odd_prime_candidates(int lower_bound, int upper_bound) {
    bool *candidates = (bool *)malloc((upper_bound + 1) * sizeof(bool));

    // Initialisiere alle ungeraden Zahlen als potenzielle Primzahlen
    for (int i = 0; i <= upper_bound; i++) {
        candidates[i] = (i % 2 != 0);
    }

    // Markiere 0 und 1 als nicht prim
    candidates[0] = false;
    candidates[1] = false;

    // Sieb des Eratosthenes
    for (int p = 3; p * p <= upper_bound; p += 2) {
        if (candidates[p] == true) {
            for (int i = p * 2; i <= upper_bound; i += p) {
                candidates[i] = false;
            }
        }
    }

    return candidates;
}

// Variante (c): Einstellbare untere und obere Grenze
bool *create_custom_prime_candidates(int lower_bound, int upper_bound) {
    bool *candidates = (bool *)malloc((upper_bound - lower_bound + 1) * sizeof(bool));

    // Initialisiere alle Zahlen als potenzielle Primzahlen
    for (int i = 0; i <= upper_bound - lower_bound; i++) {
        candidates[i] = true;
    }

    // Markiere 0 und 1 als nicht prim
    if (lower_bound <= 1 && upper_bound >= 1) {
        candidates[1 - lower_bound] = false;
    }

    // Sieb des Eratosthenes
    for (int p = 2; p * p <= upper_bound; p++) {
        int start = (lower_bound / p) * p;
        if (start < lower_bound) {
            start += p;
        }
        for (int i = start; i <= upper_bound; i += p) {
            if (i >= lower_bound && i != p) {
                candidates[i - lower_bound] = false;
            }
        }
    }

    return candidates;
}

int main() {
    int lower_bound = 10;
    int upper_bound = 30;

    printf("Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);

    // Variante (a)
    bool *prime_candidates_a = create_prime_candidates(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_a[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_a);

    // Variante (b)
    bool *prime_candidates_b = create_odd_prime_candidates(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_b[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_b);

    // Variante (c)
    lower_bound = 10;
    upper_bound = 40;
    printf("Primzahlen im Bereich von %d bis %d:\n", lower_bound, upper_bound);
    bool *prime_candidates_c = create_custom_prime_candidates(lower_bound, upper_bound);
    for (int i = lower_bound; i <= upper_bound; i++) {
        if (prime_candidates_c[i - lower_bound]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(prime_candidates_c);

    return 0;
}
