//02, 12, 2018, 10:07:27 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

vector< int > con;

void gen(int pos, int mark1, int mark2, int mark3, int number){
    if(pos == 0){
        if(mark1 && mark2 && mark3){
            con.push_back(number);
        }
    }else{
        gen(pos - 1, 1, mark2, mark3, number * 10 + 3);
        gen(pos - 1, mark1, 1, mark3, number * 10 + 5);
        gen(pos - 1, mark1, mark2, 1, number * 10 + 7);

        if(!mark1 && !mark2 && !mark3){
            gen(pos - 1, 0, 0, 0, 0);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    gen(9, 0, 0, 0, 0);

    int n;

    cin >> n;

    int cnt = 0;

    for(int i = 0 ; i < con.size() ; i++){
        if(con[i] <= n){
            cnt++;
        }
    }

    cout << cnt << endl;
    
    return 0;
}