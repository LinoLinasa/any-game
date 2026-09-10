#pragma once
#include "iostream"
using namespace std;
using namespace System;

inline string menu()
{
	string op;
	cout << endl << " \t\t " << " MENU ";
	cout << endl << " \t " << " 1. AVION ";
	cout << endl << " \t " << " 2. AUTO ";
	cout << endl << " \t " << " 3. BARCO ";
	cout << endl << " \t " << " 4. TREN ";

	cout << endl << endl << " Elija una opcion: ";
	cin >> op;

	return op;
}

inline bool hayColision(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
	//retorna true si pasa esto
	return (x1 < x2 + ancho2 &&
		x1 + ancho1 > x2 &&
		y1 < y2 + alto2 &&
		y1 + alto1 > y2);
}