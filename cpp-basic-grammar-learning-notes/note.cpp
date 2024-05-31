#include"001.h"
//----------------------------------------------------------------------------------运算符重载-- ‘ ++ ’ 
//class Per {
//	friend ostream& operator<<(ostream& cout,  Per& p);
//public:
//	Per()
//	{this->m_a = 10;
//	this->m_b = 15;}
//	Per& operator ++()
//	{
//		++this->m_a;
//		++this->m_b;
//		return *this;
//	}
//	Per operator ++(int)
//	{
//		Per temp = *this;
//		m_a++;
//		m_b++;
//		return temp;
//	}
//private:
//	int m_a;
//	int m_b;
//};
//
//ostream& operator<<(ostream& cout,  Per& p) {
//	cout << p.m_a << " " << p.m_b << endl;
//	return cout;
//}
//
//int main()
//{
//	Per p1;
//	cout << ++p1 << endl;
//	cout << p1++ << endl;
//	cout << p1 << endl;
//	return 0;
//}//该bug怎么解决：
/*在C++中，当你重载operator<<函数用于输出自定义类型时，通常会将对象作为const引用传递给该函数。
这样做主要有两个原因：一是为了提高效率，避免对象的拷贝；二是为了确保不会修改传递给输出运算符的对象。

你提到的代码中，operator<<函数的第二个参数是一个非const引用（Per &p），这意味着这个函数有潜在的能力去修改传递给它的参数。
但在你的main函数中使用operator<<时，遇到了如cout << p1++ << endl;这样的语句，其中p1++会调用后缀++运算符，返回一个临时的Per对象。
C++标准不允许非const引用绑定到临时对象上，因为这可能导致临时对象在引用它的作用域结束时被销毁，从而留下一个悬空引用。

而当operator<<的第二个参数改为不加引用，即直接传值（Per p），每次调用时都会创建对象的一个副本。这在效率上可能不是最优的，
但它解决了引用绑定到临时对象的问题，因为现在你是在对这个副本进行操作。不过，这并不是解决这个问题的推荐方式。

正确的做法是将operator<<函数的第二个参数定义为const引用，即const Per &p，这样既可以提高效率，又能保证函数不会修改对象，
同时还能接受临时对象作为参数。因此，修改后的operator<<声明应该是这样的：

friend ostream& operator<<(ostream& cout, const Per &p);
并且在实现时，确保不修改p对象的任何成员变量。这样，无论是直接对象、对象引用还是临时对象都可以安全地传递给operator<<函数。

*/

//--------------------------------------------------------------------------------------运算符重载-- ‘ = ’ 
//class Per{
//	friend void text01();
//public:
//	Per(int age)
//	{
//		m_age = new int(age);
//	}
//	Per&operator=(Per&p)
//	{//深拷贝，浅拷贝堆区的一段空间被重复
//		//释放两次(手写的析构函数干的)，出现问题
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		this->m_age = new int(*p.m_age);
//		return *this;
//	}
//	~Per() {
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//private:
//	int* m_age;
//};
//
//void text01()
//{
//	Per p1(18);
//	Per p2(20);
//	cout << *(p1.m_age) << endl;
//	p1 = p2;
//	cout<<*(p2.m_age)<<endl;
//	Per p3(25);
//	p1 = p2 = p3;//	Per&operator=(Per&p),用 void 不能连等
//	cout << *(p1.m_age) << endl;
//	cout << *(p2.m_age) << endl;
//	cout << *(p3.m_age) << endl;
//
//}
//int main()
//{
//	text01();
//	return 0;
//}

//----------------------------------------------------------------------------------------运算符重载-- ‘ == ’ 
//class Per
//{
//public:
//	Per(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(Per& p)
//	{
//		if (name == p.name && age == p.age)
//			return true;
//		else
//			return false;
//	}
//private:
//	string name;
//	int age;
//};
//
//void text01()
//{
//	Per p1("tom", 18);
//	Per p2("tom", 18);
//	if(p1==p2)
//		cout << "p1==p2" << endl;
//}
//
//int main()
//{
//	text01();
//	return 0;
//}

//------------------------------------------------------------------------------------------运算符重载-- ‘ () ’ 
//也叫做仿函数
//class mprint
//{
//public:
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//};
//void print(string test)
//{
//	cout << test << endl;
//}
//
//void text01()
//{
//	mprint m1;
//	m1("11123");//和下面的函数，你就说像不像吧
//	print("44456");//而且它很灵活，没有固定的写法
//	//因此，你甚至可以完成从下面的操作
//}
//
//class A
//{
//public:
//	int operator()(int a, int b) {
//		return a + b;
//	}//因为灵活，所以以后会经常用
//};
//
//void text02()
//{
//	A a1;
//	cout << a1(11, 12) << endl;
//	cout << A()(100, 100) << endl;//类型+()  -->  创建匿名对象
//	//匿名对象特点：改行执行完后，立即释放
//}
//
//	int main()
//	{
//		text01();
//		text02();
//	return 0;
//	}
//
//

//----------------------------------------------------------------------------------------------继承
//class A
//{
//private:
//	int a_1;
//protected:
//	int  a_2;
//public:
//	void print()
//	{
//		int a_1 = 10;
//		int a_2 = 15;
//		cout << a_1 << " " << a_2 << endl;
//	}
//};
//
//class B :public A 
//{
//	void print1()
//	{
//		int a_1 = 20;
//		int a_2 = 25;
//		cout << a_1 << " " << a_2 << endl;
//	}
//};
//
//int main()
//{
//	A a1;
//	a1.print();//可以，A类内可以访问自己的private属性的变量或方法
//	B b1;
//	b1.print();
//	//b1.print1();//报错 B(派生)类内，无法访问父类private类的变量或方法
//	return 0;//思考一下，protected的意义就在其中！
//}

//---------------------------------------------------------------------------------------------继承中的对象模型
//class Base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
//};
//
////公共继承
//class Son :public Base
//{
//public:
//	int m_D;
//};
//
//void test01()
//{
//	cout << "sizeof Son = " << sizeof(Son) << endl;
//}//16
//
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}//这里学了用开发人员命令提示工具瞅瞅 Son的内存模型
/*
使用方法：1.输入  D:  enter  转到D盘
2.输入  cd + 代码文件路径
3.加上   dir  enter
4.输入： cl   /d1   reportSingleClassLayout类名  "second.cpp"  enter
*/

//---------------------------------------------------------------------------------------------继承同名成员处理
//class Base {
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base - func()调用" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base - func(int a)调用" << endl;
//	}
//public:
//	int m_A;
//};
//
//class Son : public Base {
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
//	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
//	void func()
//	{
//		cout << "Son - func()调用" << endl;
//	}
//public:
//	int m_A;
//};
//
//void test01()
//{
//	Son s;//同名成员变量
//	cout << "Son下的m_A = " << s.m_A << endl;//直接调->调自己的
//	cout << "Base下的m_A = " << s.Base::m_A << endl;//调父类中的
//	s.func();//同名成员函数//直接调->调自己的
//	s.Base::func();//调父类中的
//	//s.func(10);//报错，当子类出现和父类同名的成员函数，
//	//子类同名成员会隐藏掉父类所有同名函数，所以找不到
//	s.Base::func(10);//想调用，要加作用域
//}
//int main() {
//	test01();
//	system("pause");
//	return EXIT_SUCCESS;
//}//静态的同名和普通的一样

//------------------------------------------------------------------------------------多继承
//class Base1 {
//public:
//	Base1()
//	{
//		m_A = 100;
//	}
//public:
//	int m_A;
//};
//
//class Base2 {
//public:
//	Base2()
//	{
//		m_A = 200;  //开始是m_B 不会出问题，但是改为mA就会出现不明确
//	}
//public:
//	int m_A;
//};
//
////语法：class 子类：继承方式 父类1 ，继承方式 父类2 
//class Son : public Base2, public Base1
//{
//public:
//	Son()
//	{
//		m_A = 999;
//		m_C = 300;
//		m_D = 400;
//	}
//public:
//	int m_A;
//	int m_C;
//	int m_D;
//};
//
////多继承容易产生成员同名的情况
////通过使用类名作用域可以区分调用哪一个基类的成员
//int main() {
//	Son s;
//	cout << "sizeof Son = " << sizeof(s) << endl;
//	cout << s.Base1::m_A << endl;
//	cout << s.Base2::m_A << endl;
//	cout << s.m_A << endl;
//	system("pause");
//	return 0;
//}

//-------------------------------------------------------------------------------------菱形继承
//class A {
//public:
//	int m_a;
//};
//class B: public A{};
//class C: public A{};
//
//class D:public B,public C{};
//
//int main() 
//{
//	//菱形继承，需加以作用域区分
//	//数据有一份就行，两份数据造成资源浪费
//	D d1;
//	d1.B::m_a = 12;
//	d1.C::m_a = 13;
//	cout << "B" << d1.B::m_a << endl;//用开发人员命令提示工具，结构图藏在大段文字之中
//	cout << "C" << d1.C::m_a << endl;//老师的是正常的，不知道为啥，这段代码一用多了一大段话
//	return 0;//但是代码应该是没问题的，文字中也有正确的结构图
//}

//-------------------------------------------------------------------------------------菱形继承解决：用 虚继承
//class A {
//public:
//	int m_a;
//};
//class B : virtual public A {};
//class C : virtual public A {};
//
//class D :public B, public C {};
//
//int main()
//{
//	D d1;
//	d1.B::m_a = 12;
//	d1.C::m_a = 13;
//	cout << "B" << d1.B::m_a << endl;
//	cout << "C" << d1.C::m_a << endl;
//	cout << "D" << d1.m_a << endl;
//	return 0;
//}
/*
* 开发人员命令提示工具中搞得
class D size(12):
		+---
 0      | +--- (base class B)
 0      | | {vbptr}//virtual base pointer指向vbtable,vbtable记录偏移量，
 //最终找到唯一的数据，虚继承通过这样的方式节约了资源
		| +---
 4      | +--- (base class C)
 4      | | {vbptr}
		| +---
		+---
		+--- (virtual base A)
 8      | m_a
		+---
*/

//----------------------------------------------------------------------------------------------------------多态
/*
   多态分为两类
* 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
* 动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
* 静态多态的函数地址早绑定  -  编译阶段确定函数地址
* 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
*/

//class An
//{
//public:
//	//Speak函数就是虚函数
//	//函数前面加上virtual关键字，变成虚函数
//	//这样  函数地址早绑定- 编译阶段确定函数地址----->函数址晚绑定-运行阶段确定函数地址
//	virtual void speak()
//	{
//		cout << "动物在说话......." << endl;
//	}
//};
//
//class Cat:public An
//{
//public:
//	void speak()//可加virtual，可不加，因为C++规定，一个基类的成员函数被声明为虚函数，
//	{//其派生类中的同名函数自动成为虚函数。
//		cout << "喵喵喵~" << endl;
//	}
//};
//
//class Dog :public An
//{
//public:
//	void speak()
//	{
//		cout << "汪汪汪！" << endl;
//	}
//};
//
//void dospeak(An &a1)//An &a1 = cat;
//{
//	a1.speak();
//}
//
//void text01()
//{
//	Cat cat;
//	dospeak(cat);
//	Dog dog;
//	dospeak(dog);
//}
//
//int main()
//{
//	text01();
//	return 0;
//}

