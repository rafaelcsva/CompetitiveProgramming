#include <bits/stdc++.h>

using namespace std;

int mp[10];

int main(){
    mp[2] = 5;
    mp[5] = 2;
    mp[3] = 4;
    mp[4] = 3;
    mp[1] = 6;
    mp[6] = 1;

    int a, b, c;

    cin >> a >> b >> c;

    cout << mp[a] + mp[b] + mp[c] << endl;

    return 0;
}