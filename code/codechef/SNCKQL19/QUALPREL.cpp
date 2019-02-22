//12, 10, 2018, 18:19:35 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5;
int n, k;
int a[N];

int binary_search(int val){
    int lo = 0, hi = n - 1;
    int r = -1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;

        if(a[mid] >= val){
            r = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }

    return r + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while(t--){
        cin >> n >> k;

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        sort(a, a + n, greater< int >());

        cout << binary_search(a[k - 1]) << endl;
    }

    return 0;
}