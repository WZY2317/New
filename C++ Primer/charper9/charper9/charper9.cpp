#include<vector>
#include<list>
#include<string>
#include<iostream>
#include<deque>
using namespace std;
//9.1  1.list����������� 2.������ͷ����β���Ĳ�����deque vector����ͷ��3.������ƺܶ�����ķ��� list�Ͳ����ˣ�Ҫ��vector
//9.2  vector<deque<int>>
//9.3 begin-end ֮�� 
bool Train9_4(vector<int>::iterator it1, vector<int>::iterator it2, int val)
{
	while (it1 != it2)
	{
		if (*it1 == val)
			return true;
		else
			it1++;
	}
	return false;
}
vector<int>::iterator Train9_5(vector<int>::iterator it1, vector<int>::iterator it2, int val)
{
	while (it1 != it2)
	{
		if (*it1 == val)
			return it1;
		else
			it1++;
	}
	return it2;
}
void Train9_20(deque<int>& que0, deque<int>& que1, list<int>& st)
{
	for (int e : st)
	{
		if (e % 2 == 1)
			que0.push_back(e);
		else
			que1.push_back(e);
	}
}
//9.6 begin�����ܵ���end��λ�� 9.7 vector<int>::iterator 9.8 list<string>::iterator  �����д�� Ҫ������ Ҳ���� list<string>::reference
//9.9 ��ͨ������ ��const������ ������Ҫд����ʱ��ʹ��const������ 9.10��
//9.11 �� 9.12  ����һ�����������Ĺ��캯������̳����е����ݺ����ͣ����ǵ����ǲ���Ҫȫ����Ԫ�ص�ʱ��Ϳ���ʹ�ý��������������Ĺ��캯��
void Train9_22()
{
	vector<int> iv = { 1,2,3,3,4 };
	int some_val = 1;
	vector<int>::iterator iter = iv.begin();
	int org_size = iv.size(), new_ele = 0;
	while (iter != (iv.begin() + org_size / 2 + new_ele))
	{
		if (*iter == some_val)
		{
			iter = iv.insert(iter, 2 * some_val);
			new_ele++;
			iter++;
			iter++;
		}
		else
			iter++;
	}
}
void Train9_31()
{
	list<int> li = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = li.begin();
	while (iter != li.end())
	{
		if (*iter % 2)
		{
			iter = li.insert(iter, *iter);
			iter++;
			iter++;
		}
		else
		{
			iter = li.erase(iter);
		}
	}
}
void replace_string(string& s, const string& oldval, const string& newval)//9.43
{
	int oldsize = oldval.size();
	if (oldsize == 0)
		return;
	auto iter = s.begin();
	while (iter != s.end())
	{
		auto iter1 = iter;
		auto iter2 = oldval.begin();
		while (iter2 != oldval.end() && *iter1 == *iter2)
		{
			iter1++;
			iter2++;
		}
		if (iter2 == oldval.end())
		{
			iter = s.erase(iter, iter1);
			if (newval.size())
			{
				iter2 = newval.end();
				while (iter2 > newval.begin())
				{
					iter2--;
					iter = s.insert(iter, *iter2);
				}
			}
			iter2 += newval.size();
		}
		else
			iter++;
	}
 }
void replace_stringp(string& s, const string& oldval, const string& newval)//9.44
{
	int p = 0;
	while ((p = s.find(oldval, p)) != string::npos)
	{
		s.replace(p, oldval.size(), newval);
		p += newval.size();
	}
}
void Train9_47()
{
	string s = "ab2c3d7R4E6";
	string number = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(number, pos))!=string::npos)
	{
		cout << s[pos] << endl;
		pos++;
	}
}
//9.48 9.49 ��
//9.50 ʹ��stoi�������� stof
class date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
public:
	date() = default;
	date(const string& ){}
};
int main()
{
	//9.14
	/*list<char*> ilist = {"ab","bb","cb","!"};
	vector<string> ivec(ilist.begin(), ilist.end());*/
	//9.15 ������==  9.16 �� 9.17 ��һ��������Ҫһ�����ڶ�������Ҫ������<�������
	//9.18 
	string in;
	deque<string> ddeque;
	while (cin >> in)
	{
		ddeque.push_back(in);
	}
	for (auto e : ddeque)
	{
		cout << e << endl;
	}
	//9.19 ��
	//9.22 ��δ����������Ϊinsert�������µĵ�����ʧЧ
	//iter��ʧЧ��midҲ��ʧЧ
	// 9.24
	vector<int> iv;
	cout << iv.at(0) << endl;
	cout << iv[0] << endl;
	cout << *iv.begin() << endl;
	cout << iv.front() << endl;
	//9.25  ������������ȵ������ʲôҲ���ᷢ���������β�������Ҳͬ��ʲô�����ᷢ�� 9.26��	
	//9.29 ����ĩβ���75��Ԫ�أ�����ֵ��ʼ���� ��ɾ��90��Ԫ�� 9.30 �����ṩһ��Ĭ�Ϲ��캯��
	//9.31 list ��forward-list ��֧�ֵ������ļӼ���ԭ������Ϊlist�Ĵ洢�ռ䲻�������ģ�Ӧ�ö�ε���++��ʵ��
	//9.32 ���Ϸ� ���������Ǵ�������*iter++����֮��iter��λ�þͱ��� ��һ��������λ�þͲ���Ӧ�ô��ݵ�λ����
	//9.33 ��vector�в���Ԫ��ʱ�����������еĵ�������ʧЧ�����û�������ֵ��begin��ʧЧ
	//9.35 size��ʵ�ʵĿռ䣬capacity ��Ԥ���Ŀռ� 9.36 ������ 9.37 list ���Ƕ�̬����ģ�array�ǹ̶���  9.38 ��
	//9.39 ���Ƿ��� 1024 ���ռ䣬����������һ����Ԫ�أ��ٺ��������˵�ǰsize��һ����Ŀռ䣬���Һ���Ŀռ��ǿմ�
	//9.40 256 1.5*256  1000 1024*2 1028 -1024*2 resize �Ŀռ�������� �����Ŀռ䣬������ռ���ٴη���
	//9.41 �õ�����ȥ��ʼ���Ϳ�����
	//9.42 Ҫ����reverse����ʼ��


}