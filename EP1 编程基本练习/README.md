# 实验内容
## 1. git 基本操作
要求每个学生开始管理自己的源代码：
每个同学申请一个 [GitHub](https://github.com/) 的项目，或者 [码云](https://gitee.com/) 项目，存放源程序和其他文档。
安装、配置git。
## 2. 编程基本功练习
> 有手就行

### （1）编程实现Helloworld。
全部用命令行工具和notepad编辑器，不用Eclipse 等集成编辑环境，每人手工创建并编译一个Java的命令行程序：“Hello World”。
```cpp
#include <iostream>

int main() {
	std::cout << "Hello World!" << std::endl;
	return 0;
}

```
### （2）练习数值计算。
找出一个整数数组中子数组之和的最大值，例如：数组[1, -2, 3, 5, -1]，返回8（因为符合要求的子数组是 [3, 5]）；数组[1, -2, 3, -8, 5, 1]，返回6（因为符合要求的子数组是 [5, 1]）; 数组[1, -2, 3,-2, 5, 1]，返回7（因为符合要求的子数组是 [3, -2, 5, 1]）。
```cpp
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
```
​

### （3）写一个命令行程序，
要求：输出1~20000内的所有素数，按每行5个打印出来，并分析程序中最费时的函数是什么， 如何改进？
> 素数筛选最费时间的就是筛选素数时一个个去遍历检查O(n*n)的时间复杂度浪费了大量时间
> 通过每次检测一个素数筛选多个可以确认的非素数的思想可以优化到O（n）；
> 如下利用欧拉晒可以大大提高效率

```cpp
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

```
​