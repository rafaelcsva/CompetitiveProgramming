    //22, 05, 2018, 19:25:59 Rafaelcs cpp
    #include <bits/stdc++.h>
     
    #define getcx getchar_unlocked
    #define pc(x) putchar_unlocked(x)
     
    using namespace std;
     
    typedef pair<int, int> pii;
    typedef long double ld;
    typedef long long ll;
     
    const int N = int(3e4 + 100);
    int v[N];
    vector <int> merge_tree[N << 2];
     
    inline int readInt()
    {
        bool minus = false;
        register int result = 0;
        register char ch = getchar_unlocked();
        while (true)
        {
            if (ch == '-') break;
            if (ch >= '0' && ch <= '9') break ;
            ch = getchar_unlocked();
        }
        if (ch == '-') minus = true; 
        else result = ch-'0';
        while (true)
        {
            ch = getchar_unlocked();
            if (ch < '0' || ch > '9') break;
            result = result*10 + (ch - '0');
        }
        if (minus) return -result;
        else return result;
    }
     
    inline void writeInt ( int n )
    {
        register int N = n, rev, count = 0 ;
        rev = N ;
        if (N == 0) 
        { 
            pc('0');  return ;
        }
        while ((rev % 10) == 0) 
        { 
            count++; rev /= 10;
        } //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) 
        { 
            rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;
        }  //store reverse of N in rev
        while (rev != 0) 
        { 
            pc(rev % 10 + '0'); rev /= 10 ;
        }
        while (count--) pc('0') ;
    }
     
    inline void write_string(char *str)
    {
        register char c = 0;
        register int i = 0;
        while (c < 33)
            c = getchar_unlocked() ;
        while (c != '\n') 
        {
            str[i] = c;
            c = getchar_unlocked() ;
            i = i + 1;
        }
        str[i] = '\0';
    }
     
    void build(int node, int i, int j){
        if(i == j){
            merge_tree[node].push_back(v[i]);
        }else{
            int left = node << 1;
            int right = left + 1;
            int mid = (i + j) / 2;
     
            for(int k = i ; k <= j ; k++){
                merge_tree[node].push_back(v[k]);
            }
     
            sort(merge_tree[node].begin(), merge_tree[node].end());
     
            build(left, i, mid);
            build(right, mid + 1, j);
        }
    }
     
    int query(int node, int i, int j, int l, int r, int k){
        if(i > r || j < l){
            return 0;
        }
     
        if(i >= l && j <= r){
            return merge_tree[node].end() - upper_bound(merge_tree[node].begin(), merge_tree[node].end(), k);
        }else{
            int left = node << 1;
            int right = left + 1;
            int mid = (i + j) / 2;
     
            return query(left, i, mid, l, r, k) + query(right, mid + 1, j, l, r, k);
        }
    }
     
    int main(){
        int n;
        
        n = readInt();
     
        for(int i = 1 ; i <= n ; i++){
            cin >> v[i];
        }
        
        build(1, 1, n);
        
        int m;
        
        m = readInt();
        int ans = 0;
        
        while(m--){
            int i, j, k;
     
            i = readInt(), j = readInt(), k = readInt();
     
            i ^= ans;
            j ^= ans;
            k ^= ans;

            ans = query(1, 1, n, i, j, k);

            writeInt(ans);
            printf("\n");
        }
     
        return 0;
    } 