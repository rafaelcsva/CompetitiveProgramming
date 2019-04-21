//06, 03, 2019, 09:13:43 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

class LiteratureOptimal{
    public:
    int minTurns(int N, vector< int > Teja, vector< int > history){
        set< int > st;

        for(int i = 1 ; i <= 3 * N ; i++){
            st.insert(i);
        }

        for(int i = 0 ; i < Teja.size() ; i++){
            st.erase(Teja[i]);
        }

        for(int i = 0 ; i < history.size() ; i++){
            if(i % 3 == 0){
                continue;
            }

            st.erase(history[i]);
        }

        int turns = 0;

        for(int j = history.size() ; st.size() ; j++){
            turns++;
            if(j % 3 == 0){
                continue;
            }
            st.erase(st.begin());
            // turns++;
        }
        
        return turns;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}