#define _CRT_SECURE_NO_WARNING
#include<iostream>
#include<cstring>

using namespace std;

float mediaTemperaturilor() {
	float medie = 0.0f;
	int suma = 0;
	int dimensiune = 7;
	int numereIntregi[] = { 20, 22, 18, 25, 27, 30, 28 };
	for (int i = 0; i < dimensiune; i++) {
		suma += numereIntregi[i];
	}
	medie = suma / dimensiune;

	cout << "Media temperaturilor din aceasta saptamana este: " << mediaTemperaturilor << endl;

	return medie;

}
