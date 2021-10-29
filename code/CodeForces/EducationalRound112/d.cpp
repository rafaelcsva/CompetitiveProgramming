#include <bits/stdc++.h>

using namespace std;

vector< int > con[256][3];

int rage_sum(char c, int od, int l, int r){
    int ans = upper_bound(con[c][od].begin(), con[c][od].end(), r) - lower_bound(con[c][od].begin(), con[c][od].end(), l);

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    string s;

    cin >> s;

    for(int i = 0 ; i < n ; i++){
        con[s[i]][i % 3].push_back(i);
    }

    while(m--){
        int li, ri;

        cin >> li >> ri;

        li--, ri--;

        string vv = "abc";

        int ans = int(1e9);

        do{
            int tmp = 0;

            for(int j = 0 ; j < vv.length() ; j++){
                for(int i = 0 ; i < vv.length() ; i++){
                    if(i == j) continue;

                    tmp += rage_sum(vv[i], j, li, ri);
                }
            }

            ans = min(ans, tmp);
        }while(next_permutation(vv.begin(), vv.end()));

        printf("%d\n", ans);
    }

    return 0;
}