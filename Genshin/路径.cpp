#include<io.h>
#include<iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


void getFiles(std::string path, std::vector<std::string>& files, std::vector<std::string>& names)
{
	//文件句柄
	intptr_t  hFile = 0;
	//文件信息 
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之 //如果不是,加入列表 
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files, names);
				}
			}
			else
			{
				string a = fileinfo.name;
				int pe = a.find_last_of(".");
				string pic_name = a.substr(pe + 1);
				if (pic_name=="png")  // 其他类型文件只需将此处jpg修改即可
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					names.push_back(fileinfo.name);
				}
					
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

void getFiles1(std::string path, std::vector<std::string>& files, std::vector<std::string>& names)
{
	//文件句柄
	intptr_t  hFile = 0;
	//文件信息 
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之 //如果不是,加入列表 
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files, names);
				}
			}
			else
			{
				string a = fileinfo.name;
				int pe = a.find_last_of(".");
				string pic_name = a.substr(pe + 1);
				if (pic_name=="jpg")  // 其他类型文件只需将此处jpg修改即可
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					names.push_back(fileinfo.name);
				}
					
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
int main()
{
	vector<string> temp;
	vector<string> name;
	getFiles("D:\\Program Files\\Blog\\myblog\\source\\Genshin", temp,name);
	getFiles1("D:\\Program Files\\Blog\\myblog\\source\\Genshin", temp,name);
	freopen("D:\\Program Files\\Blog\\myblog\\source\\Genshin\\out.txt","w",stdout);
	for (int i = 0; i < temp.size(); i++) {

		cout << "<img src=";
		printf("%c",'"');
		cout << name[i];
		printf("%c",'"');
		cout << ">" << '\n';

	}
	return 0;
}

