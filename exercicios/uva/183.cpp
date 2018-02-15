#include <bits/stdc++.h>

using namespace std;

const int N = 1000, L = 50;
char bitmap[N][N];
char command[N];
int cnt = 0;

void solveB(int r, int c, int n, int m){
	char cur = bitmap[r][c];
	
	if(r > n || c > m){
		return;
	}
	
	for(int i = r ; i <= n ; i++){
		for(int j = c ; j <= m ; j++){
			if(bitmap[i][j] != cur){
			
				if(cnt == L){
					cnt = 0;
					printf("\n");
				}
				
				printf("D");
				
				cnt++;
				
				int dc = (m - c - 1) / 2, evenc = (m - c - 1) % 2;
				int dr = (n - r - 1) / 2, evenr = (n - r - 1) % 2;
								
				if(m - c == 0){
				
					solveB(r, c, r + dr + evenr, m);
					solveB(r + dr + evenr + 1, c, n, m);
					
					return;
					
				}else if(n - r == 0){
					solveB(r, c, n, c + dc + evenc);
					solveB(r, c + dc + evenc + 1, n, m); 
					
					return;
					
				}
				
			/*	cout << "Splitted: " << r << ' ' << c << ' ' << n << ' ' << m << " in :\n";
				cout << r << ' ' << c << ' ' << r + dr + evenr << ' ' << c + dc + evenc << '\n';
				cout << r << ' ' << c + dc + evenc + 1 << ' ' << r + dr + evenr << ' ' << m << '\n';
				cout << r + dr + evenr + 1 << ' ' << c << ' ' << n << ' ' << c + dc + evenc << '\n';
				cout << r + dr + evenr + 1 << ' ' << c + dc + evenc + 1 << ' ' << n << ' ' << m << '\n';
				
				cout << "---------------------------\n\n";*/
				
				solveB(r, c, r + dr + evenr, c + dc + evenc);
				solveB(r, c + dc + evenc + 1, r + dr + evenr, m);
				solveB(r + dr + evenr + 1, c, n, c + dc + evenc);
				solveB(r + dr + evenr + 1, c + dc + evenc + 1, n, m);
				
				return;
			}
		}	
	}
	
	if(cnt == L){
		cnt = 0;
		printf("\n");
	}
	
	printf("%c", cur);
	
	cnt++;
	
}

void solveD(int r, int c, int n, int m, int &pos){
	char cur = bitmap[r][c];
	//printf("\n-- %d %d %d %d %d\n", r, c, n, m, pos);
	if(pos >= strlen(command)){
		
		return;
	}
	
	if(command[pos] != 'D'){
		for(int i = r ; i <= n ; i++){
			for(int j = c ; j <= m ; j++){
				bitmap[i][j] = command[pos];
			}
		}
		
		pos++;
		
		return;
	}
	
	pos++;
	
	int dc = (m - c - 1) / 2, evenc = (m - c - 1) % 2;
	int dr = (n - r - 1) / 2, evenr = (n - r - 1) % 2;
					
	if(m - c == 0){
		//printf("splitd1\n\n");
		solveD(r, c, r + dr + evenr, m, pos);
		solveD(r + dr + evenr + 1, c, n, m, pos);
		
		return;
		
	}else if(n - r == 0){
		//printf("splitd2\n\n");
		//cout << r << ' ' << c << ' ' << n << ' ' << c + dc + evenc << '\n';
		//cout << r << ' ' << c + dc + evenc + 1 << ' ' << n << ' ' << m << '\n';
		
		//cout << "******\n";
		solveD(r, c, n, c + dc + evenc, pos);
		
		solveD(r, c + dc + evenc + 1, n, m, pos); 
		
		return;
	}
	
	/*cout << "Splitted: " << r << ' ' << c << ' ' << n << ' ' << m << " in :\n";
	cout << r << ' ' << c << ' ' << r + dr + evenr << ' ' << c + dc + evenc << '\n';
	cout << r << ' ' << c + dc + evenc + 1 << ' ' << r + dr + evenr << ' ' << m << '\n';
	cout << r + dr + evenr + 1 << ' ' << c << ' ' << n << ' ' << c + dc + evenc << '\n';
	cout << r + dr + evenr + 1 << ' ' << c + dc + evenc + 1 << ' ' << n << ' ' << m << '\n';
	
	cout << "---------------------------\n\n";*/
	
	solveD(r, c, r + dr + evenr, c + dc + evenc, pos);
	
	solveD(r, c + dc + evenc + 1, r + dr + evenr, m, pos);
	solveD(r + dr + evenr + 1, c, n, c + dc + evenc, pos);
	solveD(r + dr + evenr + 1, c + dc + evenc + 1, n, m, pos);
	
}

void divideAndConquer(char type, int row, int col){
	if(type == 'B'){
		cnt = 0;
		
		solveB(1, 1, row, col);
	}else{
		int pos = 0;
		solveD(1, 1, row, col, pos);
	}
	
}

int main (){
	char cmd[N];
	
	while(scanf("\n%[^\n]s", cmd)){
		char type = cmd[0];
		int row = 0, col = 0;
		
		if(type == '#'){
			break;	
		}
		
		int i;
		
		for(i = 0 ; i < strlen(cmd) ; i++){
			if(cmd[i] >= '0' && cmd[i] <= '9'){
				while(cmd[i] >= '0' && cmd[i] <= '9'){
					row = row * 10 + cmd[i] - '0';
				
					i++;
				}
				
				break;
			}
		}
		
		for(; i < strlen(cmd) ; i++){
			if(cmd[i] >= '0' && cmd[i] <= '9'){
				while(cmd[i] >= '0' && cmd[i] <= '9'){
					col = col * 10 + cmd[i] - '0';
				
					i++;
				}
				
				break;
			}
		}
		
		if(type == 'B'){
			cmd[0] = 'D';
			
			for(int i = 1 ; i <= row ; i++){
				for(int j = 1 ; j <= col ; j++){
					scanf("\n%c", &bitmap[i][j]);
				}
			}
			
			printf("D%4d%4d\n", row, col);
			
			divideAndConquer(type, row, col);
			
			printf("\n");
		}else{
			cmd[0] = 'B';
			
			scanf("\n%s", command);
			
			printf("B%4d%4d\n", row, col);
			
			divideAndConquer(type, row, col);
			
			int cnt = 0;
			
			for(int i = 1 ; i <= row ; i++){
				for(int j = 1 ; j <= col ; j++){
					if(cnt == L){
						cnt = 0;
						printf("\n");
					}
					
					printf("%c", bitmap[i][j]);
					
					cnt++;
				}
			}
			
		}
	}
	printf("\n");
	return 0;
}
