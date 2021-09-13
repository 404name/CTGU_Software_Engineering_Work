#include <bits/stdc++.h> 
#include <iostream>  
#include <io.h> //�ݹ��ȡ�ļ� 
/*
* @Author CTGU_LLZ
* @����  �ļ����ʷ�����
* @ʹ��  ��ǰ�ļ�cmd����������wf�鿴help 
/*
����Ŀ��������� 
1. �﷨���[����﷨|��ʾ����|ȷ������]
2. ���ӻ�����
3. �ļ���ȡ���[�ļ���ȡʱ��ͳ��|] 
4.  ��������Ϣ 
*/ 
using namespace std;  
bool cmp(const pair<string,int>&a,const pair<string,int>&b){
	if(a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

/**
* @��ȡ�ļ��� 
* -ָ���ļ���ȡ 
* -ָ���ļ��ж�ȡ 
* -ָ���ļ�������� 
*/
class FileUtil{
	public:
		/**
		* ��ȡ�ļ���ַ ���� ���� 
		* @file_path �ļ���ַ 
		*/
		static void read(char* file_path,vector<string> &vec)
		{
		    ifstream fin(file_path); 
		    string strWord("");
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
		}
		/**
		* ��ȡ�ļ�·���������ļ� 
		*
		*/
		static void getFileNames(string path,vector<string>& files)
		{
			//�ļ����
			//ע�⣺��Щ�´���˴���long���ͣ�ʵ�������лᱨ������쳣
			intptr_t hFile = 0;
			//�ļ���Ϣ
			struct _finddata_t fileinfo;
			string p;
			if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
			{
				do
				{
					//�����Ŀ¼,�ݹ����
					//�������,���ļ�����·������vector��
					if ((fileinfo.attrib & _A_SUBDIR))
					{
						if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
							getFileNames(p.assign(path).append("\\").append(fileinfo.name), files);
					}
					else
					{
						//��֤��.txt��β�ż��� 
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
* @ȫ�ֹ����� 
* -stop�� hashMap�洢
* -change�� hashMap�洢 
* -���ʼ�¼�� hashMap�洢
* -�����¼�� hashMap�洢 
*/ 
class WordFrequence{
	public:
		//������������Ĭ��ȫ�� 
		static int maxNum; 
		static unordered_map<string,int> wordCount;
		static unordered_map<string,int> stopWords;
	public:
		//�����ļ� 
		static void loadFile(char * path){
			vector<string> words;
			FileUtil::read(path,words);
			for(auto&str:words){
				//�Ȳ�ѯ��ֹ�Ĵ� 
				if(!stopWords.count(str))
					wordCount[str]++;
			}
		}
		//�����ļ� 
		static void loadPath(char * path){
			vector<string> files;
			FileUtil::getFileNames(path,files);
			for(auto&file:files){
				cout << "���ڼ���" << file << endl; 
				 char charPath[file.size() + 5];
				 file.copy(charPath, file.size(), 0);//����5�����Ƽ����ַ���0�����Ƶ�λ�ã�
				 *(charPath+file.size())='\0';//ע���ֶ��ӽ�����������
				loadFile(charPath);
			}
		}
		//���벻���ص����ļ� 
		static void loadStopWords(char * path){
			vector<string> words;
			FileUtil::read(path,words);
			for(auto&str:words){
				//��ѯ��ֹ�Ĵ� 
				stopWords[str]++;
			}
		}
		//��ӡ���� 
		static void print(){
			vector<pair<string,int>> w; 
		    for(auto& node:wordCount){
		    	w.push_back(node);
			} 
			// map������������vector�������� 
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
		//���浽���� 
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
int WordFrequence::maxNum = 10;
unordered_map<string,int> WordFrequence::wordCount;
unordered_map<string,int> WordFrequence::stopWords;


/**
* @������ 
* -����
* -����˵�� 
*/
class Command{
	public:
		static int maxWidth;
		string name;
		string description;
};

int main(int argc,char *argv[])  
{  
    for(int i=0;i<argc;i++)  
    {  
        cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;  
    }  
    WordFrequence::loadStopWords("stopwords_en.txt");
    //WordFrequence::loadFile("one.txt");
    WordFrequence::loadPath("C:\\Users\\404name\\Desktop\\CTGU_Software_Engineering_Work");
    WordFrequence::print();
    WordFrequence::save("save.txt");
    system("pause"); 
}  
