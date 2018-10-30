class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0) return 0;
        int *record=new int[number+1];
        record[1]=1;
        record[2]=2;
        for(int i=3;i<=number;i++){
            record[i]=record[i-2]+record[i-1];
            //i-2后，可以+1+1也可以+2两种
        }
        return record[number];
        delete[] record;
    }
};
