# include <iostream>
# include <string>
using namespace std;

class BankAccount{
	private:
	string accountHolderName;
	double balance;
	
	public:
		
		BankAccount(string n, double b){
			accountHolderName = n;
			balance = b;
		}
		
		void display(){
			cout << "---<(Account Details)>---" << endl;
			cout << "Account Holder: " << accountHolderName << endl;
			cout << "Total Balance: " << balance << endl;
			
		}
		
		static int totalAccounts;
		
		
	
		
};

int BankAccount :: totalAccounts = 02;

int main(){
	
	BankAccount a1("Abdul Hadi", 5000);
	cout << "Account No 01:" << endl;
	a1.display();
	cout << endl;
	BankAccount a2("Saad Hameed", 10000);
	cout << "Account No 02: " << endl;
	a2.display();
	cout << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "   Total Accounts Created Sofar: " << BankAccount:: totalAccounts<< endl;
	cout << "|---------------------------------------|" << endl;
	return 0;
}