//动态多态满足条件：
//1、有继承关系
//2、子类重写父类中的虚函数（函数名除virtual外相同）
// （返回值 函数名 参数类型都一样）
//3、父类指针或引用指向子类对象


//----------------------------------------------------------------------------------------------------------纯虚函数 & 抽象类

//当类中有了纯虚函数，这个类也称为 == 抽象类 ==
//** 抽象类特点** ：
//* 无法实例化对象
//* 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

//class Base
//{
//public:
//	virtual void print(int a) = 0;
//	int m_a;
//};
//class Son : public Base
//{
//public:
//	void print(int a)
//	{
//		m_a = a;
//		cout << "m_a = " << m_a << endl;
//	}
//};
//class Son2 :public Base
//{};
//int main()
//{
//	Son s1;
//	Base* b1 = &s1;
//	b1->print(12);
//	//Base b2;
//	//Son2 s1;
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------虚析构和纯虚析构

/*
虚析构和纯虚析构共性：
* 可以解决父类指针释放子类对象
* 都需要有具体的函数实现

虚析构和纯虚析构区别：
* 如果是纯虚析构，该类属于抽象类，无法实例化对象

 总结：
​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
​	3. 拥有纯虚析构函数的类也属于抽象类
*/

//class An
//{
//public:
//	virtual void speak() = 0;
//	An()
//	{
//		cout << "An() used" << endl;
//	}
//	//如果没有virtual，不会调用~Cat析构，导致内存无法完全释放
//	/*virtual ~An()
//	{
//		cout << "~An() used" << endl;
//	}*/
//	virtual ~An() = 0;//纯虚析构写法，需要在类外有具体的实现
//};//因为父类可能也会在堆区开辟数据，可能会调用这段代码，所以不能啥都不写
//An::~An()
//{
//	cout << "纯~An() used";
//}
//class Cat :public An
//{
//public:
//	Cat(string name)
//	{
//		cout << "Cat() used" << endl;
//		c_name = new string(name);
//	}
//	virtual void speak()
//	{
//		cout << *c_name << " Cat speaking" << endl;
//	}
//	string*c_name;
//	~Cat()
//	{
//		cout << "~Cat() used" << endl;
//		if (c_name != NULL)
//		{
//			delete c_name;
//			c_name = NULL;
//		}
//	}
//};
//
//int main()
//{
//	An* a1 = new Cat("Tom");
//	a1->speak();
//	delete a1;
//	return 0;
//}


//----------------------------------------------------------------------------------------------------------文件操作
//--------------------------------------------------------------------------------------写文件
//#include<fstream>//1.头文件
//int main()
//{
//	ofstream ofs;//2.创建对象
//	ofs.open("text.txt", ios::out);//3.打开文件--写
//	ofs << "姓名：张三" << endl;//4.写内容
//	ofs << "性别：男" << endl;
//	ofs << "年龄：18" << endl;
//	ofs.close();//5.关闭文件
//	//默认text文件和项目文件开在一起
//	return 0;
//}

//--------------------------------------------------------------------------------------读文件
//#include<fstream>//1.头文件
//int main()
//{
//	ifstream ifs;//2.创建对象
//	ifs.open("text.txt", ios::in);//3.打开文件--读
//	if (! ifs.is_open())//4.判断文件是否打开成功
//	{
//		cout << "文件打开失败" << endl;
//		return 0;
//	}
//	//5.读数据
//	//第一种
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//	//第二种
//	/*char buf[1024];
//	while (ifs.getline(buf, sizeof(buf)))
//	{
//		cout << buf << endl;
//	}*/
//	//第三种
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//	//第四种
//	char c;
//	while ((c = ifs.get()) != EOF)
//	{
//		cout << c;
//	}
//	ifs.close();//6.关闭文件
//	return 0;
//}

//注意：头文件只有一个 <fstream>
//操作文件的类有3个
//1. ofstream：写操作
//2. ifstream： 读操作
//3. fstream ： 读写操作

//------------------------------------------------------------------------------------二进制写文件
//#include<fstream>
//class Per
//{
//public:
//	char m_name[64];//用string可能会出现点问题
//	int m_age;
//};
//int main()
//{
//	ofstream ofs;//ofstream是写入，用fstream也行，表示可写可看
//	ofs.open("text1.txt", ios::binary | ios::out);
//	//ofstream ofs("text.txt", ios::binary | ios::out);//上面两步可合写为这样一步
//	Per p1 = {"张三",18};
//	ofs.write((const char*)&p1, sizeof(Per));//二进制可以写入自定义的类
//	ofs << "aaa" << endl;
//	ofs.close();
//	return 0;
//}

//------------------------------------------------------------------------------------二进制读文件
//class Per
//{
//public:
//	char m_name[64];//用string可能会出现点问题
//	int m_age;
//};
//#include<fstream>
//int main()
//{
//	ifstream ifs;
//	ifs.open("text1.txt", ios::binary | ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return 0;
//	}
//	Per p1;
//	ifs.read((char*)&p1, sizeof(p1));
//	cout << p1.m_name << endl;
//	cout << p1.m_age << endl;
//	char buf[64];
//	while (ifs >> buf)
//	{
//		cout << buf;
//	}
//	ifs.close();
//	return 0;
//}


//--------------------------------------------------------------------------------------------------------02函数模板
//函数模板
//模板时为了提高代码的复用性，将类型参数化
//template<typename T>//要声明一个模板啦  T是一个通用的数据类型
//void myswap(T& a, T& b)//在后面跟着第一个函数中声明一个模板
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 11, b = 12;
//	//两种实现函数模板的方式
//	//1.自动类型推导
//	myswap(a, b);//传的是变量，不能是常量
//	cout << a << " " << b << endl;
//	//2.显式指定类型
//	myswap<int>(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//--------------------------------------------------------------03函数模板注意事项
//1.自动类型推导，必须推导出一致的数据类型T, 才可以使用
//2.模板必须要确定出T的数据类型，才可以使用
//template<typename T>
//void myswap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//template<typename T>
//void print() {
//	cout << "hello fuck" << endl;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	char c = '#';
//	myswap(a, b);
//	//myswap(a, c);//1
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//	//print();//2
//	print<double>();//编译器自动类型推导不知道推导出什么
//	return 0;//所以只能自己随便指定一个类型。让程序跑起来
//}

//--------------------------------------------------------------05普通函数与函数模板的区别
//1.普通函数调用时可以发生自动类型转换（隐式类型转换）
//2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//3.如果利用显示指定类型的方式，可以发生隐式类型转换
//int add(int a, int b) {
//	return a + b;
//}
//template<typename T>
//T add1(T  a, T b) {
//	return a + b;
//}
//int main()
//{
//	int a = 10, b = 20;
//	char c = 'c';
//	cout << add(a, b) << endl;
//	cout << add(a, c) << endl; cout << endl;
//
//	cout << add1(a, b) << endl;
//	//cout << add1(a, c) << endl;//有bug  说明2
//	cout << add1<int>(a, c) << endl;
//	return 0;
//}


//---------------------------------------------------------------------------06普通函数与函数模板调用规则
/*
规则：
1. 如果函数模板和普通函数都可以实现，优先调用普通函数
2. 可以通过空模板参数列表来强制调用函数模板
3. 函数模板也可以发生重载
4. 如果函数模板可以产生更好的匹配,优先调用函数模板
*/
//void show(int a, int b){
//	cout << "调用普通函数" << endl;
//}
//
//template<typename T>
//void show(T a, T b){
//	cout << "调用函数模板" << endl;
//}
//
//template<typename T>
//void show(T a) {
//	cout << "调用重载的函数模板" << endl;
//}
//
//int main() {
//	int a = 10, b = 20;
//	show(a, b);     //1.优先调用普通函数
//	show<>(a, b);//2.通过空模板参数列表来强制调用函数模板
//	show(a);        //3.函数模板也可以发生重载
//
//	char x = 'x', y = 'y';//（这个理论上可以先隐式类型转换，在调用普通的show，但是函数模板的匹配编译器觉得更简单）
//	show(x, y);     //4.如果函数模板可以产生更好的匹配, 优先调用函数模板
//	return 0;
//}
//！！！！！实际开发不要这样搞了(别模板普通的一起写)，易出错！！！！！


//----------------------------------------------------------------------------------------07模板的局限性
//模板不是万能的
//eg : 写一个函数模板，函数内部写p1<p2，如果p1，p2为Person类，这个代码就错了
//类似情况还有a=b;（a，b为数组）等
//C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模

//class Person {
//public:
//	Person(string n, int a) :name(n), age(a) {}
//	string name;
//	int age;
//	//解决p1==p2法一：重载==运算符
//	/*bool operator==(Person &p) {
//		if (this->name == p.name && this->age == p.age) {
//			return true;
//		}
//		else return false;
//	}*/
//};
//
//template<typename T>
//bool myCompare(T& a, T& b) {
//	if (a == b)return true;
//	else return false;
//}
//
//
//
////法二：利用具体化Person的版本实现代码，具体化优先调用
//template<> bool myCompare(Person& p1, Person& p2) {
//	if (p1.name == p2.name && p1.age == p2.age)
//		return true;
//	else
//		return false;
//}
//
//int main() {
//	int a = 10, b = 20;
//	if (myCompare(a, b))
//		cout << "a == b" << endl;
//	else
//		cout << "a != b" << endl;
//
//	Person p1("Tom", 12);
//	Person p2("Tom", 12);
//	if (myCompare(p1, p2))
//		cout << "p1 == p2" << endl;
//	else
//		cout << "p1 != p2" << endl;
//	return 0;
//}
/*
利用具体化的模板，可以解决自定义类型的通用化
学习模板并不是为了写模板，而是在STL能够运用系统提供的模板
*/


//-----------------------------------------------------------------------------------------------------------------------08 类模板基本语法
/*
 类模板作用：
建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
*/
//template<typename nameType, typename ageType >//写typename & class都行
//class Person {
//public:
//	Person(nameType name, ageType age) :name(name), age(age) {}
//	void showPerson() {
//		cout << "name: " << this->name << endl;
//		cout << "age: " << this->age << endl;
//	}
//	nameType name;
//	ageType age;
//};
//
//
//int main() {
//	Person<string, int>p1("ikun", 18);
//	p1.showPerson();
//	Person<char, string>p2('w', "9981");
//	p2.showPerson();
//	return 0;
//}

