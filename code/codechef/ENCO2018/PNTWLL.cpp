//26, 10, 2018, 13:12:30 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5);
stack< pii > color_wall;
int h[N], c[N];
set< int > colors;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    scanf("%d", &t);

    while(t--){
        int n, m;

        scanf("%d%d", &n, &m);

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &h[i]);
        }

        for(int i = 0 ; i < n ; i++){
            scanf("%d", &c[i]);
        }

        for(int i = 0 ; i < n ; i++){
            if(color_wall.empty()){
                color_wall.push({h[i], c[i]});
            }else{
                while(!color_wall.empty() && color_wall.top().first <= h[i]){
                    color_wall.pop();
                }

                color_wall.push({h[i], c[i]});
            }
        }

        while(!color_wall.empty()){
            colors.insert(color_wall.top().second);
            color_wall.pop();
        }

        printf("%lu\n", colors.size());
        colors.clear();
    }

    return 0;
}