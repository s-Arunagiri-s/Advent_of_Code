#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

int main() {

    fstream file;
    vector<string> puzzle;
    string tp;

    file.open("day4.txt",ios::in);
    if(file.is_open())
    {
      while(getline(file,tp))
        {
         puzzle.push_back(tp);
        }
    }

   /* vector<string> puzzle = {
        "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
        "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
        "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
        "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
        "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
        "Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"
    };*/

    int sum = 0;

    for (const auto& st : puzzle) {
        vector<int> win, mine;
         string part;
         vector<string> two_parts;
        istringstream iss(st);

        while (getline(iss, part, '|')) {
            two_parts.push_back(part);
        }


        istringstream winStream(two_parts[0].substr(two_parts[0].find(':') + 1));
        int num;
        while (winStream >> num) {
            win.push_back(num);
        }


        istringstream mineStream(two_parts[1]);
        while (mineStream >> num) {
            mine.push_back(num);
        }

        int fin_win = count_if(mine.begin(), mine.end(), [&win](int y) {
            return find(win.begin(), win.end(), y) != win.end();
        });

        if (fin_win > 0) {
            sum += 1 << (fin_win - 1);
        }
    }

    cout << "Part 1: " << sum << endl;

    vector<int> count(puzzle.size(), 1);

    for (size_t ind = 0; ind < puzzle.size(); ++ind) {
        int count_cards = count[ind];


        vector<string> two_parts;
        istringstream iss(puzzle[ind]);
        string part;
        while (getline(iss, part, '|')) {
            two_parts.push_back(part);
        }

        unordered_set<int> win;
        istringstream winStream(two_parts[0].substr(two_parts[0].find(':') + 1));
        int num;
        while (winStream >> num) {
            win.insert(num);
        }

        unordered_set<int> mine;
        istringstream mineStream(two_parts[1]);
        while (mineStream >> num) {
            mine.insert(num);
        }

        int fin_win = count_if(mine.begin(), mine.end(), [&win](int y) {
            return win.find(y) != win.end();
        });

        for (int i = 0; i < fin_win; ++i) {
            if (ind + i + 1 < count.size()) {
                count[ind + i + 1] += count_cards;
            }
        }
    }

    int fin_Sum = accumulate(count.begin(), count.end(), 0);
    cout << "Part 2: " << fin_Sum << endl;

    return 0;
}
