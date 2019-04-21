//13, 04, 2019, 09:03:00 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    int cnt1 = 0, cnt2 = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1' && (i & 1)){
            cnt1++;
        }else if(s[i] == '0' && !(i & 1)){
            cnt1++;
        }
    }

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '1' && !(i & 1)){
            cnt2++;
        }else if(s[i] == '0' && (i & 1)){
            cnt2++;
        }
    }

    cout << min(cnt1, cnt2) << endl;

    return 0;
}