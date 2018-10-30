class Solution {
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        if(number==1) return 1;
        int a=1,b=1,c;
        for(int i=2;i<=number;i++){
            c=a+b;
            a=b,b=c;
        }
        return c;
    }
};

/**��ͼ��֪��ʵ�ʻ�����r[n]=r[n-1]+r[n-2]   r[n-1]��Ӧ���һ����r[n-2]��Ӧ��������
*����쳲�����������
*һ��ʼ����Ϊ��n*n�ľ��Σ����˵ú�
*���ڶ��ڲ����ظ��ĸ������������һЩ��

*������һ�������������Կ���һ�¸�Ϊ���ӵ����⣬����ǰ�����̨�׾�Ӧ�ÿ��ǿ��Ǳ�̬��̨��
*/
