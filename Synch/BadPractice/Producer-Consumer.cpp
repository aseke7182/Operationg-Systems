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

int item = 1;

int wait(int s){
	while(s<=0);
	return --s;
}

int signal(int s){
	return ++s;
}


void produce(int &mutex, int &full, int &empty){
	if( mutex == 1 and empty!=0 ){
		mutex = wait(mutex);
		full = signal(full);

		empty = wait(empty);
		mutex = signal(mutex);
		cout<<"Item "<< item << " produced"<<endl;
		item++;
	}else{
		cout<<"Buffer is full, try first consume some"<<endl;
	}
}

void consume(int &mutex, int &full, int &empty){
	if( mutex == 1 and full!=0 ){
		mutex = wait(mutex);

		full = wait(full);
		empty = signal(full);

		mutex = signal(mutex);
		item--;
		cout<<"Item "<< item << " consumed"<<endl;
	}else{
		cout<<"Buffer is empty, try first produce some"<<endl;
	}
}

signed main(){
	freopen("inPC.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int mutex=1, full=0, empty, buffersize;
	cin>>buffersize;
	empty = buffersize;
	int choose = 0;
    while(true){
    	cin>>choose;
    	switch(choose){
    		// 1 - Produce
    		// 2 - Consume
    		// 3 - Exit
    		case 1: 
    			produce(mutex,full,empty);
    			break;
			case 2:
				consume(mutex,full,empty);
				break;
			default:
				exit(0);	
    	}
    }

    return 0;
}    
