#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Pilot {
    char* nume;
    int varsta;
    int numar_curse_castigate;
    int salariu;
public:
    Pilot() { // fara parametri
        nume = new char[10];
        strcpy(nume, "Gus Fring");
        varsta = 45;
        numar_curse_castigate = 1;
        salariu = 1000000;
    }
    Pilot(const char* nume_c, const int varsta_c, const int numar_curse_castigate_c, const int salariu_c) { // cu parametri
        nume = new char[strlen(nume_c) + 1];
        strcpy(nume, nume_c);
        varsta = varsta_c;
        numar_curse_castigate = numar_curse_castigate_c;
        salariu = salariu_c;
    }
    Pilot(Pilot& other) { // copy constructor
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        varsta = other.varsta;
        numar_curse_castigate = other.numar_curse_castigate;
        salariu = other.salariu;
    }
    ~Pilot() { // destructor
        if (nume != nullptr) delete[] nume;
    }
    Pilot& operator=(const Pilot& other) { // copiere egal
        if (this != &other) {
            delete[] nume;
        }
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
        this->varsta = other.varsta;
        this->numar_curse_castigate = other.numar_curse_castigate;
        this->salariu = other.salariu;
        return *this;
    }
    const char* get_nume() const;
    int get_varsta() const;
    int get_numar_curse_castigate() const;
    int get_salariu() const;
    void set_nume(const char* nume_s);
    void set_varsta(int varsta_s);
    void set_numar_curse_castigate(int numar_curse_castigate_s);
    void set_salariu(int salariu_s);
    friend ostream& operator<<(ostream& out, const Pilot& pilot);

};
const char* Pilot::get_nume() const { // operator de acces (primul const inseamna ca nu poti schimba variabila iar al doilea ca functia nu are voie sa schimbe)
    return nume;
}
int Pilot::get_varsta() const {
    return varsta;
}
int Pilot::get_numar_curse_castigate() const {
    return numar_curse_castigate;
}
int Pilot::get_salariu() const {
    return salariu;
}
void Pilot::set_nume(const char* nume_s) {
    if (nume != nullptr)
    {
        delete[] nume;
    }
    nume = new char[strlen(nume_s) + 1];
    strcpy(nume, nume_s);
}
void Pilot::set_varsta(int varsta_s) {
    varsta = varsta_s;
}
void Pilot::set_numar_curse_castigate(int numar_curse_castigate_s) {
    numar_curse_castigate = numar_curse_castigate_s;
}
void Pilot::set_salariu(int salariu_s) {
    salariu = salariu_s;
}
ostream& operator<<(ostream& out, const Pilot& pilot) {
    out << "Numele Pilotului: " << pilot.nume << endl;
    out << "Varsta: " << pilot.varsta << " ani" << endl;
    out << "Numar Curse Castigate: " << pilot.numar_curse_castigate << endl;
    out << "Salariu Curent: " << pilot.salariu << endl;
    return out;
}







class Circuit {
    char* locatie;
    int km;
    char* luna;
    char* vreme;
    Pilot castigator;
    int premiu;
public:
    Circuit(): castigator() {
        locatie = new char[6];
        strcpy(locatie, "Monza");
        km = 6;
        luna = new char[11];
        strcpy(luna, "Septembrie");
        vreme = new char[7];
        strcpy(vreme, "Ploaie");
        premiu = 2000000;
    }
    Circuit(const char* locatie_c, const int km_c, const char* luna_c, const char* vreme_c, const Pilot& castigator_c, const int premiu_c) {
        locatie = new char[strlen(locatie_c) + 1];
        strcpy(locatie, locatie_c);
        km = km_c;
        luna = new char[strlen(luna_c) + 1];
        strcpy(luna, luna_c);
        castigator = castigator_c;
        vreme = new char[strlen(vreme_c) + 1];
        strcpy(vreme, vreme_c);
        premiu = premiu_c;
    }
    Circuit(Circuit& other) { 
        locatie = new char[strlen(other.locatie) + 1];
        strcpy(locatie, other.locatie);
        km = other.km;
        luna = new char[strlen(other.luna) + 1];
        strcpy(luna, other.luna);
        castigator = other.castigator;
        vreme = new char[strlen(other.vreme) + 1];
        strcpy(vreme, other.vreme);
        premiu = other.premiu;
    }
    ~Circuit() { 
        if (locatie != nullptr) delete[] locatie;
        if (luna != nullptr) delete[] luna;
        if (vreme != nullptr) delete[] vreme;
    }
    Circuit& operator=(const Circuit& other) {
        if (this != &other) {
            delete[] locatie;
            delete[] luna;
            delete[] vreme;
        }
        this->locatie = new char[strlen(other.locatie) + 1];
        strcpy(locatie, other.locatie);
        this->km = other.km;
        this->luna = new char[strlen(other.luna) + 1];
        strcpy(luna, other.luna);
        this->vreme = new char[strlen(other.vreme) + 1];
        strcpy(vreme, other.vreme);
        this->castigator = other.castigator;
        this->premiu = other.premiu;
        return *this;
    }


