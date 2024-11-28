#include <iostream>
#include <vector>
using namespace std;

int knapsackBacktrack(int i, int W, const vector<int>& weights, const vector<int>& values, int currentValue) {
    if (i == weights.size() || W == 0)
        return currentValue;

    int withoutItem = knapsackBacktrack(i + 1, W, weights, values, currentValue);

    if (weights[i] <= W)
        return max(withoutItem, knapsackBacktrack(i + 1, W - weights[i], weights, values, currentValue + values[i]));

    return withoutItem;
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {6, 10, 12};
    int W = 5;

    cout << "Maximum value using Backtracking: " << knapsackBacktrack(0, W, weights, values, 0) << endl;

    return 0;
}
