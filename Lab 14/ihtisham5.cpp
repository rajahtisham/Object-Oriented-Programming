#include <iostream>
using namespace std;
template <class T>
class Calculator
{ 
T a , b;
public:
	Calculator (T x , T y)
	{ a = x ;
	b = y ;
	}
	T add()
	{return a+b;
	} 
	T subtract()
	{ return a-b;
	}
	T multiplay()
	{ return a*b;
	
	}
};
  int main()
  { 
  Calculator<int> c1(10 , 5);
  cout<<"Addition: "<<c1.add()<<endl;
  cout<<"Subtraction: "<<c1.subtract()<<endl;
  cout<<"Multiplication: "<<c1.multiplay()<<endl;
          Calculator<double> c2(5.5 , 2.0);
          cout<< "Addition: "<<c2.add()<<endl;
          cout<<"Subtraction: "<<c2.subtract()<<endl;
          cout<<"Multiplication: "<<c2.multiplay()<<endl;
          
          return 0 ;
  
  }