//--------------------------------------------------------------------------------------------09 类模板和函数模板区别
/*
1. 类模板没有自动类型推导的使用方式
2. 类模板在模板参数列表中可以有默认参数
*/
//template<class nT, class aT = int>//2.
//class Per {
//public:
//	Per(nT n, aT a) :name(n), age(a) {}
//	void showPer() {
//		cout << "name: " << this->name << endl;
//		cout << "age: " << this->age << endl;
//		cout << endl;
//	}
//	nT name;
//	aT age;
//};
//int main() {
//	//Per p1("孙悟空", 10000);//错误，无法自动类型推导//1.
//	Per<string, int>p1("孙悟空", 10000);//正确，只能用显示指定类型
//	p1.showPer();
//	Per<string>p2("猪八戒", 9999);//2.
//	p2.showPer();
//	return 0;
//}

//--------------------------------------------------------------------------------------------10 类模板中成员函数创建时机
/*
普通类中的成员函数一开始就可以创建
类模板中的成员函数在调用时才创建
*/
//class Per1 {
//public:
//	void showPer1() {
//		cout << "show Per1" << endl;
//	}
//};
//
//class Per2 {
//public:
//	void showPer2() {
//		cout << "show Per2" << endl;
//	}
//};
//
//template<class T>
//class myClass {
//public:
//	T obj;
//	void func1() {//只要不调用，就不创建
//		obj.showPer1();
//	}
//	void func2() {//只要不调用，就不创建
//		obj.showPer2();
//	}
//};
//
//int main() {
//	//代码不报错可以证明以上结论，如果函数是提前创建的，必会出错
//	myClass<Per1>m1;
//	m1.func1();
//	//m1.func2();调用的时候func2创建了，obj没有showPer2成员函数，故报错
//	myClass<Per2>m2;
//	m2.func2();
//	return 0;
//}

//--------------------------------------------------------------------------------------------11 类模板对象做函数参数
/*
三种传入方式：
1. 指定传入的类型 --- 直接显示对象的数据类型
2. 参数模板化 --- 将对象中的参数变为模板进行传递
3. 整个类模板化 --- 将这个对象类型 模板化进行传递
*/
//template<class T1, class T2>
//class Per {
//public:
//	Per(T1 name, T2 age) :name(name), age(age) {}
//	void showPer() {
//		cout << "name: " << this->name << endl;
//		cout << "age: " << this->age << endl;
//		cout << endl;
//	}
//	T1 name;
//	T2 age;
//};
//
////1. 指定传入的类型   //常用
//void printPer1(Per<string, int>& p) {
//	p.showPer();
//}
//
////2. 参数模板化
//template<class T1, class T2>
//void printPer2(Per<T1, T2>& p) {
//	//获取T1的类型
//	cout << "T1的类型：" << typeid(T1).name() << endl;//将T1的类型以字符串的形式返回
//	cout << "T2的类型：" << typeid(T2).name() << endl;//将T2的类型以字符串的形式返回
//	p.showPer();
//}
//
////3. 整个类模板化
//template<class T>
//void printPer3(T& p) {
//	cout << typeid(T).name() << endl;
//	p.showPer();
//}
//
//int main() {
//	Per<string, int>p1("大佬", 666);
//	printPer1(p1);//1.
//	printPer2(p1);//2.
//	printPer3(p1);//3.
//	return 0;
//}

//--------------------------------------------------------------------------------------------12 类模板与继承
/*
当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
如果不指定，编译器无法给子类分配内存
如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
//template<class T>
//class Base {
//public:
//	T m;
//};
//
//class Son1 :public Base<int> {
//};//1.
//
//template<class T, class T1>
//class Son2 :public Base<T> {//2.
//public:
//	Son2() {
//		cout << "T的类型为: " << typeid(T).name() << endl;
//		cout << "T1的类型为" << typeid(T1).name() << endl;
//		this->obj = 'a';
//		this->m = 66;
//	}
//	void showSon2() {
//		cout << "obj: " << this->obj << endl;
//		cout << "m: " << this->m << endl;
//	}
//	T1 obj;
//};
//
//int main() {
//	Son1 s1;
//	Son2 <int, char>s2;
//	s2.showSon2();
//	return 0;
//}

//--------------------------------------------------------------------------------------------12  类模板成员函数类外实现
//template<class T1,class T2>
//class Per {
//public:
//	Per(T1 name, T2 age);
//	void showPer();
//	T1 name;
//	T2 age;
//};
////构造函数写法
//template<class T1, class T2>
//Per<T1, T2>::Per(T1 name, T2 age) {
//	this->age = age;
//	this->name = name;
//}
////成员函数写法
//template<class T1, class T2>
//void Per<T1, T2>::showPer()
//{
//	cout << "name: " << this->name << endl;
//	cout << "age: " << this->age << endl;
//}
//int main() {
//	Per<string, int>p("kunkun", 18);
//	p.showPer();
//	return 0;
//}

//--------------------------------------------------------------------------------------------12   类模板分文件编写
/*
问题：
类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到
解决：
解决方式1：直接包含.cpp源文件(包含写函数的cpp文件 eg: #include"002.cpp")
(这里只包含.cpp文件，但.cpp文件包含有.h文件，等于是也包含了.h文件)(也可以分别包含.cpp和.h，基本原理一样)
解决方式2（推荐）：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
*/

//--------------------------------------------------------------------------------------------13类模板与友元
/*
全局函数类内实现 - 直接在类内声明友元即可
全局函数类外实现 - 需要提前让编译器知道全局函数的存在
*/

//提前让编译器知道Per类的存在
//template<class T1, class T2>
//class Per;
////全局函数类外实现
//template<class T1, class T2>//先写最上方，让编译器提前看到
//void showPer02(Per<T1, T2>& p) {
//	cout << "类外实现" << endl;
//	cout << "name: " << p.name << endl;
//	cout << "age: " << p.age << endl;
//}
//
////通过全局函数，打印Per信息
//template<class T1,class T2>
//class Per {
//	//全局函数类内实现
//	friend void showPer01(Per<T1, T2>& p) {
//		cout << "类内实现" << endl;
//		cout << "name: " << p.name << endl;
//		cout << "age: " << p.age << endl;
//	}
//	//全局函数类外实现
//	//加一个空模板参数列表
//	friend void showPer02<>(Per<T1, T2>& p);
//public:
//	Per(T1 name, T2 age);
//private:
//	T1 name;
//	T2 age;
//};
//
////构造函数写法
//template<class T1, class T2>
//Per<T1, T2>::Per(T1 name, T2 age) {
//	this->age = age;
//	this->name = name;
//}
//
//int main() {
//	Per<string, int>p("kunkun", 18);
//	showPer01(p);
//	showPer02(p);
//	return 0;
//}




//------------------------------------------------------------------------------------20vector存内置数据类型
//#include<iostream>
//#include<vector>
//#include<algorithm>//标准算法头文件
//using namespace std;
//void myprint(int val)
//{
//	cout << val << " ";
//}
//int main()
//{
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	//遍历1
//	//vector<int>::iterator itBegin = v.begin();//容器第一个元素
//	//vector<int>::iterator itEnd = v.end();//容器最后一个元素下一个位置
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << " ";
//	//	itBegin++;
//	//}
//	//遍历2
//	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}*/
//	for_each(v.begin(), v.end(), myprint);
//	return 0;
//}
//

//-----------------------------------------------------------------------------21vector存自定义数据类型
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>//标准算法头文件
//using namespace std;
//class Per
//{
//public:
//	int m_age;
//	string m_name;
//	Per(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//};
//
//void print(Per p1)
//{
//	cout << "姓名：" << p1.m_name << "\t";
//	cout << "年龄：" << p1.m_age << endl;
//}
//int main()
//{
//	vector<Per>v1;
//	Per p1("aaa", 111);
//	Per p2("bbb", 222);
//	Per p3("ccc", 333);
//	Per p4("ddd", 444);
//	Per p5("eee", 555);
//	//向容器中添加数据
//	v1.push_back(p1);
//	v1.push_back(p2);
//	v1.push_back(p3);
//	v1.push_back(p4);
//	v1.push_back(p5);
//	for (vector<Per>::iterator it = v1.begin(); it < v1.end(); it++)
//	{
//		cout << "姓名：" << it->m_name << "\t";
//		cout << "年龄：" << (*it).m_age << endl;
//	}
//	for_each(v1.begin(), v1.end(), print);
//	return 0;
//}

//--------------------------------------------------------------22vector嵌套(模拟辣二维数组)
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<vector<int>>v;
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	for (int i = 1; i <= 5; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 3);
//		v3.push_back(i + 6);
//	}
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	for (vector<vector<int>>::iterator it = v.begin(); it < v.end(); it++)
//	{
//		for (vector<int>::iterator it1 = (*it).begin(); it1 < (*it).end(); it1++)
//		{
//			cout << *it1 << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//-----------------------------------------------------------------------------------------23string 构造函数
/*
构造函数原型：
string();                              //创建一个空的字符串 例如: string str;
string(const char* s);       //使用字符串s初始化
string(const string& str); //使用一个string对象初始化另一个string对象
string(int n, char c);          //使用n个字符c初始化
*/
//int main() {
//	string s1;//默认构造//1.
//
//	const char* str = "aabbccddee";//2.
//	string s2(str);
//	cout << "s2= " << s2 << endl;
//
//	string s3(s2);//3.
//	cout << "s3= " << s3 << endl;
//
//	string s4(10, 'a');
//	cout << "s4= " << s4 << endl;
//	return 0;
//}

//-----------------------------------------------------------------------------------------24string 赋值操作
/*
赋值的函数原型：
string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s); //把字符串s赋给当前的字符串
string& operator=(char c); //字符赋值给当前的字符串
string& assign(const char *s); //把字符串s赋给当前的字符串
string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s); //把字符串s赋给当前字符串
string& assign(int n, char c); //用n个字符c赋给当前字符串
*/
//int main() {
//	string s1;
//	s1 = "hello fuck";//字符串默认类型(const char*)//1.
//	cout << "s1= " << s1 << endl;
//
//	string s2;
//	s2 = s1;//2.
//	cout << "s2= " << s2 << endl;
//
//	string s3;
//	s3 = 'a';//3.
//	cout << "s3= " << s3 << endl;
//
//	string s4;
//	s4.assign("aaa");//4.
//	cout << "s4= " << s4 << endl;
//	s4.assign("bbbbb", 2);//5.
//	cout << "s4= " << s4 << endl;
//	s4.assign(s3);//6.
//	cout << "s4= " << s4 << endl;
//	s4.assign(10, 'c');//7.
//	cout << "s4= " << s4 << endl;
//	return 0;
//}

//-----------------------------------------------------------------------------------------25string字符串拼接
/*
string& operator+=(const char* str); //重载+=操作符
string& operator+=(const char c); //重载+=操作符
string& operator+=(const string& str); //重载+=操作符
string& append(const char *s); //把字符串s连接到当前字符串结尾
string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s); //同operator+=(const string& str)
string& append(const string &s, int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾
//理解为下标pos开始(包含pos)，截取n个
*/
//int main() {
//	string s1 = "我";
//	s1 += "真是个大帅哥";//1.
//	cout << "s1= " << s1 << endl;
//	s1 += '!';
//	cout << "s1= " << s1 << endl;
//	s1 += s1;//3.
//	cout << "s1= " << s1 << endl;
//
//	string s2 = "我";
//	s2.append("真是个大帅哥");
//	cout << "s2= " << s2 << endl;//....
//	return 0;
//}

