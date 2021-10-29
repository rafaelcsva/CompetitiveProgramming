#include <bits/stdc++.h>

using namespace std;

class Game{
    public:
    int father = -1;
    int s[2];
};

const int N = int(3e5);
Game g[N];

int main(){
    ios::sync_with_stdio(false);

    int k;
    string s;

    cin >> k;
    cin >> s;
    
    int pt = 0;

    for(int i = (1 << (k - 1)) ; i < s.length() ; i++){
        g[pt++].father = i;
        g[pt++].father = i;
    }

    int team = 0;

    for(int j = 0 ; j < (1 << (k - 1)) ; j++){
        g[j].s[0] = 1;
        g[j].s[1] = 1;
    }

    for(int j = 0 ; j < s.length() ; j++){
        if(g[j].father != -1){
            if(s[j] == '1' || s[j] == '0'){
                g[g[j].father].s[j & 1] = g[j].s[s[j] - '0'];
            }else{
                g[g[j].father].s[j & 1] = g[j].s[0] + g[j].s[1];
            }
        }
    }

    int q;

    cin >> q;

    while(q--){
        int p;
        char c;

        cin >> p >> c;

        p--;

        if(s[p] != c){
            s[p] = c;

            int cur = p;

            while(g[cur].father != -1){
                if(s[cur] == '1' || s[cur] == '0'){
                    g[g[cur].father].s[cur & 1] = g[cur].s[s[cur] - '0'];
                }else{
                    g[g[cur].father].s[cur & 1] = g[cur].s[0] + g[cur].s[1];
                }
                cur = g[cur].father;
            }
        }

        char last = *s.rbegin();
        if(last == '0' || last == '1'){
            cout << g[int(s.length()) - 1].s[last - '0'] << "\n";
        }else{
            cout << (g[int(s.length()) - 1].s[0] + g[int(s.length()) - 1].s[1]) << "\n";
        }
    }

    return 0;
}
