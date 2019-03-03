void testchar(int a){
    printf("%d\n",a);

}

int main(int argc, char *argv[])
{
	char a=-2;
	testchar(a);
	///int也可以截断到char参数里面去，只是输出还是当字符char输出的
	///char提升为int一般没什么问题
}
