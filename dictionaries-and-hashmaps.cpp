#include <iostream>;
#include <vector>;
#include <set>;

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

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
string twoStrings(string s1, string s2) {
    unordered_set<char> s1_chars;
    for (char c: s1) {
        s1_chars.insert(c);
        if (s1_chars.size() == 26) break;
    }
    for (char c: s2) {
        if (s1_chars.count(c) == 1) return "YES";
    }
    return "NO";
}

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int sherlockAndAnagrams(string s) {
    int total_count = 0;
    unordered_map<string, int> substring_counts;
    for (int substring_size = 1; substring_size < s.length(); substring_size++) {
        for (int substring_start = 0; substring_start < s.length() - substring_size + 1; substring_start++) {
            string substring = s.substr(substring_start, substring_size);
            sort(substring.begin(), substring.end());
            substring_counts[substring]++;
        }
        for (auto substring_count: substring_counts) {
            if (substring_count.second > 1) {
                total_count += (substring_count.second * (substring_count.second - 1)) / 2;
            }
        }
        substring_counts.clear();
    }
    return total_count;
}


