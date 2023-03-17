//15.1 ��������ӻ����м̳еĳ�Ա����Ҫ��д��ʱ���Ҫ�ѻ���������Ա��������Ϊ�麯��
//15.2 private�ĳ�Ա����������޷����ʣ�protected�ĳ�Ա��������Է���
//15.8 ��̬���;��Ǳ���ʱ��ȷ�������ͣ���̬����������ʱȷ�������ͱ��� Quote* o=new Bulk_quote �������Ǿ�̬���� ������ʱ���Ƕ�̬����
//15.9 �����ำֵ�������ʱ��
//�����ifstream �������� Ȼ�󴫵ݸ�����iotream
//15.13��һ�����basename��˽�еģ�
//15.12 �б�Ҫ
//15.14 
//15.17 ��������һ���������͵Ķ���
//����������ǹ��м̳У��û��������ʹ�������ൽ�����ת��
#include<string>
#include<iostream>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(string number, double book_price) :bookNo(number), price(book_price)
	{

	}
	string getbookNo() const
	{
		return bookNo;
	}
	virtual double net_price(int n) const
	{
		return n * price;
	}
	virtual ~Quote() = default;
	virtual void debug()
	{
		cout << bookNo << price << endl;
	}
	

	
protected:
	string bookNo;
	double price=0.0;
};

//class Bulk_quote :public Quote
//{
//public:
//	Bulk_quote(const string &book ,double p,int mm, double disc) :Quote(book,p),min_qty(mm), discount(disc)
//	{
//
//	}
//	 double net_price(int n) const override
//	{
//		 if (n > min_qty)
//		 {
//			 return n * (1 - discount) * price;
//		 }
//		 return n * price;
//	}
//	 virtual void debug()
//	 {
//		 Quote::debug();
//		 cout << min_qty << discount << endl;
//	 }
//private:
//	int min_qty;
//	double discount;
//};
double print_total(ostream& os, const Quote& item,int n)
{
	double ret = item.net_price(n);
	os << "ISBN" << item.getbookNo() << "sold" << n << "total due" <<ret<< endl;
	return ret;
}
//class Quote {
//public:
//	string isbn() const
//	{
//
//	}
//	virtual double net_price(int n) const;
//};
//class Bulk_quote :public Quote
//{
//public:
//	double net_price(int n) const override;
//};
class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double p, int quan, double disc) :Quote(book, p), quantity(quan), discount(disc)
	{

	}
	double net_price(int n) const = 0;
protected:
	int quantity = 0;
	double discount = 0;
};
class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, int quan, double disc) :Disc_quote(book, p, quan, disc)
	{

	}
	double net_price(int n) const override
	{

	}
};
class Base
{
public:
	void pub_mem(){}
protected:
	int prot_mem;
private:
	char priv_mem;
};
struct Pub_Derv :public  Base
{
	int f() const {
		return prot_mem;
	}
	void memfcn(Base& b)
	{
		b = *this;
	}
};
struct Priv_Derv :private Base
{
	int f1() const
	{
		return prot_mem;
	}
};
class figure
{
public:
	figure(double, double);
protected:
	double xSize, ySize;

};
class figture_2d :public figure
{
public:
	figture_2d(double, double);
	

	
	virtual double area() = 0;
	virtual double pcrimeter() = 0;



};
class figture_3d :public figure
{
public:
	figture_3d(double x = 0.0, double y = 0.0, double z = 0.0) :figure(x, y), zSize(z)
	{

	}
	virtual double cubage() = 0;
protected:
	double zSize;


};
class tran :public figture_2d
{
public:
	
	virtual double area() override
	{
		return xSize * ySize;
	}
	virtual double pcrimeter() override;
};
class circle :public figture_2d
{
public:
	circle(double, double);
	virtual double area() override
	{
		return xSize * ySize;
	}
	virtual double pcrimeter() override;

};
int main()
{
	Quote q("12", 12.0);
	Bulk_quote bq("12",12,1,0.1);
	//Disc_quote di("12", 12, 1, 0.1);
	print_total(cout, bq, 3);
}