    const char* get_locatie() const;
    const char* get_luna() const;
    const char* get_vreme() const;
    int get_km() const;
    int get_premiu() const;
    const Pilot& get_castigator() const;
    void set_locatie(const char* locatie_s);
    void set_km(int km_s);
    void set_premiu(int premiu_s);
    void set_vreme(const char* vreme_s);
    void set_luna(const char* luna_s);
    void set_castigator(const Pilot& castigator_s);
    friend ostream& operator<<(ostream& out, const Circuit& circuit);
};

ostream& operator<<(ostream& out, const Circuit& circuit) {
    out << "Locatie Circuit: " << circuit.locatie << endl;
    out << "Lungime Cursa: " << circuit.km << endl;
    out << "Luna in care se tine Cursa: " << circuit.luna << endl;
    out << "Vreme Anuntata: " << circuit.vreme << endl;
    out << "Premiu: $" << circuit.premiu << endl;
    out << "Castigatorul Trecut: " << endl << circuit.castigator << endl;
    return out;
}
const char* Circuit::get_locatie() const {
    return locatie;
}
const char* Circuit::get_luna() const {
    return luna;
}
const char* Circuit::get_vreme() const {
    return vreme;
}
int Circuit::get_premiu() const {
    return premiu;
}
int Circuit::get_km() const {
    return km;
}
const Pilot& Circuit::get_castigator() const {
    return castigator;
}
void Circuit::set_locatie(const char* locatie_s) {
    if (locatie != nullptr)
    {
        delete[] locatie;
    }
    locatie = new char[strlen(locatie_s) + 1];
    strcpy(locatie, locatie_s);
}
void Circuit::set_luna(const char* luna_s) {
    if (luna != nullptr)
    {
        delete[] luna;
    }
    luna = new char[strlen(luna_s) + 1];
    strcpy(luna, luna_s);
}
void Circuit::set_vreme(const char* vreme_s) {
    if (vreme != nullptr)
    {
        delete[] vreme;
    }
    vreme = new char[strlen(vreme_s) + 1];
    strcpy(vreme, vreme_s);
}
void Circuit::set_km(int km_s) {
    km = km_s;
}
void Circuit::set_premiu(int premiu_s) {
    premiu = premiu_s;
}
void Circuit::set_castigator(const Pilot& castigator_s) {
    castigator = castigator_s;
}

class Masina {
    char* model;
    int an_fabricatie;
    int cost;
public:
    Masina() { 
        model = new char[13];
        strcpy(model, "Ferrari SF90");
        an_fabricatie = 2022;
        cost = 2000000;
    }
    Masina(const char* model_c,  int an_fabricatie_c, const int cost_c) { 
        model = new char[strlen(model_c) + 1];
        strcpy(model, model_c);
        an_fabricatie = an_fabricatie_c;
        cost = cost_c;
    }
    Masina(Masina& other) {
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
        an_fabricatie = other.an_fabricatie;
        cost = other.cost;
    }
    ~Masina() {
        if (model != nullptr) delete[] model;
    }
    Masina& operator=(const Masina& other) {
        if (this != &other) {
            delete[] model;
        }
        this->model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
        this->an_fabricatie = other.an_fabricatie;
        this->cost = other.cost;
        return *this;
    }
    const char* get_model() const;
    int get_an_fabricatie() const;
    int get_cost() const;
    void set_model(const char* nume_s);
    void set_an_fabricatie(int varsta_s);
    void set_cost(int numar_curse_castigate_s);
    friend ostream& operator<<(ostream& out, const Masina& masina);
};
const char* Masina::get_model() const { 
    return model;
}
int Masina::get_an_fabricatie() const {
    return an_fabricatie;
}
int Masina::get_cost() const {
    return cost;
}
void Masina::set_model(const char* model_s) {
    if (model != nullptr)
    {
        delete[] model;
    }
    model = new char[strlen(model_s) + 1];
    strcpy(model, model_s);
}
void Masina::set_an_fabricatie(int an_fabricatie_s) {
    an_fabricatie = an_fabricatie_s;
}
void Masina::set_cost(int cost_s) {
    cost = cost_s;
}
ostream& operator<<(ostream& out, const Masina& masina) {
    out << "Modelul Masinii: " << masina.model << endl;
    out << "An Fabricatie: " << masina.an_fabricatie << endl;
    out << "Costul Masinii: " << masina.cost << endl;
    return out;
}


