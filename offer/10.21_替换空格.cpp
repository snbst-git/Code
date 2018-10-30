class Solution {
public:
	void replaceSpace(char *str,int length) {
        //注意考虑特殊情况，如空字符串
        //可以提前统计最终大小
        int i,spacenum=0;
        for(i=0;i<length;i++){
            if(str[i]==' ') spacenum++;
        }
        char *p=str+spacenum*2+length;
        for(;i>=0;i--,p--){
            if(str[i]==' '){
                *p='0',p--;
                *p='2',p--;
                *p='%';
            }
            else *p=str[i];
        }
        
        /*常规做法，有空间的浪费，另外也不知道具体有多大
        char *sp=(char*)malloc(sizeof(char)*length+1000);
        int i,j=0,nowlen=length+1000;
        for(i=0;i<=length;i++,j++){
            if(j>=nowlen){
                nowlen+=1000;
                sp=(char *)realloc(sp,sizeof(char)*nowlen);
            }
            if(str[i]==' '){
                sp[j++]='%';
                sp[j++]='2';
                sp[j]='0';
            }
            else sp[j]=str[i];
        }
        strcpy(str,sp);*/
	}
};
