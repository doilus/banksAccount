#include <iostream>

//ZADANIE 9 Dominika £ugowska s17226
enum Banks { PKO, BGZ, BRE, BPH };
struct Account {
	Banks bank;
	int balance;
};
struct Person {
	char name[20];
	Account account;
};
struct Couple {
	Person he;
	Person she;
};
const Couple* bestClient(const Couple* cpls,
	int size, Banks bank) {
	// ...
	double balance = 0;
	int index = -1;

	for (int i = 0; i < size; i++) { // -> referencja
		//sprawdzamy tylko gdy jedno z pary ma konto w danym banku
		if ((((cpls[i]).he).account).bank == bank || (((cpls[i]).she).account).bank == bank) {
			//sprawdzamy oszczêdnoœci i zapisujemy tylko wiêksz¹ wartoœæ
			double d = (double)((((cpls[i]).he).account).balance + (((cpls[i]).she).account).balance);
			if (d >= balance) {
				//zapisujê indeks najwiêkszego balansu
				index = i;
				balance = d;
				//std::cout <<index <<" bank to: "<< bank << " bank2 to:" << (((cpls[i]).he).account).bank <<" " << (((cpls[i]).she).account).bank <<"\n" ;
			}

		}

	}
	if (index >= 0) { // jezeli znaleziono dana pare indeks bez = -1
		return cpls + index; //funkcja zwraca wartosc ostatniej pary sprawdzanej z najwiekszym balance
	}
	else {
		return nullptr;
	}


}
int main() {
	using std::cout; using std::endl;


	Couple cpls[] = { { "Johny",PKO,1200, "Mary", BGZ, 1500 },
		{ "Peter",BGZ,1400, "Suzy", BRE, 1300 },
		{ "Kevin",PKO,1600, "Katy", BPH, 1500 },
		{ "Kenny",BPH,1800, "Lucy", BRE, 1700 }

	};
	const Couple* p = bestClient(cpls, 4, BGZ);
	if (p)
		cout << p->he.name << " and " << p->she.name
		<< ": " << p->he.account.balance +
		p->she.account.balance << endl;
	else
		cout << "No such couple..." << endl;


	system("pause");
}