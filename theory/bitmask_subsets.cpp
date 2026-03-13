#include <bits/stdc++.h>

using namespace std;

/* NOTE: this equivalence is brilliant */

int main() {
    int n = 3; // generate all subsets of {0, 1, 2}

    for (int b = 0; b < (1 << n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) subset.push_back(i);
        }

        // process subset - print it
        cout << "{ ";
        for (int x : subset) std::cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
