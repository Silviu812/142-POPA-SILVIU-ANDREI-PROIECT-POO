#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;
#pragma warning(disable:4996)


class ModelException : public exception {
private:
    string eroare;

public:
    ModelException(const string& eroare) : eroare(eroare) {}

    const char* what() const noexcept override {
        return eroare.c_str();
    }
};

class AccidentException : public exception {
public:
    const char* what() const noexcept override {
        return "A intervenit un accident!";
    }
};


class CircuitException : public exception {
public:
    const char* what() const noexcept override {
        return "Eroare la cautarea circuitului!";
    }
};

class GauraException : public exception {
public:
    const char* what() const noexcept override {
        return "Bugetul a fost depasit!";
    }
};

void CalculBuget() {
    throw GauraException();
}

void PilotCreat() {
    bool pilotcreat = true;

    if (pilotcreat) {
        throw logic_error("Acest pilot exista deja in echipa!");
    }
    else {
        cout << "Pilot inregistrat cu succes!" << endl;
    }
}

void CursaExistenta() {
    bool cursa = true;

    if (cursa) {
        throw CircuitException();
    }
    else {
        cout << "Cursa exista!" << endl;
    }
}

class Pilot {
protected:
    string nume;
    int varsta;
    int numar_curse_castigate;
    int salariu;
public:
    Pilot() { // fara parametri
        nume = "Gus Fring";
        varsta = 45;
        numar_curse_castigate = 1;
        salariu = 1000000;
    }
    Pilot(string nume_c, const int varsta_c, const int numar_curse_castigate_c, const int salariu_c) { // cu parametri
        nume = nume_c;
        varsta = varsta_c;
        numar_curse_castigate = numar_curse_castigate_c;
        salariu = salariu_c;
    }
    Pilot(Pilot& other) { // copy constructor
        nume = other.nume;
        varsta = other.varsta;
        numar_curse_castigate = other.numar_curse_castigate;
        salariu = other.salariu;
    }
    ~Pilot() {}
    Pilot& operator=(const Pilot& other) { // copiere egal
        this->nume = other.nume;
        this->varsta = other.varsta;
        this->numar_curse_castigate = other.numar_curse_castigate;
        this->salariu = other.salariu;
        return *this;
    }
    string get_nume() const;
    int get_varsta() const;
    int get_numar_curse_castigate() const;
    int get_salariu() const;
    void set_nume(string nume_s);
    void set_varsta(int varsta_s);
    void set_numar_curse_castigate(int numar_curse_castigate_s);
    void set_salariu(int salariu_s);
    friend ostream& operator<<(ostream& out, const Pilot& pilot);

