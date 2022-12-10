#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool hasDuplicates(string msg) {
    string subs = msg.substr(msg.size()-14, 14);
    for (int i = 0; i < subs.size(); ++i) {
        for (int j = i+1; j < subs.size(); ++j) {
            if (subs[i] == subs[j]) {
                return true;
            }
        }
    }
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

        string msg = line.substr(0, 14);

        bool found = false;
        int ind = 14;
        while(!found && ind < line.size()-1) {
            if (!hasDuplicates(msg)) {
                found = true;
            }
            else {
                ind++;
                msg.push_back(line[ind-1]);
            }
        }
        cout << ind << endl;
    }
    
}