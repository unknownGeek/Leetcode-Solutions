/*
765. Couples Holding Hands ::
For Solution-Eplanation :: https://leetcode.com/articles/couples-holding-hands/
N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

Example 1:

Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
Note:

len(row) is even and in the range of [4, 60].
row is guaranteed to be a permutation of 0...len(row)-1.
*/
/*
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ans = 0;
        for(int i=0; i<n; i+=2){
            int firstMember = row[i];
            int secondMember = firstMember^1;//Or We Can Use The Following
            //int secondMember = firstMember&1 ? firstMember-1 : firstMember+1;
            if(row[i+1] == secondMember){
                continue;
            }
            
            for(int j=i+2; j<n; ++j){
                if(row[j] == secondMember){
                    swap(row[i+1], row[j]);
                    ++ans;
                    break;
                }
            }
            
        }
       return ans; 
    }
};
*/


/*
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int pos[n];
        for (int i=0; i<n; ++i)
            pos[row[i]] = i;
        int ans = 0;
        for (int i=0; i<n; i+=2){
            int& p = pos[row[i]^1];
            if (p == i+1){
                continue;
            }else {
                int& s = pos[row[i+1]];
                s = p;
                p = i+1;
                swap(row[p], row[s]);
                ++ans;
            }
        }
        return ans;
    }
};*/

/*
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> pos;
        int n = row.size();
        for(int i = 0; i < n; ++i){
            pos[row[i]] = i;
        }
        bool visited[n];
        memset(visited, false, sizeof visited);
        int ans = 0;
        for(int i = 0; i < n; i += 2){
                if (visited[i]){
                    continue;
                }
                int curr = i;
                int len = 0;
                while(!visited[curr]){
                    visited[curr] = true;
                    int next = row[curr] & 1 ? row[curr] - 1 : row[curr] + 1;
                    next = pos[next];
                    visited[next] = true;
                    curr = next & 1 ? next - 1 : next + 1;
                    ++len;
                }
                ans += len - 1;
        }
        return ans;
    }
};*/



/*
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt=0;
        int n = row.size();
        vector<int> pos(n, -1);
        for (int i=0; i<n; ++i){
            pos[row[i]]=i;
        }
        for (int i=1; i<n; i+=2){
            if ( (row[i-1]^row[i]) !=1) {
                row[pos[row[i-1]^1]] = row[i];
                pos[row[i]] = pos[row[i-1]^1];
                row[i] = row[i-1]^1;
                pos[row[i]]=i;
                ++cnt;
            }
        }
        return cnt;
    }
};*/


/*
class Solution {
public:
    map<int,int> mp;
    set<pair<int,int> > s;
    struct UF{
	vector<int> belong;
	vector<int> size;
	void resize(int n){
		belong.assign(n + 1, -1);
		size.assign(n + 1, 1);
	}
	inline int root(int b){
		if (belong[b] == -1){
			return b;
		}
		belong[b] = root(belong[b]);
		return belong[b];
	}
	void merge(int a, int b){
		a = root(a);
		b = root(b);
		if (a == b)return;
		belong[a] = b;
		size[b] += size[a];
	}
};
    UF uf;
    int minSwapsCouples(vector<int>& row) {
        uf.resize(row.size()+1);
        int ans=0;
        for(int i=0;i<row.size();i+=2){
            row[i]/=2;
            row[i+1]/=2;
            if(row[i]==row[i+1])continue;
            if(s.count(make_pair(row[i],row[i+1]))){
                ans++;
                s.erase(make_pair(row[i],row[i+1]));
                continue;
            }
            if(s.count(make_pair(row[i+1],row[i]))){
                ans++;
                s.erase(make_pair(row[i+1],row[i]));
                continue;
            }
            s.insert(make_pair(row[i],row[i+1]));
        }
        for(auto it=s.begin();it!=s.end();it++){
            uf.merge((*it).first,(*it).second);
        }
        for(int i=0;i<row.size();i++){
            if(i==uf.root(i)){
                ans+=uf.size[uf.root(i)]-1;
            }
        }
        return ans;
    }
};*/

class Solution {
private:
        int p[1010];
        int findRoot(int x) { 
            return x == p[x] ? x : p[x] = findRoot(p[x]); 
        }
public:
  int minSwapsCouples(vector<int> &row) {
    int N = row.size();
    const int n = N>>1;
    for (int &num : row){
            num >>= 1;
    }
    for(int i=0; i<n; ++i){ 
        p[i] = i;
    }
    for (int i = 0; i < N; i += 2) {
      int x = findRoot(row[i]);
      int y = findRoot(row[i + 1]);
      p[x] = p[y];
    }
    int ans = n;
    for(int i=0; i<n; ++i){ 
        ans -= (i == findRoot(i));
    }
    return ans;
  }
};


/*
class Solution {
	    public int minSwapsCouples(int[] f) {
	        int n = f.length;
	        DJSet ds = new DJSet(n/2);
	        for(int i = 0;i < n/2;i++){
	        	ds.union(f[i*2]/2, f[i*2+1]/2);
	        }
	        return n/2 - ds.count();
	    }
	    
	    class DJSet { 
            public int[] upper; 
            public DJSet(int n){ 
                upper = new int[n]; 
                Arrays.fill(upper, -1);
            } 
            public int root(int x){	
                return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
            }	
            public boolean equiv(int x, int y){ 
                return root(x) == root(y);
            } 
            public boolean union(int x, int y){ 
                x = root(x);
                y = root(y);
                if(x != y) { 
                    if(upper[y] < upper[x]){ 
                        int d = x; 
                        x = y; 
                        y = d;	
                    } 
                    upper[x] += upper[y]; 
                    upper[y] = x;
                } 
                return x == y;
            } 
            public int count(){ 
                int ct = 0; 
                for(int u : upper)
                    if(u < 0)
                        ct++; 
                return ct; 
            }
        }
	}	
*/
class Solution {
    public int minSwapsCouples(int[] row) {
        int index = 0;
        int ans = 0;
        while (index < row.length) {
            int partnerIndex = find(row, getPartner(row[index]));
            if (partnerIndex != index+1) {
                swap(row, index+1, partnerIndex);
                ans++;
            }
            index += 2;
        }
        return ans;
    }
    
    private static int getPartner(int x) {
        if (x % 2 == 0) return x + 1;
        else return x - 1;
    }
    
    private static int find(int[] row, int x) {
        for (int i = 0; i < row.length; i++) if (row[i] == x) return i;
        return -1;
    }
    
    private static void swap(int[] row, int i1, int i2) {
        int tmp = row[i1];
        row[i1] = row[i2];
        row[i2] = tmp;
    }
}