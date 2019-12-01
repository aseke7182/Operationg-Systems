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

vector<pair<int,int> > v;
vector<pair<int,int> > q; // our queue

bool exist(int x){
    // check for coming segment if it in our memory 
    for(int i=0 ; i < q.size() ; i++ ){
        if(q[i].F==x) return true;
    }
    return false;
}

int findMinimalSuchThatTotalMemoryDoesNotExsist( int sizeOfSegment, int memory, int totalMemory ){
    // find in our queue such that it could allocate
    for(int i=0 ; i < q.size() ; i++){
        if( sizeOfSegment- q[i].S  + memory <= totalMemory ) return i;
    }
    return -1;
}

signed main(){
    speedup;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout); // read and write from and in some txt

    int size;  // total size
    cin>>size;

    int n;
    cin>>n; // number of entered segments
    int a,b; // number of segment and it's size
    for(int i=0 ; i < n ; i++){
        cin>>a>>b;
        v.pb(mp(a,b));
    }
    int nowmemory = 0;
    for(int i=0 ; i < v.size() ; i++){
        if(!exist(v[i].F)){
            // it does not exist 
            int index = findMinimalSuchThatTotalMemoryDoesNotExsist( v[i].S,nowmemory,size); // index of possible segment that we could swap using FIFO
            if( index == -1){ // if it is not possible to allocate it now
                cout<<"it is now possible yet"<<endl;
                continue;
            }
            nowmemory -= q[index].S;
            nowmemory += v[i].S;
            q.erase(q.begin() + index); // erase from memory
            q.pb(v[i]); // add to memory
            cout<<"from " << q[index].F << " " << q[index].S << " changed to " << v[i].F << " " << v[i].S << endl;
        }else{
            cout<<"already in memory"<<endl; // already in memory
        }
    }

    // We used FIFO algorithm
    // If coming segment already in our memory, we do anything
    // If it is not in memory, we check using FIFO, if we could swap segments, such current allocated memory doesn't excceed possible size
    // If it is some, we swap them
    // If it is unreal, we do anything and continue work
    // and always making something like compaction, to obtain maximal possible free space

    return 0;
}    
