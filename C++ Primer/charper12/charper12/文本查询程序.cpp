#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include <iostream>
using namespace std;
class TextQuery
{
	
public:
	typedef string::size_type line_no;
	TextQuery(ifstream& is) 
	{
		string text;
		while (getline(is, text))
		{
			file.push_back(text);
			int n = file.size() - 1;
			istringstream line(text);
			string word;
			while (line >> word)
			{
				wordNumber[cleanup_str(word)].insert(n);
			}
			
		}
	}
	string cleanup_str(const string& word)
	{
		string ret;
		for (auto it = word.begin(); it != word.end(); it++)
		{
			if (!ispunct(*it))
				ret += tolower(*it);
			//������ǿո�
		}
		return ret;
	}
	ostream& Query_and_print(const string& sought, ostream& os)
	{
		auto loc = wordNumber.find(sought);
		if (loc == wordNumber.end())
		{

		}
		else
		{
			auto lines = loc->second;
			os << sought << "occurs" << lines.size() << "��" << endl;
			for (auto num : lines)
			{
				os << "\t��" << num + 1 << "��" << *(file.begin() + num) << endl;
			}
		}
		return os;
	}
	void runQueries(ifstream& infile)
	{
		TextQuery input(infile);
		while (true)
		{
			cout << "enter a word to look for" << endl;
			string find;
			if ((!cin >> find) || find == "q")
				break;
			Query_and_print(find, cout);
		}
	}

private:
	vector<string> file;
	map<string, set<line_no>> wordNumber;
};
//12.31 ��vector���ã���Ȼset�������к�������ģ����Ǳ���������кž�������ģ����Բ���Ҫ��set ��set�ĵײ��Ǻ�������������logn������vector����
