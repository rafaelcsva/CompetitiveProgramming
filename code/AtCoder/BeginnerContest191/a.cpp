#include <bits/stdc++.h>

using namespace std;

int main(){
    int v, t, s, d;

    cin >> v >> t >> s >> d;

    if(v * t <= d && d <= v * s){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }

    return 0;
}