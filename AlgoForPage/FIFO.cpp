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

signed main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int memorysize; cin>>memorysize;
    int array[memorysize];    
    int n,x;cin>>n;
    int index = 0;
    fill(array,memorysize);
    for(int i=0 ; i < n ; i++){
        cin>>x;
        if(exist(x,array,memorysize)){
            printmemory(index,array,memorysize,false);
            continue;
        }
        array[index] = x;
        printmemory(index,array,memorysize,true);
        index++;
        index %= memorysize;
    }


    return 0;
}    
