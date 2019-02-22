//21, 02, 2019, 23:01:37 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class CalkinWilf{
    public:

    vector< int > solve(string &path, int pos, int a, int b){
        if(pos == path.length()){
            return {a, b};
        }

        if(path[pos] == 'L'){
            return solve(path, pos + 1, a, a + b);
        }else{
            return solve(path, pos + 1, a + b, b);
        }
    }

    vector< int > findRational(string path){
        return solve(path, 0, 1, 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}