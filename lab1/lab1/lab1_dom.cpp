#include<iostream>
#include <cstdlib>
#include <ctime> 
#include <cstring>

using namespace std;

struct przedmiot
{
	char nazwa[100], typ[50], rzadkoœæ[50], klasapostaci[50];
	double waga;
	int wartoœæ,poziom;
};
void wpisanie(przedmiot &p,const char* naz, const char* typ,const char* rzadkoœæ,const char* klasa,double waga, int war,int poziom)
{
	strcpy_s(p.nazwa, naz);
	strcpy_s(p.typ, typ);
	strcpy_s(p.rzadkoœæ, rzadkoœæ);
	strcpy_s(p.klasapostaci, klasa);
	p.waga = waga;
	p.wartoœæ = war;
	p.poziom = poziom;
}

ostream& operator<<(ostream& str,przedmiot const &pr)
{
	str << "Nazwa przedmiotu: " << pr.nazwa << "\n" << "Typ: " << pr.typ << "\t" << "Rzadkosc: " << pr.rzadkoœæ << "\n"
		<< "Wartosc: " << pr.wartoœæ << "\t" << "Waga: " << pr.waga << "\n"
		<< "Wymagany poziom: " << pr.poziom << "\t" << "Klasa postaci: " << pr.klasapostaci << "\n";

	return str;
}
przedmiot& skrzynia(przedmiot* prz,int roz)
{
	int losrz = rand() % 300;
	int los;
	if (0 <= losrz && losrz < 200)
	{	
		while (true)
		{
			los = rand() % roz;
			if (strcmp(prz[los].rzadkoœæ, "zwykly") == 0)
			{
				return prz[los];
			}
		}
	}
	else if (200 <= losrz && losrz < 250)
	{
		while (true)
		{
			los = rand() % roz;
			if (strcmp(prz[los].rzadkoœæ, "niezwykly") == 0)
			{
				return prz[los];
			}
		}

	}
	else if (250 <= losrz && losrz < 290)
	{
		while (true)
		{
			los = rand() % roz;
			if (strcmp(prz[los].rzadkoœæ, "rzadki") == 0)
			{
				return prz[los];
			}
		}

	}
	else
	{
		while (true)
		{
			los = rand() % roz;
			if (strcmp(prz[los].rzadkoœæ, "legendarny") == 0)
			{
				return prz[los];
			}
		}

	}
}
int main()
{
	srand(time(NULL));
	const int size = 7;
	przedmiot prze[size];
	wpisanie(prze[0], "Kij ale ze sznurkiem", "luk", "zwykly", "lucznik", 0.5, 1, 1);
	wpisanie(prze[1], "Debowy", "luk", "zwykly", "lucznik", 4.5, 32, 12);
	wpisanie(prze[2], "Nieprzebijalny", "tarcza", "zwykly", "lucznik", 9.5, 45, 13);
	wpisanie(prze[3], "Krwawa", "zbroja", "niezwykly", "wojownik", 12, 120, 9);
	wpisanie(prze[4], "Alt", "zbroja", "niezwykly", "wojownik", 14, 97, 16);
	wpisanie(prze[5], "Alta", "zbroja", "rzadki", "wojownik", 14, 256, 16);
	wpisanie(prze[6], "Fireball", "zaklecie", "legendarny", "mag", 0.4, 2450, 30);
	cout<<"W skrzyni byl:\n"<<skrzynia(prze, size);
}