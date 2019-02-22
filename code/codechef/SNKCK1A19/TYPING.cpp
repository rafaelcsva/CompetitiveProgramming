//19, 10, 2018, 16:15:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int H = 50;
map< string, int > typed;
int han[H];
enum Hands{ lef, rig};

int sum(string &s){
    int n = s.length();
    int hand = -1;
    int tot = 0;

    for(int i = 0 ; i < n ; i++){
        char c = s[i];
        c -= 'a';

        if(han[c] != hand){
            tot += 2;
            hand = han[c];
        }else{
            tot += 4;   
            hand = han[c];
        }
    }

    return tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    han['d' - 'a'] = lef;
    han['f' - 'a'] = lef;
    han['j' - 'a'] = rig;
    han['k' - 'a'] = rig;

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        string s;

        int tot = 0;

        for(int i = 0 ; i < n ; i++){
            cin >> s;

            if(typed[s]){
                tot += typed[s] / 2;
            }else{
                typed[s] = sum(s);
                tot += typed[s];
            }
        }

        cout << tot << endl;

        typed.clear();
    }   

    return 0;
}