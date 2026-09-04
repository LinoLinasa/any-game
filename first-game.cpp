#include <iostream>
#include <conio.h>
#include <cmath>
#include <ctime>
#include <cstdlib> 
#include <windows.h>
#include <string>

#define ANCHO_PANTALLA 120
#define ALTO_PANTALLA 30

using namespace std;
using namespace System;

void juegoreflejos() {
	srand(time(NULL));
	Console::CursorVisible = false;

	int alto = 30;
	int ancho = 120;


	//creo que voy a necesitar el nombre de los jugadores // es verdad, nah ya fue, para q?

	int vidasJ1 = 3;
	int vidasJ2 = 3;
	//----------------falta hacer la funcion
	//menu_inicio(alto, ancho, 0, 0);

	while (vidasJ1 > 0 && vidasJ2 > 0) {
		//----------------falta hacer la funcion
		//jugarronda(alto, ancho, vidasJ1, vidasJ2);
	}

	system("cls");
	Console::SetCursorPosition((ancho / 2) - 10, alto / 2);
	//ahora que lo pienso... jamas pasara un empate
	//if (vidasJ1 == 0 && vidasJ2 == 0) {
	//	cout << "¡EMPATE! Ambos cayeron.";
	//}
	if (vidasJ1 > 0) {
		cout << "¡GANA EL JUGADOR 1!";
		//despues quitarle lo del comentado
		//j1.minijuegosGanados += 1;
	}
	else {
		cout << "¡GANA EL JUGADOR 2!";
		//despues quitarle lo del comentado
		//j2.minijuegosGanados += 1;
	}

	Console::SetCursorPosition((ancho / 2) - 16, (alto / 2) - 2);
	cout << "Presione ENTER para salir...";

	char tecla = ' ';
	while (tecla != 13) { // el char de enter...
		tecla = _getch();
	}
}

int main() {
	juegoreflejos();
}