// Composition Task:
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


int main() {
	Calculator calc;
	
	cout << "===Composition==="<< endl;
	calc.add(10, 3);
	calc.multiply(4, 3);
	calc.showLastResult();
	return 0;
}
