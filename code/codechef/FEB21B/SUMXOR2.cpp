#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353ll;

const int N=400009; //keep N double of n+m

int cnt[40];
ll pref[N];
ll a[30][N], b[30][N];
ll fat[N];

ll bigMOD(ll a,ll p,ll m=MOD)
{
    ll ret=1;
    while(p>0)
    {
        if(p&1)ret=(ret*a)%MOD;
        p>>=1;
        a=(a*a)%MOD;
    }
    return ret;
}

namespace ntt{
    const int N=::N;
    const long long MOD=::MOD,rt=3;
    // (MOD-1, rt, MOD) && MOD < 1e9:
        // (5 << 25, 3, 167772161)
        // (7 << 26, 3, 469762049)
        // (119 << 23, 3, 998244353)
    // (MOD-1, rt, MOD) && 2^30 > MOD > 1e9:
        // (479 << 21, 3, 1004535809)
        // (483 << 21, 5, 1012924417)

    // typedef long long T;  // only support long long, or you should replace all a*b with 1ll*a*b

    ll G[55],iG[55],itwo[55];

    void add(int &a,int b){a+=b;if(a>=MOD)a-=MOD;}

    void init(){
        int now=(MOD-1)/2,len=1,irt=bigMOD(rt,MOD-2,MOD);
        while(now%2==0){
            G[len]=bigMOD(rt,now,MOD);
            iG[len]=bigMOD(irt,now,MOD);
            itwo[len]=bigMOD(1<<len,MOD-2,MOD);
            now>>=1;len++;
        }
    }
    void dft(ll *x,int n,int fg=1){  // fg=1 for dft, fg=-1 for inverse dft
        for(int i=(n>>1),j=1,k;j<n;++j){
            if(i<j)swap(x[i],x[j]);
            for(k=(n>>1);k&i;i^=k,k>>=1);i^=k;
        }
        for(int m=2,now=1;m<=n;m<<=1,now++){
            ll r = fg>0 ? G[now] : iG[now];
            for(int i=0,j;i<n;i+=m){
                ll tr=1,u,v;
                for(j=i;j<i+(m>>1);++j){
                    u=x[j];v=x[j+(m>>1)]*tr%MOD;
                    x[j]=(u+v)%MOD;
                    x[j+(m>>1)]=(u+MOD-v)%MOD;
                    tr=tr*r%MOD;
                }
            }
        }
    }
    void brute(ll *a,ll *b,int n,int m){
        static ll c[N];
        for(int k=0,t;k<n+m-1;++k){
            t=0;
            for(int i=max(k-m+1,0);i<n && i<=k;++i){add(t,a[i]*b[k-i]%MOD);
                // if(k==2&&i==1)OUT(a[i]),OUT(b[k-i]);
            }
            c[k]=t;
        }
        for(int k=0;k<n+m-1;++k)a[k]=c[k];
    }
    void mul(ll *a,ll *b,int n,int m){   // a: 0,1,2,...,n-1; b: 0,1,2,...,m-1
        // if(n+m<=200){
            // brute(a,b,n,m);
            // return;
        // }
        int nn=n+m-1;
        if(n==0||m==0){
            memset(a,0,nn*sizeof(a[0]));
            return;
        }
        int L,len;for(L=1,len=0;L<nn;++len,L<<=1);
        // OUT(nn);
        // OUT(L);OUT(len);
        if(n<L)memset(a+n,0,(L-n)*sizeof(a[0]));
        if(m<L)memset(b+m,0,(L-m)*sizeof(b[0]));
        // rep(i,0,L)TST(a[i]);puts("");
        // rep(i,0,L)TST(b[i]);puts("");
        dft(a,L,1);dft(b,L,1);
        for(int i=0;i<L;++i)a[i]=a[i]*b[i];
        dft(a,L,-1);
        for(int i=0;i<L;++i)a[i]=a[i]*itwo[len];
    }
}

ll comb(ll n, ll k){
    ll inv = bigMOD((fat[n - k] * fat[k]), MOD - 2, MOD);

    return (fat[n] * inv);
}

int main(){
	ntt::init();

    fat[0] = 1ll;

    for(ll i = 1ll ; i < N ; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
    }

    vector< ll > r;
    // ntt.multiply(a, b, r); 

    int n;
    // printf("%d\n", 1 << 30 - 1);
    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++){
        ll ai;

        scanf("%lld", &ai);

        for(ll d = 0 ; d < 30 ; d++){
            ll e = 1ll << d;

            if(ai & e){
                cnt[d]++;
            }
        }
    }

    for(int i = 0 ; i < 30 ; i++){
        for(int j = 0 ; j <= cnt[i] ; j++){
            if(j & 1){
                a[i][j] = (comb(cnt[i], j));
            }else{
                a[i][j] = 0;
            }
        }

        for(int j = 0 ; j <= n - cnt[i]; j++){
            b[i][j] = (comb(n - cnt[i], j));
        }
        // printf("%lu\n", a.size() + b.size());
		// printf("multiplicando %d\n", i);
        ntt::mul(a[i], b[i], cnt[i] + 1, n - cnt[i] + 1);
		// printf("terminei!\n");
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 30 ; j++){
            ll e = 1 << j;

            pref[i] += (a[j][i] * e) % MOD;

            if(pref[i] >= MOD){
                pref[i] -= MOD;
            }
        }

        pref[i] += pref[i - 1];

        if(pref[i] >= MOD){
            pref[i] -= MOD;
        }
    }

	int q;

    scanf("%d", &q);

    while(q--){
        int mi;

        scanf("%d", &mi);

        printf("%lld\n", pref[mi]);
    }

    return 0;
}