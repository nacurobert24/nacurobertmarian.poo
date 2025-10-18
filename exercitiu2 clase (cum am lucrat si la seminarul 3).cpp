#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Telefon
{
private:
	float pret;
	const int id; 
	string model;
	int nrSpecificatii;
	string* specificatii;
	static int nrTelefoane; 
public:
	Telefon() :id(++nrTelefoane)
	{
		this->model = "Telefon default"; 
		this->pret = 0;
		this->nrSpecificatii = 0;
		this->specificatii = nullptr;
	}

	Telefon(string model, float pret, int nrSpecificatii, string* listaSpecificatii) :id(++nrTelefoane)
	{
		this->model = model;
		this->pret = pret; 
		this->nrSpecificatii = nrSpecificatii;
		this->specificatii = new string[this->nrSpecificatii];
		for (int i = 0; i < this->nrSpecificatii; i++)
		{
			this->specificatii[i] = listaSpecificatii[i]; 
		}

		delete[] listaSpecificatii; 
	}
	

	void afisareTelefon() 
	{
		cout << endl << this->id << ". Telefonul " << this->model << " costa " << this->pret << " dolari si are " << this->nrSpecificatii << " specificatii: ";
		if (this->specificatii != nullptr)
		{
			for (int i = 0; i < this->nrSpecificatii - 1; i++)
			{
				cout << this->specificatii[i] << " , ";
			}
			cout << this->specificatii[nrSpecificatii - 1] << " .";
		}
	}
	
	~Telefon() {
		if (this->specificatii != nullptr)
			delete[] this->specificatii;
	}
protected:
};

int Telefon::nrTelefoane = 0; 


void main()
{
	Telefon telefonDefault; 
	telefonDefault.afisareTelefon();

	string* specificatii = new string[4]{ " Camera 108MP", "Incarcare rapida", "Rezistenta la apa", "Rezistenta la praf"};

	Telefon* telefon2 = new Telefon("iPhone 17 PRO MAX", 1499, 4, specificatii); 
	
	telefon2->afisareTelefon(); 

	delete telefon2;
}
