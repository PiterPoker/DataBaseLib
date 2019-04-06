#include "DataSet.h"
#include <iostream>
#include <direct.h>
#include <fstream>

std::string config;
std::vector<std::string> out_s;
char path[255];

void DataBase::DataSet::Path()
{
	memset(path, 0, sizeof path);
	strcpy_s(path, "./");
	strcat_s(path, out_s[0].c_str());
	strcat_s(path, "/");
}

int DataBase::DataSet::CreateDataBase(const char* nameDir)
{	//Если возвращется 0, то коталог создан.
	//Если возвращается -1, то ошибка при создание коталога
	std::fstream config("configDataBase", std::ios_base::out | std::ios_base::trunc);
	if (!config)
		return -1;
	config<<nameDir<<"\n";
	config.close();
	return _mkdir(nameDir);
}

int DataBase::DataSet::DropDataBase()
{	//Если возвращется 0, то коталог создан.
	//Если возвращается -1, то ошибка при создание коталога
	int error = -1;
	DataSet();
	for (unsigned i = out_s.size() - 1; i >= 0; i--) 
	{
		Path();
		strcpy_s(path, out_s[i].c_str());
		if (remove(path) != 0)
		{
			strcpy_s(path, out_s[i].c_str());
			error = _rmdir(path);
			return error;
		}
	}
	return error;
}
														//, const char* dataBase
int DataBase::DataSet::CreateTable(const char* nameFile)
{	//Если возвращется 0, то файл создан.
	//Если возвращается -1, то ошибка при создание файла или файл с таким именем уже существует
	DataSet();
	Path();
	strcat_s(path, nameFile);
	std::fstream table(path, std::ios_base::in);
	if (table.is_open())
		return -1;
	table.open(path, std::ios_base::app);
	if (!table)
		return -1;
	table.close(); 
	std::fstream config("configDataBase", std::ios_base::app);
	config <<nameFile<<"\n";
	config.close();
	return 0;
}

int DataBase::DataSet::DropTable(const char * nameFile)
{
	int index = 0;
	DataSet();
	Path();
	strcat_s(path, nameFile);
	if (remove(path) != 0)
		return -1;
	std::fstream config("configDataBase", std::ios_base::out | std::ios_base::trunc);
	if (!config)
		return -1;
	while (index< out_s.size())
	{
		if (_stricmp(out_s[index].c_str(), nameFile)!=0)
			config << out_s[index].c_str() << "\n";
		else
			out_s.erase(out_s.begin() + index);
		index++;
	}
	return 0;
}

std::vector<std::string> DataBase::DataSet::ListTable()
{
	DataSet();
	return out_s;
}

DataBase::DataSet::DataSet()
{
	int rowIndex = 0;
	std::string pathTable;
	out_s.clear();
	std::ifstream i("configDataBase");
	if (i.is_open())
	while (!i.eof())
	{
		getline(i, config);
		if (!config.empty()) 
		{
			if (rowIndex != 0) {
				Path();
				pathTable += path + config;
			}
			else
			{
				pathTable +=config;
			}
			out_s.push_back(pathTable);
			pathTable.clear();
			rowIndex++;
		}

	}
}

DataBase::DataSet::~DataSet()
{
}