//-----------------------------------------------------------------------------------------26 string查找和替换
/*
功能描述：
查找：查找指定字符串是否存在
替换：在指定的位置替换字符串
函数原型：
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//---包含下标pos，输出子串首元素在主串中的下标
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//---返回类型为string，且调用该方法的string类型对象的数据发生了改变
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
*/


//-----------------------------------------------------------------------------------------27 string字符串比较
/*
字符串比较是按字符的ASCII码进行对比
= 返回 0
> 返回 1
< 返回 -1//第一个字符串<第二个字符串，函数返回-1
函数原型：
int compare(const string &s) const; //与字符串s比较
int compare(const char *s) const; //与字符串s比较
*/

//-----------------------------------------------------------------------------------------28string字符存取
/*
string中单个字符存取方式有两种
char& operator[](int n); //通过[]方式取字符
char& at(int n); //通过at方法获取字符
*/

//-----------------------------------------------------------------------------------------29 string插入和删除
/*
函数原型：
string& insert(int pos, const char* s); //插入字符串//在下标pos前
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c); //在指定位置插入n个字符c
string& erase(int pos, int n = npos); //删除从Pos开始的n个字符//包含下标pos位置的数据
*/

//-----------------------------------------------------------------------------------------30 string子串
/*
string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
//包含下标pos
*/



/*
**************************************各容器操作时间复杂度总结******************************************************************
* 1. set、multiset、map、multimap
特点：底层实现是红黑树，键值有序，set 和 map 键不可重复，而 multiset 和 multimap 可重复；
复杂度：插入、删除、查找都为O(logN)；

2. unordered_set，unordered_map，unordered_multiset，unordered_multimap
特点：底层实现是哈希表，键值无序，unordered_set 和 unordered_map 键不可重复，而另外两个可以重复；
复杂度：插入、删除、查找平均为O(1)，最坏为O(N)，空间换时间；

3. vector
特点：底层实现是数组，动态成倍扩容；
复杂度：
插入：push_back()，O(1)；insert()，O(N)
删除：pop_back()，O(1)；erase()，O(N)
查找：O(1)

4. list
特点：底层实现双向链表；
复杂度：
插入：push_front()，O(1)；push_back()，O(1)；insert()，O(1)
删除：pop_front()，O(1)；pop_back()，O(1)；erase()，O(1)
查找：O(N)

5. deque 双端队列
特点：底层是分段连续的线性空间，它是一种具有队列和栈的性质的数据结构，其插入和删除操作限定在两端进行；
复杂度：
插入：push_front()，O(1)；push_back()，O(1)；insert()，O(N)
删除：pop_front()，O(1)；pop_back()，O(1)；erase()，O(N)
查找：O(1)

6. stack 栈
特点：底层实现一般用 list 或 deque，封闭头部即可，数据先进后出，不支持随机访问；
复杂度：
插入：push()，O(1)
删除：pop()，O(1)
查找（栈顶）：top()，O(1)

7. queue 队列
特点：底层实现一般用 list 或 deque，数据先进先出，不支持随机访问；
复杂度：
插入：push()，O(1)
删除：pop()，O(1)
查找（队列头）：front()，O(1)

8. priority_queue 优先队列
特点：底层用堆实现，队列中各个元素被赋予优先级；
复杂度：
插入：push()，O(logN)
删除：pop()，O(logN)
查找（取堆顶）：top()，O(1)
* 
* ******************************************************************************************************************
*/



////--------------------------------------------------------------31vector构造函数
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//void test01(vector<int>& v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	//默认构造
//	vector<int> v1;
//	for (int i = 1; i <= 5; i++)
//		v1.push_back(i);
//	test01(v1);
//
//	//利用区间的方式
//	vector<int>v2(v1.begin(), v1.end());
//	test01(v2);
//
//	//n个elem方式构造
//	vector<int>v3(10, 100);//10个100
//	test01(v3);
//
//	//拷贝构造
//	vector<int>v4(v1);
//	test01(v4);
//	return 0;
//}


//--------------------------------------------------------------32vector赋值
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
//using namespace std;
//void printVector(vector<int>& v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	vector<int> v1;
//	for (int i = 1; i <= 5; i++)
//		v1.push_back(i);
//	printVector(v1);

//	//operator =
//	vector<int> v2 = v1;
//	printVector(v2);

//	//assign
//	vector<int>v3;
//	v3.assign(v1.begin(), v1.end());
//	printVector(v3);

//	//n个elem方式赋值
//	vector<int>v4;
//	v4.assign(10, 100);
//	printVector(v4);
//	return 0;
//}

//--------------------------------------------------------------33vector容量和大小
//----------------   ：size  capacity  empty  resize
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
//using namespace std;
//void printVector(vector<int>& v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	vector<int>v1;
//	 for (int i = 1; i <= 5; i++)
//			v1.push_back(i);
//	 printVector(v1);
//	 if (v1.empty())//为真代表为空
//		 cout << "2空哒！" << endl;
//	 else
//	 {
//		 cout << "不是空哒！" << endl;
//		 cout << "v1的容量" << v1.capacity() << endl;// capacity >= size
//		 cout << "v1的大小" << v1.size() << endl;
//	 }
//	 cout << "------重置大小------" << endl;
//	 v1.resize(15 , 666);//多的用666填充，后面这个传参不写默认用0填充
//	 cout << "v1的容量" << v1.capacity() << endl;// capacity >= size
//	 cout << "v1的大小" << v1.size() << endl;
//	 printVector(v1);
//	 v1.resize(10);//填充的短了，多余的就没啦！
//	 printVector(v1);
//	return 0;
//}

//--------------------------------------------------------------34vector插入和删除
//----------------   ：push_back  pop_back  insert  erase  clear
//#include<iostream>
//#include<algorithm>
//#include<string>
//#include<vector>
//using namespace std;
//void printVector(vector<int>& v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	vector<int>v1;
//	//头插
//	for (int i = 1; i <= 5; i++)
//		v1.push_back(i);
//	printVector(v1);
//
//	//头删
//	v1.pop_back(); v1.pop_back();
//	printVector(v1);
//
//	//两种插入
//	v1.insert(v1.begin(), 100);//第一个元素 前 插入
//	printVector(v1);
//	v1.insert(v1.begin() + 1, 2, 5);//第二个元素 前 插入2个5
//	printVector(v1);
//
//	//两种删除
//	v1.erase(v1.begin());//删第一个  100
//	printVector(v1);
//	v1.erase(v1.begin(), v1.begin() + 1);//也是只删第一个
//	printVector(v1);
//	v1.erase(v1.begin(), v1.end());//等于是将容器清空
//	if (v1.empty())cout << "空啦" << endl;
//
//	//清空
//	for (int i = 1; i <= 5; i++)
//		v1.push_back(i);
//	printVector(v1);
//	v1.clear();
//	if (v1.empty())cout << "空啦" << endl;
//	return 0;
//}


//--------------------------------------------------------------35vector数据存取
//#include<algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//		vector<int>v1;
//		for (int i = 1; i <= 5; i++)
//			v1.push_back(i);
//
//		//以[ ]方式访问数组中元素
//		for (int i = 0; i < v1.size(); i++)
//			cout << v1[i] << " ";
//		cout << endl;
//
//		//以at的方式访问
//		for (int i = 0; i < v1.size(); i++)
//			cout << v1.at(i) << " ";
//		cout << endl;
//
//		//front获取第一个元素
//		cout << "first one : " << v1.front() << endl;
//
//		//back获取最后一个元素
//		cout << "last one : " << v1.back() << endl;
//	return 0;
//}

//--------------------------------------------------------------36vector互换容器
//#include<algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//void printVector(vector<int> v1)
//{
//	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	cout << "交换前：" << endl;
//	vector<int>v1;
//	for (int i = 1; i <= 5; i++)
//		v1.push_back(i);
//	printVector(v1);
//
//	vector<int>v2;
//	for (int i = 10; i >= 1; i--)
//		v2.push_back(i);
//	printVector(v2);
//
//	cout << "v1的容量" << v1.capacity() << endl;
//	cout << "v1的大小" << v1.size() << endl;
//	cout << "v2的容量" << v2.capacity() << endl;
//	cout << "v2的大小" << v2.size() << endl;
//
//	cout << "交换后：" << endl;
//	v1.swap(v2);//--$^^%$^&*((&*)()***(_----&&---//&&
//	printVector(v1);
//	printVector(v2);
//
//	cout << "v1的容量" << v1.capacity() << endl;//容量大小也发生了交换
//	cout << "v1的大小" << v1.size() << endl;
//	cout << "v2的容量" << v2.capacity() << endl;
//	cout << "v2的大小" << v2.size() << endl;
//	cout << endl;
//}
//void test02()
//{
//	vector<int>v;
//	for (int  i = 0; i < 1000; i++)
//		v.push_back(i + 1);
//	cout << "v的容量" << v.capacity() << endl;
//	cout << "v的大小" << v.size() << endl;
//	v.resize(3);
//	cout << "v的容量" << v.capacity() << endl;
//	cout << "v的大小" << v.size() << endl;
//	vector<int>(v).swap(v);//运用匿名对象达到释放多余空间的效果
//	cout << "v的容量" << v.capacity() << endl;
//	cout << "v的大小" << v.size() << endl;
//}
//int main()
//{
//	test01(); 
//	test02();
//	return 0;
//}

//--------------------------------------------------------------37vector预留空间
//#include<algorithm>
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int>v1;
//	v1.reserve(1000);//预留1000个空间，减少系统重新开辟空间的次数
//	//注意，预留出的空间不可访问·
//	//cout << v1[100] << endl;
//	int num = 0;//统计重新开辟的次数
//	int* p = NULL;
//	for (int i = 1; i <= 100000; i++)
//	{
//		v1.push_back(i);
//		if (p != &v1[0])
//		{
//			p = &v1[0];
//			num++;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}

//-------------------------------------------------------------------38 deque构造函数
/*
构造方式和vector基本一样
deque<T> deqT; //默认构造形式
deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem); //构造函数将n个elem拷贝给本身。
deque(const deque &deq); //拷贝构造函数
*/
//#include<deque>
//template<class T>
//void showDeque(const deque<T>&d) {//注意const 
//	cout << "遍历容器中的元素：" << endl;//for里对应为const_iterator
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//int main() {
//	deque<int>d1;//1.
//	for (int i = 0; i < 10; i++) {
//		d1.push_back(i);
//	}
//	showDeque(d1);
//	deque<int>d2(d1.begin(), d1.end());//2.
//	showDeque(d2);
//	deque<string>d3(3, "abc");//3.
//	//showDeque(d3);//上面for循环是deque<int>，string遍历不了
//	//想要遍历，int改为string，或者用for(auto num:d)遍历
//	deque<int>d4(d1);//4.
//	showDeque(d4);
//	return 0;
//}


