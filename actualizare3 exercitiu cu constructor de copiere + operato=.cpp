/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip { BIO = 3, NORMAL = 1, DE_BAZA = 7 };

class ProdusAlimentar {
private:
	float pret;
	const int id;
	string denumire;
	Tip tip;
	int nrIngrediente;
	float* cantitati;
	static int nrProduseAlimentare;
public:
	ProdusAlimentar() :id(++nrProduseAlimentare) {
		this->pret = 0;
		this->denumire = "Produs default";
		this->tip = BIO;
		this->nrIngrediente = 0;
		this->cantitati = nullptr;
	}
	ProdusAlimentar(float pret, string denumire, Tip tip, int nrIngrediente, float* cantitatiIngrediente) :id(++nrProduseAlimentare) {
		this->pret = pret;
		this->denumire = denumire;
		this->tip = tip;
		this->nrIngrediente = nrIngrediente;
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiIngrediente[i];
		}
		delete[] cantitatiIngrediente;
	}
	
	//constructor de copiere

	ProdusAlimentar(const ProdusAlimentar& copie) :id(++nrProduseAlimentare) {
		this->pret = copie.pret;
		this->denumire = copie.denumire;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;
		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
	}

	//operator=

	void operator=(const ProdusAlimentar& copie) {
		this->pret = copie.pret;
		this->denumire = copie.denumire;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
	}

	void afisareProdusAlimentar() {
		cout << id << ". Produsul alimentar " << this->denumire << " se gaseste doar la pretul de " << this->pret << " lei, este de tipul ";
		if (this->tip == BIO) cout << "BIO";
		if (this->tip == NORMAL) cout << "NORMAL";
		if (this->tip == DE_BAZA) cout << "DE BAZA";
		cout << " si contine un numar de " << this->nrIngrediente << " ingrediente " << endl;
		if (this->cantitati != nullptr) {
			for (int i = 0; i < nrIngrediente - 1; i++) {
				cout << this->cantitati[i] << " grame, ";
			}
			cout << this->cantitati[this->nrIngrediente - 1] << " grame. ";
		}
	}
	~ProdusAlimentar() {
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
	}
};

int ProdusAlimentar::nrProduseAlimentare = 0;

void main() {
	ProdusAlimentar spanac;

	spanac.afisareProdusAlimentar();
	float* cantitati = new float[3] {200, 300, 400};
	ProdusAlimentar* paste = new ProdusAlimentar(265, "paste", BIO, 3, cantitati);

	paste->afisareProdusAlimentar();

	ProdusAlimentar produs(*paste);
	produs.afisareProdusAlimentar();

	spanac = *paste;
	spanac.afisareProdusAlimentar();

	delete paste;
}
*/
