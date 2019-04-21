//23, 02, 2019, 07:30:34 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

set< pii > st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll lasta = 0LL, lastb = 0LL;

    cin >> n;

    ll draws = 0LL;

    for(int i = 0 ; i < n ; i++){
        ll ai, bi;

        cin >> ai >> bi;
        
        if(st.find({ai, bi}) != st.end()){
            continue;
        }

        st.insert({ai, bi});

        if(ai < bi){
            draws += min(max(0LL, ai - lastb + 1LL), ai - lasta + 1LL);
        }else{
            draws += min(max(0LL, bi - lasta + 1LL), bi - lastb + 1LL); 
        }

        if(ai < bi){
            lastb = bi;
            lasta = ai + 1LL;
        }else if(ai > bi){
            lastb = bi + 1LL;
            lasta = ai;
        }else{
            lastb = lasta = ai + 1LL;
        }
    }

    cout << draws << endl;
    
    return 0;
}