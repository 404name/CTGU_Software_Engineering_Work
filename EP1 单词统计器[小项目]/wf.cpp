#include <bits/stdc++.h> 
#include <iostream>  
  
using namespace std;  
bool cmp(const pair<string,int>&a,const pair<string,int>&b){
	if(a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

/**
* @读取文件类 
* -指定文件读取 
* -指定文件夹读取 
* -指定文件输出内容 
*/
class FileUtil{
	public:
		/**
		* 读取文件地址 返回 单词 
		* @file_path 文件地址 
		*/
		static vector<string> read(char* file_path)
		{
		    ifstream fin(file_path); 
		    string strWord("");
		    vector<string> vec;
		    string str;
		    char c;
		    while(fin.get(c))
		    {
		        if(c >= 'a' && c <= 'z'){
		        	str += c;
				}else if(c >= 'A' && c <= 'Z'){
					str += c + ('a' - 'A');
				}
		        else
		        {
		            if(str != ""){
		                vec.push_back(str); 
					}
		            str = "";
		        }   
		    }
		    if(str != ""){
		        vec.push_back(str); 
			}
		    if(fin.is_open())
		        fin.close();
		    return vec;
		}

};


/*
【项目需求分析】 
1. 语法检测[检测语法|提示命令|确认命令]
2. 可视化界面
3. 文件读取输出[文件读取时间统计|] 
4.  开发者信息 
*/ 
class WordFrequence{
	public:
		//最大输出个数，默认全部 
		static int maxNum; 
		static unordered_map<string,int> wordCount;
		static unordered_map<string,int> stopWords;
	public:
		//载入文件 
		static void load(char *path){
			vector<string> words = FileUtil::read(path);
			for(auto&str:words){
				//先查询禁止的词 
				if(!stopWords.count(str))
					wordCount[str]++;
			}
		}
		//载入文件 
		static void loadStopWords(char *path){
			vector<string> words = FileUtil::read(path);
			for(auto&str:words){
				stopWords[str]++;
			}
		}
		//打印单词 
		static void print(){
			vector<pair<string,int>> w; 
		    for(auto& node:wordCount){
		    	w.push_back(node);
			} 
			sort(w.begin(),w.end(),cmp);
			int printCnt = 0;
			for(auto& node:w){
				if(maxNum != -1){
					if(printCnt == maxNum) break;
					printCnt++;
				}
		    	cout << "No"  << printCnt << ":"  << node.first << ' ' << node.second << endl;
			} 
		}
		//保存到本地 
		static void save(){} 
};
int WordFrequence::maxNum = 10;
unordered_map<string,int> WordFrequence::wordCount;
unordered_map<string,int> WordFrequence::stopWords;


/**
* @命令类 
* -命令
* -命令说明 
*/
class Command{
	public:
		static int maxWidth;
		string name;
		string description;
};





/**
* @全局工具类 
* -stop表 hashMap存储
* -change表 hashMap存储 
* -单词记录表 hashMap存储
* -短语记录表 hashMap存储 
*/ 
int main(int argc,char *argv[])  
{  
    for(int i=0;i<argc;i++)  
    {  
        cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;  
    }  
    WordFrequence::loadStopWords("stopwords.txt");
    WordFrequence::load("one.txt");
    WordFrequence::print();
    system("pause");  
}  