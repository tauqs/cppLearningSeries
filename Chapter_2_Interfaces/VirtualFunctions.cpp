#include <iostream>
using namespace std;

class Account {
	//_vptr => _vTable
public:
   Account( double d ) { _balance = d; }
   virtual ~Account() {
	   cout << "Account Destructor called"<<endl;
   }
   virtual double GetBalance() { return _balance; }
   virtual void PrintBalance() { cerr << "Error. Balance not available for base type." << endl; }
private:
	double _balance;
};

class CheckingAccount : public Account {
public:
   CheckingAccount(double d) : Account(d) {}
   // void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
	~CheckingAccount()
	{
		cout << "CheckingAccount Destructor called"<<endl;
	}
};

class SavingsAccount : public Account {
public:
   SavingsAccount(double d) : Account(d) {}
	void PrintBalance() { cout << "Savings account balance: " << GetBalance() << endl; }
};

int main() {
   // Create objects of type CheckingAccount and SavingsAccount.
//   CheckingAccount checking( 100.00 );
//   SavingsAccount  savings( 1000.00 );
//
//   // Call PrintBalance using a pointer to Account.
//   Account *pAccount = &checking;
//   pAccount->PrintBalance();
//
//   // Call PrintBalance using a pointer to Account.
//   pAccount = &savings;
//   pAccount->PrintBalance();
//
	//CheckingAccount *checking1 = new CheckingAccount(50);
	Account *pAccount1 = new CheckingAccount(50);
	delete pAccount1;
}
