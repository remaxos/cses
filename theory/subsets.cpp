#include <bits/stdc++.h>

using namespace std;


int n; // total number of elements
std::vector<int> subset;

void search(int k, vector<int> subset)
{
    cout << "k = " << k << endl;

    std::cout << "{ ";
    for (int x : subset) {
        std::cout << x << " ";
    }
    std::cout << "}\n";

    if (k == n) {
        // process subset - print it
        std::cout << "res = { ";
        for (int x : subset) {
            std::cout << x << " ";
        }
        std::cout << "}\n";
    } else {
        // exclude k from subset
        search(k + 1, subset);
        // include k in subset
        subset.push_back(k);
        search(k + 1, subset);
        subset.pop_back();
    }
}

int main() {
    n = 3; // generate all subsets of {0, 1, 2}
    search(0, subset);
    return 0;
}
