#include<stdio.h>
#include<iostream.h>
#include<string>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
//由于编译器兼容问题，将cout换成了printf
class Brand//品牌类
{
private:
	char    brnd_name[20];//品牌名
	int     Brand_code;//品牌代码
	int     quantity;//品牌数量
    float     brnd_price;//品牌价格
public:
	float getprice()
	{
		return brnd_price;
	}
	void getdata();//获取数据
	void showdata();//展示数据
};
class Item//物品类
{
private:
	char Item_name[20];//物品名
	int Item_code;//物品代码
	char colour[20];//物品颜色
	int quantity;//物品数量
	Brand brnd[3];//每个物品有3个品牌
	int pin_zhong_shu;//新增加的品种种类
public:
	void chu(int k)
	{
		quantity-=k;
	}
	float getprice()
	{
		//cout<<brnd[0].getprice()+brnd[1].getprice()+brnd[2].getprice()<<endl;
		return brnd[0].getprice()+brnd[1].getprice()+brnd[2].getprice();
	}
	inline char *getname()
	{
		return Item_name;
	}
	inline int getcode()
	{
		return Item_code;
	}
	void getdata();
	void showdata();
	void add();
	void remove();
	void search();
    void showab();
};

void Brand::getdata()
{
	puts("\n=========获取品牌信息===========");
	printf("请输入品牌名");
    gets(brnd_name);
    printf("请输入品牌编号");
    cin>>Brand_code;
    printf("请输入数量");
    cin>>quantity;
    printf("请输入价格");
    cin>>brnd_price;
	printf("\n=====获取品牌信息结束=========\n");
}
void Brand::showdata()
{
	printf("\n========展示品牌信息========\n");
	printf("名字          :  "); cout<<brnd_name<<endl;
	printf("编号          :  "); cout<<Brand_code<<endl;
	printf("数量          :  "); cout<<quantity<<endl;
    printf("价格          :  "); cout<<brnd_price<<endl;
	printf("\n=====展示品牌信息结束=======\n");
}

