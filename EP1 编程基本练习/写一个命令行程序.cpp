#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
	
	public:
		vector<int> sieve(int n) {
			vector<int> vis(n,0);
			vector<int> prime{0};
			int cnt = 0;
		    for(int i=2;i<=n;i++) {
		        if(!vis[i]){
		        	++cnt;
		        	prime.push_back(i);
				}
		        for(int j=1;j<=cnt && i*prime[j]<=n;j++) {
		            vis[i*prime[j]]=1;
		            if(!(i%prime[j]))
		                break;
		        }
		    }
		    return prime;
		}
	
}; 

int main()
{
    Solution solution;
    vector<int> res =  solution.sieve(20);
    int cnt = -1;
    for(auto& prime:res){
    	if(cnt == -1){
    		cnt = 0;
    		continue;
		}
    	cout << prime << ' ';
    	cnt++;
    	if(cnt == 5){
    		cnt = 0;
    		cout << endl;
		}
	}
    // return 7
    return 0;
}