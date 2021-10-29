#include <bits/stdc++.h>

using namespace std;

int dis[30][30];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    for(int test = 1 ; test <= t ; test++){
        string s;

        cin >> s;

        memset(dis, -1, sizeof dis);

        int k;

        cin >> k;

        for(int i = 0 ; i < k ; i++){
            char a, b;

            cin >> a >> b;

            dis[a - 'A'][b - 'A'] = 1;
        }

        for(int i = 0 ; i < 30 ; i++){
            dis[i][i] = 0;
        }

        for(int k = 0 ; k < 30 ; k++){
            for(int i = 0 ; i < 30 ; i++){
                for(int j = 0 ; j < 30 ; j++){
                    if(dis[i][k] == -1 || dis[k][j] == -1){
                        continue;
                    }

                    if(dis[i][j] == -1){
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }else{
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        int ans = int(1e9);

        for(char a = 'A' ; a <= 'Z' ; a++){
            int tmp = 0;

            for(int i = 0 ;i < s.length() ; i++){
                char c = s[i] - 'A';
                char d = a - 'A';

                if(dis[c][d] == -1){
                    tmp = 1e9;
                    break;
                }else{
                    tmp += dis[c][d];
                }
            }

            ans = min(ans, tmp);
        }

        if(ans == int(1e9)){
            ans = -1;
        }

        printf("Case #%d: %d\n", test, ans);
    }

    return 0;
}