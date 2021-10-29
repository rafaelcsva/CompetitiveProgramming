#include <bits/stdc++.h>

using namespace std;

const int N = 30;
vector< int > letters[N];

int range(vector< int > &v, int l, int r){
    auto u = lower_bound(v.begin(), v.end(), l) - v.begin();
    auto b = upper_bound(v.begin(), v.end(), r) - v.begin();

    return b - u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    string s;

    cin >> s;

    for(int i = 0 ; i < s.length() ; i++){
        letters[s[i] - 'a'].push_back(i + 1);
    }

    while(q--){
        int l, r;

        cin >> l >> r;

        int sum = 0;

        for(int i = 0 ; i < N ; i++){
            sum += range(letters[i], l, r) * (i + 1);
        }
        printf("%d\n", sum);
    }

    return 0;
}