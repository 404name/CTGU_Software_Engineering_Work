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
			//cout << "��" << j - 1 << "��:" << next[j] << endl; 
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
		
		cout << "�����" << "��" << i + 1 << "��:" << next[i] << ' ' << endl; 
			
	}
	
	/*cout << endl;*/
	
	
	return 0;
}
