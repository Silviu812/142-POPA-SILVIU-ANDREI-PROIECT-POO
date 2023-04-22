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



