#include <iostream>
#include <string>
#include <vector>
//ע�����ͷ�ļ�
#include <io.h>
using namespace std;

//���ĺ���
void getFileNames(string path, vector<string>& files);

int main(){
	vector<string> fileNames;
	string path("C://Users//404name//Desktop//CTGU_Software_Engineering_Work"); 	//�Լ�ѡ��Ŀ¼����
	getFileNames(path, fileNames);
	for (const auto &ph : fileNames) {
		std::cout << ph << "\n";
	}
	return 0;
} 
//���Ĵ���
void getFileNames(string path, vector<string>& files)
{
	//�ļ����
	//ע�⣺�ҷ�����Щ���´���˴���long���ͣ�ʵ�������лᱨ������쳣
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
				if(strPath.size() > 4 && strPath.substr(strPath.size()-4,4) == ".txt")  
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

