//05, 05, 2018, 09:01:21 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

int main(){
    int a, b;

    cin >> a >> b;

    if(b >= a){
        cout << a << endl;
    }else{
        cout << a - 1 << endl;
    }
    
    return 0;
}