//-------------------------------------------------------------------39 deque赋值操作
/*
-----deque赋值操作也与vector相同
deque& operator=(const deque &deq); //重载等号操作符
assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
*/
//#include<deque>
//void showDeque(const deque<string>d) {
//	cout << "遍历容器中的元素：" << endl;
//	for (deque<string>::const_iterator it = d.begin(); it != d.end(); it++) {
//		cout << *it << " ";
//	}cout << endl;
//}
//int main() {
//	deque<string>d1(5, "abc");
//	showDeque(d1);
//	deque<string>d2;
//	d2 = d1;//1.
//	showDeque(d2);
//
//	deque<string>d3({ "aa","bb","cc","dd","ee" });
//	showDeque(d3);
//	d2.assign(d3.begin(), d3.end() - 1);//2.
//	showDeque(d2);
//
//	d2.assign(3, "awsl");//3.
//	showDeque(d2);
//	return 0;
//}

//-------------------------------------------------------------------40 deque大小操作
/*
------------deque没有容量的概念
deque.empty(); //判断容器是否为空
deque.size(); //返回容器中元素的个数
deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
*/

//#include<deque>
//
//template<typename T>
//void showDeque(const deque<T>& d) {
//	for (auto i : d) {
//		cout << i << " ";
//	}cout << endl;
//}
//
//int main() {
//	deque<int>d1;
//	if (d1.empty()) {//1.
//		cout << "d1现在为空" << endl;
//	}
//	for (int i = 1; i <= 3; i++)
//		d1.push_back(i);
//	if (!d1.empty()) {
//		cout << "d1现在不为空" << endl;
//		cout << "d1中元素的个数为: " << d1.size() << endl;//2.
//	}
//	d1.resize(5);//3.
//	showDeque(d1);
//	d1.resize(7, 666);//4.
//	showDeque(d1);
//	d1.resize(3);
//	showDeque(d1);
//	return 0;
//}

//-------------------------------------------------------------------41 deque插入和删除
/*
  两端插入操作：
push_back(elem); //在容器尾部添加一个数据
push_front(elem); //在容器头部插入一个数据//头插的效果
pop_back(); //删除容器最后一个数据
pop_front(); //删除容器第一个数据//头删的效果
  指定位置操作：
  **！！位置是迭代器！！**
insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。//pos前插入
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。//pos前
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos); //删除pos位置的数据，返回下一个数据的位置。
*/
//#include<deque>
//int i = 1;
//void showDeque(const deque<int>& d) {
//	cout << "第" << i << "次遍历deque<int>容器元素：" << endl;
//	for (auto num : d) {
//		cout << num << " ";
//	}cout << endl;
//	i++;
//}
//void test01() {
//	deque<int>d1;
//	for (int i = 1; i <= 5; i++) {
//		d1.push_back(i);//1.
//	}
//	showDeque(d1);
//	for (int i = 1; i <= 5; i++) {
//		d1.push_front(i * 10);//2.
//	}
//	showDeque(d1);
//	d1.pop_back();//3.
//	d1.pop_back();
//	showDeque(d1);
//	d1.pop_front();//4.
//	d1.pop_front();
//	showDeque(d1);
//}
//void test02() {
//	i = 0;cout << endl;
//	deque<int>d1{ 1,2,3,4,5 };
//	cout << *(d1.insert(d1.begin() + 1, 666)) << endl;//1.
//	showDeque(d1);
//	d1.insert(d1.end(), 3, 6000);//2.
//	showDeque(d1);
//	d1.insert(d1.begin() + 1, d1.begin(), d1.begin() + 3);//3.
//	showDeque(d1);
//	d1.clear();//4.
//	if (d1.empty()) {
//		cout << "d1空啦" << endl;
//	}
//	for (int i = 0; i < 5; i++) {
//		d1.push_front((i + 1) * 10);
//	}
//	cout << *(d1.erase(d1.begin())) << endl;//6.
//	showDeque(d1);
//	cout << *(d1.erase(d1.begin(), d1.end() - 2)) << endl;//5.
//	showDeque(d1);
//}
//int main() {
//	test01();
//	test02();
//	return 0;
//}


//-------------------------------------------------------------------42 deque 数据存取
/*
at(int idx); //返回索引idx所指的数据
operator[]; //返回索引idx所指的数据
front(); //返回容器中第一个数据元素
back(); //返回容器中最后一个数据元素
*/
//#include<deque>
//int main() {
//	deque<int>d{ 1,2,3,4,5 };
//	cout << d.at(3) << endl;//1.
//	cout << d[3] << endl;//2.
//
//	d.at(3) = 666;
//	cout << d.at(3) << endl;
//	d[3] = 999;
//	cout << d[3] << endl;
//
//	cout << d.front() << endl;
//	cout << d.back() << endl;
//	return 0;
//}


//-------------------------------------------------------------------43 deque 排序
//#include<deque>
//#include<algorithm>
//void showDeque(const deque<int>& d) {
//	for (auto num : d) {
//		cout << num << " ";
//	}cout << endl;
//}
//int main() {
//	cout << "输入你想push_back的元素总个数：" << endl;
//	int n; cin >> n;
//	deque<int>d1;int x;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		d1.push_back(x);
//	}
//	showDeque(d1);
//	sort(d1.begin(), d1.end(), greater<int>());//降序排序
//	showDeque(d1);
//	return 0;
//}

//-------------------------------------------------------------------46 stack常用接口
/*
* stack无.begin()和.end()，理论上无法遍历
构造函数：
stack<T> stk; //stack采用模板类实现， stack对象的默认构造形式
stack(const stack &stk); //拷贝构造函数
赋值操作：
stack& operator=(const stack &stk); //重载等号操作符
数据存取：
push(elem); //向栈顶添加元素
pop(); //从栈顶移除第一个元素
top(); //返回栈顶元素
大小操作：
empty(); //判断堆栈是否为空
size(); //返回栈的大小
*/
//#include<stack>
//int main() {
//	stack<int>s1;//1.
//	for (int i = 1; i <= 5; i++)
//		s1.push(i);//4.
//	stack<int>s2(s1);//2.
//	stack<int>s3;
//	cout << "此时s2栈顶元素：" << s2.top() << endl;//6.
//	s3 = s1;//3.
//	s3.pop();//5.
//	cout << "此时s3元素个数：" << s3.size() << endl;//8.
//	for (int i = 0; i < 5; i++)
//		s1.pop();
//	if (s1.empty()) {//7.
//		cout << "s1为空" << endl;
//	}
//	return 0;
//}

//-------------------------------------------------------------------48 queue 常用接口
/*
构造函数：
queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
queue(const queue &que); //拷贝构造函数
赋值操作：
queue& operator=(const queue &que); //重载等号操作符
数据存取：
push(elem); //往队尾添加元素
pop(); //从队头移除第一个元素
back(); //返回最后一个元素
front(); //返回第一个元素
大小操作：
empty(); //判断堆栈是否为空
size(); //返回栈的大小
*/
//#include<queue>
//void showQueue(const queue<int>& q1) {
//	cout << "此时q1的首元素数据：" << q1.front() << endl;
//	cout << "此时q1的尾元素数据：" << q1.back() << endl;
//	cout << endl;
//}
//int main() {
//	//构造和赋值和stack一致，这里不过多演示
//	queue<int>q1;
//	for (int i = 1; i <= 5; i++) {
//		q1.push(i);
//	}
//	showQueue(q1);
//	q1.push(666);//尾插
//	showQueue(q1);
//	q1.pop();//头删
//	showQueue(q1);
//	cout << "此时q1的元素个数：" << q1.size() << endl;
//	cout << "清除q1同时遍历：" << endl;
//	for (int i = 0; i < 5; i++) {
//		cout << q1.front() << " ";
//		q1.pop();
//	}cout << endl;
//	if (q1.empty()) {
//		cout << "q1为空" << endl;
//	}
//	return 0;
//}

//-------------------------------------------------------------------50 list构造函数
/*
函数原型：
list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。
*/
//#include<list>
//void showList(const list<int>& L1) {
//	for (list<int>::const_iterator it = L1.begin(); it != L1.end(); it++) {
//		cout << (*it) << " ";
//	}cout << endl;
//}
//int main() {
//	list<int>L1;//1.
//	for (int i = 0; i < 5; i++)
//		L1.push_back(10 * (i + 1));
//	showList(L1);
//	list<int>L2(L1.begin(), L1.end());//2.
//	showList(L2);
//	list<int>L3(5, 666);//3.
//	showList(L3);
//	list<int>L4(L3);//4.
//	showList(L4);
//	return 0;
//}

//-------------------------------------------------------------------51 list赋值和交换
/*
函数原型：
assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem); //将n个elem拷贝赋值给本身。
list& operator=(const list &lst); //重载等号操作符
swap(lst); //将lst与本身的元素互换。
//*/
//#include<list>
//template<class T>
//void showList(const list<T>& L1) {
//	for (auto i : L1) {
//		cout << i << " ";
//	}cout << endl;
//}
//int main() {
//	list<int>L1;
//	for (int i = 1; i <= 5; i++) {
//		L1.push_back(i);
//	}
//	showList(L1);
//	list<int>L2;
//	L2.assign(L1.begin(), L1.end());//1.
//	showList(L2);
//	list<int>L3;
//	L3.assign(5, 666);//2.
//	showList(L3);
//	list<int>L4;
//	L4 = L3;//3.
//	showList(L4);
//
//	list<int>L5;
//	for (int i = 1; i <= 4; i++) {
//		L5.push_back(i * 10);
//	}
//	cout << "交换前：\nL1: ";
//	showList(L1);
//	cout << "交换前：\nL5: ";
//	showList(L5);
//	L1.swap(L5);//4.
//	cout << "交换后：\nL1: ";
//	showList(L1);
//	cout << "交换后：\nL5: ";
//	showList(L5);
//	return 0;
//}


//-------------------------------------------------------------------52 list大小操作
/*
函数原型：
size(); //返回容器中元素的个数
empty(); //判断容器是否为空
resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
*/
//#include<list>
//template<class T>
//void showList(const list<T>& L1) {
//	for (auto i : L1) {
//		cout << i << " ";
//	}cout << endl;
//}
//int main() {
//	list<int>L1;
//	for (int i = 1; i <= 5; i++) {
//		L1.push_back(i);
//	}
//	cout << "L1的元素个数：" << L1.size() << endl;//1.
//	if (!L1.empty()) {//2.
//		cout << "L1不为空" << endl;
//	}
//	L1.resize(7);//3.
//	showList(L1);
//	L1.resize(10, 666);//4.
//	showList(L1);
//	L1.resize(5);
//	showList(L1);
//	return 0;
//}


