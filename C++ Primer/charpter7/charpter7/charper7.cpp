#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Person
{
private:
	string name;
	string strAddress;
public:
	//��ϰ7.5
	Person() = default;
	//��ϰ7.15
	Person(const string& name, const string& strAddress)
	{
		this->name = name;
		this->strAddress = strAddress;
	}
	Person(istream& is)
	{
		is >> this->name >> this->strAddress;
	}
	string Name() const
	{
		return name;
	}
	string strAdd() const
	{
		return strAddress;
	}
	istream& is(istream& is, Person& item)
	{
		is >> item.name >> item.strAddress ;
		return is;
	}
	ostream& out(ostream& out, Person& item)
	{
		out << item.name << item.strAddress;
		return out;
	}
	//��ϰ7/10
	//���ﷵ�ص������ã�������Ϊ���read������ʵ��ʹ��
	//��ϰ7/16�����캯����һ���ֳ�Ա���������ǹ��У������ݳ�Ա����Ϊʵ�ֲ��ֵĺ���Ӧ�ø���private����
	//��ϰ7/17:struct Ĭ�ϳ�Ա�ǹ��ж���һ����˽��
	//��װ���Ǳ�����ĳ�Ա����������ʣ�ͨ�������ϸ������Ϊprivate ������ɶ���ķ�װ������ȷ���û����벻��������ƻ���װ���ԣ������������ʵ��ϸ��
	//������ʱ�ı䣬����������û�����Ĵ���
	//��ϰ7/19�������ֺ͵�ַ����Ϊ˽�У���ֹ�û���������޸ĺ��ƻ�
	//��ϰ7/20��ȷ�����ƻ���װ���ŵ���ǿ����÷ǽӿڵĺ���������ĳ�Ա

};
//class Sales_data
//{
//private:
//	string bookNo;
//	unsigned units_sold = 0;
//	double sellingprice = 0.0;//ԭʼ�۸�
//	double saleprice = 0.0;
//	double discount = 0.0;
//public:
//	//��ϰ7/21
//	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
//	friend istream& read(istream& is, Sales_data& item);
//	friend ostream& print(ostream& os, const Sales_data& item);
//	
//	Sales_data() = default;
//	Sales_data(const string& book):bookNo(book){}
//	/*Sales_data(const string& book) :bookNo(book), units_sold(0), sellingprice(0.0), saleprice(0.0),discount(0)
//	{
//
//	}*/
//	Sales_data(const string& book, const unsigned& num, const double& sell, const double& sale)
//		:bookNo(book),units_sold(sell),sellingprice(sell),saleprice(sale)
//	{
//		if (sellingprice != 0)
//			discount = saleprice / sellingprice;
//	}
//	Sales_data(istream& is)
//	{
//		is >> this->bookNo>>this->units_sold>>this->sellingprice>>this->sellingprice;
//	}
//	string isbn() const
//	{
//		return bookNo;
//	}
//	//��ϰ7.2
//	Sales_data& combine(const Sales_data& rhs)
//	{
//		units_sold += rhs.units_sold;
//		saleprice = (saleprice * discount + rhs.saleprice * rhs.discount);
//		if (sellingprice != 0)
//		{
//			discount = sellingprice / saleprice;
//		}
//		return *this;
//	}
//	//��ĳ�Ա����Ĭ����������
//	double avg_price() const
//	{
//	
//	}
//	
//	//print(cout,trans);
//
//	//��ϰ7.8����Ϊ��Ҫ�ӱ�׼�����ȡ����д�뵽sales_data ���Ҫ���޸Ķ����Ȩ��
//	
//};
//Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}
////��ϰ7.6
//istream& read(istream& is, Sales_data& item)
//{
//	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
//	return is;
//}
////read(cin,trans);
//ostream& print(ostream& os, const Sales_data& item)
//{
//	os << item.bookNo << item.units_sold << item.sellingprice << item.saleprice;
//	return os;
//}

class Window_mgr
{
public:
	void clear();
};
class Screen
{
	//��ϰ7.32
	friend void Window_mgr::clear();

private:
	typedef string::size_type pos;
	unsigned height = 0,width = 0;
	unsigned cursor = 0;
	string contents;
	void do_display(ostream& os) const
	{
		os << contents;
		
	}
public:
	
