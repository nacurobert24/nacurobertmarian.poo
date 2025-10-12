#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

struct Produs {
	char* nume;
	char* locatie;
	int cantitate;
	int pret;
};

void afisareProdus(Produs produs) {
	cout << "Produsul " << produs.nume << " care se afla in locatia " << produs.locatie << " se vine in cantitati mari, de " << produs.cantitate << " kg " << " la un pret foarte avantajos, de doar " << produs.pret << endl;
}

float mediaNumere() {
	float medie = 0.0f;
	int suma = 0; 
	int dimensiune = 8;
	int numereIntregi[] = {45, 34, 12, 78, 50, 41, 99, 32};
	for (int i = 0; i < dimensiune; i++) {
		suma += numereIntregi[i];
	}
	medie = suma / dimensiune;
	return medie;
}

void main() {
	cout << "Mesajul la consola! " << endl;
	Produs produs;

	produs.nume = new char[strlen("Telefon") + 1];
	strcpy(produs.nume, "Telefon");
	produs.locatie = new char[strlen("Bucuresti") + 1];
	strcpy(produs.locatie, "Bucuresti");
	produs.cantitate = 40;
	produs.pret = 2150;

	afisareProdus(produs);

	cout << "Media numerelor este: " << mediaNumere() << endl;

	delete[] produs.nume;
	delete[] produs.locatie;

	

}

