#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;
typedef map<string, int> weekmap;

int getdays(int mon, int year);
int getweek(int day, int mon, int year);
void printwithzero(int i) {
	char s[10];
	itoa(i, s, 10);
	int a = strlen(s);
	while (a < 2) {
		cout << "0";
		a++;
	}
	cout << s;
}

typedef struct ctime{//Ϊ-1��ʾ������
	int year, mon, day, hour, min, week;
	string name;
	ctime(int op,int a, int b, int c, int d, int e, string f = "") {//����ʱ���¼�뷽ʽ ����ʱ���¼�뷽ʽָ���ܶ�û����
		mon = b, day = c, hour = d, min = e; 
		name = f;
		if (op == 0) {//��ʼΪʱ��
			year = a;
			//����week,��ú�
			week = getweek(day, mon, year);
		}
		else {//����Ϊ����
			year = -1;
			//ָ��week
			week = a;
		}
		
	}
	int operator ==(ctime &tt) {
		if (year == -1 || tt.year == -1) {//��һ��Ϊ-1�������
			if (tt.mon == -1 || tt.mon == mon) {
				if (tt.day == -1 || tt.day == day) {
					if (tt.hour == -1 || tt.hour == hour) {
						if (tt.min == -1 || tt.min == min) {
							if (tt.week == -1 || tt.week == week) {
								return 1;
							}
						}
					}
				}
			}
		}
		else {//��������Ϊ-1��˵��Ϊ�ǹ���Ƚϣ�start&end
			if (tt.year == year) {
				if (tt.mon == -1 || tt.mon == mon) {
					if (tt.day == -1 || tt.day == day) {
						if (tt.hour == -1 || tt.hour == hour) {
							if (tt.min == -1 || tt.min == min) {
								if (tt.week == -1 || tt.week == week) {
									return 1;
								}
							}
						}
					}
				}
			}
		}
		return 0;
	}
	void operator ++(int) {//��׺Ҫint ǰ׺����Ҫ
		min++;
		if (min == 60) {//0~59
			min = 0;
			hour++;
			if (hour == 24) {//0~23
				hour = 0;
				day++;
				week = (week + 1) % 7;//1~6 0Ϊ������
				//��������
				if (day>getdays(mon,year)) {//��Ҫ�����·��ж���������Ҫ��������ж϶�������  1~28/29/30/31
					day = 1;
					mon++;
					if (mon == 13) {//1~12
						mon = 1;
						year++;
					}
				}
			}
		}
	}
	int to(int a, int b, int c, int d, int e, string f = "") {//��ֵ
		year = a, mon = b, day = c, hour = d, min = e;
		//����week,��ú�
		week = getweek(day, mon, year);
		name = f;
	}
	void print() {
		//year, mon, day, hour, min, week;
		//������ǿո񣬲���0
		cout << year;
		printwithzero(mon), printwithzero(day), printwithzero(hour), printwithzero(min);
		//printf("%d%2d%2d%2d%2d", year, mon, day, hour, min);
	}
	void printname() {
		cout << name << endl;
	}
}ctime;

strvec splitbystr(strvec &result,string s, string b) {//�������ԣ� -������������Ƚϼ�
	int pos, last = 0;
	result.clear();
	while ((pos = s.find(b, last)) != string::npos) {
		result.push_back(s.substr(last, pos - last));
		last = pos + b.size();
	}
	if (last != s.size()) {
		result.push_back(s.substr(last));
	}
	return result;
}


