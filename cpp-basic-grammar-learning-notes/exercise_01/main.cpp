////17 类模板案例-数组类封装
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
//	cout << "int类型的测试：" << endl;
//	myArray<int>arr1(5);
//	myArray<int>arr2(arr1);
//	myArray<int>arr3(50);
//	arr3 = arr1;
//	for (int i = 0; i < 5; i++) {
//		arr1.pushBack(i);
//	}
//	showArray(arr1);
//	cout << "输出arr1的容量：" << endl;
//	cout << arr1.myCapacity() << endl;
//	cout << "输出arr1的实际大小：" << endl;
//	cout << arr1.mySize() << endl;
//	cout << "~~~经过一波尾删~~~" << endl;
//	for (int i = 0; i < 3; i++) {
//		arr1.popBack();
//	}
//	showArray(arr1);
//	cout << "输出arr1的容量：" << endl;
//	cout << arr1.myCapacity() << endl;
//	cout << "输出arr1的实际大小：" << endl;
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
//	cout << "~~~经过一波尾删~~~" << endl;
//	arr.popBack();
//	arr.popBack();
//	showPerArray(arr);
//	//‘=’或拷贝构造的调用可能需要手写Per类的=重载或拷贝构造。
//}
