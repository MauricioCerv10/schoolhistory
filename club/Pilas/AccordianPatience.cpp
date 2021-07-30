#include <bits/stdc++.h>
using namespace std;

int main(){
	
	while(true){
		string end;
		cin>>end;
		if(end.compare("#") == 0) break;

		vector< stack<string> > piles;
		stack<string>  pile;
		pile.push(end);
		piles.push_back(pile);
		pile.pop();
		
		for(int i = 1;i<=51;i++){
			cin>>end;
			int tam = piles.size()-1;	
			if( tam>2 && ( end[0] == piles[tam-2].top()[0] || end[1] == piles[tam-2].top()[1] ) ){
				piles[tam-2].push(end);
				
				int con = tam-2;
				while(true){
					cout<<"uno"<<endl;
					if( (con+3 < piles.size()) && (piles[con].top()[0] == piles[con+3].top()[0] || piles[con].top()[1] == piles[con+3].top()[1]) ){
						cout<<"here1"<<endl;
						piles[con].push(piles[con+3].top());
						piles[con+3].pop();
						con = con+3;
						if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con+1 < piles.size()) && (piles[con].top()[0] == piles[con+1].top()[0] || piles[con].top()[1] == piles[con+1].top()[1]) ){
						cout<<"here2"<<endl;
						piles[con].push(piles[con+1].top());
                                                piles[con+1].pop();
                                                con = con+1;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con-3 >= 0) && (piles[con].top()[0] == piles[con-3].top()[0] || piles[con].top()[1] == piles[con-3].top()[1] ) ){
						cout<<"here3"<<endl;
						piles[con-3].push(piles[con].top());
                                                piles[con].pop();
                                                con = con-3;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con-1 >= 0) && (piles[con].top()[0] == piles[con-1].top()[0] || piles[con].top()[1] == piles[con-1].top()[1] ) ){
						cout<<"here5"<<endl;
						piles[con-1].push(piles[con].top());
                                                piles[con].pop();
                                                con = con-1;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else{
   						break;
					}
				}

			}else if( end[0] == piles.back().top()[0] || end[1] == piles.back().top()[1] ){
				piles[tam].push(end);
				int con = tam;
				while(true){
					cout<<"dos"<<endl;
					if( (con+3 < piles.size()) && (piles[con].top()[0] == piles[con+3].top()[0] || piles[con].top()[1] == piles[con+3].top()[1]) ){
						cout<<"here1"<<endl;
						piles[con].push(piles[con+3].top());
						piles[con+3].pop();
						con = con+3;
						if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con+1 < piles.size()) && (piles[con].top()[0] == piles[con+1].top()[0] || piles[con].top()[1] == piles[con+1].top()[1]) ){
						cout<<"here2"<<endl;
						piles[con].push(piles[con+1].top());
                                                piles[con+1].pop();
                                                con = con+1;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con-3 >= 0) && (piles[con].top()[0] == piles[con-3].top()[0] || piles[con].top()[1] == piles[con-3].top()[1] ) ){
						cout<<"here3"<<endl;
						piles[con-3].push(piles[con].top());
                                                piles[con].pop();
                                                con = con-3;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else if( (con-1 >= 0) && (piles[con].top()[0] == piles[con-1].top()[0] || piles[con].top()[1] == piles[con-1].top()[1] ) ){
						cout<<"here5"<<endl;
						piles[con-1].push(piles[con].top());
                                                piles[con].pop();
                                                con = con-1;
                                                if( piles[con].empty() ) piles.erase(piles.begin()+con);
					}else{
   						break;
					}
				}


			}else{
				cout<<"no"<<endl;
				pile.push(end);
				piles.push_back(pile);
				pile.pop();
			}
			if(end.compare("JS") == 0) break;
		}
		
		cout<<piles.size();
		if(piles.size() == 1) cout<<" pile remaining:";
		else cout<<" piles remaining:";
		for(int i = 0;i<piles.size();i++) cout<<" "<<piles[i].size();
		cout<<"\n";
		break;

	}
}
