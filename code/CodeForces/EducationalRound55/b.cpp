//28, 11, 2018, 12:43:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
int pre[N];
int n;
int qtd;

int solve(int pos){
    int lo = pos, hi = n;
    int r = 0;

    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int val = pre[mid] - pre[pos - 1];
        int el = mid - pos + 1;

        if(el - val == 0){
            r = el;
            lo = mid + 1;
        }else if(el - val == 1){
            if(qtd != val){
                lo = mid + 1;
                r = el;
            }else{
                hi = mid - 1;
            }
        }else{
            hi = mid - 1;
        }
    }

    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> n;
    cin >> s;

    for(int i = 1 ; i <= n ; i++){
        pre[i] = pre[i - 1];

        if(s[i - 1] == 'G'){
            qtd++;
            pre[i]++;
        }
    }

    int best = 0;

    for(int i = 1 ; i <= n ; i++){
        best = max(best, solve(i));
    }

    cout << best << endl;

    return 0;
}