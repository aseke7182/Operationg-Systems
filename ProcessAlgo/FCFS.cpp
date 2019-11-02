#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define pb push_back  
#define mp make_pair
using namespace std;

bool tmp ( const pair< pair<int,int> ,pair< int, int> >   v1 , const pair<pair<int,int> , pair<int, int> >  v2 ){
	return v1.second.first < v2.second.first;
}

int main(){
	freopen("in.txt", "r" , stdin);
	freopen("out.txt", "w", stdout);
	int n,a,b,c;
	vector< pair < pair<int,int> , pair< int,  int> > > v;
	vector< int > waitingTime;
	vector < pair< int, int> > diagram;
	cin>>n;
	for(int i=0 ; i < n ; i++){
		cin>>a>>b>>c;
		v.pb(mp(mp(i+1,a),mp(b,c)));
	}
	sort(v.begin(), v.end() , tmp);
	int time = v[0].first.second;
	diagram.pb(mp(0,time));
	waitingTime.pb(0);
	for(int i=1 ; i < v.size() ; i++){
		waitingTime.pb( max(0, time - v[i].second.first ) );
		time += v[i].first.second;
		diagram.pb(mp(time - v[i].first.second,time));
	}
	int total = 0;
	for(int i=0 ; i < waitingTime.size() ; i++){
		total+= waitingTime[i];
	}

	// for(int i=0 ; i < waitingTime.size() ; i++){
		// cout<<"Waiting Time of Proccess "<<v[i].first.first<<" is "<< waitingTime[i] << " seconds";
		// cout<<endl;
	// }
	for(int i=0 ; i < diagram.size() ; i++){
		if(!i) cout<<diagram[i].first << "--";
		cout<< "[P"<< v[i].first.first << "]--" << diagram[i].second;
		if(i!=diagram.size()-1) cout<<"--";
	}


	cout<<endl<<"Average waiting Time:" << (float)total/waitingTime.size();

	
	return 0;
}