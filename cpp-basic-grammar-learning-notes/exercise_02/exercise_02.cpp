//#include<iostream>
//#include<vector>
//#include<string>
//#include<deque>
//#include<cstdlib>
//#include<algorithm>
//#include<ctime>
//using namespace std;
//
//class Per {
//public:
//	//Per() {}
//	Per(string n, double s) :name(n), score(s) {}
//
//	string name;//姓名
//	double score;//平均分
//};
//
//void createPer(vector<Per>& v);
//void setScore(vector<Per>& v);
//void showScore(vector<Per>v);
//
//
//int main() {
//	//随机数种子//没有的话每次运行结果都一样
//	srand((unsigned int)time(nullptr));
//
//	//1.创建5个选手
//	vector<Per>v;//存放选手的容器
//	createPer(v);
//
//	//2.打分
//	setScore(v);
//
//	//3.显示最后得分
//	showScore(v);
//
//	return 0;
//}
//
//void createPer(vector<Per>& v) {
//	string nameSeed = "ABCDE";
//	for (int i = 0; i < 5; i++) {
//		string name = "player";
//		name += nameSeed[i];
//		Per p(name, 0.0);
//
//		//将创建的选手对象放入容器中
//		v.push_back(p);
//	}
//}
//
//void setScore(vector<Per>& v) {
//	for (vector<Per>::iterator it = v.begin(); it != v.end(); it++) {
//		//先将10个评委打的分数存起来
//		deque<int>d;
//		for (int i = 0; i < 10; i++) {
//			int score = rand() % 41 + 60;//[60,100]
//			d.push_back(score);
//		}
//
//		//排序（升序）
//		sort(d.begin(), d.end());
//
//		//掐头去尾
//		d.pop_front();
//		d.pop_back();
//
//		//获取平均分
//		int sum = 0;
//		for (auto i : d) {
//			sum += i;
//		}
//		double average = (double)sum / d.size();
//
//		//赋值给选手
//		it->score = average;
//	}
//}
//
//void showScore(vector<Per>v) {
//    for (Per i : v) {//这里用auto不太行
//	   cout << "选手姓名：" << i.name << "\t分数：" << i.score << endl;
//    }
//}