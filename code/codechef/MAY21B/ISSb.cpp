#pragma GCC optimize("O2")

#include <bits/stdc++.h>

using namespace std;

const int K = int(4e6) + 10;
vector< int > divs[K], dives[K];
bool is_composite[K];
int cnt[K];
int ans[K], tans[30];
set< int > primes;

int lcm(int a, int b){
    return a * b / __gcd(a, b);
}

void gen_div(int n, int p, int number){
    if(p == divs[n].size()){
        // printf("n = %d\n", n);
        dives[n].push_back(number);
        return;
    }

    int dv = divs[n][p];

    gen_div(n, p + 1, number);

    do{
        gen_div(n, p + 1, number / dv);
        number /= dv;
    }while(number % dv == 0);
}

int main(){
    set< int > difs;

    for(int i = 2 ; i * i < K ; i++){
        if(is_composite[i]){
            continue;
        }
        for(int j = i ; j < K ; j += i){
            is_composite[j] = true;
            if((j - 1) % 4 == 0){
                divs[j].push_back(i);
                primes.insert(i);

                // tot += divs[j].size();
                // sum = max(sum, (int) divs[j].size());
                int jj = j;
                int mcnt = 0;
                // if(divs[j].size() == 144){
                //     printf("eh o %d\n", j);
                // }
                cnt[j] = 1;
            }
        }
    }

    for(auto u: primes){
        printf("%d\n", u);
    }

    vector< int > va;
    set< int > dsums;

    int tot = 0;
    for(int i = 1 ; i < K ; i++){
        // va.push_back(cnt[i]);
        int sums = 0;

        for(auto u: divs[i]){
            sums += u;
        }

        dsums.insert(sums);

        if(cnt[i]){
            gen_div(i, 0, i);
            tot += dives[i].size();
            sort(dives[i].begin(), dives[i].end(), greater< int >());
            int &sum = cnt[i];
            
            for(int d = 0 ; d < dives[i].size() ; d++){
                int tds = tans[d];
                tds += i / dives[i][d];

                for(int j = 0 ; j < d ; j++){
                    if((dives[i][j] % dives[i][d]) == 0){
                        tds -= tans[j];
                    }
                }

                sum += tds * dives[i][d];
            }
            // printf("%d %d %lu\n", dives[i][int(dives[i].size()) - 1], i, dives[i].size());
            for(int d = 0 ; d < dives[i].size() ; d++){
                tans[d] = 0;
            }
        }
    }

    printf("total sums = %lu\n", dsums.size());

    // sort(va.begin(), va.end());
    // reverse(va.begin(), va.end());

    // for(int i = 0 ; i < 1000 ; i++){
    //     printf("%d ", va[i]);
    // }
    // printf("\n");

    printf("\nr: %d\n", tot);

    return 0;
}