//-------------------------------------------------------------------53 list插入和删除
/*
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素

insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。

remove(elem);//删除容器中所有与elem值匹配的元素。//删值为elem的数据
*/
//后不再详细写每个代码，只是测试不太清楚的部分


//-------------------------------------------------------------------54 list 数据存取
/*
front(); //返回第一个元素。
back(); //返回最后一个元素。
//cout << L1.at(0) << endl;//错误 不支持at访问数据
//cout << L1[0] << endl; //错误 不支持[]方式访问数据
//list容器的迭代器是双向迭代器，不支持随机访问
list<int>::iterator it = L1.begin();
//it = it + 1;//错误，不可以跳跃访问，即使是+1//只能++ --
*/


//-------------------------------------------------------------------55 list 反转和排序
/*
reverse(); //反转链表
sort(); //链表排序//升序
!!!**  L1.reverse()  L1.sort(可以加仿函数变升序)  **!!!
//用sort函数和reverse函数不行
*/


//--------------------------------------------------------------57set容器构造和赋值
//#include<set>
//#include<iostream>
//using namespace std;
//void printSet(set<int>&s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	set<int>s1;
//
//	//插入数据->只有insert
//	for (int i = 100; i >= 10; i -= 10)
//		s1.insert(i);
//	printSet(s1);//10 -100 //set容器插入时自动排序（小到大）
//	s1.insert(20);
//	s1.insert(20);//set容器重复数据不插入
//	printSet(s1
//	);
//	//拷贝构造
//	set<int>s2(s1);
//	printSet(s2);
//
//	//赋值
//	set<int>s3 = s1;
//	printSet(s3);
//	return 0;
//}



////--------------------------------------------------------------58set容器大小和交换
////---------------------------   : size  empty  swap
//#include<iostream>
//#include<set>
//using namespace std;
//void printSet(set<int>&s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	set<int> s1;//插入数据
//	s1.insert(73);s1.insert(48);s1.insert(26);s1.insert(25);s1.insert(51);
//	printSet(s1);
//
//	//empty
//	if (s1.empty())
//		cout << "s1为空" << endl;
//	else
//		cout << "s1的大小为" << s1.size() << endl;
//
//	//swap
//	set<int> s2;
//	s2.insert(13); s2.insert(18); s2.insert(16); 
//	cout << "交换前：" << endl;
//	cout << "s1:" << "\t" << endl; printSet(s1);
//	cout << "s2:" << "\t" << endl; printSet(s2);
//	s1.swap(s2);
//	cout << "交换后：" << endl;
//	cout << "s1:" << "\t" << endl; printSet(s1);
//	cout << "s2:" << "\t" << endl; printSet(s2);
//	return 0;
//}

////--------------------------------------------------------------59set容器插入和删除
//#include<iostream>
//#include<set>
//using namespace std;
//void printSet(set<int>&s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	//插入
//	set<int> s1;//插入数据
//	s1.insert(20); s1.insert(30); s1.insert(10); s1.insert(50); s1.insert(40);
//	printSet(s1);
//
//	//删除
//	s1.erase(s1.begin());
//	printSet(s1);//删的是10
//	s1.erase(40);
//	printSet(s1);//删的是40
//
//	//清空
//	s1.erase(s1.begin(), s1.end());
//	if (s1.empty())
//		cout << "s1为空" << endl;
//	cout << s1.size() << endl;
//	s1.insert(20); s1.insert(30); s1.insert(10); s1.insert(50); s1.insert(40);
//	s1.clear();
//	cout << s1.size() << endl;
//	return 0;
//}

//--------------------------------------------------------------60set容器查找和统计
//------------------    :   find    count
//#include<iostream>
//#include<set>
//using namespace std;
//void printSet(set<int>& s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	//插入
//	set<int> s1;//插入数据
//	s1.insert(20); s1.insert(30); s1.insert(10); s1.insert(50); s1.insert(40);
//	printSet(s1);
//
//	//查找
//	set<int>::iterator it =  s1.find(30);//找30的位置
//	if (it == s1.end()) {
//		cout << "s1 find nothing" << endl;
//	}
//	else {
//		cout << "find : " << *it << endl;
//	}
//
//	//统计
//	cout << s1.count(30) << endl;//统计30的个数
//	cout << s1.count(22) << endl;//对set而言，count结果只能为 0 or 1
//	return 0;
//}


//--------------------------------------------------------------61 set & multiset 的区别
//multiset的函数和set一致，区别是multiset可以重复插入相同的数据
//#include<iostream>
//#include<set>
//using namespace std;
//void printSet(set<int>& s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//void printMultiset(multiset<int>& m1)
//{
//	for (multiset<int>::iterator it = m1.begin(); it != m1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//void test01()
//{
////插入
//	set<int> s1;//插入数据
//	pair<set<int>::iterator, bool> s = 	s1.insert(20);
//	if (s.second) {
//		cout << "第一次插入成功" << endl;
//	}
//	else {
//		cout << "第一次插入失败" << endl;
//	}
//	s = s1.insert(20);
//	if (s.second) {
//		cout << "第二次插入成功" << endl;
//	}
//	else {
//		cout << "第二次插入失败" << endl;
//	}
//	cout << endl;
//}
//void test02()
//{
//	multiset<int>m1;//插入数据
//	//报错  multiset的insert返回值类型后没有bool类型
//	//pair<multiset<int>::iterator, bool> s = m1.insert(20);
//	m1.insert(10);
//	m1.insert(20);
//	m1.insert(10);
//	m1.insert(20);
//	printMultiset(m1);
//}
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}

//--------------------------------------------------------------62 pair对组的创建
//#include<iostream>
//using namespace std;
//int main()
//{
//	//方式一
//	pair<string, int>p("awsl", 438);
//	cout << p.first << " " << p.second << endl;
//
//	//方式二
//	pair<double, string>pp = make_pair(99.5, "dsb");
//	cout << pp.first << " " << pp.second << endl;
//	return 0;
//}

//--------------------------------------------------------------63 set函数排序--->从大到小
//#include<iostream>
//#include<set>
//using namespace std;
//class A 
//{
//public:
//	bool operator()(const int v1, const int v2) const
//	{
//		return v1 > v2;
//	}
//};
//void printSet(set<int>& s1)
//{
//	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//int main()
//{
//	//从小到大
//	set<int> s1;
//	s1.insert(20);s1.insert(50);s1.insert(10);s1.insert(40);s1.insert(30);
//	printSet(s1);
//
//	//从大到小
//	set<int, A> s2;
//	s2.insert(10); s2.insert(20); s2.insert(30); s2.insert(40); s2.insert(50);
//	for (set<int, A>::iterator it = s2.begin(); it != s2.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//	return 0;
//}

//--------------------------------------------------------------64 set函数排序（自定义数据类型）--->从大到小
//#include<iostream>
//#include<set>
//#include<string>
//using namespace std;
//class Per
//{
//public:
//	string m_name;
//	int m_age;
//	Per(string name, int age) :m_name(name), m_age(age){}
//};
//class Cmp
//{
//public:
//	bool operator()(const Per p1, const Per p2) const
//	{
//		return p1.m_age > p2.m_age;
//	}
//};
//void printSet(set<Per, Cmp>& s)
//{
//	for (set<Per, Cmp>::iterator it = s.begin(); it != s.end(); it++) {
//		cout << (*it).m_name << "\t ";
//		cout << (*it).m_age << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	set<Per, Cmp>s;
//	//创建基本数据并插入
//	Per p1("张三", 10);Per p2("张四", 20);Per p3("张五", 30);Per p4("张六", 40);Per p5("张七", 50);
//	s.insert(p1);s.insert(p2);s.insert(p3);s.insert(p4);s.insert(p5);
//	printSet(s);
//	return 0;
//}

//-------------------------------------------------------------- 65 map 构造和赋值
//#include<iostream>
//#include<map>
//using namespace std;
//void printMap(map<int, string>m)
//{
//	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << (*it).first << "\t";
//		cout << (*it).second << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	//创建map容器
//	map<int, string> m;//第一个key（这里是int）索引不能重复
//	m.insert(pair<int, string>(30, "ccc"));//自动排序  根据k排序，不是value
//	m.insert(pair<int, string>(20, "bbb"));
//	m.insert(pair<int, string>(10, "aaa"));
//	m.insert(pair<int, string>(50, "eee"));
//	m.insert(pair<int, string>(40, "ddd"));
//	printMap(m);
//
//	//拷贝构造
//	map<int, string>m2(m);
//	printMap(m2);
//
//	//赋值
//	map<int, string>m3 = m2;
//	printMap(m3);
//	return 0;
//}

////-------------------------------------------------------------- 66 map 大小和交换
//#include<iostream>
//#include<map>
//using namespace std;
//void printMap(map<int, string>m)
//{
//	for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << (*it).first << "\t";
//		cout << (*it).second << endl;
//	}
//}
//int main()
//{
//	map<int, string>m1;
//	m1.insert(pair<int, string>(11, "aa"));
//	m1.insert(pair<int, string>(22, "bb"));
//	m1.insert(pair<int, string>(33, "cc"));
//	printMap(m1);
//
//	//size
//	cout << "size = " << m1.size() << endl;
//
//	//empty
//	if (!m1.empty())
//		cout << "m1不为空" << endl;
//	map<int, string>m2;
//	m2.insert(pair<int, string>(33, "cc"));
//
//	//swap
//	m1.swap(m2);
//	printMap(m2); printMap(m1);
//	return 0;
//}

//-------------------------------------------------------------- 67 map 插入 删除
//#include<iostream>
//#include<map>
//using namespace std;
//void printMap(map<int, int>m)
//{
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << (*it).first << "\t";
//		cout << (*it).second << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	//插入的4种方式
//	map<int, int>m1;
//	m1.insert(map<int, int>::value_type(13, 19));//1
//	m1.insert(pair<int, int>(11, 21));//2
//	m1.insert(make_pair(12, 20));//3
//	m1[14] = 40;//4  不建议插入，可以用来访问
//	cout << m1[5] << endl;//没有，系统自动创建 (5,0)
//	pair<int, int> p1 = make_pair(12, 20);//和3对比
//	printMap(m1); 
//
//	//删除
//	m1.erase(m1.begin());//删除第一个·
//	printMap(m1);
//	m1.erase(12);//直接删除key为12的元素
//	printMap(m1);
//	m1.erase(m1.begin(), m1.end());//删除区间 == m1.clear();
//	if (m1.empty())
//		cout << "m1为空" << endl;
//	return 0;
//}

//-------------------------------------------------------------- 68 map 查找和统计
/*
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
*/


//-------------------------------------------------------------- 69 map容器排序 

//#include <map>
//class MyCompare {
//public:
//	bool operator()(int v1, int v2) const{//比较函数最后加const
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	//默认从小到大排序
//	//利用仿函数实现从大到小排序
//	map<int, int, MyCompare> m;
//	m.insert(make_pair(1, 10));
//	m.insert(make_pair(2, 20));
//	m.insert(make_pair(3, 30));
//	m.insert(make_pair(4, 40));
//	m.insert(make_pair(5, 50));
//	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
//		cout << "key:" << it->first << " value:" << it->second << endl;
//	}
//}
//int main() {
//	test01();
//	system("pause");
//	return 0;
//}


