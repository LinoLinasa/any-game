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

void juegoreflejos();
void gatoraton();
void juego_artilleria();


int main() {
    char opcion;
    do {
        system("color 07"); // Color por defecto
        system("cls"); // Limpia la consola
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
        cin >> opcion;

        switch (opcion) {
        case '1':
            juegoreflejos();
            break;
        case '2':
            gatoraton();
            break;
        case '3':
            juego_artilleria();
            break;
        case 0:
            Console::SetCursorPosition(45, 20);
            cout << "Saliendo de la sala de juegos..." << endl;
            break;
        default:
            Console::SetCursorPosition(45, 20);
            cout << "Opcion invalida." << endl;
            _sleep(1000);
            break;
        }
    } while (opcion != 0);

    return 0;
}