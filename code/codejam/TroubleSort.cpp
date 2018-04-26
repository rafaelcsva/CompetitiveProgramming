//07, 04, 2018, 18:57:43 Rafael de Castro cpp
#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5 + 100);
typedef pair<int, int>  pii;
typedef long long ll;
map<int, pii>mp;
int x[N];
vector<int>v1, v2;

int main(){
    int t;
    int test = 1;
    
    cin >> t;

    while(t--){
        int n;

        cin >> n;

        for(int i = 0 ; i < n ; i++){

            cin >> x[i];
            
            if(i % 2 == 0){
                v1.push_back(x[i]);
            }else{
                v2.push_back(x[i]);
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                x[i] = v1[i / 2];
            }else{
                x[i] = v2[i / 2];
            }
        }

        bool ok = true;

        cout << "Case #" << test++ << ": ";
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(x[i] > x[i + 1]){
                cout << i << endl;
                ok = false;
                break;
            }
        }

        if(ok){
            cout << "OK" << endl;
        }

        v1.clear();
        v2.clear();
    }   

    return 0;
}