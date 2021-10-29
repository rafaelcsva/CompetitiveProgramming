#include <bits/stdc++.h>

using namespace std;

int main(){
    int s;

    cin >> s;

    cout << s / 100 + (s % 100 ? 1 : 0) << endl;

    return 0;
}