#include"001.h"

//-------------------------------------ʵ�ּ�����---------------------------------------55��̬
//�ڿ����У�������µĹ��ܣ����ᳫ�Ķ�Դ����
//����ǿ������ԭ�򣬶���չ���ţ����޸Ĺر�
//calculator ������      substruct ����      multiply�˷�      divide����
//class Cal
//{
//public:
//	virtual int ans()
//	{
//		return 0;
//	}
//	int m_a;
//	int m_b;
//};
//class Add :public Cal
//{
//	int ans()
//	{
//		return m_a + m_b;
//	}
//};
//class Sub :public Cal
//{
//	int ans()
//	{
//		return m_a - m_b;
//	}
//};
//class Mul :public Cal
//{
//	int ans()
//	{
//		return m_a * m_b;
//	}
//};
//
//int main()
//{
//	Sub a1; Cal& c1 = a1;
//	c1.m_a = 11;
//	c1.m_b = 10;
//	cout << "m_a - m_b = " << c1.ans() << endl;
//
//	Cal*c2 = new Mul();
//	c2->m_a = 11;
//	c2->m_b = 10;
//	cout << "m_a * m_b = " << c2->ans() << endl;
//	delete c2; 
//
//	c2 = new Add();
//	c2->m_a = 11;
//	c2->m_b = 10;
//	cout << "m_a + m_b = " << c2->ans() << endl;
//	delete c2;
//	return 0;
//}

//-------------------------------------��Ʒ---------------------------------------57��̬

//class Drink
//{
//public:
//	virtual void boil() = 0;
//	virtual void brew() = 0;
//	virtual void putin() = 0;
//	virtual void putsth() = 0;
//	void make()
//	{
//		boil();
//		brew();
//		putin();
//		putsth();
//	}
//};
//class Coffee:public Drink 
//{
//public:
//	void boil()
//	{
//		cout << "c 100%" << endl;
//	}
//	void brew()
//	{
//		cout << "c quick quick" << endl;
//	}
//	void putin()
//	{
//		cout << "c slow slow" << endl;
//	}
//	void putsth()
//	{
//		cout << "c milk sugar" << endl;
//	}
//};
//void use(Drink*d1)
//{
//	d1->make();
//	delete d1;
//}
//int main()
//{
//	use(new Coffee);
//	return 0;
//}

//-------------------------------------������װ---------------------------------------60��̬

//class Cpu
//{
//public:
//	virtual void calculate() = 0;
//};
//class Videocard
//{
//public:
//	virtual void display() = 0;
//}; 
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
//class Com
//{
//public:
//	Com(Cpu* c1, Videocard* v1, Memory* m1)
//	{
//		m_c1 = c1;
//		m_v1 = v1;
//		m_m1 = m1;
//	}
//	void work()
//	{
//		m_c1->calculate();
//		m_v1->display();
//		m_m1->storage();
//	}
//	~Com()
//	{
//		if (m_c1 != NULL)
//		{
//			delete m_c1;
//			m_c1 = NULL;
//		}
//		if(m_v1 != NULL)
//		{
//			delete m_v1;
//			m_v1 = NULL;
//		}
//		if(m_m1 != NULL)
//		{
//			delete m_m1;
//			m_m1 = NULL;
//		}
//	}
//private:
//	Cpu* m_c1;//cpu
//	Videocard*m_v1;//�Կ�
//	Memory* m_m1;//�ڴ�
//};
//class InC:public Cpu
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Intel CPU Working!!!" << endl;
//	}
//};
//
//class InV :public Videocard
//{
//public:
//	virtual void display()
//	{
//		cout << "Intel VideoCard Working!!!" << endl;
//	}
//};
//class InM :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Intel Mermory Working!!!" << endl;
//	}
//}; 
//class LeC :public Cpu
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Lenovo CPU Working!!!" << endl;
//	}
//};
//
//class LeV :public Videocard
//{
//public:
//	virtual void display()
//	{
//		cout << "Lenovo VideoCard Working!!!" << endl;
//	}
//};
//class LeM :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Lenovo Mermory Working!!!" << endl;
//	}
//};
//
//void com1()
//{
//	Cpu* c1 = new InC();
//	Videocard* v1 = new InV();
//	Memory* m1 = new InM();
//	Com cc(c1, v1, m1);
//	cc.work();
//}
//
//void com2()
//{
//	cout << endl;
//	Cpu* c1 = new LeC();
//	Videocard* v1 = new LeV();
//	Memory* m1 = new LeM();
//	Com cc(c1, v1, m1);
//	cc.work();
//}
//
//int main()
//{
//	com1(); 
//	com2();
//	return 0;
//}


////-------------------------------------��������---------------------------------------04����ģ�尸��
//#include<algorithm>
//template<typename T>
//void myswap(T& a, T& b) {//����˳��
//	T t1 = a;
//	a = b;
//	b = t1;
//}
//template<typename T>
//void mysort(T *a, int sz) {//ѡ������
//	for (int i = 0; i < sz - 1; i++) {
//		int max = i;
//		for (int j = i+1; j < sz; j++) {
//			if (a[max] < a[j]) {
//				max = j;
//			}
//		}
//		myswap(a[max], a[i]);
//	}
//}
//template<class T>
//void show(T* a ,int sz) {//�����������
//	for (int i = 0; i < sz; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//int main()//����
//{
//	//int char���͵�����
//	int a1[] = { 1,2,3,4,5 };
//	int sz1 = sizeof(a1) / sizeof(a1[0]);
//	char a2[] = { 'a','b','c','d','e','f' };
//	int sz2 = sizeof(a2) / sizeof(a2[0]);
//	mysort(a1, sz1);
//	show(a1, sz1);
//	mysort(a2, sz2);
//	show(a2, sz2);
//	//string �������������
//	string a3[3] = { "aaa","vvv","zzz" };
//	int sz3 = sizeof(a3) / sizeof(a3[0]);
//	mysort(a3, sz3);
//	show(a3, sz3);
//	return 0;
//}

//-------------------------------------������ķ�װ---------------------------------------16��ģ�尸��
/*
���Զ��������������Լ��Զ����������͵����ݽ��д洢
�������е����ݴ洢������
���캯���п��Դ������������
�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
����ͨ���±�ķ�ʽ���������е�Ԫ��
���Ի�ȡ�����е�ǰԪ�ظ��������������
*/
//��Ŀ���ļ�exercise_01

//----------------------------------------STL����1---------------------------------------44��ί���
/*
* ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����
1. ��������ѡ�֣��ŵ�vector��
2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
4. deque��������һ�飬�ۼ��ܷ�
5. ��ȡƽ����
*/
//��Ŀ���ļ�exercise_02

//-------------------------------------list����------------------------------------------56������
/*
������������Person�Զ����������ͽ�������Person�����������������䡢���
������򣺰�����������������������ͬ������߽��н���
*/
//��Ŀ���ļ�exercise_03

//----------------------------------------STL����2---------------------------------------70Ա������
/*
  ��������
��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
�ֲ�����ʾԱ����Ϣ
  ʵ�ֲ���
1. ����10��Ա�����ŵ�vector��
2. ����vector������ȡ��ÿ��Ա���������������
3. ����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
4. �ֲ�����ʾԱ����Ϣ
*/
//��Ŀ���ļ�exercise_04