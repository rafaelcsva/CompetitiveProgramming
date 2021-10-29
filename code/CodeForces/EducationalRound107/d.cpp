#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int adj[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    string s = "";

    s.push_back('a');

    for(int i = 1 ; i < n ; i++){
        char c = s[i - 1] - 'a';
        int mn = 0;

        for(int j = 0 ; j < k ; j++){
            int nxt = (j + c) % k;
            int cur = (c + mn) % k;

            if(adj[c][cur] > adj[c][nxt]){
                mn = j;
            }
            // printf("%d\n", adj[c][nxt]);
        }

        adj[c][(c + mn) % k]++;
        s.push_back((c + mn) % k + 'a');
    }

    cout << s << endl;

    return 0;
}