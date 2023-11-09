#include <iostream>;
#include <vector>;

using namespace std;

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> colorCounts;
    for (int color: ar) {
        colorCounts[color]++;
    }
    int pairs = 0;
    for (auto colorCount: colorCounts) {
        pairs += colorCount.second / 2;
    }

    return pairs;
}