#include <bits/stdc++.h>

using namespace std;

typedef long long	ll;
typedef pair< ll, int >	pli;

const int N = int(3e5 + 100);
pli a[N], b[N];
int idx1[N], idx2[N];
vector< pair< ll, pair< int, int > > > positives;
vector< pair< ll, pair< int, int > > > negatives;
vector< pair< pair< int, int >, ll > > operations;

bool compar(pair< ll, pair< int, int > > a, pair< ll, pair< int, int > > b){
	return a.second.first < b.second.first;
}

int main(){
	int n;

	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}

	sort(a, a + n);

	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &b[i].first);
		b[i].second = i;
	}

	sort(b, b + n);

	ll sum = 0LL;

	for(int i = 0 ; i < n ; i++){
		ll diff = b[i].first - a[i].first;

		sum += diff;

		if(diff > 0LL){
			// printf("i: %d\n", i);
			positives.push_back({diff, {a[i].first, a[i].second}});
		}else if(diff < 0LL){
			negatives.push_back({-diff, {a[i].first, a[i].second}});
		}
	}

	sort(positives.begin(), positives.end(), compar);
	sort(negatives.begin(), negatives.end(), compar);

	if(sum != 0LL){
		printf("NO\n");
	}else{

		int i = 0, j = 0;

		while(i < positives.size() && j < negatives.size()){
			// printf("%d, %d\n", i, j);
			if(negatives[j].second.first < positives[i].second.first){
				printf("NO\n");
				return 0;
			}

			if(positives[i].first < negatives[j].first){
				negatives[j].first -= positives[i].first;

				operations.push_back({{positives[i].second.second, negatives[j].second.second}, positives[i].first});
				i++;
			}else if(positives[i].first > negatives[j].first){
				positives[i].first -= negatives[j].first;

				operations.push_back({{positives[i].second.second, negatives[j].second.second}, negatives[j].first});
				j++;
			}else{
				operations.push_back({{positives[i].second.second, negatives[j].second.second}, positives[i].first});
				i++, j++;
			}
		}

		if(i < positives.size() || j < negatives.size()){
			printf("NO\n");
			return 0;
		}

		assert(operations.size() <= n * 5);

		printf("YES\n");
		printf("%lu\n", operations.size());

		for(auto u: operations){
			printf("%d %d %lld\n", u.first.first + 1, u.first.second + 1, u.second);
		}
	}

	return 0;
}