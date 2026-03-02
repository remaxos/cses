#include <iostream>

using namespace std;

int main() {
    string str(1000000, ' ');
    cin >> str;

    char prev = ' ';
    int size = 1;
    int max = 0;
    for (char c : str) {
        if (prev == c) {
            size++;
        } else {
            if (size > max)
                max = size;
            size = 1;
            prev = c;
        }
    }
    if (size > max)
        max = size;

    cout << max;


    return 0;
}