#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> set1;
    set<int> set2;

    int sum = n*(n+1)/2;

    if (sum % 2) {
        cout << "NO" << endl;
        return 0;
    }

    set1.insert(1);
    set1.insert(4);
    set2.insert(2);
    set2.insert(3);

    for (int i = 5; i <= n; i++) {
        if (i%2) {
            if (set1.find(i-1) == set1.end()) {
                set2.erase(i-1);
                set2.insert(i);
                set1.insert(i-1);
                set1.erase(1);
                set2.insert(1);
            } else {
                set1.erase(i-1);
                set1.insert(i);
                set2.insert(i-1);
                set2.erase(1);
                set1.insert(1);
            }
        } else {
            if (set1.find(1) == set1.end()) {
                set1.erase(1);
                set1.insert(i);
                set2.insert(1);
                set2.insert(i-1);
            } else {
                set2.erase(1);
                set2.insert(i);
                set1.insert(1);
                set1.insert(i-1);
            }
        }
    }

    for (const int& element: set1) {
        cout << element << " ";
    }

    cout << endl;

    for (const int& element: set2) {
        cout << element << " ";
    }   

    cout << endl;
    
}
