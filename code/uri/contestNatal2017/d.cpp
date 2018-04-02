#include <stdio.h>
#include <algorithm>

#define lli	long long int
using namespace std;

typedef struct{
	lli first;
	lli second;
}Presente;

bool compar1(const Presente &i,const Presente &ii){
	return i.first > ii.first;
}

bool compar2(const Presente &i, const Presente &ii){
	return i.second < ii.second;
}

const int N = (int) 1e5 + 1000;
Presente presentes[N];
lli n, k;

int main (){
	lli t;
	scanf("%lli", &t);

	while(t--){
		scanf("%lli%lli", &n, &k);
	
		for(int i = 0 ; i < n ; i++){
			lli id, h, w, l;

			scanf("%lli%lli%lli%lli", &id, &h, &w, &l);

			presentes[i].first = h * w * l;
			presentes[i].second = id;
		}
		
		sort(presentes, presentes + n, compar1);
		int tmp = k;

		while(tmp < n && presentes[tmp].first == presentes[k - 1].first){
			tmp++;
		}

		sort(presentes + k - 1, presentes + tmp, compar2);
		sort(presentes, presentes + k, compar2);

		for(lli i = 0 ; i < k ; i++){
			char c = i == k-1 ? '\n' : ' ';
	
			printf("%lli%c", presentes[i].second, c);
		}
	}

	return 0;
}
