#include <iostream>;
#include <vector>;
#include <set>;
#include <map>;

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */
int makeAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int a_index = 0;
    int b_index = 0;
    int min_deletions = 0;
    while (a_index < a.size() && b_index < b.size()) {
        if (a[a_index] == b[b_index]) {
            a_index++;
            b_index++;
            continue;
        }
        a[a_index] < b[b_index] ? a_index++ : b_index++;
        min_deletions++;
    }
    while (a_index < a.size()) {
        a_index++;
        min_deletions++;
    }
    while (b_index < b.size()) {
        b_index++;
        min_deletions++;
    }
    return min_deletions;
}

/*
 * Complete the 'alternatingCharacters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int alternatingCharacters(string s) {
    char current = s[0];
    int deletions = 0;
    int current_length = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == current) {
            current_length++;
        } else {
            current = s[i];
            deletions += current_length;
            current_length = 0;
        }
    }
    return deletions + current_length;
}

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string isValid(string s) {
    unordered_map<char, int> frequencies;
    for (char c: s) {
        frequencies[c]++;
    }
    map<int, int> frequency_frequencies;
    for (auto frequency: frequencies) {
        frequency_frequencies[frequency.second]++;
    }
    if (frequency_frequencies.size() > 2) return "NO";
    if (frequency_frequencies.size() == 1) return "YES";
    auto first_frequency_it = frequency_frequencies.begin();

    pair<int, int> first_frequency = *first_frequency_it;
    pair<int, int> second_frequency = *(++first_frequency_it);
    if (second_frequency.first - first_frequency.first > 1 && first_frequency.second != 1) return "NO";

    if (first_frequency.second > 1 && second_frequency.second > 1) {
        return "NO";
    } else if (first_frequency.second > 1 && second_frequency.second == 1) {
        return "YES";
    } else if (first_frequency.second == 1 && second_frequency.second > 1) {
        return "YES";
    } else {
        return "YES";
    }
}