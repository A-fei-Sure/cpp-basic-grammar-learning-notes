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
//	//1.创建员工
//	vector<Worker>w1;
//	createWorker(w1);
//
//	//2.员工分组
//	multimap<int, Worker>m1;
//	setGroup(w1, m1);
//
//	//3、分组显示员工
//	showWorkerByGourp(m1);
//	return 0;
//}
//
//void createWorker(vector<Worker>& w1) {
//	string nameSeed = "ABCDEFGHIJ";
//	for (int i = 0; i < 10; i++)
//	{
//		Worker worker;
//		worker.name = "员工";
//		worker.name += nameSeed[i];
//		worker.salary = rand() % 10000 + 10000; // 10000 ~ 19999
//		//将员工放入到容器中
//		w1.push_back(worker);
//	}
//}
//
//void setGroup(vector<Worker>& w1, multimap<int, Worker>& m1) {
//	for (auto i : w1) {
//		//产合随机部门编号
//		int depId = rand() % 3;//0 1 2
//		//将员工插入分组
//		//key部门编号，value具体员工
//		m1.insert(make_pair(depId, i));
//	}
//}
//
//void showWorkerByGourp(multimap<int, Worker>& m) {
//	// 0 A B C 1 D E 2 F G ...
//	cout << "策划部门：" << endl;
//	multimap<int, Worker>::iterator pos = m.find(CEHUA);
//	int count = m.count(CEHUA); // 统计具体人数
//	int index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary <<
//			endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "美术部门： " << endl;
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU); // 统计具体人数
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary <<
//			endl;
//	}
//	cout << "----------------------" << endl;
//	cout << "研发部门： " << endl;
//	pos = m.find(YANFA);
//	count = m.count(YANFA); // 统计具体人数
//	index = 0;
//	for (; pos != m.end() && index < count; pos++, index++)
//	{
//		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary <<
//			endl;
//	}
//
//}