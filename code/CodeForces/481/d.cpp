//13, 05, 2018, 06:28:56 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = int(1e5 + 100);
int a[N];
int aux[N];
const ll INF = ll(1e9);
int n;

void fill(int n){
    for(int i = 0 ; i < n ; i++){
        aux[i] = a[i];
    }
}

ll ver(int diff){
    ll changes = 0;
    
    for(int i = 2 ; i < n ; i++){
        int d = aux[i] - aux[i - 1];

        if(d != diff){
            if(d == diff + 1){
                aux[i]--;
                changes++;
            }else if(d == diff - 1){
                aux[i]++;
                changes++;
            }else{
                return INF;
            }
        }
    }
    
    return changes;
}

int main(){

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    ll mn = INF;
    
    if(n <= 2){
        cout << 0 << endl;
        return 0;
    }else{
        int diff = a[1] - a[0];

        for(int i = diff - 2 ; i < diff + 2 ; i++){
            fill(n);
            
            if(diff == i){
                mn = min(mn, ver(i));

                fill(n);
                aux[0]++, aux[1]++;
                mn = min(mn, ver(i) + 2);

                fill(n);
                aux[0]--, aux[1]--;
                mn = min(mn, ver(diff) + 2);
            }else if(diff < i){
                aux[1]++;

                mn = min(mn, ver(i) + abs(diff - i));

                fill(n);
                
                aux[0]--;
                
                mn = min(mn, ver(i) + abs(diff - i));
            }else if(diff > i){
                aux[1]--;

                mn = min(mn, ver(i) + abs(diff - i));
                
                fill(n);

                aux[0]++;

                mn = min(mn, ver(i) + abs(diff - i));
            }
        }
    }

    if(mn >= INF){
        cout << -1 << endl;
    }else{
        cout << mn << endl;
    }
    
    return 0;
}