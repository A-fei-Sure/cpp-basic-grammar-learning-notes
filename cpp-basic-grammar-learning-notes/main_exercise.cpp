#include"001.h"

//-------------------------------------实现计算器---------------------------------------55多态
//在开发中，想添加新的功能，不提倡改动源代码
//而是强调开闭原则，对扩展开放，对修改关闭
//calculator 计算器      substruct 减法      multiply乘法      divide除法
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

//-------------------------------------饮品---------------------------------------57多态

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

//-------------------------------------电脑组装---------------------------------------60多态

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
//	Videocard*m_v1;//显卡
//	Memory* m_m1;//内存
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


////-------------------------------------数组排序---------------------------------------04函数模板案例
//#include<algorithm>
//template<typename T>
//void myswap(T& a, T& b) {//交换顺序
//	T t1 = a;
//	a = b;
//	b = t1;
//}
//template<typename T>
//void mysort(T *a, int sz) {//选择排序
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
//void show(T* a ,int sz) {//遍历输出数组
//	for (int i = 0; i < sz; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//int main()//降序
//{
//	//int char类型的排序
//	int a1[] = { 1,2,3,4,5 };
//	int sz1 = sizeof(a1) / sizeof(a1[0]);
//	char a2[] = { 'a','b','c','d','e','f' };
//	int sz2 = sizeof(a2) / sizeof(a2[0]);
//	mysort(a1, sz1);
//	show(a1, sz1);
//	mysort(a2, sz2);
//	show(a2, sz2);
//	//string 类型数组的排序
//	string a3[3] = { "aaa","vvv","zzz" };
//	int sz3 = sizeof(a3) / sizeof(a3[0]);
//	mysort(a3, sz3);
//	show(a3, sz3);
//	return 0;
//}

//-------------------------------------数组类的封装---------------------------------------16类模板案例
/*
可以对内置数据类型以及自定义数据类型的数据进行存储
将数组中的数据存储到堆区
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及operator=防止浅拷贝问题
提供尾插法和尾删法对数组中的数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获取数组中当前元素个数和数组的容量
*/
//项目打开文件exercise_01

//----------------------------------------STL案例1---------------------------------------44评委打分
/*
* 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分
1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分
*/
//项目打开文件exercise_02

//-------------------------------------list容器------------------------------------------56排序案例
/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/
//项目打开文件exercise_03

//----------------------------------------STL案例2---------------------------------------70员工分组
/*
  案例描述
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息
  实现步骤
1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
4. 分部门显示员工信息
*/
//项目打开文件exercise_04