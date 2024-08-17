#include <stdio.h>
#include <stdlib.h>


// Spielfeldgröße
#define ROWS 10
#define COLS 10

// Funktion zur Ausgabe des aktuellen Spielfelds
void printBoard(int board[ROWS][COLS]) {
    system("clear"); // Bildschirm löschen
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.'); // lebende Zellen als '#' und tote als '.' ausgeben
        }
        printf("\n");
    }
}

// Funktion zur Aktualisierung des Spielfelds gemäß den Regeln des Spiels des Lebens
void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            // Überprüfe die Nachbarn der aktuellen Zelle
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue; // Die Zelle selbst nicht zählen
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && board[ni][nj]) {
                        neighbors++;
                    }
                }
            }
            // Anwendung der Regeln des Spiels des Lebens
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) newBoard[i][j] = 0; // Zelle stirbt
                else newBoard[i][j] = 1; // Zelle bleibt am Leben
            } else {
                if (neighbors == 3) newBoard[i][j] = 1; // Zelle wird geboren
                else newBoard[i][j] = 0; // Zelle bleibt tot
            }
        }
    }
    // Kopiere das neue Spielfeld zurück ins ursprüngliche Spielfeld
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0}; // Spielfeld initialisieren, alle Zellen sind zunächst tot

    // Schleife für das Spiel
    char input;
    do {
        printBoard(board);
        updateBoard(board);
        printf("\nPress Enter to continue or type any character followed by Enter to exit: ");
        scanf(" %c", &input);
    } while (input == '\n');

    return 0;
}