//-------------------------------------------------------------- 71函数对象使用
/*
   函数对象概念
概念：
重载函数调用操作符的类，其对象常称为函数对象
函数对象使用重载的()时，行为类似函数调用，也叫仿函数
本质：
函数对象(仿函数)是一个类，不是一个函数
   函数对象使用
特点：
函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值//1.
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
*/
//#include<string>
//
//class MyAdd {//仿函数
//public:
//	int operator ()(int v1, int v2) const{
//		return v1 + v2;
//	}
//};
//
//class MyPrint {
//public:
//	MyPrint() {
//		this->count = 0;
//	}
//	void operator ()(string s) {
//		cout << s << endl;
//		count++;
//	}
//	int count;
//};
//
//void doPrint(MyPrint& mp2, const string s) {
//	mp2(s);
//}
//
//int main() {
//	MyAdd ma;
//	cout << ma(10, 11) << endl;//1.
//
//	MyPrint mp;
//	mp("hello fuck");
//	mp("hello fuck");
//	mp("hello fuck");
//	mp("hello fuck");
//	mp("hello fuck");
//	cout << "调用mp的次数: " << mp.count << endl;//2.
//
//	MyPrint mp2;
//	doPrint(mp2, "what fXXK?");//3.
//	return 0;
//}

//--------------------------------------------------------------72一元谓词
/*
返回bool类型的仿函数称为谓词
如果operator()接受一个参数，那么叫做一元谓词
如果operator()接受两个参数，那么叫做二元谓词
*/
//#include<vector>
//#include<algorithm>
//class BiggerFive {
//public:
//	bool operator()(int val) {
//		if (val > 5) {//大于5返回真
//			return true;
//		}
//		return false;
//	}
//};
//int main() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	//BiggerFive() --> 是匿名函数对象
//	vector<int>::iterator it = find_if(v.begin(), v.end(), BiggerFive());
//	if (it == v.end()) {
//		cout << "没找到大于5的数" << endl;
//	}
//	else {
//		cout << "v中第一个大于5的数是：" << *it << endl;
//	}
//	return 0;
//}

//--------------------------------------------------------------73二元谓词
//#include<vector>
//#include<algorithm>
//class Cmp {
//public:
//	bool operator()(int v1, int v2) {
//		return v1 > v2;
//	}
//};
//int main() {
//	vector<int>v;
//	for (int i = 5; i >= 1; i--)
//		v.push_back(i * 10);
//	sort(v.begin(), v.end());
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	//使用函数函数对象，变为排序规则从大到小
//	sort(v.begin(), v.end(), Cmp());
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	return 0;
//}

//--------------------------------------------------------------74内建函数对象-算术仿函数
/*
  功能描述：
实现四则运算
其中negate是一元运算，其他都是二元运算
  仿函数原型：
template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数
！！！！！总结：使用内建函数对象时，需要引入头文件 #include <functional>
*/
//#include<functional>
//int main() {
//	int a = 189;
//	cout << ~a << endl;//加负号再-1
//	negate<int>n;
//	cout << n(a) << endl;//加负号
//
//	plus<int>p;//这个的实现用到了面向对象，类模板，函数对象的知识
//	//p就是一个函数对象
//	cout << p(10, 52) << endl;
//	return 0;
//}

//--------------------------------------------------------------75关系仿函数
/*
仿函数原型：
template<class T> bool equal_to<T> //等于
template<class T> bool not_equal_to<T> //不等于
template<class T> bool greater<T> //大于
template<class T> bool greater_equal<T> //大于等于
template<class T> bool less<T> //小于
template<class T> bool less_equal<T> //小于等于
*/
//#include<functional>
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int>v;
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(30);
//	v.push_back(10);
//	v.push_back(20);
//	sort(v.begin(), v.end(), greater<int>());
//	for (int i : v) {
//		cout << i << " ";
//	}
//	return 0;
//}

//--------------------------------------------------------------76逻辑仿函数
/*
函数原型：
template<class T> bool logical_and<T> //逻辑与
template<class T> bool logical_or<T> //逻辑或
template<class T> bool logical_not<T> //逻辑非
*/
//#include<functional>
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<bool>v;
//	v.push_back(false);
//	v.push_back(true);
//	v.push_back(false);
//	v.push_back(true);
//	for (bool i : v) {
//		cout << i << " ";
//	}cout << endl;
//	vector<bool>v2;
//	v2.resize(v.size());//-->IMPORTANT
//	//将v中的值遍历赋给v2，并在每次赋值前对数据进行后面仿函数的操作
//	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
//	for (bool i : v2) {
//		cout << i << " ";
//	}cout << endl;
//	return 0;
//}

//--------------------------------------------------------------77常用算法 for_each遍历
/*
  概述:
算法主要是由头文件 <algorithm> <functional> <numeric> 组成。
<algorithm> 是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
<numeric> 体积很小，只包括几个在序列上面进行简单数学运算的模板函数
<functional> 定义了一些模板类,用以声明函数对象。

  功能描述：<algorithm>
实现遍历容器
  函数原型：
for_each(iterator beg, iterator end, _func);
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func 函数或者函数对象
*/
//#include<algorithm>
//#include<vector>
//
//void showV(int val) {//普通函数
//	cout << val << " ";
//}
//
//class PrintV {
//public:
//	void operator()(int val)const {//仿函数
//		cout << val << " ";
//	}
//};
//
//int main() {
//	vector<int>v;
//	for (int i = 1; i <= 5; i++) {
//		v.push_back(i * 10);
//	}
//	for_each(v.begin(), v.end(), showV);
//	cout << endl;
//	for_each(v.begin(), v.end(), PrintV());
//	cout << endl;
//	return 0;
//}

//--------------------------------------------------------------78 transform 遍历
/*
函数原型：<algorithm>
transform(iterator beg1, iterator end1, iterator beg2, _func);
//beg1 源容器开始迭代器
//end1 源容器结束迭代器
//beg2 目标容器开始迭代器
//_func 函数或者函数对象
*/
//#include<vector>
//#include<algorithm>
//class Bigger {
//public:
//	int operator()(int val) {
//		return val * 10;//返回int类型，因为transform要赋值给vTarget容器
//	}
//};
//void showV(int val) {
//	cout << val << " ";
//}
//int main() {
//	vector<int>v;
//	for (int i = 1; i <= 5; i++) {
//		v.push_back(i * 10);
//	}
//	vector<int>vTarget;
//	vTarget.resize(v.size());
//	transform(v.begin(), v.end(), vTarget.begin(), Bigger());
//	for_each(vTarget.begin(), vTarget.end(), showV);
//	return 0;
//}

//--------------------------------------------------------------79 查找 find
/*
  算法简介：  <algorithm>
find //查找元素
find_if //按条件查找元素
adjacent_find //查找相邻重复元素
binary_search //二分查找法
count //统计元素个数
count_if //按条件统计元素个数
           find
  功能描述：
查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
  函数原型：
find(iterator beg, iterator end, value);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
*/
//#include<algorithm>
//#include<vector>
//#include<string>
//class Per {
//public:
//	Per(string n, int a) :name(n), age(a) {}
//	bool operator==(const Per& p1) {
//		if (this->name == p1.name && this->age == p1.age) {
//			return true;
//		}
//		return false;
//	}
//	string name;
//	int age;
//};
//void test01() {
//	vector<int>v;
//	for (int i = 1; i <= 10; i++)
//		v.push_back(i);
//	//查找5
//	vector<int>::iterator it = find(v.begin(), v.end(), 5);
//	if (it == v.end()) {
//		cout << "没找到" << endl;
//	}
//	else {
//		cout << "找到了" << *it << endl;
//	}
//}
//void test02() {
//	vector<Per>v;
//	Per p1("aaa", 111);
//	Per p2("bbb", 222);
//	Per p3("ccc", 333);
//	Per p4("ddd", 444);
//	Per p5("eee", 555);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	vector<Per>::iterator it = find(v.begin(), v.end(), Per("ccc", 333));
//	if (it == v.end()) {
//		cout << "没找到" << endl;
//	}
//	else {
//		cout << "name= " << it->name << endl;
//		cout << "age= " << (*it).age << endl;
//	}
//}
//int main() {
//	test01();
//	test02();
//	return 0;
//}

