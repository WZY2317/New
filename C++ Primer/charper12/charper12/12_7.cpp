#include<iostream>
#include<memory>
#include<vector>
#include<cstring>
using namespace std;
shared_ptr<vector<int>> new_vector()
{
	auto pv = make_shared<vector<int>>();
	return pv;
}
void read_ints(shared_ptr<vector<int>> pv)
{
	int e;
	while (cin >> e)
	{
		pv->push_back(e);
	}
}
void print_int(shared_ptr<vector<int>> pv)
{
	for (const auto& v : *pv)
	{
		cout << v << endl;
	}
}
struct desrination{};
struct connection{};
connection connect(desrination* pd)
{
	cout << "������" << endl;
	return connection();
}
void disconnect(connection c)
{
	cout << "�ر�����" << endl;
}
void end_connection(connection* p)
{
	disconnect(*p);
}
void f1(desrination& d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
	//shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); }); 12.15
}
int main()
{
	const char* c1 = "hello";
	const char* c2 = "world";
	char* r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r, c1);
	strcat(r, c2);
	delete [] r;
}
//12.8 ��γ�����ͨ������һ���Ϸ�ָ�룬ת��Ϊ������һ������ֵ����ת����bool ������ͨnew������ڴ�ʧ�ܻ����쳣�Ͳ���ת����bool 
// ��Ϊnew ��nothrow��int�ͺ��ˣ��������һ������ָ������⡣��������д������������ͷ���һ��ָ�룬��ȥʹ������һ��ָ�룬����һ������ָ�룬�Ѿ�û�пռ��ˣ��ͻ����������
//12.9 r��qָ��ͬһ���ڴ棬����rԭ��ָ���һ��ռ�û�б��ͷţ�r2��q2ָ��ͬһ���ڴ棬����r2ԭ�����Ƕοռ�ᱻ�ͷ����ü���-1��q2�����ü���+1
//12.10 �����������ȷ�ģ�����process��ͨ������ָ�룬���ü������2����������һ�ݿ��������ü����ͱ��1
//12.11 get����һ������ָ�룬������ָ���ǲ����Ը�ֵ������ָ���
//12.12 ��֮��������ָ�벻���ԣ�����ָ�����
//12.13 �����sp��pָ��ͬһ���ڴ棬p���ͷ� sp�ͱ�ɵĿ���������ָ��
