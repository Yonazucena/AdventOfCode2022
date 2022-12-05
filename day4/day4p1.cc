#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
ifstream myfile;
    myfile.open("input.txt");
    string line;
    int count = 0;
    int sec11, sec12, sec21, sec22;
    char useless;
    while (myfile >> sec11 >> useless >> sec12 >> useless >> sec21 >> useless >> sec22) {
        if (sec11 <= sec21 and sec12 >= sec22) count++;
        else if (sec21 <= sec11 and sec22 >= sec12) count++;
    }
    cout << count << endl;
}