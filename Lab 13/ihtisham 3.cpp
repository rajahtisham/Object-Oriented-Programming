#include <iostream>
using namespace std;
template <typename T>
T swapvalues(T a , T b){
	T temp = a;
	b = temp;
	return temp;
}
int main(){
	int a = 20;
	int b = 40;
	cout<<"Total: "<<endl;
	cout<<"value of A: "<<swapvalues(a , b)<<endl;
	
	return 0;
}


