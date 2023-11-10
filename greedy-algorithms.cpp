#include <iostream>;
#include <vector>;
#include <set>;
#include <map>;

using namespace std;

/*
 * Complete the 'minimumAbsoluteDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int minimum = INFINITY;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] - arr[i] < minimum) minimum = arr[i + 1] - arr[i];
    }
    return minimum;
}

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */
int luckBalance(int k, vector<vector<int>> contests) {
    vector<int> important_contests;
    int luck = 0;
    for (auto contest: contests) {
        if (contest[1]) {
            important_contests.push_back(contest[0]);
        } else {
            luck += contest[0];
        }
    }
    sort(important_contests.begin(), important_contests.end(), greater<int>());
    for (auto important_contest: important_contests) {
        luck += k > 0 ? important_contest : -important_contest;
        k--;
    }
    return luck;
}

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int minimum_cost = 0;
    sort(c.begin(), c.end(), greater<int>());
    vector<int> purchases_per_friend(k, 0);
    int current_friend = 0;
    for (int cost: c) {
        minimum_cost += (purchases_per_friend[current_friend] + 1) * cost;
        purchases_per_friend[current_friend]++;
        current_friend++;
        if (current_friend == k) current_friend = 0;
    }
    return minimum_cost;
}

/*
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_unfairness = arr[k - 1] - arr[0];
    for (int i = k; i < arr.size(); i++) {
        min_unfairness = min(min_unfairness, arr[i] - arr[i - k + 1]);
    }
    return min_unfairness;
}