#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define pb push_back  
#define mp make_pair
using namespace std;

bool tmp ( const pair< pair<int,int> ,pair< int, int> >   v1 , const pair<pair<int,int> , pair<int, int> >  v2 ){
	if(v1.second.second == v2.second.second) return v1.second.first < v2.second.first;
	return v1.second.second < v2.second.second;
}

int main(){
	freopen("in.txt", "r" , stdin);
	freopen("out.txt", "w", stdout);
	int n,a,b,c,total=0;
	vector< pair < pair<int,int> , pair< int,  int> > > v;
	vector< pair<int, int > > waitingTime;
	vector < pair< int, pair<int, int> > > diagram;
	cin>>n;
	for(int i=0 ; i < n ; i++){
		cin>>a>>b>>c;
		v.pb(mp(mp(i+1,a),mp(b,c)));
	}

	sort(v.begin(), v.end() , tmp);
	int time = 0;
	while(v.size()!=0){
		for(int i=0 ; i < v.size() ; i++){
			if(i==v.size()-1){
				waitingTime.pb( mp(v[i].first.first ,max(0,time-v[i].second.first)));
				diagram.pb(mp(time, mp(time + v[i].first.second, v[i].first.first)));
				time += v[i].first.second;
				v.erase(v.begin() + i);
				break;
			}
			if(v[i].second.first > time) continue;
			waitingTime.pb( mp(v[i].first.first ,max(0,time-v[i].second.first)));
			diagram.pb(mp(time, mp( time + v[i].first.second,v[i].first.first)));
			time += v[i].first.second;
			v.erase(v.begin() + i);
			break;
		}
	}

	for(int i=0 ; i < waitingTime.size() ; i++){
		total += waitingTime[i].second;
		// cout<<"Waiting Time of Proccess "<<waitingTime[i].first<<" is "<< waitingTime[i].second << " seconds";
		// cout<<endl;
	}
	for(int i=0 ; i < diagram.size() ; i++){
		if(!i) cout<<diagram[i].first << "--";
		cout<< "[P"<< diagram[i].second.second << "]--" << diagram[i].second.first;
		if(i!=diagram.size()-1) cout<<"--";
	}


	cout<<endl<<"Average waiting Time: " << (float)total/waitingTime.size();


	
	return 0;
}