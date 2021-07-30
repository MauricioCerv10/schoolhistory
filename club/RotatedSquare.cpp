#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, N;
	while(cin>>N>>n,(N || n)){

		char arrN[N][N];
		char arr[n][n];
		int appears[4];

		for(int i = 0; i<4;i++){
			appears[i] = 0;
		}

		for(int i = 0; i<N;i++){
			for(int j = 0; j<N;j++){
				cin>>arrN[i][j];
			}
		}

		for(int i = 0; i<n; i++){
			for(int j = 0; j<n;j++){
				cin>>arr[i][j];
			}
		}
		
			for(int i = 0;i<N-(n-1);i++){
				for(int j = 0; j<N-(n-1);j++){
					if(arrN[i][j] == arr[0][0]){
						bool appear = true;
						for(int c = 0;c<n;c++){
							for(int h = 0;h<n;h++){
								if(arrN[i+c][j+h] != arr[c][h]){
									appear = false;
									break;
								}
							}
							if(appear == false){
								break;
							}
						}
						if(appear == true){
							appears[0]++;
						}
					}
				}
			}
        		char narr[n][n];
			for(int i = n-1; i>=0;i--){
	                	int j = 0;
				int conaux = i;
                		for(j = n-i-1; j<=i;j++){
                        		narr[n-i-1][j] = arr[conaux][n-i-1];
                      			conaux--;
                		}
                		int a2;
              			for(a2 = n-i;a2<=i;a2++){
                        		narr[a2][i] = arr[n-i-1][a2];
                		}
				conaux = i-1;
                		for(a2 = n-i; a2<=i;a2++){
                        		narr[i][conaux] = arr[a2][i];
					conaux--;
                		}
				conaux = i-1;
                		for(a2 = i-1;a2 >= n-i;a2--){
                        		narr[a2][n-i-1] = arr[i][conaux];
					conaux--;
                		}
        		}
			for(int i = 0;i<N-(n-1);i++){
                                for(int j = 0; j<N-(n-1);j++){
                                        if(arrN[i][j] == narr[0][0]){
                                                bool appear = true;
                                                for(int c = 0;c<n;c++){
                                                        for(int h = 0;h<n;h++){
                                                                if(arrN[i+c][j+h] != narr[c][h]){
                                                                        appear = false;
                                                                        break;
                                                                }
                                                        }
                                                        if(appear == false){
                                                                break;
                                                        }
                                                }
                                                if(appear == true){
                                                        appears[1]++;
                                                }
                                        }
                                }
                        }

			char nnarr[n][n];
                        for(int i = n-1; i>=0;i--){
                                int j = 0;
                                int conaux = i;
                                for(j = n-i-1; j<=i;j++){
                                        nnarr[n-i-1][j] = narr[conaux][n-i-1];
                                        conaux--;
                                }
                                int a2;
                                for(a2 = n-i;a2<=i;a2++){
                                        nnarr[a2][i] = narr[n-i-1][a2];
                                }
                                conaux = i-1;
                                for(a2 = n-i; a2<=i;a2++){
                                        nnarr[i][conaux] = narr[a2][i];
                                        conaux--;
                                }
                                conaux = i-1;
                                for(a2 = i-1;a2 >= n-i;a2--){
                                        nnarr[a2][n-i-1] = narr[i][conaux];
                                        conaux--;
                                }
                        }
			for(int i = 0;i<N-(n-1);i++){
                                for(int j = 0; j<N-(n-1);j++){
                                        if(arrN[i][j] == nnarr[0][0]){
                                                bool appear = true;
                                                for(int c = 0;c<n;c++){
                                                        for(int h = 0;h<n;h++){
                                                                if(arrN[i+c][j+h] != nnarr[c][h]){
                                                                        appear = false;
                                                                        break;
                                                                }
                                                        }
                                                        if(appear == false){
                                                                break;
                                                        }
                                                }
                                                if(appear == true){
                                                        appears[2]++;
                                                }
                                        }
                                }
                        }
			
			char nnnarr[n][n];
                        for(int i = n-1; i>=0;i--){
                                int j = 0;
                                int conaux = i;
                                for(j = n-i-1; j<=i;j++){
                                        nnnarr[n-i-1][j] = nnarr[conaux][n-i-1];
                                        conaux--;
                                }
                                int a2;
                                for(a2 = n-i;a2<=i;a2++){
                                        nnnarr[a2][i] = nnarr[n-i-1][a2];
                                }
                                conaux = i-1;
                                for(a2 = n-i; a2<=i;a2++){
                                        nnnarr[i][conaux] = nnarr[a2][i];
                                        conaux--;
                                }
                                conaux = i-1;
                                for(a2 = i-1;a2 >= n-i;a2--){
                                        nnnarr[a2][n-i-1] = nnarr[i][conaux];
                                        conaux--;
                                }
                        }

			for(int i = 0;i<N-(n-1);i++){
                                for(int j = 0; j<N-(n-1);j++){
                                        if(arrN[i][j] == nnnarr[0][0]){
                                                bool appear = true;
                                                for(int c = 0;c<n;c++){
                                                        for(int h = 0;h<n;h++){
                                                                if(arrN[i+c][j+h] != nnnarr[c][h]){
                                                                        appear = false;
                                                                        break;
                                                                }
                                                        }
                                                        if(appear == false){
                                                                break;
                                                        }
                                                }
                                                if(appear == true){
                                                        appears[3]++;
                                                }
                                        }
                                }
                        }
			for(int i = 0;i<4;i++){
				if(i != 3){
					cout<<appears[i]<<" ";
				}else{
					cout<<appears[i];
				}
			}
			cout<<"\n";
	}
}
