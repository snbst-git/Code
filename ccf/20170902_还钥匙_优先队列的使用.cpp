#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define VECSORT

using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;
typedef map<string, int> weekmap;

typedef struct operation {//1.time�Ⱥ�˳�� 2.op=0�������op=1�� �����ȼ��� 3.key˳���С����
	int op, key, time;
	operation(int a, int b,int c) {
		op = a, key = b, time = c;
	}
#ifdef VECSORT
	int operator >(operation &opp) {
		if (time == opp.time) {
			if (op == opp.op) {
				return key < opp.key;//Կ�׺���С����
			}
			else return op > opp.op;//ͬʱ������
		}
		else return time < opp.time;//ʱ��ǰ����
	}
#endif
}operation;

/*
int cmp(operation a, operation b) {//ֱ����cmp��������
	return a > b;
	//���ս����a>b����ǰ��
}*/

#ifdef VECSORT
//���cmp��������Ҫ�Զ���< ����ų���������
bool operator <(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key < b.key;//Կ�׺���С����
		}
		else return a.op > b.op;//ͬʱ������
	}
	else return a.time < b.time;//ʱ��ǰ����
}
int cmp(operation a, operation b) {//ֱ����cmp��������
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key < b.key;//Կ�׺���С����
		}
		else return a.op > b.op;//ͬʱ������
	}
	else return a.time < b.time;//ʱ��ǰ����
}
#else
//less�󶥶�ʹ��< �����a<b�� b�ڶ���ϴ���ǰ
bool operator <(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key > b.key;//Կ�׺���С����
		}
		else return a.op < b.op;//ͬʱ������
	}
	else return a.time > b.time;//ʱ��ǰ����
}
//greaterС���Ѷ���> �����a>b�� b�ڶ����С��ǰ
bool operator >(operation a, operation b) {
	if (a.time == b.time) {
		if (a.op == b.op) {
			return a.key > b.key;//Կ�׺���С����
		}
		else return a.op < b.op;//ͬʱ������
	}
	else return a.time > b.time;//ʱ��ǰ����
}
#endif

int main(){//����ʹ��memset���� ��չ�ɸ�����
	int a,b,c,N,K,i;
	cin >> N >> K;
	#ifdef VECSORT
	vector<operation> ops;
	#else
	//priority_queue<operation, vector<operation>,less<operation> > ops;//less���Ǵ󶥶���
	priority_queue<operation,vector<operation>,greater<operation> > ops;//greater���ص���С����
	#endif
	vector<int> keys(N + 1);
	vector<int>::iterator vit;
	priority_queue<int, vector<int>, greater<int> > freepos;//greaterʵ��С����top ��Ҫ����>
	for (i = 1; i <= N; i++) keys[i] = i;
	i = K;
	while (i-- > 0) {
		cin >> a >> b >> c;
		#ifdef VECSORT
		//bʱ�̽�aԿ��
		ops.push_back(operation(0, a, b));
		//b+cʱ�̻�aԿ��
		ops.push_back(operation(1, a, b+c));
		#else
		ops.push(operation(0, a, b));
		ops.push(operation(1, a, b+c));
		#endif
	}

#ifdef VECSORT
	//sort(ops.begin(), ops.end(),cmp);//ʹ��ʱ������
	sort(ops.begin(), ops.end());//ʹ��ʱ������
	for (i = 0; i < ops.size(); i++) {
		if (ops[i].op == 0) {//��Կ��
			//�ҵ�����key��ʲôλ��
			vit=find(keys.begin(), keys.end(), ops[i].key);
			if (vit == keys.end()) {
				printf("can't find %d\n", ops[i].key);
				return -1;
			}
			a = distance(keys.begin(), vit);//��0��ʼ�ĵ���begin�ǣ����Բ���Ҫ+1��
			freepos.push(a);//�±��1��ʼ
			*vit = -1;//�����õ�ԭ�������棬��ȻҲ������[]���޸�
			//freepos.push(ops[i].key);//��λ�ÿ��� ����Ӧ����λ��
		}
		else {//��Կ��
			a = freepos.top();
			freepos.pop();
			keys[a] = ops[i].key;//aλ�÷���op.key
		}
	}
#else
	while (!ops.empty()) {
		if (ops.top().op == 0) {//��Կ��
							 //�ҵ�����key��ʲôλ��
			vit = find(keys.begin(), keys.end(), ops.top().key);
			if (vit == keys.end()) {
				printf("can't find %d\n", ops.top().key);
				return -1;
			}
			a = distance(keys.begin(), vit);//��0��ʼ�ĵ���begin�ǣ����Բ���Ҫ+1��
			freepos.push(a);//�±��1��ʼ
			*vit = -1;//�����õ�ԭ�������棬��ȻҲ������[]���޸�
					  //freepos.push(ops[i].key);//��λ�ÿ��� ����Ӧ����λ��
		}
		else {//��Կ��
			a = freepos.top();
			freepos.pop();
			keys[a] = ops.top().key;//aλ�÷���op.key
		}
		ops.pop();
	}
#endif // VECSORT



	for (i = 1; i < N; i++) cout << keys[i] << " ";
	cout << keys[i] << endl;
	return 0;
}
