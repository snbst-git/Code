/**
1.Ϊʲôǰ����һ��0
2.��û�и��õķ�������һ��ð�ݵĽ���
3.̫�����������
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //���Կ���Merge
        int i=0;
        vector<int> result(array.size());
        for(i=0;i<array.size();i++){
            if(array[i]%2) result.push_back(array[i]);
        }
        for(i=0;i<array.size();i++){
            if(array[i]%2==0) result.push_back(array[i]);
        }
        for(i=0;i<array.size();i++){
            array[i]=result[i+array.size()];
        }
    }
};
