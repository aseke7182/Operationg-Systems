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

void readf(int &mutex, int &wrt, int &readcount){
	mutex = wait(mutex);
	readcount++;
	if(readcount==1) wrt = wait(wrt);
	mutex = signal(mutex);

	// READING

	mutex = wait(mutex);
	readcount--;
	if(readcount==0) wrt = signal(wrt);
	mutex = signal(mutex);
}

void writef(int &wrt){
	wrt = wait(wrt);

	// WRITING

	wrt = signal(wrt);
}



signed main(){
	freopen("inRW.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int mutex=1, wrt=1, readcount=0;
	int choose = 0;
    while(true){
    	cin>>choose;
    	switch(choose){
    		// 1 - Read
    		// 2 - Write
    		// any - Exit
    		case 1: 
    			readf(mutex, wrt, readcount);
    			break;
			case 2:
				writef(wrt);
				break;
			default:
				exit(0);	
    	}
    }

    return 0;
}    
