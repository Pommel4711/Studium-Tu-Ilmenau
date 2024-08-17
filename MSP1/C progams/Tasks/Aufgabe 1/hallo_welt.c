/******************************************************************************
* Dies ist ein Startprojekt für die Veranstaltung "Mikrocontroller- und
* Signalprozessortechnik 1" des Fachgebiets Leistungselektronik und
* Steuerungen in der Elektroenergietechnik der TU Ilmenau, das Sie zum
* Testen Ihrer Entwicklungsumgebung und als Ausgangspunkt für eigene
* Arbeiten nutzen können.
*
* Zum Kompilieren des Projekts können Sie unter Linux/MinGW den Befehl
* gcc -std=c99 -o hallo_welt hallo_welt.c
* in der Kommandozeile nutzen. (Sie benötigen den Compiler gcc.) Zum
* Ausführen verwenden Sie
* Linux: ./hallo_welt
* Windows: hallo_welt bzw. hallo_welt.exe
*
*******************************************************************************/
#include <stdio.h>

int main()
{
    // der übliche Start in eine neue Programmiersprache
    printf("Hallo Welt!\n");

    /* Für die einfachen Beispiele im Rahmen der Veranstaltung können
     * Sie printf auch praktisch zur Fehlersuche nutzen, und sich bspw.
     * den Inhalt von Variablen ausgeben lassen.
    */
    int i=5;
    printf("Variable i hat den Wert %d.\n",i);
    
    return 0;
}
