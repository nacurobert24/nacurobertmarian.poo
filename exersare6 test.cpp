#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
	const int id;
	string nume;
	string facultate;
	int nrNote;
	float* note;
	static int nrStudenti;
public:
	Student() :id(++nrStudenti) {
		this->nume = "Anonim";
		this->facultate = "Necunoscuta";
		this->nrNote = 0;
		this->note = nullptr;
	}
	Student(string nume, string facultate, int nrNote, float* noteLaScoala) :id(++nrStudenti) {
		this->nume = nume;
		this->facultate = facultate;
		this->nrNote = nrNote;
		this->note = new float[this->nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			this->note[i] = noteLaScoala[i];
		}
		delete[] noteLaScoala;
	}
	void afisareStudent() {
		cout << id << ". Studentul " << this->nume << " care se afla la facultatea " << this->facultate << " are un numar de " << this->nrNote << " note: " << endl;
		if (this->note != nullptr) {
			for (int i = 0; i < nrNote - 1; i++) {
				cout << this->note[i] << " la scoala, ";
			}
			cout << this->note[this->nrNote - 1] << " la scoala. ";
		}
		else {
			cout << "Studentul nu are note." << endl;
		}
	}
	~Student() {
		if (this->note != nullptr) {
			delete[] this->note;
		}
	}
};

int Student::nrStudenti = 0;

void main() {
	Student Robert;

	Robert.afisareStudent();
	float* note = new float[5] {7, 8, 9, 10, 6};
	Student* Andrei = new Student("Andrei", "Cibernetica", 5, note);

	Andrei->afisareStudent();

	delete Andrei;
}
