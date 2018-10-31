/**
��P69
ԭ�����ӣ�https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
�Լ����⣺
1.û�п����м�һ��������ͬ����ת����
2.��ʼû�к�������p=q=mid��Ϊ�ж���Ҫ������ԭ��
��Ϊ���p!=q��ô�϶�����p>q����mid>=p����p==mid��֪��ǰ����һ�Ѷ���һ����ֵ�����Ծ��ں���
�����p==q��ô���﷭ת�Ľ��min����ǰҲ�����ں󣬲����ж�
3.�������ƶ�ʱ��һ��ʼp=mid+1�����������midǡ��Ϊmin�����������p=mid+1���Թ���min
*/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray);

int main(){
	int n;
	cin >> n;
    vector<int> num(n);
    for(int i=0;i<n;i++){
		cin >> num[i];
    }
    cout<<minNumberInRotateArray(num);

	//cout << minNumberInRotateArray(num);
    getchar();

    return 0;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size()<=0) return 0;
    int p=0,q=rotateArray.size()-1;
	if (rotateArray[p] < rotateArray[q]) return rotateArray[p];//���û�н��з�ת   ���������תԪ����0
    while(q-p>=2){//(0+2)/2=1 �����м�
        int mid=p+(q-p)/2;//���������>>��ע�����ȼ�̫���ˣ��ᵼ�¼�������һ�£��͵ü����ţ�����ֱ��/2Ҳ����
        if(rotateArray[p]>rotateArray[mid]){
            q=mid;//��������Сֵ
        }
        else if(rotateArray[p]<rotateArray[mid]) {
            p=mid;//����=mid+1�᲻���Թ�����Ϊ��<mid��ô˵��mid�Ǵ�ֵ
			/*****Ӧ��p=mid;������mid+1
			��ҪӦ���������һ���ƶ�֮��mid+1ǡ�þ�����Сֵ
			��ô��һ�־�Ҳ��ΪС���Թ��ˣ���ʵ���￪ʼ�Ѿ�û��ǰ��Ĵ��������ˣ���Ӧ�����������ʹ������Сֵ
			����Ӧ�ð�mid���£���Ϊһ��������ʹ��֮�󲻶ϰ�qǰ��
			*/
        }
		else {//==����� ǰ������м� ������ǰ������ں���
			p++;
			/*������Խ�һ�����廯
			���[p]!=[q]
			��ô˵����Ȼ[p]==[mid]����Ȼp��mid�Ƿǵݼ���˵������==p����ôq��Ȼֻ��<p�����������ƶ�����
			��Ȼ����p=mid

			���[p]==[q]��ô˵��������Сֵ��p~midҲ������mid~q�����ж�����ʱ��Ҫ������
			*/
		}
    }
    if(p==q) return rotateArray[p];
    else return rotateArray[p]<rotateArray[q]?rotateArray[p]:rotateArray[q];
}
