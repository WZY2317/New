//12.1 b1��b2ָ�����ͬһ��ռ䣬��b1��ֵ��b2ʱ�������ָ������ü��������������b1��b2�����ĸ�Ԫ��

#ifndef  MY_STRBLOB_H
#define MY_STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<stdexcept>
using namespace std;
class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il ){}
	size_type size() const { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const string& t)
	{
		data->push_back(t);
	}
	void pop_back()
	{
		;
	}
	string& front()
	{
		return data->front();
	}
	const string& front() const
	{

	}
	string& back()
	{
		return data->back();
	}
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg);
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
//StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>> (il)){}
//void StrBlob::check(size_type i, const string msg) 
//{
//	if (i >= data->size())
//		throw out_of_range(msg);
//}
//void StrBlob::pop_back()
//{
//	
//}
#endif // ! MY_STRBLOB_H
//
//12.3 ��������Ӧ�ñ������޸�vector�����������
//12.4 check��˽�г�Ա�ĺ�����ֻ�б�������ĳ�Ա�������ã����ᱻ�û����ã����ԱȽϰ�ȫ
//Ϊ��дһ�����ճ�ʼ���б����ʽ���캯������ζ�ſ��Խ����б��������ʽת��������Ҫ��ĵط�������ѡ���б������������ʹ�����д���ӷ���

