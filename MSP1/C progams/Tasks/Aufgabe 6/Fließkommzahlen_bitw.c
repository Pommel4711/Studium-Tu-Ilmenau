#include <stdio.h>
#include <stdint.h>

typedef union {
    double value;
    struct {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
} DoubleParts;

void double_part_print(double val) {
    DoubleParts parts;
    parts.value = val;
    int exponent = parts.parts.exponent;	
    printf("Vorzeichen: %d\n", parts.parts.sign);
    printf("Wirksamer Exponent (e - 1023): %d\n", exponent - 1023);
    printf("Mantisse (hex): %llx\n", parts.parts.mantissa);
}

void double_bin_print(double val) {
    DoubleParts parts;
    parts.value = val;
    uint64_t *pointer = (uint64_t *)&val;   //erstellt point auf adresse val adresse ist eine 64 bit ganzzahl
    uint64_t mask = 0x8000000000000000;     //Soll höchste Bitposition repräsentieren 
    
    for (int i = 0; i < 64; ++i) {
        printf("%c", (*pointer & mask) ? '1' : '0');
        mask >>= 1;
        if (i == 0 || i == 11)
            printf("|");

            
    }
    printf("\n");
}



int main() {
    double val = 3.14159;
    
    printf("Ausgabe mit double_part_print:\n");
    double_part_print(val);
    
    printf("\nAusgabe mit double_bin_print:\n");
    double_bin_print(val);
    
    printf("\nAusgabe mit double_part_print_by_mask:\n");
    double_part_print_by_mask(val);
    
    return 0;
}
