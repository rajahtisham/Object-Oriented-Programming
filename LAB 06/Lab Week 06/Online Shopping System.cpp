//Online Shopping System
# include <iostream>
# include <string>
using namespace std;

//Base Class
class Product {
	protected:
		string name;
		double price;
		
	public:
		Product(string n, double p){
			name = n;
			price = p;
		}
		
		void display() {
			cout << "Name: " << name << endl;
			cout << "Price: " << price << endl;
		}
};

//Derived Class
class Electronics : public Product {
	private:
		int warrantyYears;
	public:
		Electronics(string n, double p, int w) : Product (n,p){
			warrantyYears = w;
		}
		void display(){
			Product::display();
			cout << "Warranty Years: " << warrantyYears << endl;
		}
};


//Main Function
int main(){
	Electronics e("Laptop", 50000, 2);
	e.display();
	
	return 0;
}



