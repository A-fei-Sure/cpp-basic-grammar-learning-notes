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
//	string name;//����
//	double score;//ƽ����
//};
//
//void createPer(vector<Per>& v);
//void setScore(vector<Per>& v);
//void showScore(vector<Per>v);
//
//
//int main() {
//	//���������//û�еĻ�ÿ�����н����һ��
//	srand((unsigned int)time(nullptr));
//
//	//1.����5��ѡ��
//	vector<Per>v;//���ѡ�ֵ�����
//	createPer(v);
//
//	//2.���
//	setScore(v);
//
//	//3.��ʾ���÷�
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
//		//��������ѡ�ֶ������������
//		v.push_back(p);
//	}
//}
//
//void setScore(vector<Per>& v) {
//	for (vector<Per>::iterator it = v.begin(); it != v.end(); it++) {
//		//�Ƚ�10����ί��ķ���������
//		deque<int>d;
//		for (int i = 0; i < 10; i++) {
//			int score = rand() % 41 + 60;//[60,100]
//			d.push_back(score);
//		}
//
//		//��������
//		sort(d.begin(), d.end());
//
//		//��ͷȥβ
//		d.pop_front();
//		d.pop_back();
//
//		//��ȡƽ����
//		int sum = 0;
//		for (auto i : d) {
//			sum += i;
//		}
//		double average = (double)sum / d.size();
//
//		//��ֵ��ѡ��
//		it->score = average;
//	}
//}
//
//void showScore(vector<Per>v) {
//    for (Per i : v) {//������auto��̫��
//	   cout << "ѡ��������" << i.name << "\t������" << i.score << endl;
//    }
//}