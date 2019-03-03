/**
ʵ����һ��select partition(random) ����
1.������ӵ���swap������Ū�˸���������������ʲô��
����ע��ֻ�޸��˲���swapΪrecswap���³���ִ�д��󡭡���Ҫ���������ĺð�
2.�ر�ע��֮ǰһ���ط�
k����Ե��±� ��partition���ص��Ǿ��Ե��±�
������Ҫrei=i-p��һת�������û��ע�⵽
*/
class Solution {
public:
    vector<int> rec;
    void Insert(int num)
    {
        rec.push_back(num);
    }

    void recswap(int i, int j) {
        int temp = rec[i];
        rec[i] = rec[j];
        rec[j] = temp;
    }

    double GetMedian()
    {
        //��λ��
        int size=rec.size();
        if(size==0) return 0;
        if(size%2){//����
            return select(0,size-1,size/2);//5 ȡ3 �±�2
        }
        else{//��һ��0����//if(size==0) return 0;
            double sum=select(0,size-1,size/2)+select(0,size-1,size/2-1);
            //sum/=2;//����������󣿳���0�ˣ�
            return sum/2.0;//4 ȡ2 3 �±�1 2
        }
    }
    //k������±� i�Ǿ����±�
    int select(int p,int q,int k){//����ѡ��0��ʼ���±�
        if(p==q) return rec[p];
        int i=randpartition(p,q);//�±�
        int rei=i-p;//����±�
        if(rei==k) return rec[i];
        else if(k<rei) return select(p,i-1,k);
        else return select(i+1,q,k-rei-1);///д��+1��
    }

    int randpartition(int p,int q){
        srand((int)time(0));
        //���һ�����ŵ����ȥ
        recswap(p+rand()%(q-p+1),q);
        int i=p-1,j=p;
        int u=rec[q];
        //ѡ��β��Ϊ����Ԫ��
        while(j<q){//ֻȡ��q-1
            if(rec[j]<=u) recswap(j,++i);//����i��j������
            j++;
        }
        recswap(++i,q);
        return i;//���ڵ��±�
    }

};
