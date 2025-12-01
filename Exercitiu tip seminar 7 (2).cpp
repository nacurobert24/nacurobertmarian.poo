#include <iostream>
#include <string>
using namespace std;

enum TipMasina { SPORT = 1, SUV = 2, ELECTRICA = 3 };

class Masina {
private:
    const int id;
    string model;
    float pret;
    TipMasina tip;
    int nrLuniConsum;
    float* consum;
    static int nrMasini;

public:
    Masina() : id(++nrMasini) {
        model = "Necunoscut";
        pret = 0;
        tip = SPORT;
        nrLuniConsum = 0;
        consum = nullptr;
    }

    Masina(string model, float pret, TipMasina tip, int nrLuni, float* consumInit)
        : id(++nrMasini)
    {
        this->model = model;
        this->pret = pret;
        this->tip = tip;
        this->nrLuniConsum = nrLuni;

        consum = new float[nrLuni];
        for (int i = 0; i < nrLuni; i++)
            consum[i] = consumInit[i];

        delete[] consumInit;
    }

    Masina(const Masina& m) : id(++nrMasini) {
        model = m.model;
        pret = m.pret;
        tip = m.tip;
        nrLuniConsum = m.nrLuniConsum;

        if (m.consum != nullptr) {
            consum = new float[m.nrLuniConsum];
            for (int i = 0; i < m.nrLuniConsum; i++)
                consum[i] = m.consum[i];
        }
        else consum = nullptr;
    }

    void operator=(const Masina& m) {
        model = m.model;
        pret = m.pret;
        tip = m.tip;

        if (consum != nullptr)
            delete[] consum;

        nrLuniConsum = m.nrLuniConsum;

        if (m.consum != nullptr) {
            consum = new float[m.nrLuniConsum];
            for (int i = 0; i < m.nrLuniConsum; i++)
                consum[i] = m.consum[i];
        }
        else consum = nullptr;
    }

    void afisare() {
        cout << endl << "Masina #" << id;
        cout << " | Model: " << model;
        cout << " | Pret: " << pret;
        cout << " | Tip: ";
        if (tip == SPORT) cout << "SPORT";
        if (tip == SUV) cout << "SUV";
        if (tip == ELECTRICA) cout << "ELECTRICA";

        cout << " | Consum: [ ";
        for (int i = 0; i < nrLuniConsum; i++)
            cout << consum[i] << " ";
        cout << "]";
    }

    void operator+=(float x) { pret += x; }

    bool operator>(const Masina& m) { return pret > m.pret; }

    bool operator!() { return pret > 0; }

    float operator()(float reducere) { return pret - reducere; }

    float& operator[](int index) {
        if (index < 0 || index >= nrLuniConsum)
            throw exception();
        return consum[index];
    }

    Masina operator++(int) {
        Masina copie = *this;
        pret++;
        return copie;
    }

    Masina operator++() {
        pret++;
        return *this;
    }

    explicit operator int() { return nrLuniConsum; }

    friend ostream& operator<<(ostream& out, Masina m) {
        out << endl << "Masina #" << m.id;
        out << "\nModel: " << m.model;
        out << "\nPret: " << m.pret;
        out << "\nTip: ";
        if (m.tip == SPORT) out << "SPORT";
        if (m.tip == SUV) out << "SUV";
        if (m.tip == ELECTRICA) out << "ELECTRICA";

        out << "\nConsum: ";
        for (int i = 0; i < m.nrLuniConsum; i++)
            out << m.consum[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Masina& m) {
        cout << "\nModel: ";
        in >> m.model;

        cout << "Pret: ";
        in >> m.pret;

        int t;
        cout << "Tip (1=Sport, 2=SUV, 3=Electrica): ";
        in >> t;

        if (t == 1) m.tip = SPORT;
        if (t == 2) m.tip = SUV;
        if (t == 3) m.tip = ELECTRICA;

        cout << "Nr luni consum: ";
        in >> m.nrLuniConsum;

        if (m.consum != nullptr)
            delete[] m.consum;

        m.consum = new float[m.nrLuniConsum];
        for (int i = 0; i < m.nrLuniConsum; i++) {
            cout << "Consum[" << i << "]: ";
            in >> m.consum[i];
        }

        return in;
    }

    ~Masina() {
        if (consum != nullptr)
            delete[] consum;
    }
};

int Masina::nrMasini = 0;

int main() {
    Masina m1;
    m1.afisare();

    float* consum = new float[3] { 8.5f, 9.1f, 7.8f };
    Masina* m2 = new Masina("Tesla Model Y", 45000, ELECTRICA, 3, consum);
    m2->afisare();

    cout << endl << (*m2)[0];
    (*m2)[0] = 10.2;
    cout << endl << (*m2)[0];

    cout << *m2;

    Masina m3 = (*m2)++;
    Masina m4 = ++(*m2);

    cout << m3;
    cout << m4;

    cout << endl << (int)(*m2);

    delete m2;
    return 0;
}