void Item::getdata()
{
	if(pin_zhong_shu<0)
		pin_zhong_shu=0;
	pin_zhong_shu+=3;//品种数的累加
	cout<<"\n***********************获取商品信息******************************"<<endl;
	printf("请输入商品名");
	gets(Item_name);
	printf("请输入商品价格");
	cin>>Item_code;
	printf("请输入商品颜色");
	gets(colour);
	printf("请输入商品数量");
	cin>>quantity;
	printf("\n输入品牌1");
	brnd[0].getdata();
	printf("\n输入品牌2");
	brnd[1].getdata();
	printf("\n输入品牌3");
	brnd[2].getdata();
	printf("\n*********************获取商品信息结束***************************\n");
}
void Item::showdata()
{
	 printf("\n***********************显示商品信息***********************\n");
	 printf("商品名    :  ");cout<<Item_name<<endl;
	 printf("商品编号  :  ");cout<<Item_code<<endl;
	 printf("商品颜色  :  ");cout<<colour<<endl;
	 printf("商品数量  :  ");cout<<quantity<<endl;
	 //对于新增加的品种数的输出
	 printf("商品的品种数为 : ");cout<<pin_zhong_shu<<endl;
	 printf("Brand 1\n"); brnd[0].showdata();
	 printf("Brand 2\n"); brnd[1].showdata();
	 printf("Brand 3\n"); brnd[2].showdata();
	 printf("\n*****************显示商品信息结束*************************\n");
}
void Item::add()//添加新的商品到TIS文件中
{
	ofstream file( "TIS.txt", ios::app );
	//打开添加到的文件
	if(!file)
	{
		cout<<"Error Could Not Open File";
		exit(1);
	}
	//设置一个类来接收数据并输入到文件中
	Item p1;
	p1.getdata();
	file.write((char *)&p1,sizeof(p1));
	file.close();
}
void Item::showab()
{
	ifstream file( "TIS.txt" ,ios::in);  //打开数据文件
    if(!file)   //检查数据文件是否存在
    {
		cout<<"Error Could Not Open File";
        exit(1);
    }
	//设置一个类来接收从文件中读取的数据并用于输出
    Item p1;
    file.read((char *)(&p1),sizeof(Item));
    while( !file.eof() ) 
    {
		p1.showdata() ;  //展示
        file.read((char *)(&p1),sizeof(Item)); //读入下一个数据
     }
}
void Item::search()
{
	char name1[10];
    int code;
    int option;
	//以下操作为设置检索方法
    printf("\n(1)通过商品名搜索\n(2)通过编号搜索\n");
    cin>>option;
    if(option==1)
    {
		printf("请输入商品名");
        gets(name1);
        code=0;
    }
    else
    {
		printf("请输入商品编号");
        cin>>code;
        strcpy(name1,"null");
    }
    fstream file( "TIS.txt" ,ios::in);  //打开需被检索的文件
    if(!file)  
    {
		cout<<"Error Could Not Open File";
        exit(1);
    }
    char flag='a';  //用于最后判断是否有该商品的信息
    Item p1;;
    file.read((char *)(&p1),sizeof(Item));
	while( !file.eof() ) 
    {
		if((strcmp(p1.Item_name,name1)==0) || (p1.Item_code==code))  //若比较成功则表示找到所需商品
		{															//并改flag的值，表示已找到所需商品
			p1.showdata();
            flag='z';   
            break; //找到所需商品后不再继续查找，直接退出
        }
        file.read((char *)(&p1),sizeof(Item));
	}
    if(flag !='z')  //没有找到所需商品
    {
		printf("Item Not Found\n");
    }
}
//解释一下删除的操作
//首先从文件中读入数据，检查读入的数据是否为所需删除的数据，若是需删除的数据则不写入用于暂时存储的文件中
//当所有数据都被检索一遍之后，暂时文件中存储的均为所需数据（需删除的数据未存储进来）
//将暂时文件中的所有数据覆盖TIS文件的数据
void Item::remove()
{
	char name1[10];
	int code;
    int option;
    printf("(1)通过商品名删除\n(2)通过商品代码删除\n");
    cin>>option;
    if(option==1)
    {
		printf("请输入商品名");
        gets(name1);
        code=0;
    }
    else
    {
		printf("请输入商品代码");
        cin>>code;
        strcpy(name1,"null");
    }
	//打开TIS文件和用于暂时存储的文件temp
    ifstream file( "TIS.txt" ,ios::in );
    ofstream temp( "delete.txt", ios::trunc);
    if( !file ||!temp)
    {
		cout<<"Could Not Open File";
        exit(1);
    }
    file.seekg(0);
    temp.seekp(0);
	//设置一个对象用于存储数据
    Item p1;
    file.read((char *)(&p1),sizeof(Item));
    while(  !file.eof() )
    {
		//当遇到需删除的商品的信息则直接读入下一个商品的信息不进行存储
		if( (strcmp(name1,p1.Item_name)==0)  || (code==p1.Item_code))
        {
			file.read((char *)(&p1),sizeof(Item));
        }
        else
        {
			temp.write((char *)(&p1),sizeof(Item));
            file.read((char *)(&p1),sizeof(Item));
        }
    }
	file.close();
    temp.close();
	//将临时文件的信息导入到TIS文件中
    ifstream temp1("delete.txt",ios::in);
    ofstream file1("TIS.txt", ios::trunc);
    temp1.seekg(0);
    file1.seekp(0);
    temp1.read( (char *)(&p1),sizeof(Item) );
    while( !temp1.eof() )
    {
		file1.write((char *) (&p1),sizeof(Item) );
        temp1.read((char *)(&p1),sizeof(Item) );
    }
    temp1.close();
    file1.close();
}

