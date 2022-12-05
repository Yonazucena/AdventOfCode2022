#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> //sort
using namespace std;

int main() {
    ifstream myfile;
    myfile.open("input.txt");
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int count = 0;
    string line;
    vector<int> elves;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.empty()) {
                elves.push_back(count);
                count = 0;
            }
            else {
                count = count + atoi(line.c_str());
            }
        }
    }
    sort(elves.begin(), elves.end());
    cout << elves[elves.size()-1] + elves[elves.size()-2] + elves[elves.size()-3] << endl;
}