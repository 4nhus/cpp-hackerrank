#include <iostream>;
#include <vector>;

using namespace std;

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
int hourglassSum(vector<vector<int>> arr) {
    int max_sum = -100000;
    for (int row = 0; row < arr.size() - 2; row++) {
        for (int col = 0; col < arr[0].size() - 2; col++) {
            int sum =
                    arr[row][col] + arr[row][col + 1] + arr[row][col + 2] + arr[row + 1][col + 1] + arr[row + 2][col] +
                    arr[row + 2][col + 1] + arr[row + 2][col + 2];
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}