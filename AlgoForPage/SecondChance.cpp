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


void printmemory(int index, int *array, int n, bool changed ){
    for(int i=0 ; i < n ; i++){
        if(i==index and changed ) cout<<"|*"<<array[i]<<"*|";
        else cout<<"|"<<array[i]<<"|";
    }
    if(changed) cout<<" ===> CHANGED";
    cout<<endl<<endl;
}

void fill(int *array,int n){
    for(int i=0 ; i < n ; i++)
        array[i] = -1;
}

bool exist(int x, int *array, int n){
    for(int i=0 ; i < n ; i++)
        if(array[i]==x) return true;
    return false;
}

void eraseelementandaddattheback(int x, vector<pair<int,int> > &v){
    for(int i=0 ; i < v.size() ; i++){
        if( v[i].F == x ){
            v.erase( v.begin() + i );
            break;
        }
    }
    v.pb(mp(x,1));
}

signed main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int memorysize; cin>>memorysize;
    int arr[memorysize];    
    int n,x;cin>>n;
    fill(arr,memorysize);
    int index = 0;
    vector<pair<int,int> >  v;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        if(exist(x,arr,memorysize)){
            printmemory(v[x].F,arr,memorysize,false);
            eraseelementandaddattheback(x,v);
            continue;
        }
        if(index >= memorysize){
            int a = 0;
            int need = 0;
            for(int i=0 ; i < v.size()  ; i++){
                i %= v.size();
                if(v[i].S==0){
                    need = i;
                    break;
                }
                v[i].S--;
            }
            for(int i = 0 ; i < memorysize ; i++){
                if(v[need].F==arr[i]){
                    a = i;
                }
            }
            arr[a] = x;
            printmemory(a,arr,memorysize,true);
            v.pb(mp(x,1));
            v.erase(v.begin() + need );
        }else{ 
            arr[index] = x;     
            printmemory(index,arr,memorysize,true);
            index++;
            v.pb(mp(x,1));
        }
    }


    return 0;
}    
