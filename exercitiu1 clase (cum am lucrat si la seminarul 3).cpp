#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

class Masina
{
private:
	float pret;
	const int id; 
	string marca;
	int nrDotari;
	string* dotari;
	static int nrMasini; 
public:
	Masina() :id(++nrMasini)
	{
		this->marca = "Masina default"; 
		this->pret = 0;
		this->nrDotari = 0;
		this->dotari = nullptr;
	}

	Masina(string marca, float pret, int nrDotari, string* listaDotari) :id(++nrMasini)
	{
		this->marca = marca;
		this->pret = pret; 
		this->nrDotari = nrDotari;
		this->dotari = new string[this->nrDotari];
		for (int i = 0; i < this->nrDotari; i++)
		{
			this->dotari[i] = listaDotari[i]; 
		}

		delete[] listaDotari; //eliberam vectorul primit ca argument
	}
	

	void afisareMasina() 
	{
		cout << endl << this->id << ". Masina " << this->marca << " costa " << this->pret << " euro si are " << this->nrDotari << " dotari: ";
		if (this->dotari != nullptr)
		{
			for (int i = 0; i < this->nrDotari - 1; i++)
			{
				cout << this->dotari[i] << " , ";
			}
			cout << this->dotari[nrDotari - 1] << " .";
		}
	}
	
	~Masina() {
		if (this->dotari != nullptr)
			delete[] this->dotari;
	}
protected:
};

int Masina::nrMasini = 0; 


void main()
{
	Masina masinaDefault; 
	masinaDefault.afisareMasina();

	string* dotari = new string[3]{ " Climatronic", "Senzori parcare", "Navigatie GPS" };

	Masina* masina2 = new Masina("BMW", 35000, 3, dotari); 
	
	masina2->afisareMasina(); 

	delete masina2;
}
