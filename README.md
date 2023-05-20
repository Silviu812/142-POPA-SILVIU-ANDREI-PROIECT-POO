# APLICATIE GESTIUNE FORMULA 1

Aceasta aplicatie ne ajuta sa gestionam anumite date despre campionatul mondial de formula 1

## Clasa Piloti

Prima clasa din proiect este despre piloti. Este una destul de simpla avand doar patru variabile, trei dintre acestea fiind intregi iar una de tip char
Aceasta clasa ne retine informatii de care vom avea nevoie in clasele ce urmeaza. 

## Clasa Circuit

A doua clasa mentine date despre circuite. Pe langa variabilele intregi si char, aceasta mai are o legatura cu clasa Pilot (pentru a vedea cine a castigat cursa respectiva)

## Clasa Echipa

Mai departe avem probabil cea mai importanta clasa, cea a echipelor. Retine valori necesare (numele, locul in clsament, bugetul) precum si pilotii si masina, ultimele doua fiind clase separate.

## Clasa Masina

Aceasta clasa retine modelul, anul fabricatiei si costul masinii, informatii pe care le folosim la Clasa Echipa. Fiind o clasa secundara, nu are prea multe atributii.

## Clasa Costuri

Ultima clasa are rolul de a stoca date despre costurile unei echipe(transport, masini, imbunatatiri etc), fiind folositoare in logica de business.

## Profitul Echipei

Aceasta functie are ca scop calcularea profitului unei echipe de formula 1. Se ia bugetul echipei (sau se introduce manual) si se scad din clasa costuri tot ce tine de cheltuiala + salariile jucatorilor, astfel ramane la final profitul.

## Durata Cursa

Aceasta functie are ca scop calcularea duratei unui circuit in ore, folosindu se de viteza medie si de lungimea circuitului.

## TEMA 2


MOSTENIRE :
1. Cele 2 clase mostenitoare sunt : MotorMasina (clasa Masina) si Rezerva (clasa Pilot)
2. Am folosit modificatorul protected la clasa masina pentru model si anul fabricatiei, lasand public variabila 'cost'
3. Clasa care foloseste mostenire multipla : MasinaCurse (MotorMasina + Roti Masina, ambele mostenesc clasa Masina)
4. Constructor apelat apare inainte de a se initializa clasa msotenita Exemplu : Masina(model, an_fabricatie, cost), tip_motor(tip_motor) {}
5. Datele membru protejate sunt model / anul fabricatiei si metoda este calculul vitezei maxime (clasa masina)

INTERFETE :
1. Interfata cu 2 metode : MasinaFormula1(vehicul / motor)
2. Clasa de baza abstracta : Departament
3. Prin pointerul departamentechipa* se sterg obiecte alocate de tipul ManagerDep
4. Doua metode virtuale (AfisareDetalii și OcupatieDepartament) suprascrise in clasa ManagerDep

POLIMORFISM LA EXECUTIE :
1. Doua locuri in care are loc polimorfism la executie : cand am folosit vectorul de pointeri si cand  am folosit un pointer pentru a accesa un obiect derivat
2. Cele 2 instante de upcasting : când se adaugă obiecte de tip ManagerDep în vectorul departamente si când se accesează metodele AfisareDetalii() și OcupatieDepartament() pentru obiectele din vectorul departamente (sunt marcate pe cod)
3. Downcast marcat pe cod

EXCEPTII :
1. Exceptie : ModelException (exceptie la cautarea modelului masinii)
2. Exceptii in functiile: PilotCreat si CursaExistenta
3. Exceptia de la functia cursa este tratata in functie de specificul erorii 
4. Avem exceptia de la GauraException prin functia CalculBuget

VARIABILE :
1. Variabila membru statica este numar_masini_curse
2. GetNumarMasiniCurse si AfisareNumarTotalMasini (fac cam acelasi lucru)

