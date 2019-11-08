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

vector<int> block;

int ff(int proccess_memory){
    for(int i = 0 ; i < block.size() ; i++){
        if( block[i] >= proccess_memory ){
            block[i]-= proccess_memory;
            return i;
        }
    }
    return -2;
}

int bf(int proccess_memory){
    int index = -2;
    int minmemory = N;
    for(int i=0 ; i < block.size() ; i++){
        if(block[i] >= proccess_memory and block[i] < minmemory){
            index = i;
            minmemory = block[i];
        }
    }
    if(index!=-2) block[index] -= proccess_memory;
    return index;
}

int wf(int proccess_memory){
    int index = -2;
    int maxmemory = 0;
    for(int i=0 ; i < block.size() ; i++){
        if(block[i] > proccess_memory and block[i] > maxmemory){
            index = i;
            maxmemory = block[i];
        }
    }
    if(index!=-2) block[index] -= proccess_memory;
    return index;
}

string convert(int a){
    string comeback = "";
    ss<<a;
    ss>>comeback;
    ss.clear();
    comeback = "     " + comeback;
    if( a >= 0 ) comeback = " " + comeback ;
    for(int i=0 ; i < 23 - (int)comeback.size() ; i++){
        comeback += " ";
    }
    return comeback;
}

void initprint(){
    cout<<"    Process#   |  Process Size  |    Block#      "<<endl;
    cout<<"---------------+----------------+----------------"<<endl;
}

void print_(int a, int b, int c){
    string i = convert(a);
    string proccess = convert(b);
    string numb = convert(c+1);
    cout<<i<<"|"<<proccess<<"|"<<numb<<endl; 
}

signed main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,m,x; cin>>n>>m;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        block.pb(x);
    }
    initprint();
    for(int i=0 ; i < m ; i++){
        cin>>x;
        // int blocknum = ff(x);
        // int blocknum = bf(x);
        int blocknum = wf(x);
        print_(i+1,x,blocknum);
    }
    return 0;
}    
