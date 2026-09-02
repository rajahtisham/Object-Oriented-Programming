//File Handling System
# include <iostream>
# include <string>
using namespace std;

class File{
	public:
		File(){
			cout << "File opened" << endl;
		}
		
		virtual ~File(){
			cout << "File closed" << endl;
		}
};

class TextFile : public File{
	public:
		TextFile(){
			cout << "TextFile opened" << endl;
			
		}
		
		~TextFile(){
			cout << "TextFile closed" << endl;
		}
};

int main(){
	TextFile tf;
	return 0;
}
