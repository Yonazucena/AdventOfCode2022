#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
ifstream myfile;
    myfile.open("input.txt");
    string line;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
        }
    }
    
}