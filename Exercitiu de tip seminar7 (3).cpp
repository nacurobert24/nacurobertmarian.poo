#include <iostream>
#include <string>
using namespace std;

enum GenFilm { ACTIUNE = 1, COMEDIE = 2, DRAMA = 3 };

class Film {
private:
    const int id;
    string titlu;
    float rating;
    GenFilm gen;
    int nrActori;
    string* actori;
    static int nrFilme;

public:
    Film() : id(++nrFilme) {
        titlu = "Necunoscut";
        rating = 0;
        gen = ACTIUNE;
        nrActori = 0;
        actori = nullptr;
    }

    Film(string titlu, float rating, GenFilm gen, int nrActori, string* listaActori)
        : id(++nrFilme)
    {
        this->titlu = titlu;
        this->rating = rating;
        this->gen = gen;
        this->nrActori = nrActori;

        actori = new string[nrActori];
        for (int i = 0; i < nrActori; i++)
            actori[i] = listaActori[i];

        delete[] listaActori;
    }

    Film(const Film& f) : id(++nrFilme) {
        titlu = f.titlu;
        rating = f.rating;
        gen = f.gen;
        nrActori = f.nrActori;

        if (f.actori != nullptr) {
            actori = new string[f.nrActori];
            for (int i = 0; i < f.nrActori; i++)
                actori[i] = f.actori[i];
        }
        else actori = nullptr;
    }

    void operator=(const Film& f) {
        titlu = f.titlu;
        rating = f.rating;
        gen = f.gen;

        if (actori != nullptr)
            delete[] actori;

        nrActori = f.nrActori;

        if (f.actori != nullptr) {
            actori = new string[f.nrActori];
            for (int i = 0; i < f.nrActori; i++)
                actori[i] = f.actori[i];
        }
        else actori = nullptr;
    }

    void afisare() {
        cout << endl << "Film #" << id;
        cout << " | Titlu: " << titlu;
        cout << " | Rating: " << rating;
        cout << " | Gen: ";
        if (gen == ACTIUNE) cout << "ACTIUNE";
        if (gen == COMEDIE) cout << "COMEDIE";
        if (gen == DRAMA) cout << "DRAMA";

        cout << " | Actori: [ ";
        for (int i = 0; i < nrActori; i++)
            cout << actori[i] << " ";
        cout << "]";
    }

    void operator+=(float x) { rating += x; }

    bool operator>(const Film& f) { return rating > f.rating; }

    bool operator!() { return rating > 0; }

    float operator()(float bonus) { return rating + bonus; }

    string& operator[](int index) {
        if (index < 0 || index >= nrActori)
            throw exception();
        return actori[index];
    }

    Film operator++(int) {
        Film copie = *this;
        rating++;
        return copie;
    }

    Film operator++() {
        rating++;
        return *this;
    }

    explicit operator int() { return nrActori; }

    friend ostream& operator<<(ostream& out, Film f) {
        out << endl << "Film #" << f.id;
        out << "\nTitlu: " << f.titlu;
        out << "\nRating: " << f.rating;
        out << "\nGen: ";
        if (f.gen == ACTIUNE) out << "ACTIUNE";
        if (f.gen == COMEDIE) out << "COMEDIE";
        if (f.gen == DRAMA) out << "DRAMA";

        out << "\nActori: ";
        for (int i = 0; i < f.nrActori; i++)
            out << f.actori[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Film& f) {
        cout << "\nTitlu: ";
        in >> f.titlu;

        cout << "Rating: ";
        in >> f.rating;

        int g;
        cout << "Gen (1=Actiune, 2=Comedie, 3=Drama): ";
        in >> g;

        if (g == 1) f.gen = ACTIUNE;
        if (g == 2) f.gen = COMEDIE;
        if (g == 3) f.gen = DRAMA;

        cout << "Nr actori: ";
        in >> f.nrActori;

        if (f.actori != nullptr)
            delete[] f.actori;

        f.actori = new string[f.nrActori];
        for (int i = 0; i < f.nrActori; i++) {
            cout << "Actor[" << i << "]: ";
            in >> f.actori[i];
        }

        return in;
    }

    ~Film() {
        if (actori != nullptr)
            delete[] actori;
    }
};

int Film::nrFilme = 0;

int main() {
    Film f1;
    f1.afisare();

    string* lista = new string[3]{ "Tom", "Ana", "Mara" };
    Film* f2 = new Film("Inception", 9.3, ACTIUNE, 3, lista);
    f2->afisare();

    cout << endl << (*f2)[0];
    (*f2)[0] = "Leo";
    cout << endl << (*f2)[0];

    cout << *f2;

    Film f3 = (*f2)++;
    Film f4 = ++(*f2);

    cout << f3;
    cout << f4;

    cout << endl << (int)(*f2);

    delete f2;
    return 0;
}
