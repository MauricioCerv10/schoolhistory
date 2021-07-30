#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//In worst case the trie will have number of nodes equal to the sum of lengths of the strings from the input,
//let's call that s. In worst case, each node will have number of edges equal to the size of the alphabet, let's call that a. 
//So, it should be s × a.

#define MN 100010 // number of nodes
struct node{
	int isWord;
	map<char,int> link;
};
struct trie{
	node tree[MN];
	int nodes;
	void init(){
		nodes = 0;
		tree[nodes].isWord = 0;
	}
	void add(const string s){
		int cur = 0;
		for(auto &c : s){
			if(tree[cur].link.find(c) == tree[cur].link.end()){
				tree[cur].link[c] = ++nodes;
				tree[nodes].isWord = 0;
			}
			cur = tree[cur].link[c];
		}
		tree[cur].isWord++;
	}
	int find(const string s){
                int cur = 0;
                for(auto &c : s){
                        if(tree[cur].link[c] == -1)return 0;
                        cur = tree[cur].link[c];
                }
		return tree[cur].isWord;
        }
};
int main(){
	//ios_base::sync_with_stdio(0); cin.tie(0);
	trie t1; t1.init();
	while(1){
                int opc; string s;
                 cin >> opc;
                if(opc){
                        cin >> s;
                        t1.add(s);
                }else{
                        cin >> s;
                        cout << ((t1.find(s)) ? "YES\n" : "NO\n");
                }
        }
}
