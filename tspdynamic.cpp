#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tspDP(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) == 0 && graph[u][v] != 0) {
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (graph[i][0] != 0) {
            ans = min(ans, dp[(1 << n) - 1][i] + graph[i][0]);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost using Dynamic Programming: " << tspDP(graph) << endl;
    return 0;
}
