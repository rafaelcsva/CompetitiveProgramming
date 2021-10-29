#include <bits/stdc++.h>

using namespace std;

const int N = 30, M = int(2e4) + 10;
int cnt[N][N];
int all[N];
string s[M];
map< string, bool > mark;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){
            cin >> s[i];
            mark[s[i]] = true;
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            char tmp = s[i][0];
            for(char c = 'a' ; c <= 'z' ; c++){
                s[i][0] = c;

                if(!mark.count(s[i])){
                    ans += 2 * (all[c - 'a'] - cnt[c - 'a'][tmp - 'a']);
                }

                s[i][0] = tmp;
            }

            all[tmp - 'a']++;

            for(char c = 'a' ; c <= 'z' ; c++){
                s[i][0] = c;

                if(mark.count(s[i])){
                    cnt[tmp - 'a'][c - 'a']++;
                }
            }
        }

        printf("%d\n", ans);

        mark.clear();
        memset(cnt, 0, sizeof cnt);
        memset(all, 0, sizeof all);
    }

    return 0;
}