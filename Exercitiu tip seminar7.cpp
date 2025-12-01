#include <iostream>
#include <string>

using namespace std;

enum Gen { ROMAN = 1, FANTASY = 2, STIINTA = 3 };

class Carte {
private:
    const int id;
    string titlu;
    float pret;
    Gen gen;
    int nrCapitole;
    int* pagini;
    static int nrCarti;

public:
    //constructor default
    Carte() : id(++nrCarti) {
        this->titlu = "Necunoscut";
        this->pret = 0;
        this->gen = ROMAN;
        this->nrCapitole = 0;
        this->pagini = nullptr;
    }

    // Constructor cu parametri
    Carte(string titlu, float pret, Gen gen, int nrCapitole, int* paginiInit)
        : id(++nrCarti)
    {
        this->titlu = titlu;
        this->pret = pret;
        this->gen = gen;
        this->nrCapitole = nrCapitole;

        this->pagini = new int[nrCapitole];
        for (int i = 0; i < nrCapitole; i++)
            this->pagini[i] = paginiInit[i];

        delete[] paginiInit;
    }

    //constructor de copiere
    Carte(const Carte& c) : id(++nrCarti) {
        this->titlu = c.titlu;
        this->pret = c.pret;
        this->gen = c.gen;
        this->nrCapitole = c.nrCapitole;

        if (c.pagini != nullptr) {
            this->pagini = new int[c.nrCapitole];
            for (int i = 0; i < c.nrCapitole; i++)
                this->pagini[i] = c.pagini[i];
        }
        else {
            this->pagini = nullptr;
        }
    }

    //operator =
    void operator=(const Carte& c) {
        this->titlu = c.titlu;
        this->pret = c.pret;
        this->gen = c.gen;
        this->nrCapitole = c.nrCapitole;

        if (this->pagini != nullptr)
            delete[] this->pagini;

        if (c.pagini != nullptr) {
            this->pagini = new int[c.nrCapitole];
            for (int i = 0; i < c.nrCapitole; i++)
                this->pagini[i] = c.pagini[i];
        }
        else {
            this->pagini = nullptr;
        }
    }

    void afisare() {
        cout << endl << "Carte #" << id;
        cout << " | Titlu: " << titlu;
        cout << " | Pret: " << pret;
        cout << " | Gen: ";
        if (gen == ROMAN) cout << "ROMAN";
        if (gen == FANTASY) cout << "FANTASY";
        if (gen == STIINTA) cout << "STIINTA";

        cout << " | Capitole: " << nrCapitole << " [";
        for (int i = 0; i < nrCapitole; i++) {
            cout << pagini[i];
            if (i < nrCapitole - 1) cout << ", ";
        }
        cout << "]";
    }

    void operator+=(float x) {
        this->pret += x;
    }

    bool operator>(const Carte& c) {
        return this->pret > c.pret;
    }

    //operator !
    bool operator!() {
        return this->pret > 0;
    }

    //oerator functie ()
    float operator()(float adaos) {
        return this->pret + adaos;
    }

    //operator []
    int& operator[](int index) {
        if (index < 0 || index >= nrCapitole)
            throw exception();
        return pagini[index];
    }

    Carte operator++(int) {
        Carte copie = *this;
        this->pret++;
        return copie;
    }

    
    Carte operator++() {
        this->pret++;
        return *this;
    }

    explicit operator int() {
        return nrCapitole;
    }

    //operator <<
    friend ostream& operator<<(ostream& out, Carte c) {
        out << endl << "Carte #" << c.id;
        out << "\nTitlu: " << c.titlu;
        out << "\nPret: " << c.pret;
        out << "\nGen: ";
        if (c.gen == ROMAN) out << "ROMAN";
        if (c.gen == FANTASY) out << "FANTASY";
        if (c.gen == STIINTA) out << "STIINTA";
        out << "\nCapitole: " << c.nrCapitole << " (";
        for (int i = 0; i < c.nrCapitole; i++) {
            out << c.pagini[i];
            if (i < c.nrCapitole - 1) out << ", ";
        }
        out << ")";
        return out;
    }

    //operator >>
    friend istream& operator>>(istream& in, Carte& c) {
        cout << "\nTitlu: ";
        in >> c.titlu;

        cout << "Pret: ";
        in >> c.pret;

        cout << "Gen (1=Roman, 2=Fantasy, 3=Stiinta): ";
        int g;
        in >> g;

        if (g == 1) c.gen = ROMAN;
        if (g == 2) c.gen = FANTASY;
        if (g == 3) c.gen = STIINTA;

        cout << "Nr capitole: ";
        in >> c.nrCapitole;

        if (c.pagini != nullptr) delete[] c.pagini;

        c.pagini = new int[c.nrCapitole];
        for (int i = 0; i < c.nrCapitole; i++) {
            cout << "Pagini capitol " << i << ": ";
            in >> c.pagini[i];
        }

        return in;
    }

    //destructor
    ~Carte() {
        if (pagini != nullptr)
            delete[] pagini;
    }
};

int Carte::nrCarti = 0;


int main() {
    Carte c1;
    c1.afisare();

    int* pag = new int[3] { 10, 15, 20 };
    Carte* c2 = new Carte("Dune", 59.99, FANTASY, 3, pag);
    c2->afisare();

    cout << endl << (*c2)[0];
    (*c2)[0] = 99;
    cout << endl << (*c2)[0];

    cout << *c2;

    Carte c3 = (*c2)++;
    Carte c4 = ++(*c2);

    cout << c3;
    cout << c4;

    cout << endl << "Nr capitole carte 2: " << (int)(*c2);

    delete c2;
    return 0;
}
