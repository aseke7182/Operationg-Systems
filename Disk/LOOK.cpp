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

signed main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,x;
    cin>>n;
    bool here[201];
    memset(here,false,201);
    int mn = N;
    int mx = 0;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        mn = min(mn,x);
        mx = max(mx,x);
        here[x] = true;
    }
    int now;
    cin>>now;
    int movement = 0;
    int c = -1;
    int before = now;
    int i = now;
    while(true){
        i+=c;
        if(i==mn) c = 1;
        if(i==mx+1){
            cout<<"Total movement: "<< movement<<endl;
            c = -1;
            break;
        }
        if(here[i]){
            here[i] = false;
            movement += abs(before - i);
            cout<<before<<"-->"<<i<<". movement: "<< abs(before-i)<<endl;
            before = i;
        }
    }

    return 0;
}    
