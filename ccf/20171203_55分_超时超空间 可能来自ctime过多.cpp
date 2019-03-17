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

typedef struct ctime{//为-1表示不限制
	int year, mon, day, hour, min, week;
	string name;
	ctime(int op,int a, int b, int c, int d, int e, string f = "") {//限制时间的录入方式 规则时间的录入方式指定周而没有年
		mon = b, day = c, hour = d, min = e; 
		name = f;
		if (op == 0) {//初始为时间
			year = a;
			//计算week,算得和
			week = getweek(day, mon, year);
		}
		else {//否则为规则
			year = -1;
			//指定week
			week = a;
		}
		
	}
	int operator ==(ctime &tt) {
		if (year == -1 || tt.year == -1) {//有一个为-1不比年份
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
		else {//两个都不为-1，说明为非规则比较，start&end
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
	void operator ++(int) {//后缀要int 前缀不需要
		min++;
		if (min == 60) {//0~59
			min = 0;
			hour++;
			if (hour == 24) {//0~23
				hour = 0;
				day++;
				week = (week + 1) % 7;//1~6 0为星期天
				//忘加上了
				if (day>getdays(mon,year)) {//需要根据月份判断天数，需要根据年份判断二月天数  1~28/29/30/31
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
	int to(int a, int b, int c, int d, int e, string f = "") {//赋值
		year = a, mon = b, day = c, hour = d, min = e;
		//计算week,算得和
		week = getweek(day, mon, year);
		name = f;
	}
	void print() {
		//year, mon, day, hour, min, week;
		//补充的是空格，不是0
		cout << year;
		printwithzero(mon), printwithzero(day), printwithzero(hour), printwithzero(min);
		//printf("%d%2d%2d%2d%2d", year, mon, day, hour, min);
	}
	void printname() {
		cout << name << endl;
	}
}ctime;

strvec splitbystr(strvec &result,string s, string b) {//不会有以， -结束的情况，比较简单
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


int main(){//不能使用memset…… 拓展成负数了
	int i,j,k,n,m,h;
	string tmpstr;
	strvec singlerule(6),splitedstr,littlesplitedstr;
	char charstr[20];
	vector<int> intrule[5];//只有前五个才需要
	vector<ctime> rules;
	for (i = 1; i <= 12; i++) {
		months[monsss[i - 1]] = i;
		itoa(i, charstr, 10);
		months[charstr] = i;//1~12字符串也赋值为1~12
	}
	for (i = 0; i < 7; i++) {
		weeks[weeksss[i]] = i;
		itoa(i, charstr, 10);
		weeks[charstr] = i;//0~6字符串也赋值为0~6
	}
	/*星期测试
	while (1) {
		cout << "year mon day";
		cin >> c >> b >> a;
		cout<<getweek(a, b, c)<<endl;
	}*/
	//n个条件 输入开始 结束时间
	cin >> n >> tmpstr;
	//int year, mon, day, hour, min;//week自动计算 201711170032
	ctime cur(0,atoi(tmpstr.substr(0, 4).c_str()), atoi(tmpstr.substr(4, 2).c_str()), atoi(tmpstr.substr(6, 2).c_str()), atoi(tmpstr.substr(8, 2).c_str()), atoi(tmpstr.substr(10, 2).c_str()));
	cin >> tmpstr;
	ctime end(0,atoi(tmpstr.substr(0, 4).c_str()), atoi(tmpstr.substr(4, 2).c_str()), atoi(tmpstr.substr(6, 2).c_str()), atoi(tmpstr.substr(8, 2).c_str()), atoi(tmpstr.substr(10, 2).c_str()));
	//现在开始处理n个条件
	while (n-->0) {//n没有实际意义，会把,和-处理成多个条件
		/*6个字符串
		0 7 * * 1,3-5 get_up
		30 23 * * Sat,Sun go_to_bed
		15 12,18 * * * have_dinner
		min hours dayofmonth month dayofweek 规则名字
		其中min hour day没有异常 mon和week可能为字符串
		0天-6六
		*/
		for (i = 0; i < 6; i++) cin >> singlerule[i];
		//min hour day普通处理
		for (i = 0; i < 3; i++) {//识别有无， 先根据,切分 再根据-切分
			intrule[i].clear();
			if (singlerule[i].compare("*") != 0) {
				splitbystr(splitedstr, singlerule[i], ",");
				if (splitedstr.empty()) {
					printf("Split ERROR!\n");
					return -1;
				}
				for (j = 0; j < splitedstr.size(); j++) {
					splitbystr(littlesplitedstr, splitedstr[j], "-");//最小切分
					if (littlesplitedstr.empty()) {
						printf("Split_2 ERROR!\n");
						return -1;
					}
					//如果大小为1 说明没有-
					if (littlesplitedstr.size() == 1) intrule[i].push_back(atoi(splitedstr[j].c_str()));
					else if (littlesplitedstr.size() == 2) {
						m = atoi(littlesplitedstr[0].c_str());//m-m+   那么包含m和m+在内的所有数字
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
			else intrule[i].push_back(-1);//不限
		}
		//4月份 5星期 如果是文字则调用map转数字
		//i=3;mon
		intrule[i].clear();
		if (singlerule[i].compare("*") != 0) {
			splitbystr(splitedstr, singlerule[i], ",");
			if (splitedstr.empty()) {
				printf("Split ERROR!\n");
				return -1;
			}
			for (j = 0; j < splitedstr.size(); j++) {
				splitbystr(littlesplitedstr, splitedstr[j], "-");//最小切分
				if (littlesplitedstr.empty()) {
					printf("Split_2 ERROR!\n");
					return -1;
				}
				//如果大小为1 说明没有-
				if (littlesplitedstr.size() == 1) intrule[i].push_back(months[splitedstr[j]]);
				else if (littlesplitedstr.size() == 2) {
					m = months[littlesplitedstr[0]];//m-m+   那么包含m和m+在内的所有数字
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
		else intrule[i].push_back(-1);//不限
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
				splitbystr(littlesplitedstr, splitedstr[j], "-");//最小切分
				if (littlesplitedstr.empty()) {
					printf("Split_2 ERROR!\n");
					return -1;
				}
				//如果大小为1 说明没有-
				if (littlesplitedstr.size() == 1) intrule[i].push_back(weeks[splitedstr[j]]);
				else if (littlesplitedstr.size() == 2) {
					m = weeks[littlesplitedstr[0]];//m-m+   那么包含m和m+在内的所有数字
					while (m <= weeks[littlesplitedstr[1]]) {
						intrule[i].push_back(m);
						m++;//又忘了！
					}
				}
				else {
					printf("size of littlesplitedstr=%d\n", littlesplitedstr.size());
					return -2;
				}
			}
		}
		else intrule[i].push_back(-1);//不限
		//最后是名字 不需要处理
		for (i = 0; i < intrule[0].size(); i++) {
			for (j = 0; j < intrule[1].size(); j++) {
				for (k = 0; k < intrule[2].size(); k++) {
					for (m = 0; m < intrule[3].size(); m++) {
						for (h = 0; h < intrule[4].size(); h++) {
							//规则时间没有year但是有week限制 4对应的是week
							//min hours dayofmonth month dayofweek
							//构造函数参数        op=1,week,         mon,          day,           hour,          min修改
							rules.push_back(ctime(1, intrule[4][h],intrule[3][m], intrule[2][k], intrule[1][j], intrule[0][i],singlerule[5]));
							//最后的规则名字要带上
						}
					}
				}
			}
		}
	}	
	while (!(cur == end)) {//等于的时候不比较直接退出
		for (i = 0; i < rules.size(); i++) {
			if (cur == rules[i]) {
				//匹配成功
				cur.print();//cur的name是" "
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
		//闰年 是4的倍数而不是100的倍数，或者是400的倍数
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 29;
		else return 28;
	}
}

int getweek(int day, int mon, int year) {
	///蔡勒公式https://blog.csdn.net/tigerisland45/article/details/81713845
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
	//根据年份计算
	//1970 1 1 星期4
	int count = 0;
	if (day == 29 && mon == 2) {//处理成普通日子 因为前一年是没有29号的
		count++, day--;
	}
	//算了还是直接算，中途规则有点复杂
	if (mon > 2) {//包含可能的2.29
		while (year > 1970) {//1 1肯定是最小的
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) count += 366;
			else count += 365;
			//注意，是否需要判断mon在2月前面还是后面，这个加的年份应该根据2月的年份判断
			year--;
		}
	}
	else {//在2月之下应该按照前一年，前一年闰年就是366，不然就是365
		while (year > 1970) {
			if ((year-1) % 400 == 0 || ((year-1) % 4 == 0 && (year-1) % 100 != 0)) count += 366;
			else count += 365;
			//注意，是否需要判断mon在2月前面还是后面，这个加的年份应该根据2月的年份判断
			year--;
		}
	}
	while (mon > 1) {//按照上一个月的天数
		count += getdays(mon - 1, 1970);
		mon--;
	}
	count += (day - 1);
	return (count + 4) % 7;

	*/
}