class Echipa {
    char* nume_echipa;
    int loc_clasament;
    int buget;
    Pilot pilot1;
    Pilot pilot2;
    Masina masina;
    
public:
    Echipa(): pilot1(), pilot2(), masina() {
        nume_echipa = new char[8];
        strcpy(nume_echipa, "Ferrari");
        loc_clasament = 2;
        buget = 10000000;
    }
    Echipa(const char* nume_echipa_c, const int loc_clasament_c, const int buget_c, const Pilot& pilot1_c, const Pilot& pilot2_c, const Masina& masina_c) {
        nume_echipa = new char[strlen(nume_echipa_c) + 1];
        strcpy(nume_echipa, nume_echipa_c);
        loc_clasament = loc_clasament_c;
        buget = buget_c;
        pilot1 = pilot1_c;
        pilot2 = pilot2_c;
        masina = masina_c;
    }
    Echipa(Echipa& other) {
        nume_echipa = new char[strlen(other.nume_echipa) + 1];
        strcpy(nume_echipa, other.nume_echipa);
        loc_clasament = other.loc_clasament;
        buget = other.buget;
        pilot1 = other.pilot1;
        pilot2 = other.pilot2;
        masina = other.masina;
    }
    ~Echipa() {
        if (nume_echipa != nullptr) delete[] nume_echipa;
    }
    Echipa& operator=(const Echipa& other) {
        if (this != &other) {
            delete[] nume_echipa;
        }
        this->nume_echipa = new char[strlen(other.nume_echipa) + 1];
        strcpy(nume_echipa, other.nume_echipa);
        this->loc_clasament = other.loc_clasament;
        this->buget = other.buget;
        this->pilot1 = other.pilot1;
        this->pilot2 = other.pilot2;
        this->masina = other.masina;
        return *this;
    }
    const char* get_nume_echipa() const;
    int get_loc_clasament() const;
    int get_buget() const;
    const Pilot& get_pilot1() const;
    const Pilot& get_pilot2() const;
    const Masina& get_masina() const;
    void set_nume_echipa(const char* nume_echipa_s);
    void set_loc_clasament(int loc_clasament_s);
    void set_buget(int buget_s);
    void set_pilot1(const Pilot& pilot1_s);
    void set_pilot2(const Pilot& pilot2_s);
    void set_masina(const Masina& masina_s);
    friend ostream& operator<<(ostream& out, const Echipa& echipa);
};
ostream& operator<<(ostream& out, const Echipa& echipa) {
    out << "Numele Echipei: " << echipa.nume_echipa << endl;
    out << "Loc Clasament: " << echipa.loc_clasament << endl;
    out << "Bugetul Echipei: " << echipa.buget << endl;
    out << "Pilotul Principal: " << echipa.pilot1 << endl;
    out << "Pilotul Secundar: " << echipa.pilot2 << endl << endl;
    out << " " << endl << endl << echipa.masina << endl;
    return out;
}

const char* Echipa::get_nume_echipa() const {
    return nume_echipa;
}
int Echipa::get_loc_clasament() const {
    return loc_clasament;
}
int Echipa::get_buget() const {
    return buget;
}
const Pilot& Echipa::get_pilot1() const {
    return pilot1;
}
const Pilot& Echipa::get_pilot2() const {
    return pilot2;
}
const Masina& Echipa::get_masina() const {
    return masina;
}
void Echipa::set_nume_echipa(const char* nume_echipa_s) {
    if (nume_echipa != nullptr)
    {
        delete[] nume_echipa;
    }
    nume_echipa = new char[strlen(nume_echipa_s) + 1];
    strcpy(nume_echipa, nume_echipa_s);
}
void Echipa::set_loc_clasament(int loc_clasament_s) {
    loc_clasament = loc_clasament_s;
}
void Echipa::set_buget(int buget_s) {
    buget = buget_s;
}
void Echipa::set_pilot1(const Pilot& pilot1_s) {
    pilot1 = pilot1_s;
}
void Echipa::set_pilot2(const Pilot& pilot2_s) {
    pilot2 = pilot2_s;
}
void Echipa::set_masina(const Masina& masina_s) {
    masina = masina_s;
}


