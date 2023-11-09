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

/*
 * Complete the 'rotLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER d
 */
vector<int> rotLeft(vector<int> a, int d) {
    // Rotate first (n - d) integers left
    vector<int> remaining_to_rotate;
    for (int i = 0; i < d; i++) {
        remaining_to_rotate.push_back(a[i]);
    }

    for (int i = 0; i <= a.size() - 1 - d; i++) {
        a[i] = a[i + d];
    }
    int i = a.size() - 1 - d + 1;
    for (int num: remaining_to_rotate) {
        a[i] = num;
        i++;
    }

    return a;
}

int merge_and_count(vector<int> &q, int l, int r) {
    if (l >= r) return 0;

    int middle = (l + r) / 2;
    int l_count = merge_and_count(q, l, middle);
    int r_count = merge_and_count(q, middle + 1, r);
    int merge_count = 0;

    int l_index = l;
    int r_index = middle + 1;
    vector<int> qMerge;
    while (l_index <= middle && r_index <= r) {
        if (q[l_index] > q[r_index]) {
            qMerge.push_back(q[r_index]);
            r_index++;
            merge_count += middle - l_index + 1;
        } else {
            qMerge.push_back(q[l_index]);
            l_index++;
        }
    }

    while (l_index <= middle) {
        qMerge.push_back(q[l_index]);
        l_index++;
    }

    while (r_index <= r) {
        qMerge.push_back(q[r_index]);
        r_index++;
    }

    int i = l;
    for (int num: qMerge) {
        q[i] = num;
        i++;
    }

    return l_count + r_count + merge_count;
}

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */
void minimumBribes(vector<int> q) {
    for (int i = 0; i < q.size(); i++) {
        int correct_sticker = i + 1;

        if (q[i] - correct_sticker > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
    }

    cout << merge_and_count(q, 0, q.size() - 1) << endl;
}

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    unordered_map<int, int> position_for_number;
    for (int i = 0; i < arr.size(); i++) {
        position_for_number[arr[i]] = i;
    }
    int num_swaps = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == i + 1) continue;
        int swap_to_position = position_for_number[i + 1];
        position_for_number[arr[i]] = swap_to_position;
        swap(arr.at(i), arr.at(position_for_number[i + 1]));

        num_swaps++;
    }
    return num_swaps;
}

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long> array(n, 0);
    for (auto query: queries) {
        array[query[0] - 1] += query[2];
        if (query[1] != n) array[query[1]] -= query[2];
    }
    long long max = array[0];
    for (int i = 1; i < n; i++) {
        array[i] = array[i - 1] + array[i];
        if (array[i] > max) max = array[i];
    }

    return max;
}