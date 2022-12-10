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

    vector<string> matrix;
    bool found = false;
    if (myfile.is_open()) {
        //find number of crate columns
        while (!found && getline(myfile, line)) {
            if (line[1] == '1') found = true;
            matrix.push_back(line);
        }
        int ncrates = matrix[matrix.size()-1].size()/4 + 1;
        cout << "ncrates is " << ncrates << endl;
        vector<vector<char>> crates(ncrates);

        //read crates
        int ncrate = 0;
        for (int j = 1; j < ncrates*4; j = j+4) {
            vector<char> crate;
            for (int i = matrix.size()-2; i >= 0; --i) {
                if (matrix[i][j] != ' ') crate.push_back(matrix[i][j]);
            }
            crates[ncrate].swap(crate);
            ncrate++;
        }

        //read instructions
        string useless;
        int num, iniCrate, fiCrate;
        while (myfile >> useless >> num >> useless >> iniCrate >> useless >> fiCrate) {
            vector<char> moving;
            for (int i = 0; i < num; ++i) {
                moving.push_back(crates[iniCrate-1][crates[iniCrate-1].size()-1-i]);
            }

            for (int i = 0; i < num; ++i) {
                crates[iniCrate-1].pop_back();
            }

            for(int i = moving.size()-1; i >= 0; --i) {
                crates[fiCrate-1].push_back(moving[i]);
            }

        }

        //writes top of each crate
        for (int i = 0; i < crates.size(); i++) {
            cout << crates[i][crates[i].size()-1];
        }
        cout << endl;
    }
    
    
}