int dayofmon[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char monsss[][5] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char weeksss[][5] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
weekmap weeks,months;


int main(){//����ʹ��memset���� ��չ�ɸ�����
	int i,j,k,n,m,h;
	string tmpstr;
	strvec singlerule(6),splitedstr,littlesplitedstr;
	char charstr[20];
	vector<int> intrule[5];//ֻ��ǰ�������Ҫ
	vector<ctime> rules;
	for (i = 1; i <= 12; i++) {
		months[monsss[i - 1]] = i;
		itoa(i, charstr, 10);
		months[charstr] = i;//1~12�ַ���Ҳ��ֵΪ1~12
	}
	for (i = 0; i < 7; i++) {
		weeks[weeksss[i]] = i;
		itoa(i, charstr, 10);
		weeks[charstr] = i;//0~6�ַ���Ҳ��ֵΪ0~6
	}
	/*���ڲ���
	while (1) {
		cout << "year mon day";
		cin >> c >> b >> a;
		cout<<getweek(a, b, c)<<endl;
	}*/
	//n������ ���뿪ʼ ����ʱ��
	cin >> n >> tmpstr;
	//int year, mon, day, hour, min;//week�Զ����� 201711170032
	ctime cur(0,atoi(tmpstr.substr(0, 4).c_str()), atoi(tmpstr.substr(4, 2).c_str()), atoi(tmpstr.substr(6, 2).c_str()), atoi(tmpstr.substr(8, 2).c_str()), atoi(tmpstr.substr(10, 2).c_str()));
	cin >> tmpstr;
	ctime end(0,atoi(tmpstr.substr(0, 4).c_str()), atoi(tmpstr.substr(4, 2).c_str()), atoi(tmpstr.substr(6, 2).c_str()), atoi(tmpstr.substr(8, 2).c_str()), atoi(tmpstr.substr(10, 2).c_str()));
	//���ڿ�ʼ����n������
	while (n-->0) {//nû��ʵ�����壬���,��-����ɶ������
		/*6���ַ���
		0 7 * * 1,3-5 get_up
		30 23 * * Sat,Sun go_to_bed
		15 12,18 * * * have_dinner
		min hours dayofmonth month dayofweek ��������
		����min hour dayû���쳣 mon��week����Ϊ�ַ���
		0��-6��
		*/
		for (i = 0; i < 6; i++) cin >> singlerule[i];
		//min hour day��ͨ����
		for (i = 0; i < 3; i++) {//ʶ�����ޣ� �ȸ���,�з� �ٸ���-�з�
			intrule[i].clear();
			if (singlerule[i].compare("*") != 0) {
				splitbystr(splitedstr, singlerule[i], ",");
				if (splitedstr.empty()) {
					printf("Split ERROR!\n");
					return -1;
				}
				for (j = 0; j < splitedstr.size(); j++) {
					splitbystr(littlesplitedstr, splitedstr[j], "-");//��С�з�
					if (littlesplitedstr.empty()) {
						printf("Split_2 ERROR!\n");
						return -1;
					}
					//�����СΪ1 ˵��û��-
					if (littlesplitedstr.size() == 1) intrule[i].push_back(atoi(splitedstr[j].c_str()));
					else if (littlesplitedstr.size() == 2) {
						m = atoi(littlesplitedstr[0].c_str());//m-m+   ��ô����m��m+���ڵ���������
						while (m <= atoi(littlesplitedstr[1].c_str())) {
							intrule[i].push_back(m);
							m++;
						}
					}
					else {
						printf("size of littlesplitedstr=%d\n", littlesplitedstr.size());
						return -2;
					}
				}
			}
			else intrule[i].push_back(-1);//����
		}
		//4�·� 5���� ��������������mapת����
		//i=3;mon
		intrule[i].clear();
		if (singlerule[i].compare("*") != 0) {
			splitbystr(splitedstr, singlerule[i], ",");
			if (splitedstr.empty()) {
				printf("Split ERROR!\n");
				return -1;
			}
			for (j = 0; j < splitedstr.size(); j++) {
				splitbystr(littlesplitedstr, splitedstr[j], "-");//��С�з�
				if (littlesplitedstr.empty()) {
					printf("Split_2 ERROR!\n");
					return -1;
				}
				//�����СΪ1 ˵��û��-
				if (littlesplitedstr.size() == 1) intrule[i].push_back(months[splitedstr[j]]);
				else if (littlesplitedstr.size() == 2) {
					m = months[littlesplitedstr[0]];//m-m+   ��ô����m��m+���ڵ���������
					while (m <= months[littlesplitedstr[1]]) {
						intrule[i].push_back(m);
						m++;
					}
				}
				else {
					printf("size of littlesplitedstr=%d\n", littlesplitedstr.size());
					return -2;
				}
			}
		}
		else intrule[i].push_back(-1);//����
		i++;
		//i=4;week
		intrule[i].clear();
		if (singlerule[i].compare("*") != 0) {
			splitbystr(splitedstr, singlerule[i], ",");
			if (splitedstr.empty()) {
				printf("Split ERROR!\n");
				return -1;
			}
			for (j = 0; j < splitedstr.size(); j++) {
				splitbystr(littlesplitedstr, splitedstr[j], "-");//��С�з�
				if (littlesplitedstr.empty()) {
					printf("Split_2 ERROR!\n");
					return -1;
				}
				//�����СΪ1 ˵��û��-
				if (littlesplitedstr.size() == 1) intrule[i].push_back(weeks[splitedstr[j]]);
				else if (littlesplitedstr.size() == 2) {
					m = weeks[littlesplitedstr[0]];//m-m+   ��ô����m��m+���ڵ���������
					while (m <= weeks[littlesplitedstr[1]]) {
						intrule[i].push_back(m);
						m++;//�����ˣ�
					}
				}
				else {
					printf("size of littlesplitedstr=%d\n", littlesplitedstr.size());
					return -2;
				}
			}
		}
		else intrule[i].push_back(-1);//����
		//��������� ����Ҫ����
		for (i = 0; i < intrule[0].size(); i++) {
			for (j = 0; j < intrule[1].size(); j++) {
				for (k = 0; k < intrule[2].size(); k++) {
					for (m = 0; m < intrule[3].size(); m++) {
						for (h = 0; h < intrule[4].size(); h++) {
							//����ʱ��û��year������week���� 4��Ӧ����week
							//min hours dayofmonth month dayofweek
							//���캯������        op=1,week,         mon,          day,           hour,          min�޸�
							rules.push_back(ctime(1, intrule[4][h],intrule[3][m], intrule[2][k], intrule[1][j], intrule[0][i],singlerule[5]));
							//���Ĺ�������Ҫ����
						}
					}
				}
			}
		}
	}	
	while (!(cur == end)) {//���ڵ�ʱ�򲻱Ƚ�ֱ���˳�
		for (i = 0; i < rules.size(); i++) {
			if (cur == rules[i]) {
				//ƥ��ɹ�
				cur.print();//cur��name��" "
				cout << " ";
				rules[i].printname();
			}
		}
		cur++;
	}
	
	return 0;
}

int getdays(int mon, int year) {
	if (mon != 2) {
		return dayofmon[mon];
	}
	else {
		//���� ��4�ı���������100�ı�����������400�ı���
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 29;
		else return 28;
	}
}

int getweek(int day, int mon, int year) {
	///���չ�ʽhttps://blog.csdn.net/tigerisland45/article/details/81713845
	if (mon == 1 || mon == 2) {
		mon += 12;
		year--;
	}
	int c = year / 100;
	int y = year % 100;
	int m = mon;
	int d = day;
	int w = c / 4 - 2 * c + y + y / 4 + 26 * (m + 1) / 10 + d - 1;
	if (w < 0)
		return (w + (-w / 7 + 1) * 7) % 7;
	return w % 7;
	/*
	//������ݼ���
	//1970 1 1 ����4
	int count = 0;
	if (day == 29 && mon == 2) {//�������ͨ���� ��Ϊǰһ����û��29�ŵ�
		count++, day--;
	}
	//���˻���ֱ���㣬��;�����е㸴��
	if (mon > 2) {//�������ܵ�2.29
		while (year > 1970) {//1 1�϶�����С��
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) count += 366;
			else count += 365;
			//ע�⣬�Ƿ���Ҫ�ж�mon��2��ǰ�滹�Ǻ��棬����ӵ����Ӧ�ø���2�µ�����ж�
			year--;
		}
	}
	else {//��2��֮��Ӧ�ð���ǰһ�꣬ǰһ���������366����Ȼ����365
		while (year > 1970) {
			if ((year-1) % 400 == 0 || ((year-1) % 4 == 0 && (year-1) % 100 != 0)) count += 366;
			else count += 365;
			//ע�⣬�Ƿ���Ҫ�ж�mon��2��ǰ�滹�Ǻ��棬����ӵ����Ӧ�ø���2�µ�����ж�
			year--;
		}
	}
	while (mon > 1) {//������һ���µ�����
		count += getdays(mon - 1, 1970);
		mon--;
	}
	count += (day - 1);
	return (count + 4) % 7;

	*/
}

