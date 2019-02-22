//16, 02, 2019, 10:00:23 Rafaelcs cpp
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

    if(b % a == 0){
        cout << a + b << endl;
    }else{
        cout << b - a << endl;
    }
    
    return 0;
}