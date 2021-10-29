#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int >    pii;

const int N = 5010;
map< pii, int > mark;

pii adv(pii pos, char c){
    if(c == 'R'){
        pos.first++;
    }else if(c == 'L'){
        pos.first--;
    }else if(c == 'U'){
        pos.second++;
    }else if(c == 'D'){
        pos.second--;
    }

    return pos;
}

bool reach(pii pos, int i, string &s, pii bck){
    for(int j = i ; j < s.length() ; j++){
        pii nxt = adv(pos, s[j]);

        if(nxt == bck){
            continue;
        }

        pos = nxt;
    }

    return pos == make_pair(0, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        string s;

        cin >> s;

        mark.clear();

        pii pos = {0, 0};

        if(reach(pos, 0, s, {5010, 5010})){
            printf("%d %d\n", 5010, 5010);
        }

        mark[pos] = true;
        pii ans = {0, 0};

        for(int i = 0 ; i < s.length() ; i++){
            pii nxt = adv(pos, s[i]);

            if(!mark[nxt] && reach(pos, i, s, nxt)){
                ans = nxt;
                break;
            }

            pos = nxt;
            mark[nxt] = true;
        }

        printf("%d %d\n", ans.first, ans.second);
    }

    return 0;
}