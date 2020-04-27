#pragma once
//template
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::to_string;

class Auto
{
private:
	int id;
	string Marke;
	string Modell;
public:

	// constructor
	Auto(int, string, string);

	// getters + setters
	int getId() const;
	void setId(int value);
	string getMarke() const;
	void setMarke(string value);
	string getModell() const;
	void setModell(string value);

	string toString();

	bool operator==(const Auto& a1);
	friend ostream& operator<<(ostream& os, const Auto& a);
	//!ATENTIE: fiecare operator cu 'considerentele' sale!
	// operatorul `<<` primeste ca prim parametru un obiect de tip `ostream`(cred ca vine de la "output stream")
	// prin urmare, devince clar ca nu poate fi "supraincarcat"("overloaded") ca membru al clasei, fiindca definit astfel
	// ar insemna ca ar avea ca prim parametru un obiect de tip `Auto` ceea ce nu e adevarat.
	// De aici si confuzia mea initiala cu erori de genul "Too few arguments" -> modificam putin codul -> "Too many argumebts" (cred)

	// ~Auto() = default;					// daca as fi scris o asa, nu stiu daca ar fi facut ce trebuie, dar probabil ca da
};