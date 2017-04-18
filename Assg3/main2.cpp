#include <iostream>
#include <string>
#include <cstring>
#include "list.hpp"
#include "queue.hpp"
using namespace sandq;

int main(){
	int t;
	cin >> t;
	int n;
	char slash = '/';
	while(t){
		cin >> n;
		char cmd[201];
		string str;
		queue<string> Q;
		for(int i=0; i<n; i++){
			cin >> cmd;
			for(int j=0; j<=2; j++ )
				str.push_back(cmd[j]);
			if( strncmp( str, "cd /", 4 )==0 ){
				if(!Q.empty()) Q.delete();
				int j = 0;
				while(cmd[j]!='\0'){
					if(cmd[j]=='/') break;
					else j++;
				}
				Q.enqueue(cmd[j]);
				while(cmd[]){
					int k = j;
					while(cmd[k]!='\0'){
						if(cmd[k]=='/') break;
						else k++; 
					}
					for( int l=j; l<=k; l++ ){

					}
				}
			}

			else if(  )
		}
		t--;
	}

	return 0;
}