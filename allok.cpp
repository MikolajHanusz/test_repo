#include <iostream>
//https://cpp0x.pl/dokumentacja/standard-C/strncat/315
//https://cpp0x.pl/dokumentacja/standard-C/strlen/354
short kod(Osoba&o)
{
	uint16_t kombinat, maska;
	maska = 0x3FFF;
	uint16_t tWiek = o.wiek & maska;
	uint16_t tPlec = (int)o.plec & maska;
	uint16_t tStan = (int)o.stan & maska;	
	tPlec <<= 7;
	tStan <<= 8;
	kombinat = tWiek + tStan + tPlec;
	return kombinat;
}

void dekod(short k,int &w,Plec &p, StanCywilny &s)
{
	uint16_t kombinat = k;
	uint16_t mWiek = 0x07F;
	uint16_t mPlec = 0x080;
	uint16_t mStan = 0x300;
	uint16_t tWiek = kombinat & mWiek;
	uint16_t tPlec = kombinat & mPlec;
	uint16_t tStan = kombinat & mStan;
	tPlec >>= 7;
	tStan >>= 8;
	w = (int)(tWiek);
	p = (Plec)(tPlec);
	s = (StanCywilny)(tStan);
}
enum class typ
{
	asd, asdy
};
typ* alokuj(int s)
{
	typ* wsk = new typ[s];
	return wsk;
}
void dealokuj(typ** wsk)
{
	delete[] *wsk;
	*wsk = nullptr;
	std::cout << *wsk << std::endl;
}

int main()
{
	int n;
	std::cin >>n;
	typ* wsk = alokuj(n);
	std::cout << wsk << std::endl;
	std::cin >> n;
	dealokuj(&wsk);
	std::cin >> n;
	std::cout << wsk << std::endl;

}
