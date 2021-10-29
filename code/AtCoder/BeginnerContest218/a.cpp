#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    string s;

    cin >> n;
    cin >> s;

    n--;

    cout << (s[n] == 'x' ? "No\n" : "Yes\n");

    return 0;
}