class Costuri {
    int transport;
    int masini;
    int imbunatatiri;
    int mecanici;
public:
    Costuri() {
        transport = 1000000;
        masini = 4000000;
        imbunatatiri = 1000000;
        mecanici = 1000000;
    }
    Costuri(int transport_c, const int masini_c, const int imbunatatiri_c, const int mecanici_c) { 
        transport = transport_c;
        masini = masini_c;
        imbunatatiri = imbunatatiri_c;
        mecanici = mecanici_c;
    }
    Costuri(Costuri& other) {
        transport = other.transport;
        masini = other.masini;
        imbunatatiri = other.imbunatatiri;
        mecanici = other.mecanici;
    }
    ~Costuri() = default;
    Costuri& operator=(const Costuri& other) {
        this->transport = other.transport;
        this->masini = other.masini;
        this->imbunatatiri = other.imbunatatiri;
        this->mecanici = other.mecanici;
        return *this;
    }
    int get_transport() const;
    int get_masini() const;
    int get_imbunatatiri() const;
    int get_mecanici() const;
    void set_transport(int transport_s);
    void set_masini(int masini_s);
    void set_imbunatatiri(int imbunatatiri_s);
    void set_mecanici(int mecanici_s);
    friend ostream& operator<<(ostream& out, const Costuri& costuri);

};

int Costuri::get_transport() const { 
    return transport;
}
int Costuri::get_masini() const {
    return masini;
}
int Costuri::get_imbunatatiri() const {
    return imbunatatiri;
}
int Costuri::get_mecanici() const {
    return mecanici;
}
void Costuri::set_transport(int transport_s) {
    transport = transport_s;
}
void Costuri::set_masini(int masini_s) {
    masini = masini_s;
}
void Costuri::set_imbunatatiri(int imbunatatiri_s) {
    imbunatatiri = imbunatatiri_s;
}
void Costuri::set_mecanici(int mecanici_s) {
    mecanici = mecanici_s;
}
ostream& operator<<(ostream& out, const Costuri& costuri) {
    out << "Cost Transporturi: $" << costuri.transport << endl;
    out << "Costuri Masini + Reparatii: $" << costuri.masini << endl;
    out << "Costuri Imbunatatiri: $" << costuri.imbunatatiri << endl;
    out << "Salariu Mecanici: $" << costuri.mecanici << endl;
    out << "Costuri Totale (Fara Salariul Pilotului): $" << costuri.transport + costuri.masini + costuri.imbunatatiri + costuri.mecanici;
    return out;
}

int profitul_echipei(int buget_echipa, int cost_transport, int cost_masini, int cost_imbunatatiri, int cost_mecanici, int pilot_principal_salariu, int pilot_secundar_salariu) {
    int costuri = cost_transport + cost_masini + cost_imbunatatiri + cost_mecanici + pilot_principal_salariu + pilot_secundar_salariu;
    int profit = buget_echipa - costuri;
    return profit;
}

float timp_circuit(float km_circuit, float viteza_medie_circuit_kmh, float ture_circuit){
    float timp = (km_circuit * ture_circuit) / viteza_medie_circuit_kmh;
    return timp;
}

int main()
{
    Pilot pilot1;
    cout << "Pilot Fara Parametri: " << endl;
    cout << pilot1 << endl;

    Pilot pilot2("Adi H", 42, 2, 100000);
    cout << "Pilot Cu Parametri: " << endl;
    cout << pilot2 << endl;

    Pilot pilot3(pilot2);
    cout << "Pilot Cu CopyC: " << endl;
    cout << pilot3 << endl;

    Pilot pilot4;
    pilot4.set_nume("Heisenberg");
    pilot4.set_varsta(52);
    pilot4.set_numar_curse_castigate(3);
    pilot4.set_salariu(200000);
    cout << "Pilot Cu Set: " << endl;
    cout << pilot4 << endl;

    cout << "Pilot Cu Get: " << endl;
    cout << "Nume: " << pilot4.get_nume() << endl;
    cout << "Varsta: " << pilot4.get_varsta() << endl;
    cout << "Salariu: " << pilot4.get_salariu() << endl;
    cout << "Curse Castigate: " << pilot4.get_numar_curse_castigate() << endl << endl;

    Echipa echipa1;
    Circuit circuit1;
    Costuri costuri1;

    Circuit circuit2("Germania", 6, "Martie", "Ploaie", pilot1, 300000);
    cout << circuit2 << endl;

    cout << endl << "Logica de business" << endl;
    cout << "==================" << endl;
    cout << "Profitul Echipei: " <<  profitul_echipei(echipa1.get_buget(), costuri1.get_transport(), costuri1.get_masini(), costuri1.get_imbunatatiri(), costuri1.get_mecanici(), pilot1.get_salariu(), pilot2.get_salariu()) << endl;

    cout << "Durata Cursa: " << timp_circuit(circuit1.get_km(), 140, 60) << " ore";
}