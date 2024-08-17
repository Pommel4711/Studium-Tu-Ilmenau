//Author Philipp Fiedler
//Spiel des Lebens


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10


int Zeitschritt = 0;

void printfirstBoard(bool board [ROWS] [COLS]){
system("clear");
for (int i = 0; i < COLS; i++)
{
    for (int s = 0; s < ROWS; s++)
    {
        if (board [ROWS] [COLS])    //Wenn True also Lebendig mache ein "#" bei Tod "."
        {
            printf("# ");
        }
        else{
            printf(".");
        }
        
    }
    printf("\n");
}

}

void printBoard(bool board [ROWS] [COLS]){


}


int main() {
    
    bool board[ROWS][COLS];
    //Spielfeld initialisieren
    for (int i = 0; i < ROWS; i++) {
        for (int s = 0; s < COLS; s++) {
            board[ROWS][COLS]=false;
        }
    printf("\n");
    }
    // Schleife für das Spiel
    char input;
    printf("Conway Spiel des Lebens\n\nZeitschritt = %i \nInitialisierung Board:\n", Zeitschritt);
    printfirstBoard(board);
    do {
        //printBoard(board);
        //updateBoard(board);
        printf("\nPress Enter to continue or type any ");
        printf("character followed by Enter to exit: ");
        input = getchar();
    } while (input == '\n');

    
    return 0;
}
