//09, 01, 2019, 13:09:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5010;
bool marked[N][N];
int color[N];
bool used[N];
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    int cur_color = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];

        int cicled = 0;
        int besti = -1;

        for(int d = 0 ; d < k ; d++){
            int tmp = (cur_color + d) % k;

            if(!used[tmp]){
                besti = tmp;
                break;
            }

            if(!marked[a[i]][tmp]){
                besti = tmp;
            }
        }

        if(besti == -1){
            cout << "NO" << endl;
            return 0;
        }

        cur_color = besti;

        marked[a[i]][cur_color] = true;
        color[i] = cur_color;
        used[cur_color] = true;
    }    

    cout << "YES" << endl;

    for(int i = 1 ; i <= n ; i++){
        char c = (i == n) ? '\n' : ' ';
        cout << (color[i] + 1) << c;
    }

    return 0;
}