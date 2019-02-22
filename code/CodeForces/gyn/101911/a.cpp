//30, 11, 2018, 14:45:11 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(2e5 + 10);
multiset< pii > mst;
multiset< pii >::iterator it;
pii a[N];
int day[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;

    scanf("%d %d %d", &n, &m, &d);

    for(int i = 0 ; i < n ; i++){
        int xi;

        scanf("%d", &xi);
        a[i] = {xi, i};
        mst.insert({xi, i});
    }

    sort(a, a + n);
    int days = 0;

    for(int i = 0 ; i < n ; i++){
        if(day[a[i].second] != 0){
            continue;
        }

        days++;

        day[a[i].second] = days;
        
        // printf("h %d \n", a[i].first + d);
        it = mst.upper_bound({a[i].first + d + 1, -1});

        while(it != mst.end()){
            int val = it->first;
            int ind = it->second;
            // printf("ret %d\n", val);

            mst.erase(it);
            day[ind] = days;
            it = mst.upper_bound({val + d + 1, -1});
        }
    }

    printf("%d\n", days);

    for(int i = 0 ; i < n ; i++){
        char c = i == n - 1 ? '\n' : ' ';

        printf("%d%c", day[i], c);
    }

    return 0;
}