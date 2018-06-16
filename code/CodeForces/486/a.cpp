//01, 06, 2018, 11:35:36 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

set<int>st, ratings;

int main(){
    int n, k;

    cin >> n >> k;
    
    for(int i = 0 ; i < n ; i++){
        int x;

        cin >> x;

        if(ratings.find(x) == ratings.end() && st.size() < k){
            st.insert(i + 1);
            ratings.insert(x);
        }
    }

    if(st.size() == k){
        cout << "YES" << endl;
        for(set<int>::iterator it = st.begin() ; it != st.end() ; it++){
            cout << *it << " ";
        }

        cout << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}