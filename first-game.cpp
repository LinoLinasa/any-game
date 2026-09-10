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

//aca es para setear el ancho de la pantalla  con valores define 

#define MAPAS 4
#define CASILLAS 15

void gatoraton();
void juegovehiculos();

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

//Juego reflejos -------------------------------------------------------------------------------------------------

void recuadro(int alto, int ancho, int x, int y) {
	// Reducido a 60 de ancho total
	int salto = 26;

	Console::SetCursorPosition((ancho / 2) - salto, y);
	cout << " ______________________________________________________ ";
	Console::SetCursorPosition((ancho / 2) - salto, y + 1);
	cout << "/                                                      \\";
	Console::SetCursorPosition((ancho / 2) - salto, y + 2);
	cout << "|                                                      |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 3);
	cout << "|                                                      |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 4);
	cout << "|                                                      |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 5);
	cout << "|                                                      |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 6);
	cout << "|                                                      |";
	Console::SetCursorPosition((ancho / 2) - salto, y + 7);
	cout << "\\______________________________________________________/";
}

void limpiar_interior_recuadro(int ancho, int y) {
	for (int i = 2; i <= 6; i++) {
		//-39
		Console::SetCursorPosition((ancho / 2) - 25, y + i);
		cout << "                                                      ";
	}
}

void preparado_texto(int alto, int ancho, int x, int y) {
	int mitad_largo = 21;
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 2);
	cout << " __   __   __   __   _   __   _   __   _   __  ? ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 3);
	cout << "|__) |__) |_   |__) / \\ |__) / \\ |  \\ / \\ (_   ? ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 4);
	cout << "|    | \\  |__  |    |-| | \\  |-| |_/  \\_/ __)  ? ";
}

void listos_texto(int alto, int ancho, int x, int y) {
	int mitad_largo = 13;
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 2);
	cout << "|     _   __   ___  _   __  ? ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 3);
	cout << "|     |  (_     |  / \\ (_   ? ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 4);
	cout << "|__   |  __)    |  \\_/ __)  ? ";
}

void esperen_texto(int alto, int ancho, int x, int y) {
	//ns pq la n parece una d
	int mitad_largo = 17;

	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 2);
	cout << " __   __   __   __   __   __  |\\ | ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 3);
	cout << "|_   (_   |__) |_   |__) |_   | \\| ";
	Console::SetCursorPosition((ancho / 2) - mitad_largo, y + 4);
	cout << "|__  __)  |    |__  | \\  |__  |  | ";
}

void dibujar_suelo(int alto, int ancho) {
	for (int j = 1; j <= 3; j++) {
		Console::SetCursorPosition(0, alto - j);
		Console::BackgroundColor = ConsoleColor::DarkYellow;
		for (int i = 0; i < ancho; i++) {
			Console::ForegroundColor = ConsoleColor::White;
			int prob = rand() % 10;
			if (prob == 0) cout << ".";
			else if (prob == 1) cout << "~";
			else if (prob == 2) cout << " *";
			else cout << " ";
		}
	}
	Console::ResetColor();
}

void cactus(int x, int y) {
	string lineas[]{
		"              _   _",
		"             / '-' \\",
		"            ;       ;",
		"         /'-|       |-'\\",
		"        \\   '-------'   /",
		"         '.___.....___.'",
		"           _|;__;__.|_",
		"          |     Y     |    .--.",
		" .--.      \\__.'^'.__/    /;   \\",
		"|   ;\\      |_  ;  _|     |  ' |",
		"| ;  |      { ````` }     |;   |",
		"| ;  \\      |;  ;   |_____/ ;  |",
		"|   '.'-----'      ' -_   .'   /",
		" '.   -     - ;  ;   .------`",
		"   `--------.       ;|",
		"            |;  ,   |",
		"            `-------`"
	};
	for (int i = 0; i < 17; i++) {
		int targetY = y + i;
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, targetY);
		cout << lineas[i];
	}
	Console::ResetColor();
}

void dibujarescenario_estatico(int alto, int ancho, int& vidasJ1, int& vidasJ2, int altura_base) {
	int xcactus0 = ancho / 8;
	int xcactus1 = ancho - (ancho / 4);

	dibujar_suelo(alto, ancho);
	cactus(xcactus0, altura_base);
	cactus(xcactus1, altura_base);

	Console::SetCursorPosition(2, 2);
	cout << "Vidas J1 (A): ";
	for (int i = 0; i < vidasJ1; i++) cout << "()";

	Console::SetCursorPosition(ancho - 26, 2);
	cout << "Vidas J2 (L): ";
	for (int i = 0; i < vidasJ2; i++) cout << "()";
}

