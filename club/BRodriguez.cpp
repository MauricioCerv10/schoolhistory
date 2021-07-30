#include <iostream>
using namespace std;
int length;
char  dir, axis;
string line;	
int pos;

/*

+x = 0
+y = 1
-y = 2
+z = 3
-z = 4
-x = 5
*/

int main(){
	while(true){
		cin>>length;
		cin.clear();
		cin.ignore();
		if(length == 0){
			break;
		}
		pos = 0;
		getline(cin,line);

		for(int i = 0; i<length-1;i++){
			pair <char,char> move;
			move.first = line.at(3*i);
			move.second = line.at(3*i+1);
			if(pos == 0){
				if(move.first == '+' && move.second == 'y'){
					pos = 1;
				}else if(move.first == '-' && move.second == 'y'){
					pos = 2;
				}else if(move.first == '-' && move.second == 'z'){
					pos =  4;
				}else if(move.first == '+' && move.second == 'z'){
					pos = 3;
				}else if(move.first == 'N' && move.second == 'o'){
					pos = pos;
				}
			}else if(pos == 1){
				if(move.first == '+' && move.second == 'y'){
                                        pos = 5;
                                }else if(move.first == '-' && move.second == 'y'){
                                        pos = 0;
                                }else if(move.first == '-' && move.second == 'z'){
                                        pos =  pos;
                                }else if(move.first == '+' && move.second == 'z'){
                                        pos = pos;
                                }else if(move.first == 'N' && move.second == 'o'){
                                        pos = pos;
                                }
			}else if(pos == 2){
				if(move.first == '+' && move.second == 'y'){
                                        pos = 0;
                                }else if(move.first == '-' && move.second == 'y'){
                                        pos = 5;
                                }else if(move.first == '-' && move.second == 'z'){
                                        pos =  pos;
                                }else if(move.first == '+' && move.second == 'z'){
                                        pos = pos;
                                }else if(move.first == 'N' && move.second == 'o'){
                                        pos = pos;
                                }
			}else if(pos == 3){
				if(move.first == '+' && move.second == 'y'){
                                        pos = pos;
                                }else if(move.first == '-' && move.second == 'y'){
                                        pos = pos;
                                }else if(move.first == '-' && move.second == 'z'){
                                        pos =  0;
                                }else if(move.first == '+' && move.second == 'z'){
                                        pos = 5;
                                }else if(move.first == 'N' && move.second == 'o'){
                                        pos = pos;
                                }
			}else if(pos == 4){
				if(move.first == '+' && move.second == 'y'){
                                        pos = pos;
                                }else if(move.first == '-' && move.second == 'y'){
                                        pos = pos;
                                }else if(move.first == '-' && move.second == 'z'){
                                        pos =  5;
                                }else if(move.first == '+' && move.second == 'z'){
                                        pos = 0;
                                }else if(move.first == 'N' && move.second == 'o'){
                                        pos = pos;
                                }

			}else if(pos == 5){
				if(move.first == '+' && move.second == 'y'){
                                        pos = 2;
                                }else if(move.first == '-' && move.second == 'y'){
                                        pos = 1;
                                }else if(move.first == '-' && move.second == 'z'){
                                        pos =  3;
                                }else if(move.first == '+' && move.second == 'z'){
                                        pos = 4;
                                }else if(move.first == 'N' && move.second == 'o'){
                                        pos = pos;
                                }

			}

		}

		if(pos == 0){
			cout<<"+x\n";
		}else if(pos == 1){
			cout<<"+y\n";
		}else if(pos == 2){
			cout<<"-y\n";
		}else if(pos == 3){
			cout<<"+z\n";
		}else if(pos == 4){
			cout<<"-z\n";
		}else if(pos == 5){
			cout<<"-x\n";
		}
	}
}
