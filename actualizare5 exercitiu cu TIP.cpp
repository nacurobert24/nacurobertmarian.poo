#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {SPORT=6, SUV = 9, FAMILY = 3};

class Masina {
private:
	const int id;
	string marca;
	string model;
	Tip tip;
	int nrRevizii;
	float* costRevizii;
	static int nrMasini;
public:
	Masina() :id(++nrMasini) {
		this->marca = "Necunoscut";
		this->model = "Anonim";
		this->tip = SUV;
		this->nrRevizii = 0;
		this->costRevizii = nullptr;
	}
	Masina(string marca, string model, Tip tip, int nrRevizii, float* costReviziiMasina) :id(++nrMasini) {
		this->marca = marca;
		this->model = model;
		this->tip = tip;
		this->nrRevizii = nrRevizii;
		this->costRevizii = new float[this->nrRevizii];
		for (int i = 0; i < this->nrRevizii; i++) {
			this->costRevizii[i] = costReviziiMasina[i];
		}
		delete[] costReviziiMasina;
	}
	void afisareMasina() {
		cout << id << ". Masina " << this->marca << " , modelul " << this->model << " , de tipul ";
		if (this->tip == SPORT) cout << "SPORT";
		if (this->tip == SUV) cout << "SUV";
		if (this->tip == FAMILY) cout << "FAMILY";
		cout << " are un numar de " << this->nrRevizii << " revizii: " << endl;
		if (this->costRevizii != nullptr) {
			for (int i = 0; i < nrRevizii - 1; i++) {
				cout << this->costRevizii[i] << " , ";
			}
			cout << this->costRevizii[this->nrRevizii - 1] << " . ";
		}
		else {
			cout << "Masina nu are revizia facuta! " << endl;
		}
	}
	~Masina() {
		if (this->costRevizii != nullptr) {
			delete[] this->costRevizii;
		}
	}
};

int Masina::nrMasini = 0;

void main() {
	Masina Dacia;

	Dacia.afisareMasina();
	float* costRevizii = new float[4] {1, 2, 3, 4};
	Masina* KIA = new Masina("KIA", "CEED", SUV, 4, costRevizii);

	KIA->afisareMasina();

	delete KIA;
}
