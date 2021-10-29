#include <bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int N = 10;
const ll mod = ll(998244353LL);

class matrix{
    public:
    int n;
    ll mat[1 << N][1 << N];
    matrix *ident, *base;

    matrix(int n){
        this->n = n;

        ident = new matrix();
        base = new matrix();
        base->n = ident->n = n;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                base->mat[i][j] = 0LL;
                ident->mat[i][j] = (i == j);
            }
        }
    }

    matrix(){

    }
    
    matrix operator *(matrix &other){
        matrix ans;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                ans.mat[i][j] = 0LL;
                
                for(int k = 0 ; k < n ; k++){
                    ans.mat[i][j] += this->mat[i][k] * other.mat[k][j];
                    ans.mat[i][j] %= mod;
                }
            }
        }
        
        ans.n = n;

        return ans;
    }

    matrix pow(ll p){
        matrix r = *ident;
        matrix d = *this;

        while(p){
            if(p & 1LL){
                r = r * d;
            }

            d = (d * d);
            p >>= 1LL;
        }

        return r;
    }

    //pass one line of matrix in the vector, put the base value too, |clause| = n + 1
    //line is 0 index based
    void add_clause(int lin, vector< ll > clause){
        assert(clause.size() == n + 1);
        assert(0 <= lin && lin < n);

        for(int i = 0 ; i < n ; i++){
            this->mat[lin][i] = clause[i];
        }

        this->base->mat[lin][0] = clause[n];
    }

    void print_line(int line){
        for(int i = 0 ; i < n ; i++){
            printf("%lld ", this->mat[i][line]);
        }
        
        printf("\n");
    }
    
    void print(){
        printf("sz = %d\n",this->n);
        fflush(stdout);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                printf("%lld ", this->mat[i][j]);
                fflush(stdout);
            }
            
            printf("\n");
        }
    }
    
    matrix get_answer_matrix(int e){
        matrix u = this->pow(e);
        
        return u * (*(this->base));
    }
    
    void set_base_case(int line, ll val){
        (this->base)->mat[line][0] = val;
    }
    
    ll get_answer(int line){
        return this->mat[line][0];
    }
};

vector< int > masks;
int ind[N];
vector< vector< int > > all;

bool is_possible(int mask1, int mask2){
    for(int i = 0 ; i < 7 ; i++){
        int e = 1 << i;
        
        if(mask2 & e){
            if(i != 0){
                int ee = 1 << (i - 1);
                
                if(mask1 & ee){
                    mask1 ^= ee;
                    continue;
                }
            }
            
            if(i != 6){
                int ee = 1 << (i + 1);
                
                if(mask1 & ee){
                    mask1 ^= ee;
                    continue;
                }
            }
            
            return false;
        }
    }
    
    assert(mask1 == 0);
    
    return true;
}

ll dp[N];

int main(){
    dp[0] = 1LL;
    dp[1] = 1LL;

    for(int i = 2 ; i < N ; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int h;
    ll w;

    matrix m(1 << h);

    scanf("%d %lld", &h, &w);


    return 0;
}