#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const int N = 7, M = 11, MOVES = 4; 
const int MOVES_O = 8;
string kitchen[N];
int mark[N + 10][M + 20];
int distance[N][N];
int nround = 1;
int vi[MOVES] = {0, 0, -1, 1};
int vj[MOVES] = {1, -1, 0, 0};
int vii[MOVES_O] = {1, 0, -1, 0, 1, -1, -1, 1};
int vjj[MOVES_O] = {1, 1, 1 , -1,-1, -1, 0, 0};
const int STATES = 4;

bool ok(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;    
}

void dfs(int i, int j){
    mark[i][j] = nround;
    
    for(int k = 0 ; k < MOVES ; k++){
        int x = vi[k] + i, y = vj[k] + j;
        
        if(ok(x, y)){
            if(mark[x][y] != nround){
                dfs(x, y);   
            }
        }
    }
    
    for(int k = 0 ; k < MOVES_O ; k++){
        int x = vii[k] + i, y = vjj[k] + j;
        
        if(ok(x, y)){
            mark[x][y] = nround;
        }
    }
}

bool is_adj(int i, int j, int x, int y){
    for(int k = 0 ; k < MOVES_O ; k++){
        int xx = vii[k] + i, yy = vjj[k] + j;
        
        if(x == xx && y == yy){
            //cout << "MOVE " << x << " " << y << " ;" << "pq eh adjacente!!!" << endl;
            return true;   
        }
    }
    
    return false;
}

int main()
{
    int numAllCustomers;
    cin >> numAllCustomers; //cin.ignore();
    for (int i = 0; i < numAllCustomers; i++) {
        string customerItem; // the food the customer is waiting for
        int customerAward; // the number of points awarded for delivering the food
        cin >> customerItem >> customerAward;
    }
    for (int i = 0; i < N; i++) {
        string kitchenLine;
        cin >> kitchenLine;
        //cout << "MOVE 0 0 ;" << kitchenLine.length() << endl; 
        assert(kitchenLine.length() == M);
        kitchen[i] = kitchenLine;
        
        //cin.ignore();
       // cout << "MOVE 0 0; " << kitchenLine << " " << kitchen[i] << endl;
    }
    
    // cout << "MOVE 0 0; ";
    cout << endl;
    
    int pass = 0;
    
    // game loop
    bool ice_cream = false, blue_berries = false;
    bool carry = false;
    int carryx = 0, carryy = 0;
    int p = 0;
    
    while (1) {
        int turnsRemaining;
        cin >> turnsRemaining;
        int playerX;
        int playerY;
        string playerItem;
        cin >> playerX >> playerY >> playerItem;
        //cout << "WAIT ;" << "estou no " << playerX << " " << playerY << endl;
        int partnerX;
        int partnerY;
        string partnerItem;
        cin >> partnerX >> partnerY >> partnerItem; 
        int numTablesWithItems; // the number of tables in the kitchen that currently hold an item
        cin >> numTablesWithItems; //cin.ignore();
        int tableX, tableY;
        
        for (int i = 0; i < numTablesWithItems; i++) {
            int tableX;
            int tableY;
            string item;
            cin >> tableX >> tableY >> item; 
        }
        
        string ovenContents; // ignore until wood 1 league
        int ovenTimer;
        cin >> ovenContents >> ovenTimer;
        int numCustomers; // the number of customers currently waiting for food
        cin >> numCustomers; //cin.ignore();
        for (int i = 0; i < numCustomers; i++) {
            string customerItem;
            int customerAward;
            cin >> customerItem >> customerAward;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // MOVE x y
        // USE x y
        // WAIT

        
        bool found = false;
        int x = 0, y = 0;
        
        dfs(playerY, playerX);
        
        for(int i = 0 ; i < N && !found ; i++){
            for(int j = 0 ; j < M && !found ; j++){
                if(p == 0){
                    if(kitchen[i][j] == 'D' && mark[i][j] == nround){
                        x = i, y = j;
                        found = true;
                    }
                }else if(p == 1 || p == 2){
                    if(kitchen[i][j] == 'B' && mark[i][j] == nround && !blue_berries){
                        x = i, y = j;
                        found = true;
                        // blue_berries = true;
                    }
                    
                    if(kitchen[i][j] == 'I' && mark[i][j] == nround && !ice_cream){
                        x = i, y = j;
                        found = true;
                        // ice_cream = true;
                    }
                }else{
                    if(kitchen[i][j] == 'W' && mark[i][j] == nround){
                        x = i, y = j;
                        found = true;
                    }
                }
            }
        }
        
        // cout << "MOVE 2 1" << endl;
        // continue;
        if(found){
            if(is_adj(playerY, playerX, x, y)){
                if(kitchen[x][y] == 'I'){
                    ice_cream = true;   
                }else if(kitchen[x][y] == 'B'){
                    blue_berries = true;    
                }
                
                cout << "USE " << y << " " << x << endl;
                p = (p + 1) % STATES;
                
                if(p == 0)
                    ice_cream = blue_berries = false;
            }else{
                cout << "MOVE " << y << " " << x << " ;" << playerY << " " << playerX << " " << x << " " << y << endl;
                //carry = true;
                // carryx = x, carryy = y;
            }
        }else{
            cout << "WAIT; " << playerX << " " << playerY << " " << blue_berries << " " << ice_cream << endl;
        }
        
        nround++;
    }
}