#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {FAST_FOOD = 5, TRADITIONAL =7, LUX = 9};

class Restaurant {
private:
	const int id;
	string nume;
	string adresa;
	Tip tip;
	int nrMeniuri;
	string* meniuri;
	static int nrRestaurante;
public:
	Restaurant() :id(++nrRestaurante) {
		this->nume = "Necunoscut";
		this->adresa = "Anonima";
		this->tip = FAST_FOOD;
		this->nrMeniuri = 0;
		this->meniuri = nullptr;
	}
	Restaurant(string nume, string adresa, Tip tip, int nrMeniuri, string* meniuriMancare) :id(++nrRestaurante) {
		this->nume = nume;
		this->adresa = adresa;
		this->tip = tip;
		this->nrMeniuri = nrMeniuri;
		this->meniuri = new string[this->nrMeniuri];
		for (int i = 0; i < this->nrMeniuri; i++) {
			this->meniuri[i] = meniuriMancare[i];
		}
		delete[] meniuriMancare;
	}
	void afisareRestaurant() {
		cout << id << ". Restaurantul " << this->nume << " , care se afla la adresa " << this->adresa << " si este un restaurant ";
		if (this->tip == TRADITIONAL) cout << "TRADITIONAL";
		if (this->tip == LUX) cout << "LUX";
		if (this->tip == FAST_FOOD) cout << "FAST FOOD";
		cout << " are un numar de " << this->nrMeniuri << " meniuri: " << endl;
		if (this->meniuri != nullptr) {
			for (int i = 0; i < this->nrMeniuri - 1; i++) {
				cout << this->meniuri[i] << " , ";
			}
			cout << this->meniuri[this->nrMeniuri - 1] << " . ";
		}
	}
	~Restaurant() {
		if (this->meniuri != nullptr) {
			delete[] this->meniuri;
		}
	}
};

int Restaurant::nrRestaurante = 0;

void main() {
	Restaurant SutaDeGrame;

	SutaDeGrame.afisareRestaurant();
	string* meniuri = new string[3]{ "Pizza", "Paste", "Peste" };
	Restaurant* Urban = new Restaurant("Urban", "Strada Aleea Garii", FAST_FOOD, 3, meniuri);

	Urban->afisareRestaurant();

	delete Urban;
}
