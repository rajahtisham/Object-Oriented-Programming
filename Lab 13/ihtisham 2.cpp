#include <iostream>
using namespace std;
template <class T>
T findGreater (T a , T b)
{
	if (a>b)
	return a;
	else return b;
	
 } 
 int main()
 { 
   int X = 10 , Y = 20 ;
   cout <<" Greater integer: "<< findGreater(X,Y)<< endl; 
  return 0; }

