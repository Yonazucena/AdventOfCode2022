#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ifstream myfile;
    myfile.open("input.txt");
    string line;

    //get number of crate columns
    vector<string> matrix;
    bool found = false;
    if (myfile.is_open()) {
        while (!found && getline(myfile, line)) {
            if (line[1] == '1') found = true;
            matrix.push_back(line);
        }
        int ncrates = matrix[matrix.size()-1].size()/4 + 1;
        cout << "ncrates is " << ncrates << endl;
        vector<stack<char>> crates(ncrates);

        //creates crates
        int ncrate = 0;
        for (int j = 1; j < ncrates*4; j = j+4) {
            stack<char> crate;
            for (int i = matrix.size()-2; i >= 0; --i) {
                if (matrix[i][j] != ' ') crate.push(matrix[i][j]);
            }
            crates[ncrate].swap(crate);
            ncrate++;
        }

        //reads instructions
        string useless;
        int num, iniCrate, fiCrate;
        while (myfile >> useless >> num >> useless >> iniCrate >> useless >> fiCrate) {
            for (int i = 0; i < num; ++i) {
                int move = crates[iniCrate-1].top();
                crates[iniCrate-1].pop();
                crates[fiCrate-1].push(move);
            }
        }

        //writes top of each crate
        for (int i = 0; i < crates.size(); i++) {
            cout << crates[i].top();
        }
        cout << endl;
    }
    
    
}