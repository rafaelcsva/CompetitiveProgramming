//29, 04, 2018, 10:13:33 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
vector<int>v;

int main(){
    int n, s;

    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        int h, m;

        cin >> h >> m;

        v.push_back(h * 60 + m);
    }

    int h = 3600, m = 3600;
    int day = 60 * 24;
    int r = -1;

    for(int i = 0 ; i < day * 5 ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0){
                if(i <= v[j]){
                    if(v[j] - i >= s + 1){
                        r = i;
                        break;
                    }
                }
            }else if(j == n - 1){
                if(i >= v[j] && i - v[j] >= s + 1){
                    r = i;
                    break;
                }
            }else{
                if(v[j - 1] <= i && v[j] >= i){
                    if(i - v[j - 1] >= s + 1 && v[j] - i >= s + 1){
                        r = i;
                        break;
                    }
                }
            }
        }

        if(r != -1){
            break;
        }
    }

    cout << r / 60 << ' ' << r % 60 << endl;
    
    return 0;
}