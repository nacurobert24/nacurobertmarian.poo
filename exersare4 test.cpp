#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Film {
private:
	const int id;
	string titlu;
	string regizor; 
	int nrRatinguri;
	float* ratinguri;
	static int nrFilme;
public:
	Film() :id(++nrFilme) {
		this->titlu = "Anonim";
		this->regizor = "Necunoscut";
		this->nrRatinguri = 0;
		this->ratinguri = nullptr;
	}
	Film(string titlu, string regizor, int nrRatinguri, float* ratinguriFilm) :id(++nrFilme) {
		this->titlu = titlu;
		this->regizor = regizor;
		this->nrRatinguri = nrRatinguri;
		this->ratinguri = new float[this->nrRatinguri];
		for (int i = 0; i < this->nrRatinguri; i++) {
			this->ratinguri[i] = ratinguriFilm[i];
		}
		delete[] ratinguriFilm;
	}
	void afisareFilm() {
		cout << id << ". Filmul " << this->titlu << " cu regizorul " << this->regizor << " are un numar de ratinguri de " << this->nrRatinguri << " : " << endl;
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
	Film* Batman = new Film("Batman", "RobertMarian", 5, ratinguri);

	Batman->afisareFilm();

	delete Batman;
}
