#include <vector>
#include <fstream>
#define CHAR_CONST " | "
#define CHAR_COUNT 4
namespace cmdTable 
{
	using namespace std;
	template <typename T, typename C>
	class CommandsForTable
	{
	private:
		T row;
		std::vector<T> rows;
		fstream table;
	public:
		CommandsForTable()
		{ }
		std::vector<T> ReadRwos(C *name) {
			table.open(name, ios_base::in);
			if (table.is_open())
				while (!table.eof())
				{
					getline(table, row);
					if (!row.empty())
					{
						rows.push_back(row);
						row.clear();
					}
				}
			return rows;
		}
		unsigned int WriteRwos(vector<T> listData, C *name) {
			table.open(name, ios_base::out);
			for (decltype(listData.size()) i = 0; i < listData.size(); ++i) {
				table << listData[i].c_str();
			}
			table.close();
			return 0;
		}
		unsigned int AddNewRwos(vector<T> listData, C *name) {
			table.open(name, ios_base::app);
			for (decltype(listData.size()) i = 0; i < listData.size(); ++i) {
				table << listData[i].c_str();
			}
			table.close();
			return 0;
		}
		std::vector<T> Search(const C* nameSearch,const C* nameTable) {
			table.open(nameTable, ios_base::in);
			if (table.is_open())
				while (!table.eof())
				{
					getline(table, row);
					size_t pos = 0;
					T token;
					T rowSearch = row;
					while ((pos = rowSearch.find(CHAR_CONST)) != std::string::npos) {
						token = rowSearch.substr(0, pos);
						rowSearch.erase(0, pos + CHAR_COUNT);
						if (strcmp(token.c_str(), nameSearch) == NULL)
							rows.push_back(row.c_str());
					}

				}
			table.close();
			return rows;
		}
	};
}
