//13, 02, 2019, 16:24:19 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = int(1e5 + 10);
priority_queue< pii > pq;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    int tapes = 0;

    cin >> n >> m >> k;

    int cost = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        cost++;
        
        if(i != 1){
            pq.push({-(a[i] - a[i - 1]), i});
        }
    }

    tapes = n;

    while(tapes > k){
        cost += -pq.top().first;
        cost--;
        // cout << pq.top().second << "unied " << endl;
        pq.pop();

        tapes--;
    }

    cout << cost << endl;
    
    return 0;
}