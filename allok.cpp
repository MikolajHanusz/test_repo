#include <iostream>
//https://cpp0x.pl/dokumentacja/standard-C/strncat/315
//https://cpp0x.pl/dokumentacja/standard-C/strlen/354
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
