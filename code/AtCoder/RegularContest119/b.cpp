#include <bits/stdc++.h>

using namespace std;

int carry[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s, t;

    cin >> n;

    cin >> s >> t;

    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        int a = s[i] - '0';
        int b = t[i] - '0';
        if(a == 0 && carry[a]){
            carry[a]--;
            a = 1;
        }else if(a == 1 && carry[a] && (a != b || (i != n - 1 && s[i + 1] == '0'))){
            carry[a]--;
            a = 0;
        }

        if(a != b){
            carry[!a]++;
            ans++;
        }
    }

    if(carry[0] || carry[1]){
        printf("-1\n");
    }else{
        printf("%d\n", ans);
    }

    return 0;
}