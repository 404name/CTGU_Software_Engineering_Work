#include <bits/stdc++.h> 
#include <iostream>  
#include <io.h> //递归读取文件 
/*
* @Author CTGU_LLZ
* @程序  文件单词分析器
* @使用  当前文件cmd窗口下输入wf查看help 
/*
【项目需求分析】 
1. 语法检测[检测语法|提示命令|确认命令]
2. 可视化界面
3. 文件读取输出[文件读取时间统计|] 
4.  开发者信息 
*/ 
using namespace std;  


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
		static void read(char* file_path,vector<string> &vec)
		{
		    ifstream fin(file_path); 
		    string strWord("");
		    string str = "";
		    char c;
		    while(fin.get(c))
		    {
		        if(c >= 'a' && c <= 'z'){
		        	str += c;
				}else if(c >= 'A' && c <= 'Z'){
					str += c + ('a' - 'A');
				}else if(c == '\''){
					fin.get(c);
					if(((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))){
						
						if(c >= 'A' && c <= 'Z'){
							 c += ('a' - 'A');
						}
						if(str.size() == 0){
							str += c;
						}else{
							str += '\'';
							str += c; 
						}
					}else{
						if(str != ""){
			                vec.push_back(str); 
						}
			            str = "";
					}
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
		}
		/**
		* 读取文件路径下所有文件 
		*
		*/
		static void getFileNames(string path,vector<string>& files)
		{
			//文件句柄
			//注意：有些章代码此处是long类型，实测运行中会报错访问异常
			intptr_t hFile = 0;
			//文件信息
			struct _finddata_t fileinfo;
			string p;
			if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
			{
				do
				{
					//如果是目录,递归查找
					//如果不是,把文件绝对路径存入vector中
					if ((fileinfo.attrib & _A_SUBDIR))
					{
						if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							getFileNames(p.assign(path).append("\\").append(fileinfo.name), files);
					}
					else
					{
						//保证是.txt结尾才加入 
						string strPath = p.assign(path).append("\\").append(fileinfo.name);
						if(strPath.size() > 4 && strPath.substr(strPath.size()-4,4) == ".txt"){
							files.push_back(strPath);
						} 
						
					}
				} while (_findnext(hFile, &fileinfo) == 0);
				_findclose(hFile);
			}
		}

};

/**
* @全局工具类 
* -stop表 hashMap存储 stopWords
* -change表 hashMap存储  changeWords
* -单词记录表 hashMap存储 wordCount
* -短语记录表 hashMap存储  vocabulary
*/ 
class WordFrequence{
	public:
		//最大输出个数，默认全部 
		static int maxNum; 
		static int vocabularyLenth; 
		static unordered_map<string,int> wordCount;
		static unordered_map<string,int> stopWords;
		static unordered_map<string,int> vocabulary;
		static unordered_map<string,string> changeWords;
	public:
        static bool cmp(const pair<string,int>&a,const pair<string,int>&b){
            if(a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        }
		//载入文件 
		static void loadFile(char * path){
			vector<string> words;
			FileUtil::read(path,words);
			for(auto&str:words){
				//先查询禁止的词 
				if(!stopWords.count(str)){
					//动词归一化 
					if(changeWords.count(str)){
						str = changeWords[str];
					}
					wordCount[str]++;
				}
			}
		}
		//载入文件 
		static void loadPath(char * path){
			vector<string> files;
			FileUtil::getFileNames(path,files);
			for(auto&file:files){
				cout << "正在加载" << file << endl; 
				 char charPath[file.size() + 5];
				 file.copy(charPath, file.size(), 0);//这里5代表复制几个字符，0代表复制的位置，
				 *(charPath+file.size())='\0';//注意手动加结束符！！！
				loadFile(charPath);
			}
		}
		//载入不加载单词文件 
		static void loadStopWords(char * path){
			vector<string> words;
			FileUtil::read(path,words);
			for(auto&str:words){
				//查询禁止的词 
				stopWords[str]++;
			}
		}
		//载入不加载单词文件 
		static void loadchangeWords(char * path){
			vector<string> words;
			FileUtil::read(path,words);
			string from = "",to = ""; 
			for(auto&str:words){
				//查询禁止的词 
				if(from == "") from = str;
				else{
					from = "";
					changeWords[from]  =to;
				}
			}
		}
		//打印单词 
		static void print(){
			vector<pair<string,int>> w; 
		    for(auto& node:wordCount){
		    	w.push_back(node);
			} 
			// map不能排序，则用vector代理排序 
			sort(w.begin(),w.end(),cmp);
			int printCnt = 0;
			for(auto& node:w){
				if(maxNum != -1){
					if(printCnt == maxNum) break;
				}
				printCnt++;
		    	cout << "No"  << printCnt << ":"  << node.first << ' ' << node.second << endl;
			} 
		}
		//保存到本地 
		static void save(char * inPath){
		    ofstream out(inPath);
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
		    	out << "No"  << printCnt << ":"  << node.first << ' ' << node.second << endl;
			} 
			out.close();
		} 
};
int WordFrequence::maxNum = -1;
int WordFrequence::vocabularyLenth = -1;
unordered_map<string,int> WordFrequence::wordCount;
unordered_map<string,int> WordFrequence::stopWords;
unordered_map<string,int> WordFrequence::vocabulary;
unordered_map<string,string> WordFrequence::changeWords;

/**
* @命令类 
* -命令
* -命令说明 
*/
class Command{
	public:
    	static int maxWidth;
        static map<string,Command*> commands;
        static vector<Command*> commandList;
        bool isActive;
        string cmdName;
        string description;
        string arg;
        string error;
    public:
    	Command(string name,string des){
            cmdName = name;
            description = des;
    		isActive = false;
    		arg = "";
    		error = "";
		};
		static void confirmCommandList(){
			for(auto &command:commandList){
                command->print();
            }
        }
    	static void showHelp(){
    		cout << "[用法]：wf [-options] [args]" << endl;
			cout << "[例子]：wf -f one.txt -n 10 -s save.txt"<< endl; 
			cout << "[解释]：读取one，输出前10高频词汇，且存入save,选项不分前后，系统自带检测排序功能"<< endl; ;
			cout << "其中选项包括" << endl; 
			for(auto &command:commandList){
                command->print();
            }
        }
		static void addCommand(string key,Command * command){
			commandList.push_back(command);
			commands[key] = command;
        }
        void print(){
        	printf("    %-15s%s\n",cmdName.c_str(),description.c_str());
        }

};
map<string,Command*> Command::commands;
vector<Command*> Command::commandList;

int main(int argc,char *argv[])  
{  
    for(int i=0;i<argc;i++)  
    {  
        cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;  
    }  
    
    // help
    Command::addCommand("====",new Command("--------------","【可选】载入转换文件"));
    Command::addCommand("-x-f", new Command("-x -f [文件]","读取停词表文件,过滤单词"));
    Command::addCommand("-v", new Command("-v [文件]","读取转换表文件,转换原型"));
    Command::addCommand("-s", new Command("-s [文件]","存储结果至文件内"));
    
    Command::addCommand("++++", new Command("--------------","【可选】输出设定"));
	Command::addCommand("-n", new Command("-n [单词数量]","结果取频率最高前N个(默认全部)"));
	Command::addCommand("-p", new Command("-p [短语长度]","设定输出短语长度(默认为单词长度为1)"));
	 
    Command::addCommand("----", new Command("--------------","【必选】载入文本文件"));
    Command::addCommand("-f", new Command("-f [文件]","加载文本文件"));
    Command::addCommand("-d", new Command("-d [文件夹]","读取当前文件夹下所有文本文件"));
    Command::addCommand("-d-s", new Command("-d -s [文件夹]","递归读取当前文件夹下所有文本文件"));
    
	
	Command::showHelp();
	
	
    
    //WordFrequence::loadStopWords("stopwords_en.txt");
    WordFrequence::loadFile("test1.txt");
    //WordFrequence::loadPath("C:\\Users\\404name\\Desktop\\CTGU_Software_Engineering_Work");
    WordFrequence::print();
    WordFrequence::save("save.txt");
    system("pause"); 
}  
