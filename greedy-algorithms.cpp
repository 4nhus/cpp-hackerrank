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