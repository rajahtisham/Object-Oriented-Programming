#include<iostream>
#include <string>
using namespace std;
 template <class T>
 class Pair
 {
 	T first , second;
 	public:
 		Pair( T a , T b)
 		{ 
 		first = a;
 		second = b;
		 }
 void display()
 {
 	cout<<"First: "<<first<<" Second: "<<second<<endl;
 	
 }
 };
 int main(){
 	Pair<int>p1(10 , 20);
 	Pair<double>p2(30.0 , 40.5);
 	Pair<string>p3("Ihtisham" , "Zain");
 	p1.display();
 	p2.display();
 	p3.display();
 	
 	return 0 ;
 }
 

