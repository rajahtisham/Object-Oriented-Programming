// Aggregation Task:
# include <iostream>
using namespace std;
class Display{
	private:
		double lastResult;
		
	public:
		Display() : lastResult(0.0){	}
		
		void showResult(double result) {
			lastResult =result;
			cout<< "Display:" << result << endl;
		}
		
		double getLastResult() const {
		return lastResult;}
};
class Calculator{
	private:
	     Display display;   // calculater owns display.
	     
    public:
    	//Addition
    	void add(double a, double b){
    		double result = a+b;
    		display.showResult(result);
		}
		
		//Multiplication
		void multiply(double a, double b) {
			double result = a*b;
			display.showResult(result);
		}
	     
	    void showLastResult() {
	    	cout << "Last result was: " << display.getLastResult() << endl;
		}
};

class Student{
	private:
		string name;
		Calculator*sharedCalc;
		
	public:
		Student(string n, Calculator*calc) : name(n) , sharedCalc(calc){}
		
		void doAddition(double a, double b) {
			cout << name << " is adding " << a << "+"<< b << endl;
			sharedCalc -> add(a, b);
		}
		
		void doMultiplication(double a, double b) {
			cout << name << " is multiplying " << a << "*"<< b << endl;
			sharedCalc -> multiply(a, b);
		}
		
};

int main(){
	Calculator*sharedCalculator = new Calculator();
	Student ali("Ali", sharedCalculator);
	Student sara("Sara", sharedCalculator);
	Student ahmad("Ahmad", sharedCalculator);
	
	cout << "===Aggregation===" << endl;
	ali.doAddition(10,20);
	sara.doMultiplication(2,6);
	ahmad.doAddition(100,20);

	
	//Students destroyed here but calculator still exits. Teacher delets calculator when class ends.
	
	delete sharedCalculator;
	
	return 0;
}
