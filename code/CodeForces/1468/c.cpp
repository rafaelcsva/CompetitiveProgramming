#include <bits/stdc++.h>

using namespace std;

set< pair< int, int > > customers;
set< int > customersa;
int cus = 1;
const int N = int(5e5) + 10;
int val[N];

int main(){
    int q;

    scanf("%d", &q);

    while(q--){
        int t, m;

        scanf("%d", &t);

        if(t == 1){
            int m;

            scanf("%d", &m);

            customersa.insert(cus);
            customers.insert({-m, cus});
            val[cus++] = -m;
        }else if(t == 2){
            if(customersa.size() > 0){
                int u = *customersa.begin();
                printf("%d ", u);
                customersa.erase(u);
                customers.erase({val[u], u});
            }
        }else{
            if(customers.size() > 0){
                auto u = *customers.begin();
                printf("%d ", u.second);
                customers.erase(u);
                customersa.erase(u.second);
            }
        }
    }
    printf("\n");

    return 0;
}