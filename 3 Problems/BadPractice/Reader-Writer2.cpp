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

int wait(int s){
	while(s<=0);
	return --s;
}

int signal(int s){
	return ++s;
}

void readerin(int &mutex, int &wrt, int &readcount){
	if(wrt==1 or readcount > 0 ){
		mutex = wait(mutex);
		readcount++;
		if(readcount==1) wrt = wait(wrt);
		mutex = signal(mutex);
		cout<<"Reader number "<< readcount<< " entered"<<endl;
	}else{
		cout<<"There is some Writer, try later"<<endl;
	}
}

void readerdec(int &mutex, int &wrt, int &readcount){
	if( readcount>0 ){
		mutex = wait(mutex);
		readcount--;
		if(readcount==0) wrt = signal(wrt);
		mutex = signal(mutex);
		cout<<"Reader number "<< readcount<< " leave"<<endl;
	}else{
		cout<<"There is some Writer or no reader, try later"<<endl;
	}
}

void writerin( int &wrt){
	if(wrt==1){
		wrt = wait(wrt);
		cout<<"Writer entered"<<endl;
	}else{
		cout<<"There is reader or writer, try later"<<endl;
	}
}

void writerdec(int &wrt, int &readcount){
	if(readcount==0 and wrt == 0){
		wrt = signal(wrt);
		cout<<"Writer exited"<<endl;
	}else{
		cout<<"There is some reader or no writer, try later"<<endl;
	}
}



signed main(){
	freopen("inRW.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int mutex=1, wrt=1, readcount=0;
	int choose = 0;
    while(true){
    	cin>>choose;
    	switch(choose){
    		// 1 - ReaderInc
    		// 2 - ReaderDec
    		// 3 - WriterInc
    		// 4 - WriterDec
    		// any - Exit
    		case 1: 
    			readerin(mutex, wrt, readcount);
    			break;
			case 2:
				readerdec(mutex, wrt, readcount);
				break;
			case 3:
				writerin(wrt);
				break;
			case 4: 
				writerdec(wrt, readcount);
				break;
			default:
				exit(0);	
    	}
    }

    return 0;
}    
