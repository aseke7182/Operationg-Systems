#include<bits/stdc++.h>

#define int long long
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
map<int,int> m;
map<int,int>::iterator it;
vector<pair<int,int> > v;
int memorysize;


int findx(int x){
    for(int i=0; i<v.size() ; i++)
        if(v[i].F==x) return i;
}

void printmemory( int x, bool changed ){
    int index = findx(x);
    for(int i=0 ; i < v.size(); i++){
        if(i==index and changed ) cout<<"|*"<<v[i].F<<"*|";
        else cout<<"|"<<v[i].F<<"|";
    }
    for(int i=v.size() ; i< memorysize ; i++){
        if(i==index and changed ) cout<<"|*"<<-1<<"*|";
        else cout<<"|"<<-1<<"|";
    }
    if(changed) cout<<" ===> CHANGED";
    cout<<endl<<endl;
}

bool exist(int x,int time){
    for(int i=0 ; i < v.size() ; i++)
        if(v[i].F==x){
            v[i].S=time;
            return true;
        }
    return false;
}

int maximuminvector(){
    int ans = 0;
    int mx = -1;
    int time = 1e9+5;
    for(int i=0 ; i < v.size() ; i++){
        if( m[ v[i].F ] > mx ){
            mx = m[ v[i].F ];
            ans = i;
            time = v[i].S;
        }
        if( m[v[i].F] == mx and v[i].S < time ){
            ans = i;
            time = v[i].S;
        }
    }
    return ans;
}



signed main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>memorysize;
    int n,x; cin>>n;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        m[x]++;
        if(exist(x,i)){
            v[findx(x)].S = i; 
            printmemory(x,false);
            continue;
        }
        if(v.size() >= memorysize){
            int index = maximuminvector();
            v[index].F = x;
            v[index].S = i;
            printmemory(x,true);
        }
        else{
            v.pb(mp(x,i));
            printmemory(x,true);
        }
    }


    return 0;
}    
