//
//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//#include<map>
//using namespace std;
//
//#define CEHUA 0
//#define MEISHU 1
//#define YANFA 2
//
//
//class Worker {
//public:
//	Worker() {}
//	Worker(string n, int a) :name(n), salary(a) {};
//	string name;
//	int salary;
//};
//
//void createWorker(vector<Worker>& w1);
//void setGroup(vector<Worker>& w1, multimap<int, Worker>& m1);
//void showWorkerByGourp(multimap<int, Worker>& m1);
//
//int main() {
//	srand((unsigned int)time(nullptr));
//
//	//1.����Ա��
//	vector<Worker>w1;
//	createWorker(w1);
//
//	//2.Ա������
//	multimap<int, Worker>m1;
//	setGroup(w1, m1);
//
//	//3��������ʾԱ��
//	showWorkerByGourp(m1);
//	return 0;
//}
//
//void createWorker(vector<Worker>& w1) {
//	string nameSeed = "ABCDEFGHIJ";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.name = "Ա��";
//		worker.name += nameSeed[i];
//		worker.salary = rand() % 10000 + 10000; // 10000 ~ 19999
//		//��Ա�����뵽������
//		w1.push_back(worker);
//	}
//}
//
//void setGroup(vector<Worker>& w1, multimap<int, Worker>& m1) {
//	for (auto i : w1) {
//		//����������ű��
//		int depId = rand() % 3;//0 1 2
//		//��Ա���������
//		//key���ű�ţ�value����Ա��
//		m1.insert(make_pair(depId, i));
//	}
//}
//
//void showWorkerByGourp(multimap<int, Worker>& m) {
//	// 0 A B C 1 D E 2 F G ...
//	cout << "�߻����ţ�" << endl;
//	multimap<int, Worker>::iterator pos = m.find(CEHUA);
//	int count = m.count(CEHUA); // ͳ�ƾ�������
//	int index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary <<
//			endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "�������ţ� " << endl;
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU); // ͳ�ƾ�������
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary <<
//			endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "�з����ţ� " << endl;
//	pos = m.find(YANFA);
//	count = m.count(YANFA); // ͳ�ƾ�������
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary <<
//			endl;
//	}
//
//}