#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;

#define pc(x) putchar(x);

inline void writeInt (ll n){
    ll N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

ll read_int(){
	char r;
	bool start=false,neg=false;
	ll ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

class Node {
	public:
	ll mx1 = -1, mx2 = -1;
	ll cnt = 0;
	ll sum = 0;
	ll lazzy = -1;
};

const int N = int(1e6) + 1;
Node segtree[N << 1];
Node nullnode;
ll a[N];

Node merge(Node &lf, Node &rg){
	ll mx1, mx2 = -1;
	ll cnt = 0;
	Node r;

	mx1 = max(lf.mx1, rg.mx1);

	if(mx1 != lf.mx1){
		mx2 = lf.mx1;
	}else{
		cnt += lf.cnt;
	}

	if(mx1 != rg.mx1){
		mx2 = rg.mx1;
	}else{
		cnt += rg.cnt;
	}

	mx2 = max(mx2, max(rg.mx2, lf.mx2));

	r.cnt = cnt;
	
	r.sum = lf.sum + rg.sum;
	r.mx1 = mx1;
	r.mx2 = mx2;
	
	return r;
}

void print_node(int node, int i, int j){
	printf("%d~%d [%lld, %lld] (%lld) s:%lld\n", i, j, segtree[node].mx1, segtree[node].mx2, segtree[node].cnt, segtree[node].sum);
}

void build(int node, int l, int r){
	segtree[node].lazzy = -1;
	
	if(l == r){
		segtree[node].mx1 = a[l];
		segtree[node].cnt = 1;
		segtree[node].mx2 = -1;
		segtree[node].sum = a[l];
	}else{
		int mid = (l + r) >> 1;
		int lf = node << 1;
		int rg = lf + 1;
		
		build(lf, l, mid);
		build(rg, mid + 1, r);
		
		segtree[node] = merge(segtree[lf], segtree[rg]);
	}
	
	//print_node(node, l, r);
}

void push(int node){	
	ll t = segtree[node].lazzy;
	
	if(segtree[node].mx1 <= t){
		segtree[node].lazzy = -1;
		return;
	}

	int lf = node << 1;
	int rg = lf + 1;

	
	segtree[node].sum -= segtree[node].cnt * segtree[node].mx1;
	segtree[node].sum += segtree[node].cnt * t;
	segtree[node].mx1 = t;

	if(max(lf, rg) < N){
		segtree[lf].lazzy = segtree[lf].lazzy == -1 ? t : min(segtree[lf].lazzy, t);
		segtree[rg].lazzy = segtree[rg].lazzy == -1 ? t : min(segtree[rg].lazzy, t);
	}

	segtree[node].lazzy = -1;
}

Node query(int node, int l, int r, int i, int j){
	if(segtree[node].lazzy != -1){
		push(node);
	}
	
	if(i > r || j < l){
		return nullnode;
	}
	
	if(l <= i && j <= r){
		return segtree[node];
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;
		
		auto lfr = query(lf, l, r, i, mid);
		auto rgr = query(rg, l, r, mid + 1, j);
		
		return merge(lfr, rgr);
	}
}

void update(int node, int l, int r, int i, int j, ll t){
	//printf("%d:\n", node);
	//print_node(node, i, j);
	
	if(segtree[node].lazzy != -1){
		push(node);
	}
	
	if(j < l || i > r || segtree[node].mx1 <= t){
		return;
	}
	
	if(i >= l && j <= r && segtree[node].mx1 > t && segtree[node].mx2 < t){
		segtree[node].lazzy = t;
		push(node);
	}else{
		int mid = (i + j) >> 1;
		int lf = node << 1;
		int rg = lf + 1;
		
		update(lf, l, r, i, mid, t);
		update(rg, l, r, mid + 1, j, t);
		
		segtree[node] = merge(segtree[lf], segtree[rg]);
	}
	
	//print_node(node, i, j);
}

int main(){
	int t;
	
    t = read_int();
	
	while(t--){
		int n, m;
		
        n = read_int();
        m = read_int();

		// assert(false);
		
		for(int i = 1 ; i <= n ; i++){
			a[i] = read_int();
		}

		build(1, 1, n);
		
		for(int i = 1 ; i <= m ; i++){
			int tp;
			
            tp = read_int();
			
			if(tp == 0){
				int x, y, t;

                x = read_int();
                y = read_int();
                t = read_int();
                
				update(1, x, y, 1, n, t);
			}else{
				int x, y;
				
                x = read_int();
                y = read_int();
				
				auto qu = query(1, x, y, 1, n);
			
                writeInt(((tp == 1) ? qu.mx1 : qu.sum));
                pc('\n');
			}
		}
	}
	
	return 0;
}