#include <bits/stdc++.h>
using namespace std;

struct Pt{
	double x,y;
};

bool sortbyX(const pair<pair<Pt,Pt>,double> &a,const pair<pair<Pt,Pt>,double> &b){
	return a.first.first.x < b.first.first.x;
}

bool sortbyY(const pair<pair<Pt,Pt>,double> &a,const pair<pair<Pt,Pt>,double> &b){
        return a.first.first.y < b.first.first.y;
}

int caso;

int main(){
	int t;
	cin>>t;
	while(t--){
		if(caso++) cout<<"\n";

		vector<pair<pair<Pt,Pt>,double>> films;
		vector<double> axeX;
		int n;
		cin>>n;
		for(int i = 0; i<n ;i++){
			double x1,x2,y1,y2,r;
			cin>>x1>>y1>>x2>>y2>>r;
			axeX.push_back(x1);
			axeX.push_back(x2);

			Pt pt1;
			pt1.x = x1; pt1.y = y1;
			Pt pt2;
			pt2.x = x2; pt2.y = y2;

			pair<Pt,Pt> seg;
			if(pt1.x <= pt2.x) { seg.first = pt1; seg.second = pt2; }
			else{ seg.first = pt2; seg.second = pt1; }

			pair<pair<Pt,Pt>,double> film;
			film.first = seg;
			film.second = r;

			films.push_back(film); 
		}
		
		sort(axeX.begin(),axeX.end());
		sort(films.begin(),films.end(),sortbyY);
		double ini, fin;
		vector<pair<pair<double,double>,double>> res;
 
		for(int i = 0; i<axeX.size()-1;i++){
			ini = axeX[i]; fin = axeX[i+1];
			double coe = 1;
			pair<pair<double,double>,double> ans;
			
			for(int j = 0; j<films.size() ; j++){
				
				if(ini >= films[j].first.first.x && fin <= films[j].first.second.x) {
					coe *= films[j].second;
					
				}
			}
			ans.first.first = ini;
			ans.first.second = fin;
			ans.second = coe;
			res.push_back(ans);
		}

		cout<<res.size()+2<<endl;
		cout<<"-inf "<<fixed<<setprecision(3)<<res[0].first.first<<" 1.000\n";
		for(int i = 0; i<res.size();i++){
			 cout<<fixed<<setprecision(3)<<res[i].first.first<<" "<<fixed<<setprecision(3)<<res[i].first.second<<" "<<fixed<<setprecision(3)<<res[i].second<<endl;
		}
		cout<<fixed<<setprecision(3)<<res[res.size()-1].first.second<<" +inf 1.000\n";
	}
}

