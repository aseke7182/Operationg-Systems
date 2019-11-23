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
    queue<int> q;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        q.push(x);
    }
    int now;
    cin>>now;
    int movement = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        movement += abs(now-a);
        cout<<now << "-->" << a << ". Movement:" << abs(now-a)<<endl;
        now = a;
    }
    cout<<"Total movement: " << movement;

    return 0;
}    
