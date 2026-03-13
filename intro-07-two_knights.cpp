#include <bits/stdc++.h>

using namespace std;

int attacking(int k, int pos1, int pos2)
{
    if (abs(pos1 / k - pos2 / k) == 1 && abs(pos1 % k - pos2 % k) == 2)
        return 1;
    if (abs(pos1 / k - pos2 / k) == 2 && abs(pos1 % k - pos2 % k) == 1)
        return 1;

    return 0;
}


int attacking_squares(int k, int x, int y)
{
    int total = 0; 
    if (x + 1 <= k && y + 2 <= k) 
        total++;
    if (x + 2 <= k && y + 1 <= k) 
        total++;

    if (x - 1 >= 1 && y + 2 <= k)
        total++;
    if (x - 2 >= 1 && y + 1 <= k)
        total++;

    if (x - 1 >= 1 && y - 2 >= 1)
        total++;
    if (x - 2 >= 1 && y - 1 >= 1)
        total++;

    if (x + 1 <= k && y - 2 >= 1)
        total++;
    if (x + 2 <= k && y - 1 >= 1)
        total++;

    return total;
}

#define MAX 10000

int main ()
{
    int n;
    cin >> n;

#if 0
    int carry = 0;
    for (int i = 1; i <= n; i++) {

        int pos = 0;
        for (int j = 0; j < i * i; j++) {
            for (int k = 0; k < i * i; k++) {
                if (k == j)
                    continue;

                if ((((j / i == i - 1) || (j % i == i - 1)) || ((k / i == i - 1) || (k % i == i - 1))) && !attacking(i, j, k)) {
                    pos++;
                    //cout << "1:" << j / i + 1 << " " << j % i + 1 << " 2:" << k / i + 1 << " " << k%i + 1 << "\n";

                }
            }
        }

        carry = pos / 2 + carry; 
        cout << "i=" << i << " " << carry << "\n";
    }
#endif

    int carry = 0;
    for (int k = 1; k <= n; k++) {
        long int pos = 0;
        for (int i = 1; i <= k; i++) {
            pos += (k * k - 1 - attacking_squares(k, i, k));
        }
        cout << "line: " << pos;
#if 0
        for (int j = 1; j <= k; j++) {
            pos += (k * k - 1 - attacking_squares(k, k, j));
        }
#endif
        //pos += (k * k - 1 - attacking_squares(k, k, k));

        cout << "k=" << k << " " << pos + carry << endl;
        carry = pos+carry;
    }

    return 0;
}

