#include <bits/stdc++.h>

using namespace std;


int n;
vector<int> v;

void generate_permutations(int k)
{
    cout << "k=" << k << "\n";

    if (k == n) {
        cout << "RESULT {";
        for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++) {
            cout << *iter << " ";
        }
        cout << "}\n";


        return;
    }

    v.push_back(k + 1); 

    cout << "before {";
    for (vector<int>::iterator iter = v.begin(); iter < v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "}\n";


    generate_permutations(k + 1);
    v.pop_back();
    v.insert(v.begin(), k+1);
    generate_permutations(k + 1);
    v.pop_back();
}

vector<int> generator;
void generate_permutations2(set<int> pool)
{
#if 0
    cout << "pool {";
    for (int iter : pool) {
        cout << iter << " ";
    }
    cout << "}\n";

    cout << "generator {";
    for (int iter : generator) {
        cout << iter << " ";
    }
    cout << "}\n";
#endif

    if (pool.size() == 0) {
        cout << "FINAL {";
        for (int iter : generator) {
            cout << iter << " ";
        }
        cout << "}\n";
        return;
    }
    set<int> copy = pool;
    for (int iter : copy) {
        cout << "iter=" << iter << endl;
        generator.push_back(iter);
        pool.erase(iter);
        generate_permutations2(pool);
        pool.insert(iter);
        generator.pop_back();
    }
}

int main()
{
    n = 3;

    set<int> pool;
    for (int i = 1; i <= n; i++) {
        pool.insert(i);
    }

#if 0
    cout << "pool {";
    for (int iter : pool) {
        cout << iter << " ";
    }
    cout << "}\n";
#endif

    generate_permutations2(pool);

    return 0;
}


#if 0
0 -> 1
-> 1
#endif
