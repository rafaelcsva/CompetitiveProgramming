//31, 07, 2018, 11:43:26 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

vector<int>seq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k, s;

    scanf("%lld %lld %lld", &n, &k, &s);

    if((n - 1LL) * k < s || s < k){
        printf("NO\n");
    }else{
        printf("YES\n");

        int house = 1;

        while(s - (n - 1LL) >= (k - 1LL)){
            if(house == 1)
                house = n;
            else
                house = 1;
                
            seq.push_back(house);
            s -= (n - 1LL);
            k--;
        }
        

        if(k){
            int f = s - k + 1;
            
            if(f){
                if(house == 1){
                    house = house + f;
                }else{
                    house = house - f;
                }

                seq.push_back(house);
                s -= f;
                k--;
                int i = 0;

                while(k){
                    if(house == 1){
                        house++;
                    }else{
                        house--;
                    }

                    seq.push_back(house);
                    k--;
                }   
            }
        }
        
        for(int u: seq){
            printf("%d ", u);
        }

        printf("\n");
    }

    return 0;
}