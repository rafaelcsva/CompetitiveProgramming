#include <bits/stdc++.h>

using namespace std;

string s[12];
int pt1[12], pt2[12];

int main(){
    int h, w;

    cin >> h >> w;

    memset(pt1, -1, sizeof pt1);
    memset(pt2, -1, sizeof pt2);

    for(int i = 0 ; i < h ; i++){
        cin >> s[i];
    }

    int ans = 0;

    set< pair< int, int > > cur;
    for(int i = 0 ; i < w ; i++){
        int l = 0;
        set< pair< int, int > > tmp;
        int st = -1, en = -1;
        for(int j = 0 ; j < h ; j++){
            if(s[j][i] == '#'){
                if(st == -1){
                    st = j;
                }
                en = j;
            }else if(st != -1){
                tmp.insert({st, 1});
                tmp.insert({en, 2});
                st = en = -1;
            }
        }
        for(auto u: tmp){
            if(cur.find(u) == cur.end()){
                ans ++;
                // printf("1. %d\n", u.first);
            }
        }
        cur = tmp;
    }

    cur.clear();

    for(int i = 0 ; i < h ; i++){
        int l = 0;
        set< pair< int, int > > tmp;
        int st = -1, en = -1;
        for(int j = 0 ; j < w ; j++){
            if(s[i][j] == '#'){
                if(st == -1){
                    st = j;
                }
                en = j;
            }else if(st != -1){
                tmp.insert({st, 1});
                tmp.insert({en, 2});
                st = en = -1;
            }
        }

        for(auto u: tmp){
            if(cur.find(u) == cur.end()){
                ans ++;
                // printf("2. %d\n", u.first);
            }
        }
        cur = tmp;
    }

    cout << ans << "\n";

    return 0;
}