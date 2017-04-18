#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "queue.hpp"

using namespace sandq;

int main(){
	int t;
	cin >> t;
	int n;
	queue<string> Q, Q1;
	string cmd, temp, tempstr;
	while(t){
		while(!Q.empty())
			tempstr = Q.dequeue();
		cin >> n;
		Q.enqueue("/");
		long long int i = 0, j;
		while(n){
			cin >> cmd;
			if( cmd=="pwd" ){
				Q.display();
				cout << endl;
			}

			else{
				cin >> cmd;
				if( cmd[0]=='/' ){
					while(!Q.empty())
						tempstr = Q.dequeue();
					Q.enqueue("/");
					j = 1;
					while(cmd[j]!='\0'){
						temp = "";
						while(cmd[j]!='\0' && cmd[j]!='/'){
							temp = temp + cmd[j];
							j++;
						}
						temp = temp + '/';
						if( temp[0]=='.' && temp[1]=='.' ){
							while( Q.size()!=1 ){
								tempstr = Q.dequeue();
								Q1.enqueue(tempstr);
							}
							tempstr = Q.dequeue();

							if( Q1.size()==0 )
								Q.enqueue("/");

							while(!Q1.empty()){
								tempstr = Q1.dequeue();
								Q.enqueue(tempstr); 
							}
						}
						else
							Q.enqueue(temp.c_str());

						if(cmd[j]=='/') j++;
					}
				}
				else{
					j=0;
					while(cmd[j]!='\0'){
						temp = "";
						while(cmd[j]!='\0' && cmd[j]!='/'){
							temp = temp + cmd[j];
							j++;
						}
						temp = temp + '/';
						if(temp[0]=='.' && temp[1]=='.'){
							while(Q.size()!=1){
								tempstr = Q.dequeue();
								Q1.enqueue(tempstr);
							}
							tempstr = Q.dequeue();

							if(Q1.size()==0)
								Q.enqueue("/");

							while(!Q1.empty()){
								tempstr = Q1.dequeue();
								Q.enqueue(tempstr);
							}
						}
						else
							Q.enqueue(temp);

						if(cmd[j]=='/') j++;
					}
				}
			}
		n--;
		}
		cout << endl;
		t--;
	}
	return 0;
}