	Screen() = default;
	Screen(unsigned ht, unsigned wh) :height(ht), width(wh), contents(ht* wh, ' ')
	{
		
	}
	Screen(unsigned ht, unsigned wd, char c) :height(ht), width(wd), contents(ht* wd, 'c')
	{

	}
	//��ϰ7/25 �����ĸ����ݳ�Ա�����������ͣ����ֱ��ʹ�������ִ�п����͸�ֵ�����ǿ��Ե�
	Screen& move(pos r, pos c)
	{
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
	Screen& set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen& display(ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const
	{
		do_display(os);
		return *this;
	}
	pos size() const
	{

	}


};

//��ϰ7.33
//Screen::pos Screen::size() const
//{
//	return height * width;
//}
//��ϰ7.34 ����������Ϊ����ʹ�ù���pos ��������֪�� 
//��ϰ7.35 Type ʹ�õ������ڲ��ģ� parmҲ������ڲ��ģ� setval�ķ���ֵ��������Ӧ���ϣ� Typeǰ��Ӧ�ü��� Exercise����
//��ϰ7.36����Ա��ʼ����˳���ǺͶ����˳��һ��
//��ϰ7.37����һ���ǵ���Ĭ�Ϲ��캯�����ڶ����ǵ���const string&
//��ϰ7.38��Sales_data(istream &is=cin){is>>*this;
//��ϰ7.39���ṩ��Ĭ�Ϲ��캯��֮�󣬵����ǲ����κβ�������һ�������ʱ�򣬾Ͳ�֪��������һ��Ĭ�Ϲ��캯���ã������ͻ���������ԡ�
//��ϰ7.40��7.41��7.42��




void Window_mgr::clear()
{
	Screen myScreen(10, 10, 'X');
	myScreen.contents=" ";
}
class X;
class Y;
class X
{
	Y* x;
};
class Y
{
	X y;
};
//��ϰ7.43
class NoDefault
{
public:
	NoDefault(int i)
	{

	}
private:
	int val;
};
class C
{
	C(int i = 0) :c(i)
	{

	}
private:
	NoDefault c;
};
//��ϰ7.44 7.45 Nodefaultû��Ĭ�Ϲ��캯���� C��Ĭ�Ϲ��캯�����Բ��ᱨ��
//��ϰ7.46 ���û�й��캯�����ͻ�ʹ��Ĭ�ϵĺϳɹ��캯�������ĳ�����캯�����������βΣ�����ͬʱΪ��Щ�β��ṩĬ��ʵ�Σ�����Ҳ��Ĭ�Ϲ��캯��
//ÿһ���඼Ҫ����һ��Ĭ�Ϲ��캯�� ���ڱ������ϳɵ�Ĭ�Ϲ��캯���������Ա�����࣬��ô�Ͱ���Щ��ִ�и��������Ĺ��캯�����������ͺ͸������͵ĳ�Ա
//ֻ�Զ�����ȫ��������Ķ���ִ�г�ʼ��
string reverseWords(string s) {
	vector<string> vs;
	for (int i = 0; i < s.size(); i++)
	{
		string tmp;
		while (s[i] != ' ' && i < s.size())
		{
			tmp += s[i];
			i++;
		}
		
		vs.push_back(tmp);
	}
	

	string res;
	for (auto it = vs.rbegin(); it != vs.rend(); it++)
	{
		res = res + *it + ' ';
	}
	return res.substr(0, res.size() - 1);
}
//��ϰ 7.58
class Account
{
private:
	string strName;
	double aAmount = 0.0;
	static double dRate;
};
//��ϰ7.59 ���˾�̬������Ա֮�⣬������̬��Ա���������ڳ�ʼ��
int main()
{
	//explicit �������������͵���ʳת��
	//��ϰ7.52 ��
	//7.53�� 7.54��constexpr����ֻ���з�����䣬����set-�������������ݳ�Ա��ֵ 7.55 �ۺ��඼������ֵ����
	//7.56 ��̬��Աָ����ǰ�����static ����ĳ�Ա�����������κ�һ�����󣬶������������������еģ�
	//�ŵ㣺������λ����ķ�Χ֮�ڣ�������������ĳ�Ա��ȫ������������ֳ�ͻ��������˽�г�Ա������ȫ�ֱ����Ͳ����ԣ����Ҿ�̬��Ա������ΪĬ��ʵ��
	




}