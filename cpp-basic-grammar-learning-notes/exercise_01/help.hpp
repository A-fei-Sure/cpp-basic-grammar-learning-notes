//#pragma once
//
//#include<iostream>
//using namespace std;
//
//class Per {
//public:
//	Per() {}
//	Per(string n, int a) :name(n), age(a) {}
//	string name;
//	int age;
//};
//
//template<class T>
//class myArray {
//public:
//	//有参构造函数
//	myArray(int capacity);
//
//	//拷贝构造函数（不重写的话系统默认浅拷贝）
//	myArray(const myArray& arr) {
//		this->size = arr.size;
//		this->capacity = arr.capacity;
//		//深拷贝
//		this->pAddress = new T[arr.size];
//		for (int i = 0; i < arr.size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		cout << "myArray拷贝构造函数" << endl;
//	}
//
//	//重载=运算符
//	myArray& operator=(const myArray& arr) {
//		//先判断原来堆区是否有数据，有的话先释放
//		if (this->pAddress != nullptr) {
//			delete[] this->pAddress;
//			this->pAddress = nullptr;
//			this->capacity = 0;//这两个0可以省去
//			this->size = 0;
//		}
//		//深拷贝
//		this->size = arr.size;
//		this->capacity = arr.capacity;
//		this->pAddress = new T[arr.size];
//		for (int i = 0; i < arr.size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		cout << "myArray重载=运算符" << endl;
//		return *this;
//	}
//
//	//尾插法
//	void pushBack(const T& val) {
//		if (this->capacity == this->size) {
//			cout << "已经被填满了" << endl;
//			return;
//		}
//		this->pAddress[this->size] = val;
//		this->size++;
//	}
//
//	//尾删法
//	void popBack() {
//		if (this->size == 0) {
//			cout << "已经被榨干了" << endl;
//			return;
//		}
//		this->size--;
//	}
//
//	//通过下标访问元素数据
//	T& operator[](int index) {
//		return this->pAddress[index];
//	}
//
//	//返回数组的容量
//	int myCapacity() {
//		return this->capacity;
//	}
//
//	//返回数组大小
//	int mySize() {
//		return this->size;
//	}
//
//		//析构函数
//		~myArray() {
//			if (this->pAddress != nullptr) {
//				delete[] this->pAddress;
//				this->pAddress = nullptr;
//			}
//			cout << "myArray析构函数" << endl;
//		}
//	
//private:
//	T* pAddress;//数组 指向真实空间
//	int capacity;//容量
//	int size;//实际大小
//};
////有参构造函数
//template<class T>
//myArray<T>::myArray(int capacity) {
//	this->capacity = capacity;
//	this->size = 0;
//	this->pAddress = new T[capacity];
//	cout << "myArray有参构造函数" << endl;
//}
//
////针对基本数据类型 & 引用数据类型的打印输出
//template<class T>
//void showArray(myArray<T>& arr) {
//	cout << "遍历模板数据：" << endl;
//	for (int i = 0; i < arr.mySize(); i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
////针对Per类的打印输出
//void showPerArray(myArray<Per>& arr) {
//	cout << "遍历Per模板数据：" << endl;
//	for (int i = 0; i < arr.mySize(); i++) {
//		cout << "name: " << arr[i].name << "\t" << "age: " << arr[i].age << endl;
//	}
//}