//09, 01, 2019, 13:18:14 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int N = 200;
priority_queue< int, vector<int>, greater<int> > pq;
int a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;

    cin >> n >> x >> y;

    for(int i = 0 ; i < n ; i++){
        cin >> a[i];

        pq.push(a[i]);
    }

    if(x > y){
        cout << n << endl;
    }else{
        int turn = 0;
        int burned = 0;

        while(!pq.empty()){
            int u = pq.top();
            pq.pop();

            if(!turn){
                if(u > x){
                    break;
                }else{
                    burned++;
                }
            }

            turn = !turn;
        }

        cout << burned << endl;
    }
    
    return 0;
}