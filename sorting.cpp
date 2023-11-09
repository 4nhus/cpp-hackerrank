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
