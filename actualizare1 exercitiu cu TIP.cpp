#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {SMARTPHONE=5, FEATURE_PHONE=6, FLAGSHIP=9};

class Telefon {
private:
	const int id;
	string marca;
	string model;
	Tip tip;
	int nrAplicatii;
	string* aplicatii;
	static int nrTelefoane;
public:
	Telefon() :id(++nrTelefoane) {
		this->marca = "Necunoscuta";
		this->model = "Necunoscut";
		this->tip = FLAGSHIP;
		this->nrAplicatii = 0;
		this->aplicatii = nullptr;
	}
	Telefon(string marca, string model, Tip tip, int nrAplicatii, string* aplicatiiMobile) :id(++nrTelefoane) {
		this->marca = marca;
		this->model = model;
		this->tip = tip;
		this->nrAplicatii = nrAplicatii;
		this->aplicatii = new string[this->nrAplicatii];
		for (int i = 0; i < this->nrAplicatii; i++) {
			this->aplicatii[i] = aplicatiiMobile[i];
		}
		delete[] aplicatiiMobile;
	}
	void afisareTelefon() {
		cout << id << ". Telefonul " << this->marca << " , modelul " << this->model << " , care este de tipul ";
		if (this->tip == SMARTPHONE) cout << "SMARTPHONE";
		if (this->tip == FEATURE_PHONE) cout << "FEATURE PHONE";
		if (this->tip == FLAGSHIP) cout << "FLAGSHIP";
		cout << " are un numar de " << this->nrAplicatii << " aplicatii: " << endl;
		if (this->aplicatii != nullptr) {
			for (int i = 0; i < nrAplicatii - 1; i++) {
				cout << this->aplicatii[i] << " pe telefon, ";
			}
			cout << this->aplicatii[this->nrAplicatii - 1] << " pe telefon. ";
		}
	}
	~Telefon() {
		if (this->aplicatii != nullptr) {
			delete[] this->aplicatii;
		}
	}
};

int Telefon::nrTelefoane = 0;

void main() {
	Telefon iPhone16PM;

	iPhone16PM.afisareTelefon();
	string* aplicatii = new string[3]{ "Whatsapp", "Messenger", "Facebook" };
	Telefon* iPhone17PM = new Telefon("iPhone", "17PM", FLAGSHIP, 3, aplicatii);

	iPhone17PM->afisareTelefon();

	delete iPhone17PM;
}
