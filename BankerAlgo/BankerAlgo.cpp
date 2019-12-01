#include<bits/stdc++.h>

// #define int long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define _ <<" "
#define __ <<endl
#define speedup ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
bool ok=true;
stringstream ss;
const int N = (int)1e9+7;

int n,m;
vector<bool> finish;
vector<int> work;
int need[1000][1000];
int available[1000];
int maximum[1000][1000];
int allocation[1000][1000];
vector<int> ans;
vector<int> req;

string request(int proccess ){
	for(int i=0 ; i < m ; i++){
		if( req[i] > need[proccess][i] ){
			return "Exceeded maximum claim\n";
		}	
	}	
	for(int i=0 ; i < m ; i++){
		if( req[i] > available[i] ){
			return "Wait, resources are not available\n";
		}
	}
	for(int i=0 ; i < m ; i++){
		available[i] -= req[i];
		allocation[proccess][i] += req[i];
		need[proccess][i] -= req[i];
	}
	return "Well done, working...\n";
}


signed main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n>>m;
    bool going = true;
    bool safeSequence = true;
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		cin>>allocation[i][j];

    for(int i=0 ; i < n ; i++)
    	for(int j=0 ; j < m ; j++)
    		cin>>maximum[i][j];

	for(int i=0 ; i < m ; i++)
		cin>>available[i];

    for(int i=0 ; i < n ; i++)
    	for(int j=0 ; j < m ; j++)
    		need[i][j] = maximum[i][j] - allocation[i][j];

    for(int i=0 ; i < n ; i++)
    	finish.pb(false);


    // Resourse-Request Algorithm
    // ========================== 
    req.pb(0);
    req.pb(2);
    req.pb(0);
    int proc = 0;
    string s = request(proc);
    if( s == "exceeded maximum claim" ){
    	cout<<s;
    	exit(0);
    } else cout<<s;
    // ========================== 


    while(going){
    	going = false;
	    for(int i=0 ; i < n ; i++){
	    	if(!finish[i]){
	    		ok = true;
	    		for(int j=0 ; j < m ; j++){
	    			if( need[i][j] > available[j] ){
	    				ok = false;
	    				break;
	    			}
	    		}
	    		if(ok){
	    			for(int j=0; j < m ; j++){
	    				available[j] += allocation[i][j];
	    			}
	    			finish[i] = true;
	    			ans.pb(i);
	    			going = true;
	    		}
	    	}
	    }
	}
	for(int i=0 ; i < n ; i++){
		if(!finish[i]){
		 	safeSequence = false;
		 	break;
		}
	}
	if(safeSequence){
		for(int i=0 ; i < ans.size() ; i++){
			cout<<"P"<<ans[i];
			if(i!=ans.size()-1) cout<<" -> ";
		}
	}else{
		cout<<"There is no safe Sequence";
	}
    return 0;
}    
