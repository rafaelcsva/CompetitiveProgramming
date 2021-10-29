#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;

    vector< int > v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(), v.end());

    cout << v[1] + v[2] << "\n";

    return 0;
}