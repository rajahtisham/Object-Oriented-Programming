#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // Open file in read mode
    ifstream file("notes.txt");

    string line;
    int count = 0;

    // Check if file opened successfully
    if (!file) {
        cout << "File not found!" << endl;
        return 0;
    }

    // Read file line by line
    while (getline(file, line)) {
        count++;
    }

    // Display total lines
    cout << "Total number of lines: " << count << endl;

    file.close();

    return 0;
}
