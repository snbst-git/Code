int inc(int &a) {
	return a++;
}

int testall = 0;

int j;
int i=0;
char c=0;
///i��ȫ�� �ֲ����������ԣ�ֻ�ǲ�����ĳ���������ڷ������õ���ʽ
///�Ǹ���Ҫ�ǿռ����գ����Ƕ���main()������ľֲ���������������Ż���գ�����ʹ��
int main(int argc, char *argv[])
{

	j=inc(i);
	j=inc(++i);
	j=inc(i++);
	j=inc(i+5);

    ///char c����ȫ����ûȫ��������������Ϊ���Ͳ�����
	j=inc(c);
	j=inc(++c);
	j=inc(c++);
	j=inc(c+5);
}
