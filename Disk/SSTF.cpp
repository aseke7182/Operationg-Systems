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

bool used[200];

int go(int n, vector<int> v ){
    int ans = 0;
    int mn = N;
    for(int i=0 ; i < v.size() ; i++ ){
        if( !used[v[i]]) continue;
        if( abs(n-v[i]) < mn ){
            mn = abs(n-v[i]);
            ans = v[i];
        }
    }
    return ans;
}


signed main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        used[x] = true;
        v.pb(x);
    }
    int now;
    cin>>now;
    int movement = 0;
    int a  = 0;
    for(int i=0 ; i < n ; i++){

        a = go(now,v);
        used[a] = false;
        movement += abs(now-a);
        cout<<now<<"-->"<<a<<". movement:"<< abs(now-a)<<endl;
        now = a;
    }
    cout<<"Total movement: "<<movement;



    return 0;
}    