//--------------------------------------------------------------80 查找 find_if
/*
* 自定义查找函数对象
函数原型：  <algorithm>
find_if(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 函数或者谓词（返回bool类型的仿函数）
*/
//#include<vector>
//#include<algorithm>
//#include<string>
//class GreaterFive {
//public:
//	bool operator()(int val) {
//		return val > 50;
//	}
//};
//class Per {
//public:
//	Per(string n, int a) :name(n), age(a) {}
//	string name;
//	int age;
//};
//class GreaterThree {
//public:
//	bool operator()(const Per& p) {
//		return (p.age) > 300;
//	}
//};
//void test01() {
//	vector<int>v;
//	for (int i = 1; i <= 10; i++) {
//		v.push_back(i * 10);
//	}
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end()) {
//		cout << "没找到" << endl;
//	}
//	else {
//		cout << "找到了" << *it << endl;
//	}
//}
//void test02() {
//	vector<Per>v;
//	Per p1("aaa", 111);
//	Per p2("bbb", 222);
//	Per p3("ccc", 333);
//	Per p4("ddd", 444);
//	Per p5("eee", 555);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	vector<Per>::iterator it = find_if(v.begin(), v.end(), GreaterThree());
//	if (it == v.end()) {
//		cout << "没找到" << endl;
//	}
//	else {
//		cout << "name= " << it->name << endl;
//		cout << "age= " << it->age << endl;
//	}
//}
//int main() {
//	test01();
//	test02();
//	return 0;
//}

//--------------------------------------------------------------81 查找 adjacent_find
/*
  功能描述：    <algorithm>
查找相邻且重复元素
  函数原型：
adjacent_find(iterator beg, iterator end);
// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
// beg 开始迭代器
// end 结束迭代器
*/
//#include<vector>
//#include<algorithm>
//#include<string>
//
//int main() {
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(2);
//	v.push_back(4);
//	v.push_back(4);
//	v.push_back(3);
//	v.push_back(3);
//	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
//	if (it == v.end()) {
//		cout << "找不到!" << endl;
//	}
//	else {
//		cout << "找到相邻重复元素为:" << *it << endl;
//	}
//
//	return 0;
//}

//--------------------------------------------------------------82 查找 binary_find
/*
  功能描述：          <algorithm>
查找指定元素是否存在  **!在无序序列用不了，基于二分!**
  函数原型：
bool binary_search(iterator beg, iterator end, value);
// 查找指定的元素，查到 返回true 否则false
// 注意: 在无序序列中不可用
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
*/
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int>v;
//	for (int i = 1; i <= 10; i++) {
//		v.push_back(i * 10);
//	}
//	bool temp = binary_search(v.begin(), v.end(), 60);
//	if (temp == true) {
//		cout << "找到了" << endl;
//	}
//	else {
//		cout << "没找到" << endl;
//	}
//	return 0;
//}

//--------------------------------------------------------------83 查找 count
/*
  功能描述：   <algorithm>
统计元素个数
  函数原型：
count(iterator beg, iterator end, value);
// 统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// value 统计的元素
*/
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int>v;
//	v.push_back(5);
//	v.push_back(9);
//	v.push_back(9);
//	v.push_back(9);
//	v.push_back(4);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//	v.push_back(6);
//	v.push_back(6);
//	v.push_back(2);//自定数据类型重写==运算符
//	int numNine = count(v.begin(), v.end(), 9);
//	cout << "v中数据为9的元素个数为: " << numNine << endl;
//	return 0;
//}

//--------------------------------------------------------------84 查找 count_if
/*
  功能描述：
按条件统计元素个数
  函数原型：
count_if(iterator beg, iterator end, _Pred);
// 按条件统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词
*/
//#include<algorithm>
//#include<vector>
//class Per {
//public:
//	Per(string n, int a) :name(n), age(a) {}
//	string name;
//	int age;
//};
//class CountNum {
//public:
//	bool operator()(const Per& p) {
//		return p.age > 333;
//	}
//};
//int main() {
//	vector<Per>v;
//	Per p1("aaa", 111);
//	Per p6("eee", 555);
//	Per p2("bbb", 222);
//	Per p7("eee", 555);
//	Per p3("ccc", 333);
//	Per p4("ddd", 444);
//	Per p5("eee", 555);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	v.push_back(p6);
//	v.push_back(p7);
//	int num = count_if(v.begin(), v.end(), CountNum());
//	cout << "age大于333的元素个数" << num << endl;
//	return 0;
//}

//--------------------------------------------------------------85 排序 sort
/*
算法简介：
sort //对容器内元素进行排序
random_shuffle //洗牌 指定范围内的元素随机调整次序
merge // 容器元素合并，并存储到另一容器中
reverse // 反转指定范围的元素

sort(iterator beg, iterator end, _Pred);
 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
 beg 开始迭代器
 end 结束迭代器
 _Pred 谓词
*/
/*你懂的*/

//--------------------------------------------------------------86 排序 random_shuffle
/*
random_shuffle(iterator beg, iterator end);
 指定范围内的元素随机调整次序
 beg 开始迭代器
 end 结束迭代器
***********使用时记得加随机数种子*************
*/
//#include<algorithm>
//#include<ctime>
//#include<vector>
//class ShowV {
//public:
//	void operator()(int val) {
//		cout << val << " ";
//	}
//};
//int main() {
//	srand((unsigned int)time(nullptr));//记得加
//	vector<int>v;
//	for (int i = 1; i <= 10; i++)
//		v.push_back(i);
//	for_each(v.begin(), v.end(), ShowV()); cout << endl;
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), ShowV()); cout << endl;
//	return 0;
//}

//--------------------------------------------------------------87 排序 merge
/*
  功能描述：      **merge合并的两个容器必须的有序序列**
两个容器元素合并，并存储到另一容器中,目标依然有序（升序）
  函数原型：
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 容器元素合并，并存储到另一容器中
// 注意: 两个容器必须是有序的
// beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
dest 目标容器开始迭代器
*/
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 1; i <= 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 1);
//	}
//	vector<int>vTarget;//目标容器
//	vTarget.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//  //两个升序这么写
//  //merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin(), greater<int>());
//	for (auto i : vTarget) {
//		cout << i << " ";
//	}
//	return 0;
//}

//--------------------------------------------------------------88 排序 reverse
/*
  功能描述：
将容器内元素进行反转
  函数原型：
reverse(iterator beg, iterator end);
// 反转指定范围的元素
*/
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int>v;
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(30);
//	cout << "反转前：" << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	reverse(v.begin(), v.end());
//	cout << "反转后：" << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}
//	return 0;
//}

//--------------------------------------------------------------89 拷贝和替换 copy
/*
算法简介：     <algorithm>
copy // 容器内指定范围的元素拷贝到另一容器中
replace // 将容器内指定范围的旧元素修改为新元素
replace_if // 容器内指定范围满足条件的元素替换为新元素
swap // 互换两个容器的元素

  功能描述：
容器内指定范围的元素拷贝到另一容器中
  函数原型：
copy(iterator beg, iterator end, iterator dest);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
*/
//#include<algorithm>
//#include<vector>
//int main() {
//	vector<int> v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i + 1);
//	}
//	vector<int>v2;
//	v2.resize(v1.size());
//	copy(v1.begin(), v1.end(), v2.begin());
//	cout << "v1: " << endl;
//	for (auto i : v1) {
//		cout << i << " ";
//	}cout << endl;
//	cout << "v2: " << endl;
//	for (auto i : v2) {
//		cout << i << " ";
//	}
//	return 0;
//}
//--------------------------------------------------------------90 拷贝和替换 replace
/*
功能描述：
将容器内指定范围的旧元素修改为新元素
函数原型：
replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内旧元素 替换成 新元素
// beg 开始迭代器
// end 结束迭代器
// oldvalue 旧元素
// newvalue 新元素
*/
//#include<vector>
//#include<algorithm>
//int main() {
//	vector<int> v;
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(10);
//	v.push_back(20);
//	cout << "替换前: " << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	//将20替换成999
//	replace(v.begin(), v.end(), 20, 999);
//	cout << "替换后: " << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	return 0;
//}

//--------------------------------------------------------------91拷贝和替换replace_if
//#include<vector>
//#include<algorithm>
//class Judge {
//public:
//	bool operator()(int val) {
//		return val <= 20;
//	}
//};
//int main() {
//	vector<int> v;
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(10);
//	v.push_back(20);
//	cout << "替换前: " << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	//小于等于20的替换为666
//	replace_if(v.begin(), v.end(), Judge(), 666);
//	cout << "替换后: " << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}cout << endl;
//	return 0;
//}

//--------------------------------------------------------------92拷贝和替换swap
/*
功能描述：
  互换两个容器的元素
函数原型：
  swap(container c1, container c2);
// 互换两个容器的元素
// c1容器1
// c2容器2
*/
//#include<vector>
//#include<algorithm>
//void showBoth(const vector<int>& v1, const vector<int>& v2) {
//	cout << "v1: " << endl;
//	for (auto i : v1) {
//		cout << i << " ";
//	}cout << endl;
//	cout << "v2: " << endl;
//	for (auto i : v2) {
//		cout << i << " ";
//	}cout << endl;
//}
//int main() {
//	vector<int>v1{ 1,2,3,4,5 };
//	vector<int>v2{ 7,6,5,4,3,2,1 };
//	cout << "交换前：" << endl;
//	showBoth(v1, v2);
//	swap(v1, v2);
//	cout << "交换后：" << endl;
//	showBoth(v1, v2);
//	return 0;
//}

//--------------------------------------------------------------93算术生成accumulate
/*
功能描述：               <numeric>
  计算区间内 容器元素累计总和
函数原型：
  accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和
// beg 开始迭代器
// end 结束迭代器
// value 起始值
*/
//#include<vector>
//#include<numeric>
//int main() {
//	vector<int> v;
//	for (int i = 0; i <= 100; i++) {
//		v.push_back(i);
//	}
//	int sum = accumulate(v.begin(), v.end(), 10);
//	cout << "sum = " << sum << endl;//5050+10
//	return 0;
//}

//--------------------------------------------------------------94算术生成fill
/*
功能描述：
  向容器中填充指定的元素
函数原型：
  fill(iterator beg, iterator end, value);
// 向容器中填充元素
// beg 开始迭代器
// end 结束迭代器
// value 填充的值
*/
//#include<numeric>
//#include<vector>
//int main() {
//	vector<int>v1;
//	v1.resize(10);
//	vector<int>v2{1,2,3,4,5};
//	fill(v1.begin(), v1.end(), 666);
//	fill(v2.begin(), v2.end(), 999);
//	for (auto i : v1) {
//		cout << i << " ";
//	}cout << endl;
//	for (auto i : v2) {
//		cout << i << " ";
//	}cout << endl;
//	return 0;
//}

//--------------------------------------------------------------95集合算法 set_intersection
/*
学习目标：
掌握常用的集合算法
算法简介：
set_intersection // 求两个容器的交集
set_union // 求两个容器的并集
set_difference // 求两个容器的差集

  功能描述：
求两个容器的交集
  函数原型：
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的交集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
dest 目标容器开始迭代器
  总结：
求交集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器中取小值
set_intersection返回值既是交集中最后一个元素的位置
*/
//#include<vector>
//#include<algorithm>
//class ShowV {
//public:
//	void operator()(int val) {
//		cout << val << " ";
//	}
//};
//int main() {
//	vector<int>v1{ 1,2,3,4,5 };
//	vector<int>v2{ 3,4,5,6,7 };
//	vector<int>vTarget;
//	vTarget.resize(min(v1.size(), v2.size()));
//	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
//	for_each(vTarget.begin(), itEnd, ShowV());//注意itEnd，如果是vTarget.end()，会多出多余的0
//	return 0;
//}

//--------------------------------------------------------------96集合算法 set_union
/*
  功能描述：
求两个集合的并集
  函数原型：
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
dest 目标容器开始迭代器
  总结：
求并集的两个集合必须的有序序列
目标容器开辟空间需要两个容器相加
set_union返回值既是并集中最后一个元素的位置
*/

//--------------------------------------------------------------97集合算法 set_difference
/*
  功能描述：
求两个集合的差集 v1,v2差集：v1-(v1交v2)
  函数原型：
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的差集
// 注意:两个集合必须是有序序列
// beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 //
dest 目标容器开始迭代器
  总结：
求差集的两个集合必须的有序序列
目标容器开辟空间需要从两个容器取较大值
set_difference返回值既是差集中最后一个元素的位置
*/
//#include<algorithm>
//#include<vector>
//class Show {
//public:
//	void operator()(int val) {
//		cout << val << " ";
//	}
//};
//int main() {
//	vector<int> v1;
//	vector<int> v2;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	vector<int>vTarget1;
//	vTarget1.resize(max(v1.size(), v2.size()));
//	vector<int>::iterator itEnd1 =
//		set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
//	cout << "v1和v2的差集: " << endl;
//	for_each(vTarget1.begin(), itEnd1, Show());
//	cout << endl;
//
//	vector<int>vTarget2;
//	vTarget2.resize(max(v1.size(), v2.size()));
//	vector<int>::iterator itEnd2 =
//		set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget2.begin());
//	cout << "v2和v1的差集: " << endl;
//	for_each(vTarget2.begin(), itEnd2, Show());
//	cout << endl;
//	return 0;
//}