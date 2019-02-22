//25, 11, 2018, 15:02:02 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2010;
int p[N];
int f[N];
bool choosed[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;

    cin >> n >> m;

    n *= 2;

    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
    }

    for(int i = 1 ; i <= m ; i++){
        int a, b;

        cin >> a >> b;

        f[a] = b;
        f[b] = a;
    }

    int mteam;

    cin >> mteam;

    int turn = 1;
    int nturns = 0;
    int last = -1;
    int xi;

    while(nturns != n){
        if(turn == mteam){
            if(last != -1 && f[last] != 0 && !choosed[f[last]]){
                cout << f[last] << endl;
                choosed[f[last]] = true;          
            }else{
                int best = -1;
                int besti = -1;

                for(int i = 1 ; i <= n ; i++){
                    if(f[i] != 0 && !choosed[i]){
                        if(p[i] > best){
                            best = p[i];
                            besti = i;
                        }
                    }
                }

                if(besti != -1){
                    cout << besti << endl;
                    choosed[besti] = true;
                }else{
                    for(int i = 1 ; i <= n ; i++){
                        if(!choosed[i]){
                            if(p[i] > best){
                                besti = i;
                                best = p[i];
                            }
                        }
                    }

                    cout << besti << endl;
                    choosed[besti] = true;
                }
            }
        }else{
            int xi;

            cin >> xi;

            last = xi;
            choosed[xi] = true;
        }

        nturns++;

        if(mteam == 1){
            mteam = 2;
        }else{
            mteam = 1;
        }
    }

    return 0;
}