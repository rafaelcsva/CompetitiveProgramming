//16, 07, 2018, 12:09:50 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int compute(char a, char b, char c, char d){
    if(a == c && b == d || (a == d && c == b)){
        return 0;
    }

    if(b != d){
        if(a == d || a == b || c == b || c == d){
            return 1;
        }
        
        return 2;
    }else{
        if(a == d || a == b || c == d || c == b){
            return 1;
        }

        return 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b;

    int n;

    cin >> n;
    cin >> a >> b;

    int cnt = 0;

    for(int i = 0, j = n - 1 ; i < n / 2 && j >= 0 ; j--, i++){
        if(a[i] != b[i] || a[j] != b[j]){
            cout << i << ' ' << compute(a[i], b[i], a[j], b[j]) << endl;
            cnt += compute(a[i], b[i], a[j], b[j]);
        }
    }

    if(n & 1){
        if(a[n / 2] != b[n / 2]){
            cnt++;
        }
    }

    cout << cnt << endl;
    
    return 0;
}