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
//	//�вι��캯��
//	myArray(int capacity);
//
//	//�������캯��������д�Ļ�ϵͳĬ��ǳ������
//	myArray(const myArray& arr) {
//		this->size = arr.size;
//		this->capacity = arr.capacity;
//		//���
//		this->pAddress = new T[arr.size];
//		for (int i = 0; i < arr.size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		cout << "myArray�������캯��" << endl;
//	}
//
//	//����=�����
//	myArray& operator=(const myArray& arr) {
//		//���ж�ԭ�������Ƿ������ݣ��еĻ����ͷ�
//		if (this->pAddress != nullptr) {
//			delete[] this->pAddress;
//			this->pAddress = nullptr;
//			this->capacity = 0;//������0����ʡȥ
//			this->size = 0;
//		}
//		//���
//		this->size = arr.size;
//		this->capacity = arr.capacity;
//		this->pAddress = new T[arr.size];
//		for (int i = 0; i < arr.size; i++) {
//			this->pAddress[i] = arr.pAddress[i];
//		}
//		cout << "myArray����=�����" << endl;
//		return *this;
//	}
//
//	//β�巨
//	void pushBack(const T& val) {
//		if (this->capacity == this->size) {
//			cout << "�Ѿ���������" << endl;
//			return;
//		}
//		this->pAddress[this->size] = val;
//		this->size++;
//	}
//
//	//βɾ��
//	void popBack() {
//		if (this->size == 0) {
//			cout << "�Ѿ���ե����" << endl;
//			return;
//		}
//		this->size--;
//	}
//
//	//ͨ���±����Ԫ������
//	T& operator[](int index) {
//		return this->pAddress[index];
//	}
//
//	//�������������
//	int myCapacity() {
//		return this->capacity;
//	}
//
//	//���������С
//	int mySize() {
//		return this->size;
//	}
//
//		//��������
//		~myArray() {
//			if (this->pAddress != nullptr) {
//				delete[] this->pAddress;
//				this->pAddress = nullptr;
//			}
//			cout << "myArray��������" << endl;
//		}
//	
//private:
//	T* pAddress;//���� ָ����ʵ�ռ�
//	int capacity;//����
//	int size;//ʵ�ʴ�С
//};
////�вι��캯��
//template<class T>
//myArray<T>::myArray(int capacity) {
//	this->capacity = capacity;
//	this->size = 0;
//	this->pAddress = new T[capacity];
//	cout << "myArray�вι��캯��" << endl;
//}
//
////��Ի����������� & �����������͵Ĵ�ӡ���
//template<class T>
//void showArray(myArray<T>& arr) {
//	cout << "����ģ�����ݣ�" << endl;
//	for (int i = 0; i < arr.mySize(); i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
////���Per��Ĵ�ӡ���
//void showPerArray(myArray<Per>& arr) {
//	cout << "����Perģ�����ݣ�" << endl;
//	for (int i = 0; i < arr.mySize(); i++) {
//		cout << "name: " << arr[i].name << "\t" << "age: " << arr[i].age << endl;
//	}
//}