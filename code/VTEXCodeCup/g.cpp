#include <bits/stdc++.h>

using namespace std;

typedef long long 	ll;
typedef pair< int, ll >		pii;

class Client{
public:
	ll ti, di;
	int idx;

	bool operator<(Client &other){
		if(this->ti == other.ti){
			return this->idx < other.idx;
		}

		return this->ti < other.ti;
	}
};

const ll inf = ll(1e18);
const int N = int(2e5);
Client clients[N];
queue< Client > alberto, bernardo;
pii answer[N];

int main(){
	int n;
	ll k;

	scanf("%d %lld", &n, &k);

	for(int i = 0 ; i < n; i++){
		scanf("%lld %lld", &clients[i].ti, &clients[i].di);
		clients[i].idx = i;
	}

	sort(clients, clients + n);

	int pos = 0;
	ll time_alberto = 0LL;
	ll time_bernardo = 0LL;

	while(!alberto.empty() || !bernardo.empty() || pos < n){
		ll nxt_q = inf;
		ll nxt_alb = inf;
		ll nxt_ber = inf;

		if(pos < n){
			nxt_q = clients[pos].ti;
		}

		if(!alberto.empty()){
			nxt_alb = time_alberto;

			if(alberto.front().ti > time_alberto){
				nxt_alb = alberto.front().ti;
			}

			nxt_alb += alberto.front().di;
		}

		if(!bernardo.empty()){
			nxt_ber = time_bernardo;

			if(bernardo.front().ti > time_bernardo){
				nxt_ber = bernardo.front().ti;
			}

			nxt_ber += bernardo.front().di * k;
		}

		if(nxt_q < min(nxt_ber, nxt_alb)){
			if(alberto.size() <= bernardo.size()){
				alberto.push(clients[pos]);
				pos++;
			}else{
				bernardo.push(clients[pos]);
				pos++;
			}
		}else{
			if(nxt_alb < nxt_ber){
				answer[alberto.front().idx] = {0, nxt_alb};
				time_alberto = nxt_alb;
				alberto.pop();
			}else{
				answer[bernardo.front().idx] = {1, nxt_ber};
				time_bernardo = nxt_ber;
				bernardo.pop();
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		printf("%c %lld\n", answer[i].first + 'A', answer[i].second);
	}

	return 0;
}