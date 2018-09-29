//30, 06, 2018, 10:32:08 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int N = 1010;
int mark1[N], mark2[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    string a, b;

    cin >> n;

    cin >> a >> b;

    for(int i = 0 ; i < n ; i++){
        mark1[b[i] - '0']++, mark2[b[i] - '0']++;
    }
    
    int best1 = 0;

    for(int i = 0 ; i < a.length() ; i++){
        int idx = -1;

        for(int j = a[i] - '0' ; j <= 9 ; j++){
            if(mark1[j]){
                idx = j;
                break;
            }
        }

        if(idx != -1){
            mark1[idx]--;
        }else{
            for(int j = 0 ; j <= 9 ; j++){
                if(mark1[j]){
                    mark1[j]--;
                    break;
                }
            }
            
            best1++;
        }
    }

    int best2 = 0;

    for(int i = 0 ; i < a.length() ; i++){
        char c = '9';
        int idx = -1;

        for(int j = a[i] - '0' + 1 ; j <= 9; j++){
            if(mark2[j]){
                idx = j;
                break;
            }
        }

        if(idx != -1){
            best2++;
            mark2[idx]--;
        }else{
            for(int j = 0 ; j <= 9 ; j++){
                if(mark2[j]){
                    mark2[j]--;
                    break;
                }
            }
        }
    }

    cout << best1 << endl << best2 << endl;

    return 0;
}