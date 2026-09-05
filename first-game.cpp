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

void explosione(int x, int y) {
	//explosion 1 y 2 respectivamente
	if (x < 2) x = 2;
	if (x > 117) x = 117;

	Console::SetCursorPosition(x - 2, y - 1); cout << "\\ | /";
	Console::SetCursorPosition(x - 2, y);     cout << "- O -";
	Console::SetCursorPosition(x - 2, y + 1); cout << "/ | \\";
	_sleep(600);
}

void animacion_disparo(int x_inicio, int x_fin, int y, bool acierto) {
	if (acierto) {
		int paso;
		if (x_inicio < x_fin) {
			paso = 1;
		}
		else {
			paso = -1;
		}

		for (int i = x_inicio; i != x_fin; i += paso) {
			Console::SetCursorPosition(i, y);
			cout << "*";
			_sleep(7);
			Console::SetCursorPosition(i, y);
			cout << " ";
		}
		explosione(x_fin, y);
	}
	else {
		explosione(x_inicio, y);
	}
}


void menu_inicio(int alto, int ancho, int x, int y) {
	//110 - 55
	system("color 06");
	system("cls");

	Console::SetCursorPosition((ancho / 2) - 49, y + 4);
	cout << " __   __   __   |     __       __   __      __   __   _  ___  __   __  ___  _   __   __   __ ";
	Console::SetCursorPosition((ancho / 2) - 49, y + 5);
	cout << "|__) |_   |_    |    |_    |  /  \\ (_      |__) |__) |  |  | |\\/| |_   |  |  | /   /  \\ (_  ";
	Console::SetCursorPosition((ancho / 2) - 49, y + 6);
	cout << "| \\  |__  |     |__  |__  \\_/ \\__/ __)     |  | | \\  |  |  | |  | |__  |  |  | \\__ \\__/ __) ";

	Console::SetCursorPosition((ancho / 2) - 20, y + 10);
	cout << "Es un duelo revolver frente a tu rival,";
	Console::SetCursorPosition((ancho / 2) - 22, y + 11);
	cout << "el primero en apuntar tendra que responder";
	Console::SetCursorPosition((ancho / 2) - 22, y + 12);
	cout << "una operacion, si lo resuelves correctamente";
	Console::SetCursorPosition((ancho / 2) - 20, y + 13);
	cout << "tu tiro es efectivo; caso opuesto el tiro";
	Console::SetCursorPosition((ancho / 2) - 22, y + 14);
	cout << "te da a ti mismo y vuelve a iniciar la ronda";
	Console::SetCursorPosition((ancho / 2) - 15, y + 16);
	cout << "Cada uno tiene 3 vidas...";
	Console::SetCursorPosition((ancho / 2) - 10, y + 18);
	cout << "Suerte Vaquero";

	Console::SetCursorPosition((ancho / 2) - 10, y + 21);
	cout << "   O_         _O   ";
	Console::SetCursorPosition((ancho / 2) - 10, y + 22);
	cout << "  /|>-       -<|\\  ";
	Console::SetCursorPosition((ancho / 2) - 10, y + 23);
	cout << "  / \\         / \\  ";


	//----------------------falta esta funcion hacer
	//dibujar_suelo(alto, ancho);

	Console::SetCursorPosition((ancho / 2) - 15, alto - 5);
	cout << "Presione ENTER para continuar";
	_getch();
	system("cls");
}

//Jugador& j1, Jugador& j2


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