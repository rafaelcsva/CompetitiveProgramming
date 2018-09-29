//16, 09, 2018, 07:46:24 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 100);
multiset< pii > st;
int minutes[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, d;
    
    scanf("%d %d %d", &n, &m, &d);

    for(int i = 0 ; i < n ; i++){
        scanf("%d", &minutes[i]);
        st.insert({minutes[i], i});
    }
    
    int day = 1;

    d++;
    
    while(st.size() > 0){
        int fi = 0;

        set< pii >::iterator it = st.lower_bound({0, -1});

        while(it != st.end()){
            minutes[it->second] = day;
            fi = it->first;
            st.erase(it);
            it = st.lower_bound({d + fi, -1});
        }

        day++;
    }

    printf("%d\n", day - 1);

    for(int i = 0 ; i < n ; i++){
        char c = i == n - 1 ? '\n' : ' ';
        printf("%d%c", minutes[i], c);
    }
    
    return 0;
}