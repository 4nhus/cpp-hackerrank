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


/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */
int countingValleys(int steps, string path) {
    int num_valleys = 0;
    int curr_height = 0;
    bool reached_sea_level = true;
    for (char step: path) {
        if (reached_sea_level && step == 'D') {
            num_valleys++;
            reached_sea_level = false;
            curr_height--;
        } else if (reached_sea_level) {
            reached_sea_level = false;
            curr_height++;
        } else if (step == 'D') {
            curr_height--;
            if (curr_height == 0) reached_sea_level = true;
        } else {
            curr_height++;
            if (curr_height == 0) reached_sea_level = true;
        }
    }
    return num_valleys;
}