#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;
typedef map<int,string> fathermap;
typedef vector<string> strvec;
struct ele;
typedef vector<ele> elevec;
vector<ele> eles;

//需要记录的信息 名字 属性（没有就是空） 父级（没有就是空字符串） 行数
struct ele{
	string name, id;
	strvec father;
	strvec fid;
    int line;
    ele(string a,string b,strvec c,int num,strvec e){
        name=a,id=b,father=c,line=num;//属性前面有个# 不作处理，比较的时候也是一样的
		fid = e;
    }
};

int cmpfather(ele &e,strvec &fa){
	if (fa.size() == 0) return 1;//没有限制条件
	if (e.father.size() == 0 && fa.size() != 0) return 0;//不可能满足条件
	int i, j;
	//可能不是紧跟着的！所以进行跨越
	for(i=e.father.size()-1,j=fa.size()-1;i>=0&&j>=0;i--){
		if (fa[j][0] != '#') {
			if (e.father[i].compare(fa[j])) continue;//不相等
			else j--;
		}
		else {//比较id
			if (e.fid[i].compare(fa[j])) continue;//不相等
			else j--;
		}	
	}
	if(j==-1) return 1;//全部相等
	return 0;
}

void selecteles(elevec &result,string str,int op) {
	result.clear();
	int i;
	if (op == 0) {
		for (i = 0; i < eles.size(); i++) {
			if (str.compare(eles[i].name) == 0) {
				result.push_back(eles[i]);
			}
		}
	}
	else if (op == 1) {
		for (i = 0; i < eles.size(); i++) {
			if (str.compare(eles[i].id) == 0) {
				result.push_back(eles[i]);
			}
		}
	}
}


//返回等级
int countstring(string &s){//因为前面的..最后也用不上
    //计算前面有的..数目
    int pos,num=0;
    while((pos=s.find(".."))!=string::npos){
        if(pos==0){
            num++;
            s.erase(0,2);//开头两个..
        }
        else break;
    }
	return num;
}
//维护一个vector 记录当前1 2 3分别是什么father 有新的这个等级的就替换

void splitstringbyspace(string a,strvec &result){
    int pos=0;

    result.clear();
    while((pos=a.find(" "))!=string::npos){
        result.push_back(a.substr(0,pos));
		a.erase(0, pos+1);//删掉pos+1 连空格
        //eg:abc def则last=0 pos=3 截取0开始的3个字符
    }
	//错误：没有考虑到最后剩下一个字符串没有空格的情况
	if (!a.empty()) result.push_back(a);//虽然没有空格，但是还有内容
}

int main(){
    int n,m,i,j,k,count;
	vector<int> out;
    string input,nullstr,str;
    cin>>n>>m;
    strvec strs,fvec,fidvec;
	elevec evec;
    fathermap fmap,fidmap;
    //fmap[-1]=nullstr;//0的上一级是NULL 现在使用vector 大不了size=0，没必要单独留一个
    fathermap::iterator mit,next,mmit,nnext;
	getchar();
    for(i=1;i<=n;i++){//i也是行数
        getline(cin,input);
        j=countstring(input);
        //默认不会有跳两级的情况出现

		fvec.clear();
		fidvec.clear();
        //注意有一个新的更高等级的时候，必须删除等级比它低的所有father
        for(mit=fmap.begin(),mmit=fidmap.begin();mit!=fmap.end()&&mmit!=fidmap.end();){//按照int排序的应该是
            //if(mit->first>=j) mit->second.clear();//清空 最好能用earse mit的方式！看一下用法
			next = mit;
			next++;
			nnext = mmit;
			nnext++;
			if (mit->first >= j) fmap.erase(mit),fidmap.erase(mmit);
			else fvec.push_back(mit->second),fidvec.push_back(mmit->second);//那就是大于，放进vec里面
			mit = next;	//删除后mit变为fmap.end()，不能再使用mit++，所以添加next记录接下来应该处理的，完成遍历功能
			mmit = nnext;
        }
        splitstringbyspace(input,strs);
        //把名称转换成小写
        transform(strs[0].begin(),strs[0].end(),strs[0].begin(),::tolower);//转小写
		fmap[j] = strs[0];
        if (strs.size() == 1) {
            //没有id
            eles.push_back(ele(strs[0],nullstr,fvec,i,fidvec));
			fidmap[j] = nullstr;
        }
        else if(strs.size()==2){//size==2
            eles.push_back(ele(strs[0],strs[1],fvec,i,fidvec));
			fidmap[j] = strs[1];
        }
        else{
            printf("Error\n");
        }
    }
	//比较严肃的问题：没有考虑div同名的问题，比如匹配的应该是div div p先找到了div div，但是二级div下面没有p，但是一级div下面有p
	//解决方案：保存全部的父亲 可以使用vector来弄，，，， map的意义没有了


	//感觉其实没必要单独留一个name，不如直接都放到vector里面去了…… 匹配的时候不都要这样挨个来的
	for (i = 1; i <= m; i++) {
		getline(cin, input);
		splitstringbyspace(input, strs);
		count = 0;
		out.clear();
		j = strs.size() - 1;
		str = strs[j];
		strs.erase(strs.begin() + j);//删除strs最后一项，其他都直接匹配father
		if (str[0] == '#') {//匹配id 理论上只会是最后那个元素才这样
			selecteles(evec,str , 1);
		}
		else {//匹配name和father
			selecteles(evec,str , 0);
		}
		for (j = 0; j < evec.size() ; j++) {
			//接下来在evec中从前到后筛选 父亲
			if (cmpfather(evec[j], strs) == 1) {
				out.push_back(evec[j].line);
				count++;
			}
		}
		if (count == 0) cout << "0" << endl;
		else {
			cout << count << " ";
			for (j = 0; j < out.size() - 1; j++) {
				cout << out[j] << " ";
			}
			cout << out[j] << endl;
		}
	}
    return 0;
}

/*
11 5
html
..head
....title
..body
....h1
....p #subtitle
....div #main
......h2
......p #one
......div
........p #two
p
#subtitle
h3
div p
div div p

*/