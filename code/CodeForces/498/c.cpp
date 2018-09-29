//16, 07, 2018, 11:50:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = int(1e6);
ll pref[N], suf[N];
ll d[N];
int n;

int binary_search(int start, ll value){
    int en = n - 1;

    while(start <= en){
        int mid = (start + en) / 2;

        if(suf[mid] == value){
            return 1;
        }

        if(suf[mid] > value){
            start = mid + 1;
        }else{
            en = mid - 1;
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);    

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> d[i];
    }

    for(int i = 0 ; i < n ; i++){
        pref[i] = d[i];

        if(i)
            pref[i] += pref[i - 1];
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        suf[i] = d[i] + suf[i + 1];
    }

    ll best = 0LL;

    for(int i = 0 ; i < n - 1 ; i++){
        if(binary_search(i + 1, pref[i]) != -1){
            best = pref[i];
        }
    }

    cout << best << endl;

    return 0;
}