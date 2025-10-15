#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

struct Carte {
	char* titlu;
	char* autor;
	int anPublicatie;
	double pret;
};

void afisareCarte(Carte carte) {
	cout << "Cartea " << carte.titlu << " scrisa de catre " << carte.autor << " a fost publicata in anul " << carte.anPublicatie << " si costa " << carte.pret << " lei " << endl;
}

struct Carte1 {
	char* titlu;
	char* autor;
	int anPublicatie;
	double pret;
};

void afisareCarte1(Carte1 carte1) {
	cout << "Cartea " << carte1.titlu << " scrisa de catre autorul " << carte1.autor << " a aparut in anul " << carte1.anPublicatie << " la pretul de " << carte1.pret << " lei" << " si este una dintre cele mai interesante carti despre astrologie! " << endl;
}

struct Student {
	char* nume;
	char* prenume;
	char* locatie;
	int varsta;
};

void afisareStudent(Student student) {
	cout << "Studentul " << student.nume << " " << student.prenume << " din orasul " << student.locatie << " in varsta de " << student.varsta << " de ani " << "a cumparat cele doua carti si este foarte multumit de ele" << endl;
}

struct Student1 {
	char* nume;
	char* prenume;
	char* locatie;
	int varsta;
};

void afisareStudent1(Student1 student1) {
	cout << "Studentul " << student1.nume << " " << student1.prenume << " din orasul " << student1.locatie << " care are varsta de " << student1.varsta << " a cumparat doar una dintre carti, cea de astrologie si este foarte incantat de alegerea facuta! " << endl;
}

void main() {

	cout << "Mesajul la consola!" << endl;

	Carte carte;
	carte.titlu = new char[strlen("Atmosfera") + 1];
	strcpy(carte.titlu, "Atmosfera");
	carte.autor = new char[strlen("Mihai Andronache") + 1];
	strcpy(carte.autor, "Mihai Andronache");
	carte.anPublicatie = 2021;
	carte.pret = 200;

	afisareCarte(carte);

	delete[] carte.titlu;
	delete[] carte.autor;

	Carte1 carte1;

	carte1.titlu = new char[strlen("Aventurile cosmice") + 1];
	strcpy(carte1.titlu, "Aventurile cosmice");
	carte1.autor = new char[strlen("Robert Marian") + 1];
	strcpy(carte1.autor, "Robert Marian");
	carte1.anPublicatie = 2025;
	carte1.pret = 50;

	afisareCarte1(carte1);

	delete[] carte1.titlu;
	delete[] carte1.autor;

	Student student;

	student.nume = new char[strlen("Cristian") + 1];
	strcpy(student.nume, "Cristian");
	student.prenume = new char[strlen("Lucian") + 1];
	strcpy(student.prenume, "Lucian");
	student.locatie = new char[strlen("Bucuresti") + 1];
	strcpy(student.locatie, "Bucuresti");
	student.varsta = 21;

	afisareStudent(student);

	delete[] student.nume;
	delete[] student.prenume;
	delete[] student.locatie;

	Student1 student1;

	student1.nume = new char[strlen("Mihai") + 1];
	strcpy(student1.nume, "Mihai");
	student1.prenume = new char[strlen("Constantin") + 1];
	strcpy(student1.prenume, "Constantin");
	student1.locatie = new char[strlen("Craiova") + 1];
	strcpy(student1.locatie, "Craiova");

	delete[] student1.nume;
	delete[] student1.prenume;
	delete[] student1.locatie;
}
