#include <stdio.h>
//Verwendung von Bitmasken und Schiebeoperationen:

// Extrahieren des low Byte eines Integers
int extractLowByte(int num) {
    return num & 0xFF;
}
// Extrahieren des high Byte eines Integers
int extractHighByte(int num) {
    int r;
    r= num >>8;

    return (r) & 0xFF;
}


//Verwendung von unions
union IntBytes{    
    struct {
        unsigned char lowByte;
        unsigned char highByte;
    }bytes; 
    int num; 
};

int combineBytes (int lowByte, int highByte){
return(highByte<<8 | lowByte);
};

int main() {
    //Extrahieren low and Highbyte
    int nummer = 62040;
    printf("Bitmasken Low Byte: %d High Byte: %d\n", extractLowByte(nummer), extractHighByte(nummer));  

    union IntBytes val;
    val.num = 62040;
    printf("Unsions extract Lowbyte: %d Unions Highbyte: %d\n", val.bytes.lowByte, val.bytes.highByte);
    
    //Integer Zusammensetzen
    int lowByte = 255;
    int highByte = 255;
    printf("Combined Bitmasken Integer: %d\n" ,combineBytes(lowByte,highByte));
      
    val.bytes.lowByte = lowByte;
    val.bytes.highByte = highByte;
    printf("Combined union Integer: %d\n", val.num);
    
    return 0;


}
