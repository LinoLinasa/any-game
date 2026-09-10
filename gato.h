#pragma once
#include <iostream>

using namespace std;
using namespace System;

class gato {
private:
	int x, y;
	int dx, dy;
	char direccion;
	//short color;

	int ancho, alto;
public:
	gato(int px, int py);
	~gato();
	void borrar();
	void mover();
	void dibujar();
	void ACdireccion(char d) { direccion = d; }
	//void define_color(short c);

	//gets para conseguir la info
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	void rebotar() { dx *= -1; dy *= -1; }
};

inline gato::gato(int px, int py)
{
	this->x = px;
	this->y = py;
	this->direccion = 'N';
	//this->color = pcolor;
	this->dx = 0;
	this->dy = 0;
	this->ancho = 7;
	this->alto = 3;
}

inline gato::~gato() {}

//	.	.	. 1 tab
//  .   .   . 3 espacios
inline void gato::borrar() {
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i); cout << "        ";
	}

}
inline void gato::mover() {

	if (direccion == 72) { dx = 0; dy = -1; } // arriba
	if (direccion == 75) { dx = -1; dy = 0; } // izquierda
	if (direccion == 80) { dx = 0; dy = 1; }  // abajo
	if (direccion == 77) { dx = 1; dy = 0; }  // derecha

	if (x + dx >= 1 && x + dx <= 80) x += dx;
	if (y + dy >= 1 && y + dy <= 20) y += dy;

}

inline void gato::dibujar() {
	//define_color(color);
	string hola[] = {
		"|\\---/|",
		"| o_o |",
		" \\_^_/"
	};
	for (int i = 0; i < 3; i++) {
		Console::SetCursorPosition(x, y + i); cout << hola[i];
	}
}