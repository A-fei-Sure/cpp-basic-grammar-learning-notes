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
//	//��������
//	Per p1("����", 35, 175);
//	Per p2("�ܲ�", 45, 180);
//	Per p3("��Ȩ", 40, 170);
//	Per p4("����", 25, 190);
//	Per p5("�ŷ�", 35, 160);
//	Per p6("����", 35, 200);
//	L.push_back(p1);
//	L.push_back(p2);
//	L.push_back(p3);
//	L.push_back(p4);
//	L.push_back(p5);
//	L.push_back(p6);
//
//	for (Per i : L) {
//		cout << "������" << i.name << "\t���䣺" << i.age << "\t��ߣ�" << i.height << endl;
//	}
//
//	L.sort(myCompare); cout << endl;
//
//	for (Per i : L) {
//		cout << "������" << i.name << "\t���䣺" << i.age << "\t��ߣ�" << i.height << endl;
//	}
//}
//
//int main() {
//	test01();
//	return 0;
//}