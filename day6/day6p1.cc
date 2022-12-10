#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool hasDuplicates(char one, char two, char three, char four) {
    if (one == two || one == three || one == four) return true;
    if (two == three || two == four) return true;
    if (three == four) return true;
    return false;
}

int main() {
ifstream myfile;
    myfile.open("input.txt");
    string line;
    if (myfile.is_open()) {
        int count = 0;
        string line;
        myfile >> line;

        char first, second, third, fourth;
        first = line[0];
        second = line[1];
        third = line[2];
        fourth = line[3];

        bool found = false;
        int ind = 4;
        while(!found) {
            if (!hasDuplicates(first, second, third, fourth)) {
                found = true;
            }
            else {
                first = second;
                second = third;
                third = fourth;
                fourth = line[ind];
                ind++;
            }
        }
        cout << ind << endl;
    }
    
}