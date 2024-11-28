#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& set, vector<int>& current, int index, int target, bool& found) {
    if (target == 0) {
        found = true;
        cout << "{ ";
        for (int num : current)
            cout << num << " ";
        cout << "}" << endl;
        return;
    }

    if (index >= set.size() || target < 0)
        return;

    // Include the current element
    current.push_back(set[index]);
    findSubsets(set, current, index + 1, target - set[index], found);

    // Exclude the current element
    current.pop_back();
    findSubsets(set, current, index + 1, target, found);
}

void subsetSum(vector<int>& set, int target) {
    vector<int> current;
    bool found = false;

    cout << "Subsets with sum " << target << ":\n";
    findSubsets(set, current, 0, target, found);

    if (!found)
        cout << "No solution exists." << endl;
}

int main() {
    vector<int> set = {1, 2, 5, 6, 8};
    int target;

    cout << "Enter the target sum: ";
    cin >> target;

    subsetSum(set, target);

    return 0;
}
