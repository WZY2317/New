#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<numeric>
#include<algorithm>
#include<iterator>
using namespace std;
void Train10_1()
{
	vector<int> vi;
	int val;
	while (cin >> val)
	{
		vi.push_back(val);
	}
	cout << "������Ҫ��ѯ������" << endl;
	cin >> val;
	cout << count(vi.begin(), vi.end(), val) << endl;

}
void Train10_2()
{
	list<string> li;
	string str;
	while (cin >> str)
	{
		li.push_back(str);
	}
	cout << "������Ҫ��ѯ���ַ���" << endl;
	cin >> str;
	cout << count(li.begin(), li.end(), str) << endl;
}
int Train10_3()
{
	vector<int> vi = { 0,1,2,3 };
	int sum = accumulate(vi.begin(), vi.end(), 0);
	return sum;
}
void Train10_6()
{
	vector<int> iv = { 1,2,3,56 };
	fill_n(iv.begin(), iv.size(), 0);
}
//10_4  0��double�����Ͳ�ͬ 10_5 C�����ַ�����==�ǱȽ�ָ��ĵ�ַ��������Ƚ������ַ��Ƿ���� 
//10.7 lst��û��Ԫ��list�޷���vec�����ݿ�����ȥ 10.8 ��Ȼvec�����пռ䣬����û��Ԫ��
void Train10_9()
{
	vector<string> words;
	string str;
	while (cin >> str)
	{
		words.push_back(str);
	}
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	words.erase(unique_end, words.end());
}
//10.10 ���ͺ�����ʵ�����Ͳ�֪�������Ĵ��ڣ�ֻ�ǶԵ��������в������ɵ���������ʵ�ֶ��������ķ���
//10.11 10.12 10.13 ��//10.15
void Train10_20(const vector<string>&words, vector<string>::size_type sz)
{
	auto res = count_if(words.begin(), words.end(), [sz](const string& a)
		{
			return a.size() >= sz;
		});
}
void Train10_21()
{
	int i=10;
	auto res = [i]()mutable->bool {if (i)i--; else return true; };
}
void add(int a)
{
	auto sum = [a](int b)->int { return a + b; };
}
void Train10_34()
{
	vector<int> vi = { 0,1,2,3,4 };
	for (auto it = vi.rbegin(); it != vi.rend(); it++)
	{
		cout << *it << endl;

	}
	for (auto it = vi.cend(); it != vi.cbegin();)
	{
		cout << *(--it) << endl;
	}
	auto rcomma = find(vi.rbegin(), vi.rend(), 0);
}
int main()
{
	//auto sum = [](int a, int b) ->int {return a + b; };//10.14
	// 10.37
	ostream_iterator<int> out_iter(cout, " ");
	vector<int > vi= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	copy(vi.begin(), vi.end(), out_iter);
	cout << endl;
	list<int> li;
	vector<int>::reverse_iterator re(vi.begin() + 2);
	vector<int>::reverse_iterator rb(vi.begin() + 7);
	copy(rb, re, back_inserter(li));
	copy(li.begin(), li.end(), out_iter);
}