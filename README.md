# Bank Accounts
Defniujemy jedno wyliczenie i trzy C-struktury

```c++
enum Banks {PKO, BGZ, BRE, BPH};
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

```
Zdefiniować funkcję o nagłówku: 
```c++
const Couple* bestClient(const Couple* cpls,
int size, Banks bank);

```
która zwraca wskaźnik do tej pary (Couple) z tablicy przekazanej jako pierwszy
argument (o wymiarze size), która ma największą sumę oszczędności jego (he) i jej
(she), ale tylko spo±ród takich par, w których przynajmniej jedno z małżonków ma
konto w banku bank. Jeżli żadna z osób nie ma konta w banku bank, to funkcja
zwraca nullptr. Nie wolno zakładać, że stan konta jest nieujemny; może być dowolnie
duży dodatni i dowolnie duży ujemny. Je±li dwie lub więcej par spośród tych, które
spełniają narzucony warunek ma takie same, największe, oszczędności, to funkcja
zwraca wskaźnik do dowolnej z nich.

