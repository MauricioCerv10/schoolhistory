#include <bits/stdc++.h>
using namespace std;

int main(){
    bool done=false;
    int counter=1;
    string word;
    getline(cin,word);
    while(word!="end"){
        vector < stack<char> > stacks;
        stack<char> container;
        container.push(word[0]);
        stacks.push_back(container);
        container.pop();
        for(int i=1;i<word.length();i++){
            done=false;
	    cout<<"entro ciclo"<<endl;
            for(int j=0;j<stacks.size();j++){
                if(word[i]<=stacks[j].top()){
			cout<<"PUso"<<word[i]<<endl;
                    stacks[j].push(word[i]);
                    done=true;
                    break;
                }
            }
            if(!done){
		cout<<"NO hecho, puso "<<word[i]<<endl;
                container.push(word[i]);
                stacks.push_back(container);
                container.pop();
            }
        }
        cout << "Case " << counter << ": " << stacks.size() << endl;
        counter++;
        getline(cin,word);
    }
}
