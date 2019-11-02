#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define pb push_back  
#define mp make_pair
using namespace std;

bool tmp ( const pair< pair<int,int> ,pair< int, int> >   v1 , const pair<pair<int,int> , pair<int, int> >  v2 ){
	if(v1.first.second == v2.first.second) return v1.second.first < v2.second.first;
	return v1.first.second < v2.first.second;
}

int main(){
	freopen("in.txt", "r" , stdin);
	freopen("out.txt", "w", stdout);
	int n,a,b,c,total=0,cnt=0;
	vector< pair < pair<int,int> , pair< int,  int> > > v;
	map<int, int> waitingTime;
	vector < pair< int, pair<int, int> > > diagram;
	cin>>n;
	for(int i=0 ; i < n ; i++){
		cin>>a>>b>>c;
		v.pb(mp(mp(i+1,a),mp(b,a)));
	}
	sort(v.begin(), v.end() , tmp);
	int time = 0;
	diagram.pb(mp(0,mp(0,0)));
	// int beforeindex = -2;
	while(v.size()!=cnt){
		for( int i=0 ; i < v.size() ; i++ )
		{
			if( v[i].second.first < time and v[i].first.second > 0  )
			{	
				v[i].first.second--;
				if( v[i].first.second == 0 )
				{
					if(diagram[diagram.size()-1].second.second == v[i].first.first){
						diagram[diagram.size()-1].second.first = time + v[i].first.second;
						// diagram.pb(mp(time, mp(time + v[i].first.second , v[i].first.first)));
					}
					waitingTime[v[i].first.first] = ( max(0,time - v[i].second.first - v[i].second.second));
					cnt++;
				} 
				else if(  diagram[diagram.size()-1].second.second != v[i].first.first )
				{
					diagram.pb(mp( max(0,time - v[i].first.second), mp( abs(time), v[i].first.first)));
				}
				// if( v[i].first.second < v[max(0,i-1)].first.second ) swap(v[i],v[max(0,i-1)]); 
				break;
			}
		}
		time++;
	}
	for( map<int, int>::iterator it= waitingTime.begin(); it!=waitingTime.end() ; it++  ){
		total += (*it).second;
		// cout << "Waiting Time of Proccess " << (*it).first << " is " << (*it).second << " seconds"<<endl; 
	}

	for(int i=1 ; i < diagram.size() ; i++){
		if(i==1) cout<<diagram[i].first << "--";
		cout<< "[P"<< diagram[i].second.second << "]--" << diagram[i].second.first;
		if(i!=diagram.size()-1) cout<<"--";
	}

	cout<<endl<<"Average waiting Time: " << (float)total/waitingTime.size();


	
	return 0;
}