# include <iostream>
# include <string>
using namespace std;

class Box{
	private:
		int length;
	
	public:
		Box(int l) {
			length = l;
		}
        friend void displayLength(Box b1);

};
      
        void displayLength(Box b1){
      	cout << b1.length << endl;
	  }
int main(){
	Box b1(90);
	displayLength(b1);
	return 0;
}
