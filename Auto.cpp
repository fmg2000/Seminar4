#include "Auto.h"
//template

Auto::Auto(int id, string marke, string modell)
{
	this->id = id;
	Marke = marke;
	Modell = modell;
}

int Auto::getId()const { return id; }
void Auto::setId(int value) { id = value; }
string Auto::getMarke()const { return Marke; }
void Auto::setMarke(string value) { Marke = value; }
string Auto::getModell()const { return Modell; }
void Auto::setModell(string value) { Modell = value; }

string Auto::toString()
{
	//return "";
	return to_string(id) + ": " + string(Marke) + " " + string(Modell);
}

bool Auto::operator==(const Auto& a)
{
	return id == a.getId();
}

// nu stiu daca ar fi fost mai bine, eventually sa nu fi "supraincarcat" operatorul asta, ci sa fi facut pur si simplu o metoda `string toString() const`
// am impresia ca, spre deosibre de python, nu am o gama asa de larga de cazuri in care m-as putea folosi de faptul ca eu am facut overloading la operatorul asta,
// pe cand cu o metoda `string toString()` as fi putut face mai multe...nu sunt sigur, doar am vaga impresie. Asta pentru ca operatorul asta ma ajuta doar cand am
// de-a face cu obiecte de tip `ostream`, pe cand un `string` ar fi fost mai flexibil in diferite contexte...dar din nou, nu bag mana in foc, doar am impresia
ostream& operator <<(ostream& os, const Auto& a)
{
	os << a.getId() << " " << a.getMarke() << " " << a.getModell();
	return os;
}