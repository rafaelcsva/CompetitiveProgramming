#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;

    cin >> n >> t;

    while(t--){
        int k;

        cin >> k;

        int lo = k, hi = n;

        int r = -1;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;

            cout << "? " << 1 << " " << mid << endl;

            int x;

            cin >> x;

            if(mid - x >= k){
                r = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }

        assert(r != -1);

        cout << "! " << r << endl;
    }

    return 0;
}