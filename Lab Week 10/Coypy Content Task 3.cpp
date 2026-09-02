#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream file1("notes.txt");
    ofstream file2("copy.txt");

    string line;

    // Check file opening
    if (!file1) {
        cout << "notes.txt not found!" << endl;
        return 0;
    }

    // Copy data
    while (getline(file1, line)) {

        file2 << line << endl;
    }

    cout << "Content copied successfully." << endl;

    file1.close();
    file2.close();

    return 0;
}
