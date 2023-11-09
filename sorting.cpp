#include <iostream>;
#include <vector>;
#include <set>;

using namespace std;

/*
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */
void countSwaps(vector<int> a) {
    int num_swaps = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - 1; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                num_swaps++;
            }
        }
    }
    cout << "Array is sorted in " << num_swaps << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[a.size() - 1] << endl;
}

/*
 * Complete the 'maximumToys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER k
 */
int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int num_toys = 0;
    for (int price: prices) {
        if (k - price < 0) break;
        k -= price;
        num_toys++;
    }
    return num_toys;
}

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
int activityNotifications(vector<int> expenditure, int d) {
    int notifications = 0;
    vector<int> window(expenditure.begin(), expenditure.begin() + d);
    sort(window.begin(), window.end());

    for (int i = d; i < expenditure.size(); i++) {
        int double_median;
        int middle = d / 2;
        middle--;
        if (d % 2 == 0) {
            double_median = window[middle] + window[middle + 1];
        } else {
            double_median = window[middle + 1] * 2;
        }
        if (expenditure[i] >= double_median) notifications++;

        window.insert(upper_bound(window.begin(), window.end(), expenditure[i]), expenditure[i]);
        window.erase(lower_bound(window.begin(), window.end(), expenditure[i - d]));
    }
    return notifications;
}

long merge_and_count(vector<int> &arr, int l, int r) {
    if (l >= r) return 0;

    int m = (l + r) / 2;
    long l_count = merge_and_count(arr, l, m);
    long r_count = merge_and_count(arr, m + 1, r);
    long merge_count = 0;
    int l_index = l;
    int r_index = m + 1;
    vector<int> merge;
    while (l_index <= m && r_index <= r) {
        if (arr[r_index] < arr[l_index]) {
            merge_count += m - l_index + 1;
            merge.push_back(arr[r_index]);
            r_index++;
        } else {
            merge.push_back(arr[l_index]);
            l_index++;
        }
    }
    while (l_index <= m) {
        merge.push_back(arr[l_index]);
        l_index++;
    }
    while (r_index <= r) {
        merge.push_back(arr[r_index]);
        r_index++;
    }
    for (int i = 0; i < merge.size(); i++) {
        arr[l + i] = merge[i];
    }

    return l_count + r_count + merge_count;
}

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
long countInversions(vector<int> arr) {
    return merge_and_count(arr, 0, arr.size() - 1);
}