#include <iostream>
#include <string>
using namespace std;

enum Nivel { LICENTA = 1, MASTER = 2, DOCTORAT = 3 };

class Student {
private:
    const int id;
    string nume;
    float medie;
    Nivel nivel;
    int nrNote;
    float* note;
    static int nrStudenti;

public:
    Student() : id(++nrStudenti) {
        nume = "Necunoscut";
        medie = 0;
        nivel = LICENTA;
        nrNote = 0;
        note = nullptr;
    }

    Student(string nume, float medie, Nivel nivel, int nrNote, float* lista)
        : id(++nrStudenti)
    {
        this->nume = nume;
        this->medie = medie;
        this->nivel = nivel;
        this->nrNote = nrNote;

        note = new float[nrNote];
        for (int i = 0; i < nrNote; i++)
            note[i] = lista[i];

        delete[] lista;
    }

    Student(const Student& s) : id(++nrStudenti) {
        nume = s.nume;
        medie = s.medie;
        nivel = s.nivel;
        nrNote = s.nrNote;

        if (s.note) {
            note = new float[s.nrNote];
            for (int i = 0; i < s.nrNote; i++)
                note[i] = s.note[i];
        }
        else note = nullptr;
    }

    void operator=(const Student& s) {
        nume = s.nume;
        medie = s.medie;
        nivel = s.nivel;

        if (note) delete[] note;

        nrNote = s.nrNote;

        if (s.note) {
            note = new float[s.nrNote];
            for (int i = 0; i < s.nrNote; i++)
                note[i] = s.note[i];
        }
        else note = nullptr;
    }

    void afisare() {
        cout << endl << "Student #" << id;
        cout << " | Nume: " << nume;
        cout << " | Medie: " << medie;
        cout << " | Nivel: ";
        if (nivel == LICENTA) cout << "LICENTA";
        if (nivel == MASTER) cout << "MASTER";
        if (nivel == DOCTORAT) cout << "DOCTORAT";

        cout << " | Note: [ ";
        for (int i = 0; i < nrNote; i++)
            cout << note[i] << " ";
        cout << "]";
    }

    void operator+=(float x) { medie += x; }

    bool operator>(const Student& s) { return medie > s.medie; }

    bool operator!() { return medie > 0; }

    float operator()(float bonus) { return medie + bonus; }

    float& operator[](int index) {
        if (index < 0 || index >= nrNote)
            throw exception();
        return note[index];
    }

    Student operator++(int) {
        Student copie = *this;
        medie++;
        return copie;
    }

    Student operator++() {
        medie++;
        return *this;
    }

    explicit operator int() { return nrNote; }

    friend ostream& operator<<(ostream& out, Student s) {
        out << endl << "Student #" << s.id;
        out << "\nNume: " << s.nume;
        out << "\nMedie: " << s.medie;
        out << "\nNivel: ";
        if (s.nivel == LICENTA) out << "LICENTA";
        if (s.nivel == MASTER) out << "MASTER";
        if (s.nivel == DOCTORAT) out << "DOCTORAT";

        out << "\nNote: ";
        for (int i = 0; i < s.nrNote; i++)
            out << s.note[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Student& s) {
        cout << "\nNume: ";
        in >> s.nume;

        cout << "Medie: ";
        in >> s.medie;

        int n;
        cout << "Nivel (1=Lic, 2=Master, 3=Doctorat): ";
        in >> n;

        if (n == 1) s.nivel = LICENTA;
        if (n == 2) s.nivel = MASTER;
        if (n == 3) s.nivel = DOCTORAT;

        cout << "Nr note: ";
        in >> s.nrNote;

        if (s.note) delete[] s.note;

        s.note = new float[s.nrNote];
        for (int i = 0; i < s.nrNote; i++) {
            cout << "Nota[" << i << "]: ";
            in >> s.note[i];
        }

        return in;
    }

    ~Student() {
        if (note) delete[] note;
    }
};

int Student::nrStudenti = 0;

int main() {
    Student s1;
    s1.afisare();

    float* lista = new float[3] { 8.5f, 9.0f, 7.5f };
    Student* s2 = new Student("Andrei", 9.1f, MASTER, 3, lista);
    s2->afisare();

    cout << endl << (*s2)[0];
    (*s2)[0] = 10;
    cout << endl << (*s2)[0];

    cout << *s2;

    Student s3 = (*s2)++;
    Student s4 = ++(*s2);

    cout << s3;
    cout << s4;

    cout << endl << (int)(*s2);

    delete s2;
    return 0;
}
