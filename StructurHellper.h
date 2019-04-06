#pragma once
#include <iostream>
#include <string>
#include <vector>
#define CHAR_CONST " | "
namespace cmdTable
{
	template <typename T>
	class StructurHellper
	{
	private:
		std::string strLine;
		std::vector<std::string> rows;
		T row;
		std::vector<T> listStruct;
	public:

		std::vector<T> ConvertStruct(std::vector<std::string> outputList) {
			std::string s, word;
			std::string delimiter = CHAR_CONST;
			for (int i = 0; i < outputList.size(); i++) {
				s = outputList[i].c_str();
				size_t pos = s.find(delimiter);
				std::string token;
				listStruct.push_back(TestStr());
				word = s.substr(0, pos);
				strcpy_s(listStruct[i].name, word.c_str());
				s.erase(0, pos + delimiter.length());
				listStruct[i].nuber = std::stoi(s.substr(0, pos));
				listStruct[i].age = std::stoi(s);
			}
			return listStruct;
		}

		std::vector<std::string> ConvertRows(std::vector<T> inputList) {
			for (int i = 0; i < inputList.size(); i++) {
				strLine += inputList[i].name;
				strLine += CHAR_CONST;
				strLine += std::to_string(inputList[i].nuber);
				strLine += CHAR_CONST;
				strLine += std::to_string(inputList[i].age);
				strLine += '\n';
				rows.push_back(strLine);
				strLine.clear();
			}
			return rows;
		}



		StructurHellper(){			
		}
		~StructurHellper() {		
		}
	};
}

