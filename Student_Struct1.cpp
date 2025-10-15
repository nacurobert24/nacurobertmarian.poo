#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct Student {
	char* nume;
	char* facultate;
	char* oras;
	bool bursier;
	int varsta;
	int media;
};

void afisareStudent(Student student) {
	cout << "Studentul " << student.nume << " care este la facultatea " << student.facultate << " din orasul " << student.oras<<  " ,ce are varsta de " << student.varsta << " ani" << " are media de " <<student.media << " iubeste sa mearga la facultatea sa!" << endl;
}

struct Student1 {
	char* nume;
	char* facultate;
	char* oras;
	int varsta;
	int media;
};

void afisareStudent1(Student1 student1) {
	cout << "Studentul " << student1.nume << " in varsta de " << student1.varsta << " care este la facultatea " << student1.facultate << " din orasul " << student1.oras << " are media de " << student1.media << " si ii place foarte mult sa descopere cat mai multe hobby-uri noi, odata cu a invata pentru facultatea sa! " << endl;
}

void main() {
	cout << "Mesajul catre consola!" << endl;
	Student student;
	student.varsta = 21;
	student.media = 9;
	student.nume = new char[strlen("Vlad") + 1];
		strcpy(student.nume, "Vlad");
		student.facultate = new char[strlen("ASE") + 1];
		strcpy(student.facultate, "ASE");
		student.oras = new char[strlen("Bucuresti") + 1];
		strcpy(student.oras, "Bucuresti");
		student.bursier = true;

		afisareStudent(student);

		delete[] student.nume;
		delete[] student.facultate;
		delete[] student.oras;

		Student1 student1;
		student1.varsta = 22;
		student1.media = 8;
		student1.nume = new char[strlen("Robert") + 1];
		strcpy(student1.nume, "Robert");
		student1.facultate = new char[strlen("ASE") + 1];
		strcpy(student1.facultate, "ASE");
		student1.oras = new char[strlen("Bucuresti") + 1];
		strcpy(student1.oras, "Bucuresti");

		afisareStudent1(student1);

		delete[] student1.nume;
		delete[] student1.facultate;
		delete[] student1.oras;
}

/*struct Student1 {
	char* nume;
	char* facultate;
	char* oras;
	int varsta;
	int media;
};

void afisareStudent1(Student1 student) {
	cout << "Studentul " << student.nume << " in varsta de " << student.varsta << " care este la facultatea " << student.facultate << " din orasul " << student.oras << " are media de " << student.media << " si ii place foarte mult sa descopere cat mai multe hobby-uri, odata cu a invata pentru facultatea sa! " << endl;
}
*/
