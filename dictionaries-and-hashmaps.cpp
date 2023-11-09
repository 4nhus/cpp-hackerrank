#include <iostream>;
#include <vector>;

using namespace std;

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int> magazine_strings;
    for (auto s: magazine) {
        magazine_strings[s]++;
    }
    for (auto s: note) {
        if (--magazine_strings[s] < 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}


