/*
	reference:https://blog.csdn.net/creatorx/article/details/75446472
*/

//题目中数据量大，但是只关心数据的相对顺序，可以采用这种方法
struct Value   //输入数据的结构
{
	int val;	//数据值
	int id;		//离散之前在原数组中的位置
}value[maxn];   //离散前数据的数组

int rank[maxn]; //原数组离散后的数组

//读入数据
for (int i = 0; i < maxn; ++i)
{
	scanf("%d", &value[i].val);
	value[i].id = i;
}


//离散化
sort(value, value + maxn, cmp);

for (int i = 0; i < maxn; ++i)
{
	rank[value[i].id] = i;
}