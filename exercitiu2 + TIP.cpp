#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {GAMING=3, OFFICE = 7, BUSINESS=10};

class Laptop {
private:
	const int id;
	string brand;
	string model;
	Tip tip;
	int nrPreturiLuni;
	float* preturiPeLuna;
	static int nrLaptopuri;
public:
	Laptop() :id(++nrLaptopuri) {
		this->brand = "Necunoscut";
		this->model = "Necunoscut";
		this->tip = OFFICE;
		this->nrPreturiLuni = 0;
		this->preturiPeLuna = nullptr;
	}
	Laptop(string brand, string model, Tip tip, int nrPreturiLuni, float* preturiPeLunaAleAnului) :id(++nrLaptopuri) {
		this->brand = brand;
		this->model = model;
		this->tip = tip;
		this->nrPreturiLuni = nrPreturiLuni;
		this->preturiPeLuna = new float[this->nrPreturiLuni];
		for (int i = 0; i < this->nrPreturiLuni; i++) {
			this->preturiPeLuna[i] = preturiPeLunaAleAnului[i];
		}
		delete[] preturiPeLunaAleAnului;
	}
	void afisareLaptop() {
		cout << id << ". Laptopul " << this->brand << " , modelul " << this->model << " , care este de ";
		if (this->tip == GAMING) cout << "GAMING";
		if (this->tip == OFFICE) cout << "OFFICE";
		if (this->tip == BUSINESS) cout << "BUSINESS";
		cout << " are un numar de preturi de " << this->nrPreturiLuni << " : " << endl;
		if (this->preturiPeLuna != nullptr) {
			for (int i = 0; i < this->nrPreturiLuni - 1; i++) {
				cout << this->preturiPeLuna[i] << " , ";
			}
			cout << this->preturiPeLuna[this->nrPreturiLuni - 1] << " . ";
		}
	}
	~Laptop() {
		if (this->preturiPeLuna != nullptr) {
			delete[] this->preturiPeLuna;
		}
	}
};

int Laptop::nrLaptopuri = 0;

void main() {
	Laptop ASUS;

	ASUS.afisareLaptop();
	float* preturiPeLuna = new float[4] {6500, 7600, 8400, 12000};
	Laptop* MACBOOK = new Laptop("Apple", "MACBOOK PRO", OFFICE, 4, preturiPeLuna);

	MACBOOK->afisareLaptop();

	delete MACBOOK;
}
