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
    for(int i=0 ; i < n ; i++){
        cin>>x;
        here[x] = true;
    }
    int now;
    cin>>now;
    int movement = 0;
    int before = now;
    int i = now+1;
    while(true){
        i++;
        if(i==now){
            cout<<"Total movement: "<< movement<<endl;
            break;
        }
        if(here[i] ){
            here[i] = false;
            movement += abs(before - i);
            cout<<before<<"-->"<<i<<". movement: "<< abs(before-i)<<endl;
            before = i;
        }
        if(i==200){
            i = 0;
        }
    }

    return 0;
}    
