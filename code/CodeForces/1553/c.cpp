#include <bits/stdc++.h>

using namespace std;

int solve(string &s){
    int sc[2], mt[2];
    sc[0] = sc[1] = 0;
    mt[0] = mt[1] = 5;

    for(int i = 0 ; i < s.length() ; i++){
        int d = i & 1;

        mt[d]--;

        if(s[i] == '1'){
            sc[d]++;
        }
        // printf("%d %d %d %d\n", i, sc[1], mt[0], sc[0]);
        if((sc[0] > mt[1] + sc[1]) || (sc[1] > mt[0] + sc[0])){
            return i + 1;
        }
    }

    return 10;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;
    
        vector< int > v;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '?'){
                v.push_back(i);
            }
        }

        int ans = 11;

        for(int msk = 0 ; msk < (1 << v.size()) ; msk++){
            string cc = s;

            for(int e = 0 ; e < v.size() ; e++){
                int de = 1 << e;

                if(msk & de){
                    cc[v[e]] = '1';
                }else{
                    cc[v[e]] = '0';
                }
            }
            // cout << "test " << cc << endl;
            ans = min(ans, solve(cc));
        }

        cout << ans << "\n";
    }

    return 0;
}