/**������û�п��ǵ�
1.ָ��Ϊ���������
2.ָ��Ϊ�����������base==0��ô�ͻᵼ�´���

��ʼд��ʱ�����ģ�ظ�ƽ���������е������ˣ��᲻���и��õķ���
*/


class Solution {
public:
    double Power(double base, int exponent) {
    //ģ�ظ�ƽ����
        int i,flag;
        double result=1;
        int *expbit=new int[32];
        if(exponent==0){
            if(base==0) return 0;
            else return 1;
        }
        if(exponent>0) flag=0;
        else{//******û�п��Ǹ��������
            flag=1,exponent*=-1;
            if(base==0) throw new std::exception("Base==0 cannot be the denominator.");
            //exit(1);//*****��ĸΪ0Ӧ�ý��б��� û�������
        }
        for(i=0;i<32;i++){
            expbit[i]=exponent&1;//0~32��¼�˴ӵ͵��ߣ����ѭ����ʱ��Ӹߵ���
            exponent=exponent>>1;
        }
        for(i=31;i>=0;i--){
            if(expbit[i]) result*=base;
            if(i) result=result*result;//���һ�β���Ҫƽ��
        }
        delete[] expbit;
        if(flag) result=1.0/result;
        return result;
    }
};
