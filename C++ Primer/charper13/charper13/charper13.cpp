#include<string>
#include<iostream>
#include<vector>
using namespace std;
//13.1 ��һ�����캯���Ĳ����������������ã�����������������Ĭ��ֵ�Ļ�������������ǿ������캯��
//������ʼ���� ��=�� ��һ��������Ϊʵ�Σ����ݸ�һ�������õ��βε�ʱ��Ҳ���õ����Լ�һ�������ķ������Ͳ������õĻ���Ҳ����ÿ������캯��
//13.2 �������캯���Ĳ������봫�����ã���Ϊ����������õĻ����ڴ��ݸ��βε�ʱ�����ÿ������캯����Ȼ��ͻ�һֱ���ÿ������캯��
//13.3���ںϳɵĿ������캯��Ҫ���������const��Ա�������������͵ĳ�Ա��ֱ�ӽ����ڴ濽���������࣬Ҫ�����俽�����캯��
//13.4 = ���õ��������캯�������ҳ�ʼ��һ��point�����ʱ��Ҳ�õ��ˣ�����������ﷵ��һ�����������͵���Ҳ�õ���

//13.6������ֵ�����������ʵ�ֿ�����ֵ�ģ�����������󶨵�������thisָ�����棬�Ҳ����������������������ϣ������������и�ֵ�ǣ���ʹ�ÿ�����ֵ�����
//ͨ������£��ϳɵĿ������캯����Ѳ���static�ĳ�Ա�����ֵ��������ĳ�Ա��//���һ����û���Լ��Ŀ�����ֵ���������ô�ͻ���ñ�����Ĭ�����ɵ�
//13.7 ��ѳ�Աdata��ֵ����������������������sharedptr�����ü�����һ
//13.9 �����������������ͷŶ�����ʹ�õ���Դ�����ٷǾ�̬���ݵģ����һ����û����ʽ�Ķ���һ��������������ô���������Զ�����һ���ϳɵĹ��캯����
//����ϳɵĹ��캯������ʲô�����������պ�����ִ����󣬷Ǿ�̬��Ա�ᱻ������١�Ҳ��������������֮�������������׶��н������ٵ�
// 
//13.10 ���úϳɵ�����������data�����٣�����ָ�����ü�����-1 ��ָ��Ķ���Ҳ�ᱻ���� 
//13.11 ������һ���ĸ����� ��Ķ�����߲����ں������ý���֮�󶼻������������������������һ��ָ�����͵ģ�������ֻ��ָ��Ķ������������ָ��Ż���ʧ
//13.15 �������Ŷ����ظ��ģ��ϳɿ������캯�������ã����ϳɿ������캯����ֱ�Ӹ��Ƴ�Ա��
//13.16 �Լ������˿������캯��֮�󣬻������µ���ţ���������Ĳ���������ֵ���ݣ�ע����ֵ���ݵĹ����У�����ÿ������캯����������01234
//13.17 ���������ô��ݵ�ʱ��ͻ����������
//13,19 ��Ҫ������������Լ��Ŀ������캯�������ڸ���ʱ������úϳɵĿ������ƺ����������Ļ�����žͲ���Ψһ���ˣ���žͱ����ͬ��
//13.20 ��
//13.45 ��ֵ���ð󶨵�һ�����������ٵ�ֵ��ȥ����ֵ���þ��Ǹ�һ�������������Ҳ���ǳ������ã���ֵ���г־õ�״̬������ֵ�Ƕ��ݵ�
//13.46 r1����ֵ���ã���Ϊ�������ص���һ����ֵ r2����ֵ���ã���Ϊ�±����㷵�ص�����ֵ r3 ����ֵ����Ϊr1��һ������������������ֵ r4 ����ֵ����


class Hasptr
{
public:
	~Hasptr() {
		delete ps;
	}
	Hasptr(const std::string& s = std::string()) :ps(new std::string(s)), i(0)
	{

	}
	Hasptr(const Hasptr& ha)
	{
		ps = new std::string(*ha.ps);
		i = ha.i;
	}
	Hasptr& operator=(const Hasptr& ha)
	{
		auto news = new std::string(*ha.ps);
		delete ps;
		ps = news;
		i = ha.i;
		return *this;
	}
	string& operator*()
	{
		return *ps;
	}
private:
	std::string* ps;
	int i;
};
struct X
{
	X() { std::cout << "���캯��X" << std::endl; }
	X(const X&) {
		std::cout << "�������캯��" << std::endl;

	}
	X& operator=(const X& rhs)
	{
		std::cout << "������ֵ�����=��const X&��" <<std:: endl;
		return *this;
	}
	~X() { std::cout << "��������" << std::endl; }
};
class numbered
{
private:
	static int seq;
public:
	numbered() { mysn = seq++; }
	numbered(numbered& n) { mysn = seq++; }

	int mysn;
};
void f(numbered& s)
{
	cout << s.mysn << endl;
}
void f1(X x)
{

}
void f2(X& x)
{

}
class Employee
{
	
public:
	Employee() { mysn = number++; }
	Employee(const string& nam)
	{
		name = nam;
		mysn = number++;
	}
	Employee(Employee& e)
	{
		name = e.name;
		mysn = number++;
	}
	Employee& operator=(Employee& rhs)
	{
		name = rhs.name;
		return *this;
	}
	const string& getname()
	{
		return this->name;
	}

private:
	string  name;
	static int number;
	int mysn;
};
int main()
{
	X x;
	cout << endl;
	cout << "�����ò�������" << endl;
	f1(x);
	cout << endl;
	cout << "���ò�������" << endl;
	f2(x);
	cout << endl;
	cout << "��̬����" << endl;
	X* px = new X;
	cout << endl;
	cout << "��ӵ�������" << endl;
	vector<X> vx;
	vx.push_back(x);
	cout << endl;
	cout << "�ͷŶ�̬�������" << endl;
	delete px;
	cout << endl;
	cout << "��ӳ�ʼ���͸�ֵ" << endl;
	X y = x;
	y = x; cout << endl;
	
	
}