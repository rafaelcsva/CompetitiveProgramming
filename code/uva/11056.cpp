//25, 07, 2018, 12:10:13 Rafaelcs cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

typedef unsigned long long ull;

const int M = 110, N = 22;

bool cmp(char d[], char f[]){
    int mn = min(strlen(d), strlen(f));

    for(int i = 0 ; i < mn ; i++){

        if((d[i] | 32) < (f[i] | 32)){
            return true;
        }else if((d[i] | 32) > (f[i] | 32)){
            return false;
        }
    }

    return strlen(d) < strlen(f);
}

class Pilot{
    public:
        int p_time;
        char name[N];

        bool operator >(Pilot &other){
            return this->p_time > other.p_time;
        }

        bool operator <(Pilot &other){
            if(this->p_time < other.p_time){
                return true;
            }else if(this->p_time == other.p_time){
                return cmp(this->name, other.name);
            }else{
                return false;
            }
        }
};

Pilot pilots[M];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    while(scanf("%d", &n) != EOF){
        for(int i = 0 ; i < n ; i++){
            int min, sec, ms;

            scanf("\n%s : %d min %d sec %d ms", pilots[i].name, &min, &sec, &ms);
        
            pilots[i].p_time = min * 60 * 1000 + sec * 1000 + ms;
        }

        sort(pilots, pilots + n);

        int i = 0;

        for(int row = 1 ; row <= (n + 1) / 2 ; row++){
            printf("Row %d\n", row);

            printf("%s\n", pilots[i].name);
            if(i + 1 < n){
                printf("%s\n", pilots[i + 1].name);
            }

            i += 2;
        }

        printf("\n");
    }

    return 0;
}