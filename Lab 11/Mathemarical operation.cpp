# include <iostream>
# include <string>
using namespace std;

class Distance{
	private:
		double inch;
		double feet;
		
	public:
		Distance(double i, double f){
			inch =i;
			feet = f;
		}
		
		 friend double addDistance(Distance d1);
};

    double addDistance(Distance d1){
    	double sum = d1.inch + d1.feet;
    	cout << d1.inch << "+"<< d1.feet << "=" <<sum <<endl;
    	
    	return 0;
	}
	
int main(){
	Distance d1(4683.8,688.5);
	addDistance(d1);
	return 0;
}
