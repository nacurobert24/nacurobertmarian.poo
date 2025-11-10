/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
enum Tip {ACTIUNE=8, COMEDIE=9, DRAMA=7};

class Film {
private:
	const int id;
	string titlu;
	string regizor;
	Tip tip;
	int nrRatinguri;
	float* ratinguri;
	static int nrFilme;
public:
	Film() :id(++nrFilme) {
		this->titlu = "Anonim";
		this->regizor = "Necunoscut";
		this->tip = ACTIUNE;
		this->nrRatinguri = 0;
		this->ratinguri = nullptr;
	}
	Film(string titlu, string regizor, Tip tip, int nrRatinguri, float* ratinguriFilm) :id(++nrFilme) {
		this->titlu = titlu;
		this->regizor = regizor;
		this->tip = tip;
		this->nrRatinguri = nrRatinguri;
		this->ratinguri = new float[this->nrRatinguri];
		for (int i = 0; i < this->nrRatinguri; i++) {
			this->ratinguri[i] = ratinguriFilm[i];
		}
		delete[] ratinguriFilm;
	}

	//constructor de copiere

	Film(const Film& copie) :id(++nrFilme) {
		this->titlu = copie.titlu;
		this->regizor = copie.regizor;
		this->tip = copie.tip;
		this->nrRatinguri = copie.nrRatinguri;
		if (copie.ratinguri != nullptr) {
			this->ratinguri = new float[copie.nrRatinguri];
			for (int i = 0; i < copie.nrRatinguri; i++) {
				this->ratinguri[i] = copie.ratinguri[i];
			}
		}
		else {
			this->ratinguri = nullptr;
		}
	}

	//operator=

	void operator=(const Film& copie) {
		this->titlu = copie.titlu;
		this->regizor = copie.regizor;
		this->tip = copie.tip;
		this->nrRatinguri = copie.nrRatinguri;
		if (this->ratinguri != nullptr) {
			delete[] this->ratinguri;
		}
		if (copie.ratinguri != nullptr) {
			this->ratinguri = new float[copie.nrRatinguri];
			for (int i = 0; i < copie.nrRatinguri; i++) {
				this->ratinguri[i] = copie.ratinguri[i];
			}
		}
		else {
			this->ratinguri = nullptr;
		}
	}

	void afisareFilm() {
		cout << id << ". Filmul " << this->titlu << " cu regizorul " << this->regizor << " , care este de tipul ";
		if (this->tip == ACTIUNE) cout << "ACTIUNE";
		if (this->tip == COMEDIE) cout << "COMEDIE";
		if (this->tip == DRAMA) cout << "DRAMA";
		cout << " are un numar de ratinguri de " << this->nrRatinguri << " : " << endl;
		if (this->ratinguri != nullptr) {
			for (int i = 0; i < nrRatinguri - 1; i++) {
				cout << this->ratinguri[i] << " la film, ";
			}
			cout << this->ratinguri[this->nrRatinguri - 1] << " la film. ";
		}
	}
	~Film() {
		if (this->ratinguri != nullptr) {
			delete[] this->ratinguri;
		}
	}
};

int Film::nrFilme = 0;

void main() {
	Film Spiderman;

	Spiderman.afisareFilm();
	float* ratinguri = new float[5] {10, 9, 8, 7, 6};
	Film* Batman = new Film("Batman", "RobertMarian", ACTIUNE, 5, ratinguri);

	Batman->afisareFilm();

	Film film(*Batman);
	film.afisareFilm();

	Spiderman = *Batman;
	Spiderman.afisareFilm();

	delete Batman;
}
*/
