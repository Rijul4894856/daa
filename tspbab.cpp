#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    vector<bool> visited;
    int level, cost, bound, currentVertex;
};

int calculateBound(const vector<vector<int>>& graph, Node& u, int n) {
    int bound = u.cost;
    for (int i = 0; i < n; i++) {
        if (!u.visited[i]) {
            int minEdge = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (!u.visited[j] && graph[i][j]) {
                    minEdge = min(minEdge, graph[i][j]);
                }
            }
            bound += (minEdge != INT_MAX) ? minEdge : 0;
        }
    }
    return bound;
}

struct CompareNode {
    bool operator()(const pair<int, Node>& a, const pair<int, Node>& b) {
        return a.first > b.first;  // Compare based on the bound (ascending order)
    }
};

int tspBranchAndBound(const vector<vector<int>>& graph) {
    int n = graph.size();
    priority_queue<pair<int, Node>, vector<pair<int, Node>>, CompareNode> pq;

    Node root;
    root.level = 0;
    root.cost = 0;
    root.visited = vector<bool>(n, false);
    root.visited[0] = true;
    root.currentVertex = 0;
    root.bound = calculateBound(graph, root, n);

    pq.push({root.bound, root});

    int minCost = INT_MAX;

    while (!pq.empty()) {
        auto currentNode = pq.top().second;
        pq.pop();

        if (currentNode.bound >= minCost)
            continue;

        if (currentNode.level == n - 1) {
            int finalCost = currentNode.cost + graph[currentNode.currentVertex][0];
            minCost = min(minCost, finalCost);
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!currentNode.visited[i] && graph[currentNode.currentVertex][i]) {
                Node child = currentNode;
                child.level = currentNode.level + 1;
                child.visited[i] = true;
                child.currentVertex = i;
                child.cost += graph[currentNode.currentVertex][i];
                child.bound = calculateBound(graph, child, n);

                if (child.bound < minCost)
                    pq.push({child.bound, child});
            }
        }
    }

    return minCost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost using Branch and Bound: " << tspBranchAndBound(graph) << endl;
    return 0;
}
