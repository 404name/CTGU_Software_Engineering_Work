#include<iostream>
using namespace std;

void getNext(int* returnnext, string p){
	
	int max = p.length();
	
	int next[max];
	
	next[0] = -1;
	
	int k = -1;

	int j = 0;
	
	while (j < p.length() - 1){
		if (k == -1 || p[j] == p[k]){
			next[++j] = ++k;
			//cout << "第" << j - 1 << "个:" << next[j] << endl; 
		}
		else{
			k = next[k];
		}
	}	
	
	returnnext = next;
}

int main(){
	
	string p = "ABABAABBBABABAB";
	
	int *next;
	
	getNext(next, p);
	
	for (int i = 0; i < p.length() - 1; i++){
		
		cout << "输出中" << "第" << i + 1 << "个:" << next[i] << ' ' << endl; 
			
	}
	
	/*cout << endl;*/
	
	
	return 0;
}
