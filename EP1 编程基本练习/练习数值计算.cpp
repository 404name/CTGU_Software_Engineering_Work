#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		int check(vector<int> &arr){
			int sum = 0;
			for(auto &num:arr){
				sum += num;
				if(sum < 0) sum = 0;
			}
			return sum;
		}
}; 

int main()
{
    Solution solution;
    vector<int> vec{1, -2, 3,-2, 5, 1};
    cout << solution.check(vec) << endl;
    // return 7
    return 0;
}