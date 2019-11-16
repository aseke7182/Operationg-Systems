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
    int cnt = 0;
    for(int i=0 ; i < n ; i++){
        if(changed) cnt++;
        if(i==index and changed ) cout<<"|*"<<array[i]<<"*|";
        else cout<<"|"<<array[i]<<"|";
    }
    if(changed) cout<<" ===> CHANGED";
    cout<<endl<<endl;
    cout<<cnt;
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

void eraseelementandaddattheback(int x, vector<int> &v){
    for(int i=0 ; i < v.size() ; i++){
        if(v[i]==x){
            v.erase(v.begin()+i);
            break;
        }
    }
    v.pb(x);
}

signed main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int memorysize; cin>>memorysize;
    int arr[memorysize];    
    int n,x;cin>>n;
    fill(arr,memorysize);
    int index = 0;
    vector<int>  v;
    for(int i=0 ; i < n ; i++){
        cin>>x;
        if(exist(x,arr,memorysize)){
            printmemory(v[x],arr,memorysize,false);
            eraseelementandaddattheback(x,v);
            continue;
        }
        if(index >= memorysize){
            int a = 0;
            for(int i = 0 ; i < memorysize; i++)
                if(v[0]==arr[i]) a = i;
            arr[a] = x;
            printmemory(a,arr,memorysize,true);
            v.pb(x);
            v.erase(v.begin());
        }else{ 
            arr[index] = x;     
            printmemory(index,arr,memorysize,true);
            index++;
            v.pb(x);
        }
    }


    return 0;
}    
