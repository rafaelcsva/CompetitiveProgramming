#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << "? 1 " << n << endl;

    int ans;

    cin >> ans;

    int ans1 = -1;

    if(ans != 1){
        cout << "? 1 " << ans << endl;

        cin >> ans1;
    }

    if(ans1 == ans){
        // cout << "left"
        int lo = 1, hi = ans;
        int r = ans - 1;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int tmp = -1;

            if(mid != ans){
                cout << "? " << mid << " " << ans << endl;

                cin >> tmp;
            }

            if(tmp == ans){
                lo = mid + 1;
                r = mid;
            }else{
                hi = mid - 1;
            }
        }

        cout << "! " << r << endl;
    }else{
        int lo = ans, hi = n;
        int r = -1;

        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int tmp = -1;

            if(mid != ans){
                cout << "? " << ans << " " << mid << endl;
                cin >> tmp;
            }

            if(tmp == ans){
                hi = mid - 1;
                r = mid;
            }else{
                lo = mid + 1;
            }
        }

        cout << "! " << r << endl;
    }

    return 0;
}