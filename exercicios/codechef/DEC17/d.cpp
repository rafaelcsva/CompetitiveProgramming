#include <bits/stdc++.h>

using namespace std;

int main (){
	int t;

	scanf("%d", &t);

	while(t--){
		int A, B, C;
	
		
		int c[3];

		for(int i = 0 ; i < 3 ; i++)
			scanf("%d", c + i);

		scanf("%d%d%d", &A, &B, &C);

		sort(c, c + 3);
		int copy[3];

		for(int i = 0 ; i < 3 ; i++)
			copy[i] = c[i];

		int sum = 0;

		int a = c[0];

		if(a % 2)
			a--;

		a = a * 3;

		sum = min(A * a, min((B * a) / 2, (C * a) / 3));

		a = a / 3;

		for(int j = 0 ; j < 3 ; j++)
			c[j] -= a;

		int ans1 = 0;

		if(c[0]){
			if(c[0] == c[1] == c[2]){
				sum += min(C, min(3 * A, B + A));
			}else{
				ans1 = C;
				ans1 += min((c[2] - c[1]) * A + (c[1] - 1) * B, (c[2] + c[1] - 2) * A);
				int tmp;

				if(c[1] != c[2]){
					tmp = min(B * 2 + B * (c[1] - 1) + A * (c[2] - c[1] - 1), A * (c[0] + c[1] + c[2]));
				}else{
					tmp = min(B * 2 + (B * (c[1] - 2)) + A, A * (c[0] + c[1] + c[2]));
				}
			
				ans1 = min(ans1, tmp);
			}

		}else{
			ans1 = min(B * c[1] + A * (c[2] - c[1]), A * (c[2] + c[1]));
		}		
		sum += ans1;
		int aux = copy[0] + copy[1] + copy[2];
		int m = min(copy[0] + copy[1], copy[2]);
	
		sum = min(sum, min( m * B + (aux - 2 * m) * A , A * (aux)));
	
		int ans2 = C;

		for(int i = 0 ; i < 3 ; i++)
			copy[i] -= 1;

		int t = min(copy[0] + copy[1] , copy[2]);

	//	cout << t * B + (aux -3 - 2 * t) * A << '\n';
		ans2 += t * B + (aux -3 - 2 * t) * A;

		sum = min(sum, ans2);

		cout << sum << '\n';	
	}

	return 0;
}
