#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define pb push_back  
#define mp make_pair
using namespace std;

bool tmp ( const pair< pair<int,int> ,pair< int, int> >   v1 , const pair<pair<int,int> , pair<int, int> >  v2 ){
	// if(v1.second.first == v2.second.first ) return v1.second.second < v2.second.second ;
	return v1.second.first< v2.second.first;
}

int main(){
	
	freopen("in.txt", "r" , stdin);
	freopen("out.txt", "w", stdout);
	
	int n,m,a,b,c,total=0,cnt=0;
	vector< pair < pair<int,int> , pair< int,  int> > > v;
	map<int, int> waitingTime;
	vector< pair< int, pair< int, int> > > diagram ;
	cin>>n>>m;
	
	for(int i=0 ; i < n ; i++){
		cin>>a>>b>>c;
		v.pb(mp(mp(i+1,a),mp(b,a)));
	}
	
	sort(v.begin(), v.end() , tmp);
	int time = 0,delta = 0;

	// for(int i=0 ; i < v.size() ; i++ ){
	// 	cout<<v[i].first.first<<" "<<v[i].first.second << " " << v[i].second.first << " " << v[i].second.second << endl;  
	// }

	while(v.size() != cnt){
		for(int i=0 ; i < v.size() ; i++)
		{
			if( v[i].second.first <= time and v[i].first.second > 0 )
			{
				diagram.pb(mp(time,mp(time+min(m,v[i].first.second),v[i].first.first)));
				time += min(m,v[i].first.second);
				v[i].first.second -= m;
				if( v[i].first.second < 1){
					waitingTime[v[i].first.first] = time - v[i].second.second - v[i].second.first;
					// cout<<time<< " ";
					cnt++;
				}
			}
		}
	}

	for( map<int, int>::iterator it= waitingTime.begin(); it!=waitingTime.end() ; it++  ){
		total += (*it).second;
		// cout << "Waiting Time of Proccess " << (*it).first << " is " << (*it).second << " seconds"<<endl; 
	}

	for(int i=0 ; i < diagram.size() ; i++){
		if(!i) cout<<diagram[i].first << "--";
		cout<< "[P"<< diagram[i].second.second << "]--" << diagram[i].second.first;
		if(i!=diagram.size()-1) cout<<"--";
	}


	cout<<endl<<"Average waiting Time: " << (float)total/waitingTime.size();


	
	return 0;
}