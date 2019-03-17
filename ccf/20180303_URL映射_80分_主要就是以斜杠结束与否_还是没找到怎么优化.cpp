#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;

//<str> 和 <int> 前面一定是斜杠，后面要么是斜杠，要么是规则的结束（也就是该参数是规则的最后一部分）

strvec splitrule(string &s){//规则匹配，对于path最后需要忽略/
    int pos,last=1;//首字符为1跳过
    strvec result;
    while((pos=s.find('/',last))!=string::npos){
        result.push_back(s.substr(last,pos-last));
        last=pos+1;
    }
	if (s[s.size() - 1] == '/') result.push_back("/");
    if(last<s.size()){//最后是以/结尾则走上面的 对于path最后没有/ 
        result.push_back(s.substr(last,s.size()-last));
    }
	return result;
}

int match(strvec &result,strvec rule,string &s) {
	result.clear();//匹配失败404 匹配成功放东西
	/*
	规则匹配：
	1.没有<>进行简单匹配 字符串compare==0即可
	2.<str> 任意没有/的字符串
	3.<int> 任意没有/的数字串，有'0'~'9'以外的不行
	4.<path> 包含/的字符串
	*/
	int i,pos,last=1,type,ii;
	char numberstr[250];
	string sub;
	//逐个匹配
	for (i = 0; i < rule.size(); i++) {
		pos = s.find('/', last);
		if (pos == string::npos) {//s要么是/结尾，要么就是没有/结尾
			//如果规则是/ 那么补充测试s是否/结尾
			//如果规则不是/ 那么补充测试最后一个字符串
			if (i < rule.size() - 1) return 0;//如果不是最后一个规则，那么s已经不够匹配了，s顶多能够匹配这最后一个

			if (rule[i][0] == '/') {//以/结尾的规则 如果不是最后一个规则那么
				if (s[s.size() - 1] == '/') return 1;
				else return 0;
			}
			else {//s已经没有/了，直接取最后的字符串进行匹配 失败则中途退出，成功则根据pos==string::npos返回结果
				if (last < s.size()) sub = s.substr(last);
			}
		}
		else sub = s.substr(last, pos - last);
		if (rule[i][0] == '<') {
			switch (rule[i][1]) {
			case 's':
				//某个字符串 无需检查
				result.push_back(sub);
				break;
			case 'i':
				//某个整数 需要检查
				for (ii = 0; ii < sub.size(); ii++) {
					if (sub[ii]<'0' || sub[ii]>'9') return 0;
				}
				//错误：需要转一下09--->int-->9  result.push_back(std::to_string(ii));
				//ii = atoi(sub.c_str());
				//itoa(ii,numberstr,10);
				//result.push_back(numberstr);
				while (sub[0] == '0') sub.erase(0, 1);
				result.push_back(sub);
				//
				break;
			case 'p':
				sub = s.substr(last);//截取全部
				result.push_back(sub);
				break;
			default:
				//printf("error\n");
				return 0;
				break;
			}
		}
		else {
			//普通字符串完全相符
			if (sub.compare(rule[i]) == 0);//result.push_back(sub);//错误：不是参数，不需要push进去
			else return 0;//失败
		}
		last = pos + 1;
	}
	//这里负责path和尾巴没有/的情况
	if (i == rule.size()) {
		if (rule[i - 1].compare("<path>") == 0) return 1;
		else {//字符串匹配
			if (rule[i - 1][0] == '/') {//尾巴上有/的 应该已经在上面进行了匹配
				if (pos==string::npos&&s[s.size() - 1] == '/') return 1;
				else return 0;
			}
			else {
				if (pos == string::npos&&s[s.size() - 1] != '/') return 1;//规则没/ s也没/匹配成功导致有这样的结果 
			}
		}
	}
	//<str> 和 <int> 前面一定是斜杠，后面要么是斜杠，要么是规则的结束（也就是该参数是规则的最后一部分）
	//规则必须完全匹配 下面分普通字符串匹配时last=pos+1应该>=size 而对于path可能没有到达尾巴，所以匹配rule
	return 0;
}

int main(){//不能使用memset…… 拓展成负数了
    int n,m,i,flag,ii;
    string sa,sb;
    rules rulemap;
	rules::iterator mit;
    strvec rule;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>sa>>sb;
        rule= splitrule(sa);
		rulemap[rule] = sb;
    }
    for(i=0;i<m;i++){
        cin>>sa;
		flag = 0;
		for (mit = rulemap.begin(); mit != rulemap.end(); mit++) {
			if (match(rule, mit->first, sa)) {
				//匹配成功
				flag = 1;
				if (rule.size() > 0) {
					cout << mit->second << " ";
					for (ii = 0; ii < rule.size() - 1; ii++) {
						cout << rule[ii] << " ";
					}
					cout << rule[ii] << endl;
				}
				else cout << mit->second << endl;
				break;//下一轮
			}
		}
		if (flag == 0) cout << "404" << endl;
    }

    return 0;
}

