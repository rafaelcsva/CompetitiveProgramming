//29, 04, 2018, 11:06:04 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
const int N = int(1e5 + 100);
ll l[N], e[N];
const ll INF = ll(1e9);

int binary_search(ll v, ll vetor[], int n){
    int start = 0, end = n;
    int r = -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(vetor[mid] == v){
            return vetor[mid];
        }else if(vetor[mid] > v){
            end = mid - 1;
        }else{
            r = vetor[mid];
            start = mid + 1;
        }
    }

    return r;
}

int main(){
    ll n, m, cl, ce, v;

    cin >> n >> m >> cl >> ce >> v;

    for(int i = 0 ; i < cl ; i++){
        cin >> l[i];
    }

    for(int i = 0 ; i < ce ; i++){
        cin >> e[i];
    }

    int q;

    cin >> q;

    while(q--){
        ll x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int lf = binary_search(y2, l,  cl - 1);
        int lr = lower_bound(l, l + cl, y2) - l;
    
        if(lr == ce){
            lr = -1;
        }else{
            lr = l[lr];
        }

        cout << lf << ' ' << lr << endl;
        
        ll r = INF;
        ll ax1 = 0LL;
        ll ax2 = 0LL;
        
        if(lf != -1){
            ax1 += abs(lf - y1);
            ax1 += abs(x1 - x2);
            ax1 += abs(lf - y2);
            r = lf;
            cout << "ax1 = " << ax1 << endl;
        }

        if(lr != -1){
            ax2 += abs(lr - y1);
            ax2 += abs(x1 - x2);
            ax2 += abs(lr - y2);
            r = min(cl, ax2);
            cout << "ax2 = " << ax2 << endl;
        }

        int le = binary_search(y2, e, ce - 1);
        int re = lower_bound(e, e + ce, y2) - e;

        if(re == ce){
            re = -1;
        }else{
            re = e[re];
        }

        ax1 = 0LL, ax2 = 0LL;

        if(le != -1){
            ax1 += abs(le - y1);
            ax1 += (abs(x1 - x2) + v - 1) / v;
            ax1 += abs(le - y2);
            r = min(r, ax1);
            cout << "ax1 = " << ax1 << endl;
        }

        if(re != -1){
            ax2 += abs(re - y1);
            ax2 += (abs(x1 - x2) + v - 1) / v;
            ax2 += abs(re - y2);
            r = min(r, ax2);
            cout << "ax2 = " << ax2 << endl;
        }
        cout << le << ' ' << re << endl;
        
        cout << r << endl;
    }

    return 0;
}