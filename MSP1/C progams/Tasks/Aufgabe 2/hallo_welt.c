// hallo_welt.c

#include <stdio.h>
#include "produkt.h"
#include "produkt.c"


int main() {
    int a = 5;
    int b = 3;
    int produkt = berechneProdukt(a, b);
    printf("Das Produkt von %d und %d ist: %d\n", a, b, produkt);
    return 0;
}
