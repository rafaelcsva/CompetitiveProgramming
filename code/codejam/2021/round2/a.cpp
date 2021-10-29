#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int t, n;

    cin >> t >> n;

    for(int i = 0 ; i < t ; i++){
        for(int i = 1 ; i < n ; i++){
            cout << "M " << i << " " << n << endl;

            int pos;

            cin >> pos;

            assert(pos != -1);
            if(i != pos){
                cout << "S " << i << " " << pos << endl;

                cin >> pos;
            }
        }

        cout << "D" << endl;

        int ans;

        cin >> ans;

        assert(ans != -1);
    }

    return 0;
}