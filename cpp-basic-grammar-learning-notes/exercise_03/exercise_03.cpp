//
//#include<iostream>
//#include<list>
//#include<string>
//using namespace std;
//
//class Per {
//public:
//	Per(string n, int a, int h) :name(n), age(a), height(h) {}
//
//	string name;
//	int age;
//	int height;
//};
//
//bool myCompare(const Per& p1, const Per& p2) {
//	if (p1.age == p2.age) {
//		return (p1.height > p2.height);
//	}
//	else {
//		return p1.age > p2.age;
//	}
//}
//
//void test01(){
//	list<Per>L;
//
//	//载入数据
//	Per p1("刘备", 35, 175);
//	Per p2("曹操", 45, 180);
//	Per p3("孙权", 40, 170);
//	Per p4("赵云", 25, 190);
//	Per p5("张飞", 35, 160);
//	Per p6("关羽", 35, 200);
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	for (Per i : L) {
//		cout << "姓名：" << i.name << "\t年龄：" << i.age << "\t身高：" << i.height << endl;
//	}
//
//	L.sort(myCompare); cout << endl;
//
//	for (Per i : L) {
//		cout << "姓名：" << i.name << "\t年龄：" << i.age << "\t身高：" << i.height << endl;
//	}
//}
//
//int main() {
//	test01();
//	return 0;
//}