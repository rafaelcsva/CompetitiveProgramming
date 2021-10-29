#include <bits/stdc++.h>

using namespace std;

const int N = int(2e6) + 10;
vector< int > con[2];
int test = 1;
int father[N];
int dis[N];
char lt;

void bfs(int u, int en){
    queue< int > q;

    father[u] = u;
    dis[u] = 0;
    q.push(u);

    while(!q.empty()){
        auto u = q.front();
        // printf("%d %d\n", u, father[u]);
        q.pop();

        auto f0 = upper_bound(con[0].begin(), con[0].end(), u);
        auto f1 = upper_bound(con[1].begin(), con[1].end(), u);

        if(f0 == con[0].end()){
            lt = '0';
            father[en] = u;
            break;
        }

        if(f1 == con[1].end()){
            lt = '1';
            father[en] = u;
            break;
        }

        if(dis[*f0] == -1){
            father[*f0] = u;
            dis[*f0] = 0;
            q.push(*f0);
        }

        if(dis[*f1] == -1){
            father[*f1] = u;
            dis[*f1] = 0;
            q.push(*f1);
        }
    }
}

int main(){
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--){
        con[0].clear();
        con[1].clear();

        string s;

        cin >> s;

        int pos = 0;
    
        for(auto u: s){
            dis[pos] = -1;
            con[u - '0'].push_back(pos);
            pos++;
        }

        if(con[0].size() == 0){
            cout << "0\n";
            continue;
        }else if(con[1].size() == 0){
            cout << "1\n";
            continue;
        }

        bfs(con[1][0], s.length());

        int st = father[s.length()];
        // printf("%d\n", st);
        string ans = "";
        ans += lt;

        while(father[st] != st) {
            ans += s[st];
            st = father[st];
            // printf("st: %d\n", st);
        }

        ans += s[st];
        reverse(ans.begin(), ans.end());

        cout << ans << "\n";
    }

    return 0;
}