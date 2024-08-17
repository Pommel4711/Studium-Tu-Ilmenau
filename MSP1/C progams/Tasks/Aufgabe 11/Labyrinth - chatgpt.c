
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LAB_WIDTH 62
#define LAB_HEIGHT 18
#define MAX_STACK_SIZE 100

// Definition der Himmelsrichtungen
enum Direction { N, NO, O, SO, S, SW, W, NW };

// Definition eines Elements im Stack
struct Element {
    int y;
    int x;
    enum Direction dir;
};

// Globale Variablen für den Stack und den Index des obersten Elements
struct Element stack[MAX_STACK_SIZE];
int top = -1;

// Funktion zum Hinzufügen eines Elements zum Stack
void push(struct Element item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Fehler: Stapel ist voll\n");
        exit(EXIT_FAILURE);
    }
    top++;
    stack[top] = item;
}

// Funktion zum Entfernen des obersten Elements vom Stack
struct Element pop() {
    if (top == -1) {
        printf("Fehler: Stapel ist leer\n");
        exit(EXIT_FAILURE);
    }
    struct Element item = stack[top];
    top--;
    return item;
}

// Funktion zum Überprüfen, ob ein Feld im Labyrinth gültig ist
bool is_valid(int y, int x) {
    return (y >= 0 && y < LAB_HEIGHT && x >= 0 && x < LAB_WIDTH);
}

// Funktion zum Überprüfen, ob ein Feld ein Ausgang ist
bool is_exit(int y, int x) {
    return (y >= 0 && y < LAB_HEIGHT && x >= 0 && x < LAB_WIDTH && (y == 0 || y == LAB_HEIGHT - 1 || x == 0 || x == LAB_WIDTH - 1) && lab[y][x] == 'B');
}

// Funktion zur Suche nach einem Weg durch das Labyrinth
void find_path(char lab[LAB_HEIGHT][LAB_WIDTH], int start_y, int start_x, enum Direction start_dir) {
    int mark[LAB_HEIGHT][LAB_WIDTH] = {0}; // Markierung für bereits besuchte Felder

    push((struct Element){start_y, start_x, start_dir}); // Startpunkt in den Stack legen

    while (top != -1) {
        struct Element current = pop();
        int y = current.y;
        int x = current.x;
        enum Direction dir = current.dir;

        if (is_exit(y, x)) {
            printf("Weg gefunden!\n");
            return;
        }

        // Versuche alle Bewegungsrichtungen
        for (int d = 0; d < 8; d++) {
            enum Direction next_dir = (dir + d) % 8;
            int next_y = y, next_x = x;
            switch (next_dir) {
                case N: next_y--; break;
                case NO: next_y--; next_x++; break;
                case O: next_x++; break;
                case SO: next_y++; next_x++; break;
                case S: next_y++; break;
                case SW: next_y++; next_x--; break;
                case W: next_x--; break;
                case NW: next_y--; next_x--; break;
            }
            if (is_valid(next_y, next_x) && lab[next_y][next_x] == ' ' && mark[next_y][next_x] == 0) {
                mark[next_y][next_x] = 1;
                push((struct Element){next_y, next_x, next_dir});
            }
        }
    }

    printf("Keinen Weg gefunden\n");
}

int main() {
    // Definition des Labyrinths
    char lab[LAB_HEIGHT][LAB_WIDTH] = {
        {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXBX"
        "XXXXXXXXXXXXXXX XXXXXXXXXXXXXXXXX X",
        "X X XX X X X X X X X",         
        "X X X X X X X X X X X",
        "X X X X XXXXXXXXX X X XXXXX XXXXX X X",
        " X X X X X X X",
        " XX X X XXXXXXX XXXXXXX X X XXXXX",
        " XX X X X XXX X X",
        "X X XXXXXX X XXXXXXXXX X X X",
        "X XXXX X X X XXXXXXXXXXX X",
        "X XXXXXXXXX X XXXXX X X X X",
        "X X X X X XXXXXXX X X XXX X",
        "XXX XXX X X X X X X X X X",
        "X X X XXXXX X XXXXX X XXX X",
        "X X X X X X X X",
        "XAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"}
    }
    
};
