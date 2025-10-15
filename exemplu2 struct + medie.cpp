#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

struct Film {
	char* titlu;
	char* gen;
	int anLansare;
	float rating;
};

void afisareFilm(Film film) {
	cout << "Filmul " << film.titlu << " de genul " << film.gen << " lansat in anul " << film.anLansare << " cu rating-ul de " << film.rating << " este unul dintre cele mai vizionate filme de anul acesta"
		<< endl;
}

float mediaNumere() {
	float medie = 0.0f;
	int suma = 0;
	int dimensiune = 10;
	int numereIntregi[] = { 21,12,23,57,43,87,31,32,76,98 };
	for (int i = 0; i < dimensiune; i++) {
		suma += numereIntregi[i];
	}
	medie = suma / dimensiune;
	return medie;
}

void main() {

	cout << "Mesajul la lansare! " << endl;

	Film film;
		
	film.titlu = new char[strlen("Inception") + 1];
	strcpy(film.titlu, "Inception");
	film.gen = new char[strlen("SF") + 1];
	strcpy(film.gen, "SF");
	film.anLansare = 2021;
	film.rating = 10;

	afisareFilm(film);

	cout << "Media numerelor este: " << mediaNumere() << endl;

		
}
