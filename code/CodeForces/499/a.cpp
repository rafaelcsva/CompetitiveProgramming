//26, 07, 2018, 12:07:31 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    string s;

    cin >> s;

    sort(s.begin(), s.end());

    char last = s[0];
    int sum = last - 'a' + 1;
    k--;
    
    for(int i = 1 ; i < n && k ; i++){
        if(s[i] - last >= 2){
            sum += s[i] - 'a' + 1;
            last = s[i];
            k--;
        }
    }

    if(k){
        cout << -1 << endl;
    }else{
        cout << sum << endl;
    }

    return 0;
}