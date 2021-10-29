#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin >> a >> b;

    if(a.length() < b.length()){
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        cout << a << "\n";
    }else{
        assert(a.length() == b.length());
        sort(a.begin(), a.end());

        for(int i = 0 ; i < a.length() ; i++){
            int ansi = 0;
            int ans = -1;
    
            // cout << "entrei como " << a << "\n";

            for(int j = i ; j < a.length() ; j++){
                string tmp = a;

                swap(tmp[i], tmp[j]);

                sort(tmp.begin() + i + 1, tmp.end());
                // cout << i << " " << tmp << " " << (tmp <= b) << "\n";

                if(tmp <= b){
                    if(ans < a[j]){
                        ans = a[j];
                        ansi = j;
                    }
                }
            }

            swap(a[i], a[ansi]);

            if(a[i] < b[i]){
                sort(a.begin() + i + 1, a.end());
                reverse(a.begin() + i + 1, a.end());
                break;
            }
        }

        assert(a[0] != '0');
        cout << a << "\n";
    }

    return 0;
}