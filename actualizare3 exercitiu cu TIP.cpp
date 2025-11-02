#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {MANAGER=3, ANGAJAT=5, FREELANCER=10};

class CarteDeVizita {
private:
	const int id;
	string nume;
	string functie;
	Tip tip;
	int nrNumereTel;
	string* numereTel;
	static int nrCartiDeVizita;
public:
	CarteDeVizita() :id(++nrCartiDeVizita) {
		this->nume = "Necunoscut";
		this->functie = "Necunoscuta";
		this->tip = FREELANCER;
		this->nrNumereTel = 0;
		this->numereTel = nullptr;
	}
	CarteDeVizita(string nume, string functie, Tip tip, int nrNumereTel, string* numereTelAgenda) :id(++nrCartiDeVizita) {
		this->nume = nume;
		this->functie = functie;
		this->tip = tip;
		this->nrNumereTel = nrNumereTel;
		this->numereTel = new string[this->nrNumereTel];
		for (int i = 0; i < nrNumereTel; i++) {
			this->numereTel[i] = numereTelAgenda[i];
		}
		delete[] numereTelAgenda;
	}
	void afisareCarteDeVizita() {
		cout << id << ". Cartea de vizita " << this->nume << " are functia de " << this->functie << " , este de tipul ";
		if (this->tip == MANAGER) cout << "MANAGER";
		if (this->tip == ANGAJAT) cout << "ANGAJAT";
		if (this->tip == FREELANCER) cout << "FREELANCER";
		cout <<  " si are " << this->nrNumereTel << " numere de telefon " << endl;
		if (this->numereTel != nullptr) {
			for (int i = 0; i < nrNumereTel - 1; i++) {
				cout << this->numereTel[i] << " , ";
			}
			cout << this->numereTel[this->nrNumereTel - 1] << " . ";
		}
		else {
			cout << "Carte de vizita nu are numere de telefon" << endl;
		}
	}
	~CarteDeVizita() {
		if (this->numereTel != nullptr) {
			delete[] this->numereTel;
		}
	}
};

int CarteDeVizita::nrCartiDeVizita = 0;

void main() {
	CarteDeVizita NacuRobert;

	NacuRobert.afisareCarteDeVizita();
	string* numereTel = new string[2] {"0723345093" , "0745932156"};
	CarteDeVizita* CristianAndrei = new CarteDeVizita("CristianAndrei", "Manager", FREELANCER, 2, numereTel);

	CristianAndrei->afisareCarteDeVizita();

	delete CristianAndrei;
}
