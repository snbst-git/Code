/**
1.������ؽ��������ų���
һ���ǴӺ���ѱȵ�ǰ����С�Ķ��޳�������ζ�Ŷ�����ֻ��ʣ�±ȵ�ǰ��Ļ���ǰ�����ȼ�����
����ͷ���û�б�ɾ��˵�����Ǹ���ģ�����ÿ��ֻ��Ҫ�����ͷ
2.ע��size��unsigned�������з�������Ƚϵ�ʱ�������i-front+1>size�ķ�ʽ
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        //��ò�Ҫÿ�ζ���ͷ��β��һ�Σ��������ǰ��Ľ����
        int i=0;
        list<int> rec;//���ڱ����±� ���豣��ԭֵ
        vector<int> result;
        if(size<=0) return result;
        while(i<num.size()){
            //����������Ԫ�أ�����ȵ�ǰ���ֵ����ô����ǰ������С��
            //����ȵ�ǰԪ��С���Ա��棬���ǲ�������ʹ�ã���һ�ж��С�ڣ�
            //���С����ô�ڽϴ�ķŽ�����ʱ���Ѿ���ǰ���ɾ���������Ƿ���ǰ����ô��ľ�����Ϊͷ
            while(rec.size()&&num[rec.back()]<=num[i]){
                rec.pop_back();
            }
            //pop�����±귶Χ�Ĳ���
            while(rec.size()&&i>=size-1&&rec.front()<i-size+1){//i-0��һ�� i-(size-1)��size��
                rec.pop_front();
            }
            rec.push_back(i);
            if(i>=size-1)//���ٵȵ�һ�����ڷ������ ��ʱ�±�Ϊsize-1
            result.push_back(num[rec.front()]);
            i++;
        }
        return result;
    }
};
