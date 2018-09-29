//04, 07, 2018, 13:01:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e5 + 10);
int a[N];
ld best = 0.0L;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++){
        if(a[i] == -1){
            int v = 2;
            ld dis = 1.0L;
            i++;

            while(i < n){
                if(v == 0){
                    break;
                }

                if(a[i] == -1LL){
                    v += 2;
                    dis++;
                }else if(a[i] == 0){
                    v--;
                    dis++;
                }else{
                    if(v < 2){
                        dis += 0.5L;
                        v--;
                    }else{
                        v -= 2;
                        dis++;
                    }
                }
            }

            best = max(best, dis);
        }
    }

    cout << fixed << setprecision(2) << best << endl;

    return 0;
}