//07, 07, 2018, 09:01:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b;

    cin >> a >> b;

    if(a * b == 15){
        cout << "*" << endl;
    }else if(a + b == 15){
        cout << "+" << endl;
    }else{
        cout << "x" << endl;
    }
    
    return 0;
}