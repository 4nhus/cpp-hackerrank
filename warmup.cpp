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


/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */
int jumpingOnClouds(vector<int> c) {
    if (c.size() < 4) {
        return 1;
    }

    vector<int> minJumps(c.size());
    fill(minJumps.begin(), minJumps.end(), 200);
    minJumps[0] = 0;
    if (!c[1]) minJumps[1] = 1;
    if (!c[2]) minJumps[2] = 1;

    for (int i = 3; i < c.size(); i++) {
        if (c[i]) continue;
        minJumps[i] = min(minJumps[i - 1], minJumps[i - 2]) + 1;
    }

    return minJumps[c.size() - 1];
}