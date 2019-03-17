#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

typedef vector<string> strvec;
typedef map<strvec,string> rules;

//<str> �� <int> ǰ��һ����б�ܣ�����Ҫô��б�ܣ�Ҫô�ǹ���Ľ�����Ҳ���Ǹò����ǹ�������һ���֣�

strvec splitrule(string &s){//����ƥ�䣬����path�����Ҫ����/
    int pos,last=1;//���ַ�Ϊ1����
    strvec result;
    while((pos=s.find('/',last))!=string::npos){
        result.push_back(s.substr(last,pos-last));
        last=pos+1;
    }
	if (s[s.size() - 1] == '/') result.push_back("/");
    if(last<s.size()){//�������/��β��������� ����path���û��/ 
        result.push_back(s.substr(last,s.size()-last));
    }
	return result;
}

int match(strvec &result,strvec rule,string &s) {
	result.clear();//ƥ��ʧ��404 ƥ��ɹ��Ŷ���
	/*
	����ƥ�䣺
	1.û��<>���м�ƥ�� �ַ���compare==0����
	2.<str> ����û��/���ַ���
	3.<int> ����û��/�����ִ�����'0'~'9'����Ĳ���
	4.<path> ����/���ַ���
	*/
	int i,pos,last=1,type,ii;
	char numberstr[250];
	string sub;
	//���ƥ��
	for (i = 0; i < rule.size(); i++) {
		pos = s.find('/', last);
		if (pos == string::npos) {//sҪô��/��β��Ҫô����û��/��β
			//���������/ ��ô�������s�Ƿ�/��β
			//���������/ ��ô����������һ���ַ���
			if (i < rule.size() - 1) return 0;//����������һ��������ôs�Ѿ�����ƥ���ˣ�s�����ܹ�ƥ�������һ��

			if (rule[i][0] == '/') {//��/��β�Ĺ��� ����������һ��������ô
				if (s[s.size() - 1] == '/') return 1;
				else return 0;
			}
			else {//s�Ѿ�û��/�ˣ�ֱ��ȡ�����ַ�������ƥ�� ʧ������;�˳����ɹ������pos==string::npos���ؽ��
				if (last < s.size()) sub = s.substr(last);
			}
		}
		else sub = s.substr(last, pos - last);
		if (rule[i][0] == '<') {
			switch (rule[i][1]) {
			case 's':
				//ĳ���ַ��� ������
				result.push_back(sub);
				break;
			case 'i':
				//ĳ������ ��Ҫ���
				for (ii = 0; ii < sub.size(); ii++) {
					if (sub[ii]<'0' || sub[ii]>'9') return 0;
				}
				//������Ҫתһ��09--->int-->9  result.push_back(std::to_string(ii));
				//ii = atoi(sub.c_str());
				//itoa(ii,numberstr,10);
				//result.push_back(numberstr);
				while (sub[0] == '0') sub.erase(0, 1);
				result.push_back(sub);
				//
				break;
			case 'p':
				sub = s.substr(last);//��ȡȫ��
				result.push_back(sub);
				break;
			default:
				//printf("error\n");
				return 0;
				break;
			}
		}
		else {
			//��ͨ�ַ�����ȫ���
			if (sub.compare(rule[i]) == 0);//result.push_back(sub);//���󣺲��ǲ���������Ҫpush��ȥ
			else return 0;//ʧ��
		}
		last = pos + 1;
	}
	//���︺��path��β��û��/�����
	if (i == rule.size()) {
		if (rule[i - 1].compare("<path>") == 0) return 1;
		else {//�ַ���ƥ��
			if (rule[i - 1][0] == '/') {//β������/�� Ӧ���Ѿ������������ƥ��
				if (pos==string::npos&&s[s.size() - 1] == '/') return 1;
				else return 0;
			}
			else {
				if (pos == string::npos&&s[s.size() - 1] != '/') return 1;//����û/ sҲû/ƥ��ɹ������������Ľ�� 
			}
		}
	}
	//<str> �� <int> ǰ��һ����б�ܣ�����Ҫô��б�ܣ�Ҫô�ǹ���Ľ�����Ҳ���Ǹò����ǹ�������һ���֣�
	//���������ȫƥ�� �������ͨ�ַ���ƥ��ʱlast=pos+1Ӧ��>=size ������path����û�е���β�ͣ�����ƥ��rule
	return 0;
}

int main(){//����ʹ��memset���� ��չ�ɸ�����
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
				//ƥ��ɹ�
				flag = 1;
				if (rule.size() > 0) {
					cout << mit->second << " ";
					for (ii = 0; ii < rule.size() - 1; ii++) {
						cout << rule[ii] << " ";
					}
					cout << rule[ii] << endl;
				}
				else cout << mit->second << endl;
				break;//��һ��
			}
		}
		if (flag == 0) cout << "404" << endl;
    }

    return 0;
}

