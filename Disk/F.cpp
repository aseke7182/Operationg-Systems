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

int convert(string s){
    ss<<s;
    int a;
    ss>>a;
    ss.clear();
    return a;
}


signed main(){
    string s;
    while(cin>>s){
            
        if(s=="0") break;
        s = "0" + s;
        int ans[(int)s.size()];
        for(int i=0 ; i < s.size() ; i++) ans[i] = 0;
        ans[0] = 1;
        for(int i=1 ; i < s.size() ; i++){
            if(s[i]=='0') continue;
            int a = convert(string()+s[i-1]+s[i]);
            ans[i] += ans[i-1];
            if( a<=26 and a>=10  and i>1 ){
                ans[i] += ans[i-2];
            }
        }

        cout<<ans[s.size()-1]<<endl;

    }

    return 0;
}    
