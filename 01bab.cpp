#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int level, value, weight, bound;
};

int bound(const Node& u, int n, int W, const vector<int>& weights, const vector<int>& values) {
    if (u.weight >= W)
        return 0;

    int profit_bound = u.value;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        profit_bound += values[j];
        j++;
    }

    if (j < n)
        profit_bound += (W - totalWeight) * values[j] / weights[j];

    return profit_bound;
}

int knapsackBranchAndBound(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    queue<Node> Q;

    Node u, v;
    u.level = -1;
    u.value = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;
        else if (u.level != n - 1)
            v.level = u.level + 1;

        v.weight = u.weight + weights[v.level];
        v.value = u.value + values[v.level];

        if (v.weight <= W && v.value > maxProfit)
            maxProfit = v.value;

        v.bound = bound(v, n, W, weights, values);
        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.value = u.value;
        v.bound = bound(v, n, W, weights, values);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int W = 5;

    cout << "Maximum value using Branch and Bound: " << knapsackBranchAndBound(W, weights, values) << endl;

    return 0;
}
