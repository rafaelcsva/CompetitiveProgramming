//04, 06, 2018, 20:16:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 200100;
int v[N];
int aux[N];
string t, p;

bool can(int at){
    int pt = 0;
    int sub_pos = 0;

    for(int i = 0 ; i <= at ; i++){
        aux[i] = v[i] - 1;
    }

    sort(aux, aux + at + 1);
    
    for(int i = 0 ; i < t.length() ; i++){
        if(i == aux[pt] && pt <= at){
            pt++;
            continue;
        }

        if(sub_pos < p.length() && t[i] == p[sub_pos]){
            sub_pos++;
        }
    }

    return sub_pos == p.length();
}

int main(){
    cin >> t >> p;

    for(int i = 0 ; i < t.length() ; i++){
        cin >> v[i];
    }

    int start = 0, end = t.length() - 1;
    int r = -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(can(mid)){
            start = mid + 1;
            r = mid;
        }else{
            end = mid - 1;
        }
    }
    
    cout << r + 1 << endl;
    
    return 0;
}