//30, 09, 2018, 14:28:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

map< string, int > dis;
const int N = 10;
bool is_boy[N];
int x[N];
string target = "12345678";
bool primes[N * N];
queue< string > q;

void bfs(string source){
    while(!q.empty()){
        q.pop();
    }
    
    dis.clear();

    dis[source] = 0;

    q.push(source);

    while(!q.empty()){
        string u = q.front();
        q.pop();
        // cout << u << endl;

        for(int i = 0 ; i < u.length() ; i++){
            for(int j = 0 ; j < u.length() ; j++){
                int x = u[i] - '0';
                int y = u[j] - '0';

                if(primes[x + y] && is_boy[x] != is_boy[y]){
                    string v1 = "", v2 = "";

                    for(int k = 0 ; k < u.length() ; k++){
                        if(k == j)
                            continue;

                        if(k == i){
                            v1.push_back(u[k]);
                            v1.push_back(u[j]);

                            v2.push_back(u[j]);
                            v2.push_back(u[k]);
                        }else{
                            v1.push_back(u[k]);
                            v2.push_back(u[k]);
                            // v2.push_back(u[j]);
                        }
                    }

                    if(dis.count(v1) == 0){
                        dis[v1] = dis[u] + 1;
                        q.push(v1);
                    }

                    if(dis.count(v2) == 0){
                        dis[v2] = dis[u] + 1;
                        q.push(v2);
                    }
                }
            }
        }

        if(dis.count(target) > 0){
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;

    primes[3] = primes[5] = primes[7] = primes[11] = primes[13] = true;
    string source = "";

    while(scanf("%d", &x[0]) != EOF){
        if(x[0] == 0){
            break;
        }

        for(int i = 1 ; i < 8 ; i++){
            scanf("%d", &x[i]);
        }

        for(int i = 0 ; i < 8 ; i++){
            if(x[i] < 0){
                is_boy[abs(x[i])] = false;
            }else{
                is_boy[x[i]] = true;
            }

            source.push_back(char(abs(x[i]) + '0'));
        }
        // cout << source << endl;

        bfs(source);

        printf("Case %d: ", test++);

        if(dis.count(target) == 0){
            printf("-1\n");
        }else{
            printf("%d\n", dis[target]);
        }
        
        source = "";
        memset(is_boy, 0, sizeof is_boy);
    }

    return 0;
}