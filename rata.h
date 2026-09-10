#pragma once
#include <iostream>

using namespace std;
using namespace System;

class rata {
private:
	int x, y;
	int dx, dy;
	//short color;

	int ancho, alto;
public:
	rata(int px, int py);
	~rata();
	void borrar();
	void mover();
	void dibujar();
	//void define_color(short c);


	//gets para conseguir la info
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	void rebotar() { dx *= -1; dy *= -1; }
};

inline rata::rata(int px, int py)
{
	this->x = px;
	this->y = py;
	//this->color = pcolor;
	this->dx = 1;
	this->dy = 1;
	this->ancho = 14;
	this->alto = 4;
	dx = rand() % 2;
	if (dx == 0) dx = 1;
	else dx = -1;
	dy = rand() % 2;
	if (dy == 0) dy = 1;
	else dy = -1;
}

inline rata::~rata() {}

//	.	.	. 1 tab
//  .   .   . 3 espacios
inline void rata::borrar() {
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x, y + i); cout << "              ";
	}

}
inline void rata::mover() {
	if (x + dx < 1 || x + dx >= 92) dx *= -1;
	if (y + dy < 1 || y + dy >= 22) dy *= -1;

	x += dx;
	y += dy;
}

inline void rata::dibujar() {
	//define_color(color);
	string hola[] = {
	" _  _",
	"(o)(o)--.",
	" \\.. / ( )",
	" m\\ /m--m'`--."
	};
	for (int i = 0; i < 4; i++) {
		Console::SetCursorPosition(x, y + i); cout << hola[i];
	}
}