#include <string>
#include <vector>
namespace DataBase 
{
	class DataSet
	{
	private:
		static void Path();
	public:
		static int CreateDataBase(const char* nameDir);
		static int DropDataBase();
													//, const char* dataBase
		static int CreateTable(const char* nameFile);
		static int DropTable(const char* nameFile);
		static std::vector<std::string> ListTable();
		DataSet();
		~DataSet();
	};
}
