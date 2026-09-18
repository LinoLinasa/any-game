#include <iostream>
#include <conio.h>
#include <ctime>
#include "gato.h"
#include "rata.h"
#include "misfunciones.h"

using namespace std;
using namespace System;


short cantratas(bool idioma)
{
	short rat;
	if (idioma) {
		short rat;
		do {
			cout << endl << "\t\t" << "Menu";
			cout << endl << "\t" << "Juego del gato y del raton(es)";
			cout << endl << "\t" << "Defina la cant de ratones que quiere en el juego";
			cout << endl << "\t" << "Escriba '0' para que la cant sea aleatoria (max 10 ratas)";
			cout << endl << "\t" << "Presione 11 para salir";
			cout << endl << "\t" << "Cant. raton(es): ";
			cin >> rat;
		} while (rat < 0 || rat > 11);
		if (rat == 0) rat = rand() % 10 + 1;
		return rat;
		}
		else {
		do {
			cout << endl << "\t\t" << "Menu";
			cout << endl << "\t" << "Cat-and-mouse game";
			cout << endl << "\t" << "Define the number of mice you want in the game.";
			cout << endl << "\t" << "Enter '0' for a random quantity (max. 10 rats).";
			cout << endl << "\t" << "Press '11' to exit.";
			cout << endl << "\t" << "Qty. of mouse/mice:";
			cin >> rat;
		} while (rat < 0 || rat > 11);
		if (rat == 0) rat = rand() % 10 + 1;
		return rat;
		}
}

//rata** ratacion(rata** arreglo, int& cant, int eliminado) {
//
//	//se rompia con una sola rat
//	if (cant == 1) {
//		arreglo[eliminado]->borrar();
//		delete arreglo[eliminado];
//		delete[] arreglo;
//		cant--;
//		return NULL; // retorna nulo porque ya no hay ratas
//	}
//
//	rata** temporal = new rata * [cant - 1];
//
//	arreglo[eliminado]->borrar();
//	delete arreglo[eliminado];
//
//	int a = 0;
//	for (int i = 0; i < cant; i++) {
//		if (i != eliminado) {
//			temporal[a] = arreglo[i];
//			a++;
//		}
//	}
//	delete[] arreglo;
//	cant--;
//	return temporal;
//}


void gatoraton(bool idioma)
{
	srand(time(NULL));
	Console::CursorVisible = false;
	gato* gato1;
	rata** ratas;
	int cantrat;

	while (1) {
		Console::Clear();
		cantrat = cantratas(idioma);
		if (cantrat == 11) break;
		Console::Clear();
		int posx1 = 5 + rand() % 76;
		int posy1 = 3 + rand() % 16;
		
		//declaramos tds los obj a usar
		ratas = new rata * [cantrat];
		gato1 = new gato(posx1, posy1);

		for (int i = 0; i < cantrat; i++) {
			int posx2 = 5 + rand() % 76;
			int posy2 = 3 + rand() % 16;
			ratas[i] = new rata(posx2, posy2);
		}

		int contador = 0;

		while (1) {

			if (kbhit()) {
				char tecla = getch();
				if (tecla == 27) break;
				if (tecla == -32 || tecla == 224) {
					tecla = getch();
					gato1->ACdireccion(tecla);
				}
			}

			//borrar
			gato1->borrar();
			for (int i = 0; i < cantrat; i++) {
				ratas[i]->borrar();
			}
			//mover
			gato1->mover();
			for (int i = 0; i < cantrat; i++) {
				ratas[i]->mover();
			}
			//coalision
			// 
			//entre ratas
			for (int i = 0; i < cantrat; i++) {
				for (int j = 0; j < cantrat; j++) {
					if (i == j) continue;

					if (hayColision(
						ratas[i]->getX(),
						ratas[i]->getY(),
						ratas[i]->getAncho(),
						ratas[i]->getAlto(),
						ratas[j]->getX(),
						ratas[j]->getY(),
						ratas[j]->getAncho(),
						ratas[j]->getAlto()))
					{
						ratas[i]->rebotar();
						ratas[i]->mover();
						ratas[j]->rebotar();
						ratas[j]->mover();
					}
				}
			}

			//

			for (int i = 0; i < cantrat; i++) {
				if (hayColision(
					ratas[i]->getX(),
					ratas[i]->getY(),
					ratas[i]->getAncho(),
					ratas[i]->getAlto(),
					gato1->getX(),
					gato1->getY(),
					gato1->getAncho(),
					gato1->getAlto())) {

					contador++;

					ratas[i]->borrar();
					delete ratas[i]; // borramos el ratón viejo de memoria

					// Reaparece en una nueva posición aleatoria (siguen apareciendo en consola)
					int nuevoX = 5 + rand() % 70;
					int nuevoY = 3 + rand() % 15;
					ratas[i] = new rata(nuevoX, nuevoY);
				}
			}

			//dibujar
			gato1->dibujar();
			for (int i = 0; i < cantrat; i++) {
				ratas[i]->dibujar();
			}

			// CAMBIO RETO 2: Mostrar el contador en pantalla en la esquina superior
			Console::SetCursorPosition(2, 1);
			if(idioma) cout << "Ratones atrapados: " << contador;
			else cout << "Trapped mice: " << contador;

			_sleep(100);

		}

		delete gato1;
		for (int i = 0; i < cantrat; i++) {
			delete ratas[i];
		}
		delete[] ratas;
	}
}