int generaroperacion(int ancho, int y_recuadro) {
	//numeros aleatorios
	int num1 = (rand() % 15) + 1;
	int num2 = (rand() % 15) + 1;

	//Operacion aleatoria
	int tipo = rand() % 11;
	int respuesta = 0;
	string operador = "";

	if (tipo == 0 || tipo == 1 || tipo == 2 || tipo == 3 || tipo == 8) {
		operador = "+";
		respuesta = num1 + num2;
	}
	else if (tipo == 4 || tipo == 5 || tipo == 6 || tipo == 7 || tipo == 10) {
		operador = "-";
		respuesta = num1 - num2;
	}
	else if (tipo == 9) {
		operador = "x";
		respuesta = num1 * num2;
	}

	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 3);
	cout << "Rapido! Cuanto es: " << num1 << " " << operador << " " << num2 << "?: ";

	return respuesta;
}

void jugarronda(int alto, int ancho, int& vidasJ1, int& vidasJ2) {
	system("cls");

	int altura_base = alto - 33;
	if (altura_base < 10) altura_base = 10;

	dibujarescenario_estatico(alto, ancho, vidasJ1, vidasJ2, altura_base);

	int y_recuadro = 1;

	//1
	recuadro(alto, ancho, 0, y_recuadro);
	preparado_texto(alto, ancho, 0, y_recuadro);
	_sleep(1500);

	// Se agrega la fase "Listos"
	limpiar_interior_recuadro(ancho, y_recuadro);
	listos_texto(alto, ancho, 0, y_recuadro);
	_sleep(1500);

	//2
	limpiar_interior_recuadro(ancho, y_recuadro);
	esperen_texto(alto, ancho, 0, y_recuadro);

	// rand de max 15 seg y min 3 seg
	int tiempo_tension = (rand() % 13) + 3;

	for (int i = 0; i < tiempo_tension; i++) {
		Console::SetCursorPosition((ancho / 2) - 10 + i, y_recuadro + 5);
		_sleep(1000);
		cout << "O";
	}

	//3
	limpiar_interior_recuadro(ancho, y_recuadro);
	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 3);
	cout << "!!! DISPAREN (J1:A / J2:L) !!!";

	bool disparo_realizado = false;
	char tecla_presionada = ' ';

	while (!disparo_realizado) {
		if (_kbhit()) {
			tecla_presionada = _getch();
			if (tecla_presionada == 'a' || tecla_presionada == 'A' ||
				tecla_presionada == 'l' || tecla_presionada == 'L') {
				disparo_realizado = true;
			}
		}
	}

	Console::SetCursorPosition((ancho / 2) - 15, y_recuadro + 4);
	if (tecla_presionada == 'a' || tecla_presionada == 'A') {
		cout << "Jugador 1 apunto primero!";
	}
	else {
		cout << "Jugador 2 apunto primero!";
	}
	_sleep(1000);

	//4
	limpiar_interior_recuadro(ancho, y_recuadro);
	int respuesta_correcta = generaroperacion(ancho, y_recuadro);
	int respuesta_jugador;
	cin >> respuesta_jugador;

	int y_brazo = altura_base + 4;
	int x_J1 = (ancho / 8) + 28;
	int x_J2 = ancho - (ancho / 4);

	// evaluo si el tiro salio bien o le salió por la culata
	Console::SetCursorPosition((ancho / 2) - 20, y_recuadro + 5);
	if (respuesta_jugador == respuesta_correcta) {
		cout << "¡RESPUESTA CORRECTA! Tiro acertado.        ";
		if (tecla_presionada == 'a' || tecla_presionada == 'A') {
			animacion_disparo(x_J1, x_J2, y_brazo, true);
			vidasJ2--;
		}
		else {
			animacion_disparo(x_J2, x_J1, y_brazo, true);
			vidasJ1--;
		}
	}
	else {
		cout << "¡ERROR! El arma te exploto en la cara.     ";
		if (tecla_presionada == 'a' || tecla_presionada == 'A') {
			animacion_disparo((ancho / 8) + 14, 0, y_brazo, false);
			vidasJ1--;
		}
		else {
			animacion_disparo((ancho - (ancho / 4)) + 14, 0, y_brazo, false);
			vidasJ2--;
		}
	}

	_sleep(1000);
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

	dibujar_suelo(alto, ancho);

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

	menu_inicio(alto, ancho, 0, 0);

	while (vidasJ1 > 0 && vidasJ2 > 0) {
		jugarronda(alto, ancho, vidasJ1, vidasJ2);
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
		//j1.estrellas += 1;
		//j1.monedas += 10;
	}
	else {
		cout << "¡GANA EL JUGADOR 2!";
		//despues quitarle lo del comentado
		//j2.minijuegosGanados += 1;
		//j2.estrellas += 1;
		//j2.monedas += 10;
	}

	Console::SetCursorPosition((ancho / 2) - 16, (alto / 2) - 2);
	cout << "Presione ENTER para salir...";

	char tecla = ' ';
	while (tecla != 13) { // el char de enter...
		tecla = _getch();
	}
}
//
//int main() {
//	juegoreflejos();
//	gatoraton();
//	juegovehiculos();
//}