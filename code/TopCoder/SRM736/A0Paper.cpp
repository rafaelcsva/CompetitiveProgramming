//15, 08, 2018, 12:08:32 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class A0Paper{
    public:
        string canBuild(vector< int > A){
            int i = int(A.size()) - 1;

            for(; i >= 1 ; i--){
                A[i - 1] += A[i] / 2;
            }

            if(A[0]){
                return "Possible";
            }else{
                return "Impossible";
            }
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}