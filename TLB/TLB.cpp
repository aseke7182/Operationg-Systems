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

map<string,int> m;


int vm[256] = {0};

int tlb[16] = {0};
int tlbframes[16] = {0};


bool contains(int temp){
    for(int i = 0; i < 16; i++){
        if(temp == tlb[i]) return true;
    }
    return false;
}


int findFrame(int temp){
    for(int i = 0; i < 16; i++){
        if(temp == tlb[i]) return tlbframes[i];
    }
    return -1;
}


void insertTLB(int page, int frame){
    for(int i = 0; i < 256; i++){
        if(tlb[i] == 0){
            tlb[i] == page;
            tlbframes[i] = frame;
            return; 
        }
    }

    tlb[0] = page;
    tlbframes[0] = frame;
}



signed main(){
    int temp;
    int page;
    int tlb_hits = 0;
    int vm_hits = 0;
    int tlb_misses = 0;
    int page_number[10] = {45, 12, 99, 33, 12, 45, 12, 9, 1, 1};
    int page_offset[10] = {2, 5, 6, 0, 12, 3, 55, 12, 44, 12};
    vm[45] = 132;
    vm[12] = 66;
    vm[9] = 12;
    vm[1] = 56;
    vm[99] = 33;

    cout<<"PAGE NUMBER     "<<"Physical address with offset"<<endl;
    for(int i = 0; i < 10; i++){
        if(contains(page_number[i])){
            int frame = findFrame(page_number[i]);
            cout<<page_number[i]<<"                   "<<frame<<" "<<page_offset[i]<<endl;
            tlb_hits++;
        }
        else if(vm[page_number[i]] != 0){
            int frame = vm[page_number[i]];
            int physicalAddress = frame + page_offset[i];
            cout<<page_number[i]<<"                    "<<frame<<" "<<page_offset[i]<<endl;
            insertTLB(page_number[i], frame);
            vm_hits++;
            tlb_misses++;
        }
        else{
            cout<<"Page Fault"<<endl;
        }
    }


}