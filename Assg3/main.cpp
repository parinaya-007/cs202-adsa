#include <iostream>
#include <string>
// #include <cstring>
#include "list.hpp"
#include "queue.hpp"
using namespace sandq;

int main(){
	// list<string> l;
	int t;
	cin >> t;
	int n;
	string slash;
	slash.push_back('/');
	while(t){
		cin >> n;
		string cmd;
		queue<string> Q;
		for(int i=0; i<n; i++){
			cin >> cmd;
			string newCmd, dir;
			cout << "x1" << endl;
			if( cmd.compare(0, 4, "cd /")==0 ){
				cout << "zzzz" << endl;
				if(!Q.empty()) Q.deleteQ();
				// size_t pos = cmd.find('/');
				cout << "x2" << endl;
				size_t pos = cmd.find(slash);
				cout << "x3" << endl;
				cout << "loop = " << i << " : " << "pos = " << pos << endl;
				while( pos != string::npos ){
					cout << "x4" << endl;
					newCmd = cmd.substr(pos);
					cout << "x5" << endl;
					cout << "newCmd = " << newCmd << endl;
					size_t index = newCmd.find('/');
					dir = newCmd.substr(0, index);
					cout << "dir = " << dir << endl;
					Q.enqueue(dir);
					pos = cmd.find('/');
				}
			}

			if( cmd.compare(0, 3, "cd ")==0 ){
				cout << "y" << "len = " << cmd.length()-1 << endl;
				string newCmd = cmd.substr(3, cmd.length()-1);
				Q.enqueue(newCmd);
			}

			if( cmd.compare(0, 3, "pwd")==0 ){
				Q.display();
			}
			cout << endl;
		}

		t--;
	}


	return 0;
}


