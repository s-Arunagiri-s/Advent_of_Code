#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <unordered_set>
#include <fstream>

using namespace std;

struct Hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& m) const {
        auto m1 = hash<T1>{}(m.first);
        auto m2 = hash<T2>{}(m.second);
        return m1 ^ m2;
    }
};

const vector<pair<int, int>> dir = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

bool isValid(char c) {
    return !(isdigit(c) || c == '.');
}

bool isAdjacent_Symbol_loc(int row, int column, const vector<string>& schem) {
    for (const auto& d : dir) {
        int n_Col = column + d.second;
        int n_Row = row + d.first;

        if (n_Row < schem.size() &&  n_Row >= 0 && n_Col >= 0 && n_Col < schem[n_Row].size()) {
            if (isValid(schem[n_Row][n_Col])) {
                return true;
            }
        }
    }
    return false;
}

int calculateSum(const vector<string>& schem) {
    int Sum = 0;
    unordered_set<pair<int, int>, Hash> seenloc;

    for (int row = 0; row < schem.size(); ++row) {
        int column = 0;
        while (column < schem[row].size()) {
            if (isdigit(schem[row][column]) &&
               seenloc.find({row, column}) == seenloc.end()) {
                string number(1, schem[row][column]);
                int Col = column;
                while (column + 1 < schem[row].size() && isdigit(schem[row][column + 1])) {
                    number += schem[row][column + 1];
                    ++column;
                }

                for (int curr_Col = Col; curr_Col <= column; ++curr_Col) {
                    seenloc.insert({row, curr_Col});
                    if (isAdjacent_Symbol_loc(row, curr_Col, schem)) {
                        Sum += stoi(number);
                        break;
                    }
                }
            }
            ++column;
        }
    }

    return Sum;
}

int main() {
   /* vector<string> engine_text= {
        "467..114..",
        "...*......",
        "..35..633.",
        "......#...",
        "617*......",
        ".....+.58.",
        "..592.....",
        "......755.",
        "...$.*....",
        ".664.598.."
    };*/

    fstream file;
    vector<string> engine_text;
    string tp;

    file.open("day3.txt",ios::in);
    if(file.is_open())
    {
      while(getline(file,tp))
        {
         engine_text.push_back(tp);
        }
    }



    int sum = calculateSum(engine_text);
    cout << "Part numbers total sum is  " << sum << endl;

    return 0;
}
