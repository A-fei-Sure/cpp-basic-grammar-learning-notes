////17 ��ģ�尸��-�������װ
//
//#include"help.hpp"
//void test01();
//void test02();
//
//
//
//int main() {
//	test01(); cout << endl;
//	test02(); cout << endl;
//	return 0;
//}
//
//void test01() {
//	cout << "int���͵Ĳ��ԣ�" << endl;
//	myArray<int>arr1(5);
//	myArray<int>arr2(arr1);
//	myArray<int>arr3(50);
//	arr3 = arr1;
//	for (int i = 0; i < 5; i++) {
//		arr1.pushBack(i);
//	}
//	showArray(arr1);
//	cout << "���arr1��������" << endl;
//	cout << arr1.myCapacity() << endl;
//	cout << "���arr1��ʵ�ʴ�С��" << endl;
//	cout << arr1.mySize() << endl;
//	cout << "~~~����һ��βɾ~~~" << endl;
//	for (int i = 0; i < 3; i++) {
//		arr1.popBack();
//	}
//	showArray(arr1);
//	cout << "���arr1��������" << endl;
//	cout << arr1.myCapacity() << endl;
//	cout << "���arr1��ʵ�ʴ�С��" << endl;
//	cout << arr1.mySize() << endl;
//}
//
//void test02() {
//	myArray<Per>arr(10);
//	Per p1("jerry", 2);
//	Per p2("Tom", 8);
//	Per p3("kazz", 50);
//	Per p4("John", 2100);
//	Per p5("Marry", 1200);
//	arr.pushBack(p1);
//	arr.pushBack(p2);
//	arr.pushBack(p3);
//	arr.pushBack(p4);
//	arr.pushBack(p5);
//	showPerArray(arr);
//	cout << "~~~����һ��βɾ~~~" << endl;
//	arr.popBack();
//	arr.popBack();
//	showPerArray(arr);
//	//��=���򿽱�����ĵ��ÿ�����Ҫ��дPer���=���ػ򿽱����졣
//}
