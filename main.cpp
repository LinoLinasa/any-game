#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <windows.h>
#include <string>
//#include "gato + ratones game.cpp"
//#include "other things.cpp"
//#include "first-game.cpp"

#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30

using namespace std;
using namespace System;

void juegoreflejos(bool idioma);
void gatoraton( bool idioma );
void juego_artilleria(bool idioma);

bool menuIdioma() {

    char idioma;

    do {
        system("cls"); // Limpia la consola
        Console::SetCursorPosition(45, 10);
        cout << "Choose your language";
        Console::SetCursorPosition(45, 12);
        cout << "Elije tu idioma";

        Console::SetCursorPosition(45, 16);
        cout << "Choose your option (E: English; S: Spanish): "; cin >> idioma;
    } while (idioma != 'E' && idioma != 'S'&& idioma != 'e'&& idioma != 's');
    if(idioma == 'E' || idioma == 'e') return false;
    else return true;
}

int main() {
    char opcion;
    bool lenguaje;
    lenguaje = menuIdioma();
    do {
        system("cls");
            if (lenguaje) {
                Console::SetCursorPosition(45, 10);
                cout << "=== MENU PRINCIPAL ===";
                Console::SetCursorPosition(45, 12);
                cout << "1. Duelo de Reflejos";
                Console::SetCursorPosition(45, 13);
                cout << "2. Gato y Ratones";
                Console::SetCursorPosition(45, 14);
                cout << "3. Artilleria";
                Console::SetCursorPosition(45, 16);
                cout << "0. Salir del programa";
                Console::SetCursorPosition(45, 18);
                cout << "Elige una opcion: ";
            }
            else {
                Console::SetCursorPosition(45, 10);
                cout << "=== MAIN MENU ===";
                Console::SetCursorPosition(45, 12);
                cout << "1. Battle of Reflexes";
                Console::SetCursorPosition(45, 13);
                cout << "2. Cat and Mice";
                Console::SetCursorPosition(45, 14);
                cout << "3. Artillery";
                Console::SetCursorPosition(45, 16);
                cout << "0. Exit program";
                Console::SetCursorPosition(45, 18);
                cout << "Choose an option: ";
            }
            cin >> opcion;

            switch (opcion) {
            case '1':
                juegoreflejos(lenguaje);
                break;
            case '2':
                gatoraton(lenguaje);
                break;
            case '3':
                juego_artilleria(lenguaje);
                break;
            case '0':
                Console::SetCursorPosition(45, 20);
                if (lenguaje) cout << "Saliendo de la sala de juegos..." << endl;
                else cout << "Leaving the arcade..." << endl;
                break;
            default:
                Console::SetCursorPosition(45, 20);
                if (lenguaje) cout << "Opcion invalida." << endl;
                else cout << "Invalid option." << endl;
                _sleep(1000);
                break;
            }
        } while (opcion != '0');
    return 0;
}