    void Afisare() {
        cout << "Nume: " << nume << endl;
        cout << "Varsta: " << varsta << endl;
        cout << "Curse Castigate: " << numar_curse_castigate << endl;
        cout << "Salariu: " << salariu << endl;
    }
};
string Pilot::get_nume() const { // operator de acces (primul const inseamna ca nu poti schimba variabila iar al doilea ca functia nu are voie sa schimbe)
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
void Pilot::set_nume(string nume_s) {
    nume = nume_s;
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




void Cursa() {
    bool accident = true;
    if (accident) {
        throw AccidentException();
    }
    else {
        cout << "Cursa fara incidente!" << endl;
    }
}


class Circuit {
    char* locatie;
    int km;
    char* luna;
    char* vreme;
    Pilot castigator;
    int premiu;
public:
    Circuit() : castigator() {
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
protected:
    string model;
    int an_fabricatie;
public:
    int cost;
    Masina() {
        model = "Ferrari SF90";
        an_fabricatie = 2022;
        cost = 2000000;
    }
    Masina(string model_c, int an_fabricatie_c, const int cost_c) {
        model = model_c;
        an_fabricatie = an_fabricatie_c;
        cost = cost_c;
    }
    Masina(Masina& other) {
        model = other.model;
        an_fabricatie = other.an_fabricatie;
        cost = other.cost;
    }
    ~Masina() {}
    Masina& operator=(const Masina& other) {
        this->model = other.model;
        this->an_fabricatie = other.an_fabricatie;
        this->cost = other.cost;
        return *this;
    }
    string get_model() const;
    int get_an_fabricatie() const;
    int get_cost() const;
    void set_model(string model_s);
    void set_an_fabricatie(int an_fabricatie_s);
    void set_cost(int cost_s);
    friend ostream& operator<<(ostream& out, const Masina& masina);
    void Afisare() {
        cout << "Model: " << model << endl;
        cout << "An fabricatie: " << an_fabricatie << endl;
        cout << "Costul Masinii: " << cost << endl;
    }
    virtual void CautareModel() {
        throw ModelException("Eroare la cautarea modelului!");
    }
protected:
    int CalculeazaTopSpeed() {
        int topspeed = 300;
        topspeed = topspeed + (an_fabricatie % 100); // adauga 1 km/h pentru fiecare an (model nou)
        return topspeed;
    }
};
string Masina::get_model() const {
    return model;
}
int Masina::get_an_fabricatie() const {
    return an_fabricatie;
}
int Masina::get_cost() const {
    return cost;
}
void Masina::set_model(string model_s) {
    model = model_s;
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
    Echipa() : pilot1(), pilot2(), masina() {
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

float timp_circuit(float km_circuit, float viteza_medie_circuit_kmh, float ture_circuit) {
    float timp = (km_circuit * ture_circuit) / viteza_medie_circuit_kmh;
    return timp;
}

//
//
//  CERINTA 2
//
//

class MotorMasina : public Masina {
private:
    string tip_motor;

public:
    MotorMasina(string model, int an_fabricatie, int cost, string tip_motor)
        : Masina(model, an_fabricatie, cost), tip_motor(tip_motor) {}

    void Afisare() {
        Masina::Afisare();
        cout << "Tip motor: " << tip_motor << endl;
        int topspeed = CalculeazaTopSpeed();
        cout << "Viteza Maxima: " << topspeed << " km/h" << endl;
    }
};

class RotiMasina : public Masina {
private:
    string tip_roti;

public:
    RotiMasina(string model, int an_fabricatie, int cost, string tip_roti)
        : Masina(model, an_fabricatie, cost), tip_roti(tip_roti) {}

    void Afisare() {
        Masina::Afisare();
        cout << "Tip Roti: " << tip_roti << endl;
    }
    void AfisareRoti() {
        cout << "Tip Roti: " << tip_roti << endl;
    }
};

class Rezerva : public Pilot {
private:
    string rezerva;

public:
    Rezerva(string nume, int varsta, int numar_curse_castigate, int salariu, string rezerva)
        : Pilot(nume, varsta, numar_curse_castigate, salariu), rezerva(rezerva) {}

    void Afisare() {
        Pilot::Afisare();
        cout << "Rezerva: " << rezerva << endl;
    }
};

class DepartamentEchipa {
protected:
    string departament;

public:
    DepartamentEchipa(const string& departament) : departament(departament) {}

    virtual void AfisareDetalii() = 0; 

    virtual void OcupatieDepartament() {
        cout << "Ocupatia departamentului in echipa." << endl;
    }

    virtual ~DepartamentEchipa() {}
};

class ManagerDep : public DepartamentEchipa {
private:
    string manager;

public:
    ManagerDep(const string& departament, const string& manager) : DepartamentEchipa(departament), manager(manager) {}

    void AfisareDetalii() override {
        cout << "Departament: " << departament << endl;
        cout << "Nume Manager: " << manager << endl;
    }
    void OcupatieDepartament() override {
        cout << "Realizare obiective pentru Managerul Departamentului." << endl;
        cout << "Strategie specifica Managerului Departament: Coordonarea tehnica a echipei si atribuirea rolurilor." << endl;
    }
};

class MasinaCurse : public MotorMasina, public RotiMasina {
private:
    int pct_aerodinamica;
    int pct_handling;
    int pct_fiabilitate;
    static int numar_masini_curse; // variabila membru statica

public:
    MasinaCurse(string model, int an_fabricatie, int cost, string tip_motor, string tip_roti, int pct_aerodinamica, int pct_handling, int pct_fiabilitate)
        : MotorMasina(model, an_fabricatie, cost, tip_motor), RotiMasina(model, an_fabricatie, cost, tip_roti), pct_aerodinamica(pct_aerodinamica), pct_handling(pct_handling), pct_fiabilitate(pct_fiabilitate) {
        numar_masini_curse++;
    }

    static int GetNumarMasiniCurse() {
        return numar_masini_curse;
    }

    static void AfisareNumarTotalMasini() {
        cout << "Numarul total de masini de curse create: " << numar_masini_curse << endl;
    }

    void Afisare() {
        MotorMasina::Afisare();
        RotiMasina::AfisareRoti();
        cout << "Puncte Aerodinamica: " << pct_aerodinamica << endl;
        cout << "Puncte Handling: " << pct_handling << endl;
        cout << "Puncte Fiabilitate: " << pct_fiabilitate << endl;
    }
};

int MasinaCurse::numar_masini_curse = 0; // variabila membru statica

class IVehicul {
public:
    virtual void PornesteMotor() = 0; // Metoda pur virtuala
    virtual void OpresteMotor() = 0;
    virtual ~IVehicul() {} // Destructor virtual
};

class IMotor {
public:
    virtual void Accelerare() = 0; // Metoda pur virtuala
    virtual void Franeaza() = 0;
    virtual ~IMotor() {} // Destructor virtual
};

class MasinaFormula1 : public IVehicul, public IMotor {
public:
    void PornesteMotor() override {
        cout << "Motorul masinii de Formula 1 a pornit!" << endl;
    }

    void OpresteMotor() override {
        cout << "Motorul masinii de Formula 1 a fost oprit!" << endl;
    }

    void Accelerare() override {
        cout << "Masina de Formula 1 accelereaza!" << endl;
    }

    void Franeaza() override {
        cout << "Masina de Formula 1 franeaza!" << endl;
    }
};

int main()
{
    MotorMasina masina("Ferrari", 2020, 1000000, "Benzina"); // MOSTENIRI
    masina.Afisare();
    cout << endl;
    RotiMasina masina2("Mercedes", 2020, 1000000, "Soft");
    masina2.Afisare();
    cout << endl;
    MasinaCurse masina3("Alfa Romeo", 2023, 2000000, "Benzina", "Hard", 90, 68, 43);
    masina3.Afisare();
    cout << endl;

    ///////////////////////////////////////////////////////////////////

    IVehicul* masina4 = new MasinaFormula1(); // INTERFETE SI METODE VIRTUALE

    masina4->PornesteMotor();
    masina4->OpresteMotor();

    IMotor* masinaSport = dynamic_cast<IMotor*>(masina4);
    if (masinaSport) {
        masinaSport->Accelerare();
        masinaSport->Franeaza();
    }
    delete masina4;
    cout << endl;

    ManagerDep* manager = new ManagerDep("Walter White", "Ferrari");
    manager->AfisareDetalii();
    delete manager;

    vector<DepartamentEchipa*> departamente; // (dynamic dispatch)
    departamente.push_back(new ManagerDep("Departament Tehnic", "Ion Ion")); // upcasting (obiecte de tip ManagerDep sunt atribuite la pointeir DepartamentEchipa
    departamente.push_back(new ManagerDep("Departament Aerodinamica", "John Pork"));

    for (DepartamentEchipa* departament : departamente) {
        departament->AfisareDetalii(); // upcasting (pointerii DepartamentEchipa si metodele sunt apelate in timpul executiei)
        departament->OcupatieDepartament();
        delete departament;
    }

    DepartamentEchipa* departament = new ManagerDep("Departament Buget", "Batman"); // (dynamic dispatch)
    departament->AfisareDetalii();
    departament->OcupatieDepartament();
    delete departament;

    DepartamentEchipa* dep = new ManagerDep("Departament Tehnic", "Ion Ion");

    ManagerDep* managerdep = dynamic_cast<ManagerDep*>(dep); // downcast
    if (managerdep) { //downcast cu succes
        managerdep->OcupatieDepartament();
    }
    else {} // downcast nereusit, returneaza pointer null
    delete dep;

    /////////////////////////////////////////////
    cout << endl << "Exceptii: " << endl; // EXCEPTII
    try {
        Masina car;
        car.CautareModel();
    }
    catch (const exception& e) {
        cout << "A survenit o exceptie: " << e.what() << endl;
    }

    try {
        PilotCreat();
    }
    catch (const exception& e) {
        cout << "Eroare inregistrare pilot: " << e.what() << endl;
    }

    try {
        CursaExistenta();
    }
    catch (const CircuitException& e) {
        cout << "Eroare in timpul cursei: " << e.what() << endl;
    }

    try {
        Cursa();
    }
    catch (const AccidentException& e) {
        cout << "Eroare in timpul cursei: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    try {
        CalculBuget();
    }
    catch (const GauraException& e) {
        cout << "Exceptie prinsa: " << e.what() << endl;
    }
    cout << endl;
    MasinaCurse::AfisareNumarTotalMasini();
    /*   CERINTA 1
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
    */
}