class Warehouse {//创建仓库类来实现2
private:
	Item good;
	char time[20];
	int number;
	int i;
public:
	Warehouse()
	{
		number=i=0;
		memset(time,'\0',sizeof(time));
	}
	//进_货,出_货均是把信息读入Warehouse类中
	void jin_huo()
	{
		/*设计输出每日进货与出货的统计表，要求进货与出货分别为两个文本文件，
		清单上列出进出货物的时间、品种描述、具体品牌的进出货数量，
		如果是出货清单，在每笔出货的清单后还要有该次提取货物的总价格。*/		
		printf("请输入进货的物品信息\n");
		Item good;
		good.getdata();
		printf("请输入进货数量\n");
		cin>>this->number;
		printf("请输入进货时间\n");
		gets(this->time);
		this->good=good;
	}
	void chu_huo(Item i,char t[],int n)
	{
		good=i;
		strcpy(time,t);
		number=n;
	}
	//以下两个函数的作用是将出货信息和进货信息存储到文件中
	void chuhuo_output()
	{
		char name1[10];
		int code;
		int option;
		printf("(1)通过商品名出货\n(2)通过商品代码出货\n");
		cin>>option;
		if(option==1)
		{
			printf("请输入商品名");
			gets(name1);
			code=0;
		}
		else
		{
			printf("请输入商品代码");
			cin>>code;
			strcpy(name1,"null");
		}
		ifstream file( "TIS.txt" ,ios::in );
		ofstream file1( "chuhuo.txt", ios::app);
		if( !file ||!file1)
		{
			cout<<"Could Not Open File";
			exit(1);
		}
		file.seekg(0);
		file1.seekp(0);
		Item p1;int d=0;
		file.read((char *)(&p1),sizeof(Item));
		//由于出货之前要有存货，所以需要检索是否有货
		while(  !file.eof() )
		{
			if( (strcmp(name1,p1.getname())==0)  || (code==p1.getcode()))
			{
				int k;char time[20];
				printf("请输入出货数量\n");
				cin>>k;
				printf("请输入出货日期\n"); 
				gets(time);
				Warehouse w;
				w.chu_huo(p1,time,k);
				file1.write((char *) (&w),sizeof(w) );
				d=1;//若有存货则可出货，对d进行标记
				//cout<<k*p1.getprice()<<endl;
				printf("出货总价为 %f\n",p1.getprice()*k);
				p1.chu(k);
				break;
			}
			else
			{
				file.read((char *)(&p1),sizeof(Item));
			}
		}
		file.close();
		file1.close();
		if(d==0)
			printf("该物品不存在\n");
	}
	void jinhuo_output()
	{
		Warehouse w1;
		w1.jin_huo();
		w1.show();
		ofstream file( "jinhuo.txt" ,ios::app );
		file.write((char *) (&w1),sizeof(w1) );
		file.close();
	}
	//由于是以二进制的形式存储于文件中，所以需要加一个显示函数来显示信息
	void show()
	{
		good.showdata();
		printf("%s    %d\n",time,number);
	}
	void show_chuhuo()
	{
		ifstream file( "chuhuo.txt", ios::in);
		Warehouse p1;
		file.read((char *)(&p1),sizeof(Warehouse));
		while(  !file.eof() )
		{
			p1.show();
			file.read((char *)(&p1),sizeof(Warehouse));
		}
	}
	void show_jinhuo()
	{
		ifstream file( "jinhuo.txt", ios::in);
		Warehouse p1;
		file.read((char *)(&p1),sizeof(Warehouse));
		while(  !file.eof() )
		{
			p1.show();
			file.read((char *)(&p1),sizeof(Warehouse));
		}
	}

};
struct cmp {//用于优先队列的排序
	bool operator () (Item &a,Item &b)
	{return a.getcode()<b.getcode();}
};
void paixu()
{
	
	priority_queue<Item,vector<Item>,cmp> Q;
	ifstream file( "TIS.txt" ,ios::in );
    ofstream temp( "delete.txt");
    if( !file ||!temp)
    {
		cout<<"Could Not Open File";
        exit(1);
    }
    file.seekg(0);
    temp.seekp(0);
    Item p1;
    file.read((char *)(&p1),sizeof(Item));
	//将TIS的数据全部放到优先队列中，经过优先队列的排序后得出一个有序的Item队列
    while(  !file.eof() )
    {
		Q.push(p1);
		file.read((char *)(&p1),sizeof(Item));
    }
	file.close();
	//将优先队列中所有的元素导出临时文件中
	while(!Q.empty())
	{
		temp.write((char *)(&Q.top()),sizeof(Item) );
		Q.pop();
	}
    temp.close();
	//将临时文件的数据导入到TIS文件中完成排序
    ifstream temp1("delete.txt",ios::in);
    ofstream file1("TIS.txt", ios::trunc);
    temp1.seekg(0);
    file1.seekp(0);
    temp1.read( (char *)(&p1),sizeof(Item) );
    while( !temp1.eof() )
    {
		file1.write((char *) (&p1),sizeof(Item) );
        temp1.read((char *)(&p1),sizeof(Item) );
    }
    temp1.close();
    file1.close();
}
int main()
{
	Item m;
	int choice;
    while(1)
	{
		printf("\n\t物品保管系统 (TIS)\n");
       	printf("(1)增加物品\n(2)展示所有物品\n");
        printf("(3)寻找物品\n(4)删除物品\n");
		printf("(5)出货\n(6)入货\n(7)货品排序\n");
		printf("(8)展示出货清单\n(9)展示进货清单\n");
		printf("(0)退出TIS");
        printf("\n请输入选择");
        cin>>choice;
		Warehouse w;
        switch(choice)
        {
			case 1:
				m.add();
                break;
			case 2:
				m.showab();
                break;
            case 3:
				m.search();
                break;
            case 4:
				m.remove();
                break;
			case 5:
				w.chuhuo_output();
				break;
			case 6:
				w.jinhuo_output();
				break;
			case 7:
				paixu();
				m.showab();
				break;
			case 8:
				w.show_chuhuo();
				break;
			case 9:
				w.show_jinhuo();
				break;
            case 0:
				exit(1);
		}
	}
	return 0;
}
