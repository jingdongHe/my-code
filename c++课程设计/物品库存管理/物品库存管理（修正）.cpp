#include<stdio.h>
#include<iostream.h>
#include<string>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
//���ڱ������������⣬��cout������printf
class Brand//Ʒ����
{
private:
	char    brnd_name[20];//Ʒ����
	int     Brand_code;//Ʒ�ƴ���
	int     quantity;//Ʒ������
    float     brnd_price;//Ʒ�Ƽ۸�
public:
	float getprice()
	{
		return brnd_price;
	}
	void getdata();//��ȡ����
	void showdata();//չʾ����
};
class Item//��Ʒ��
{
private:
	char Item_name[20];//��Ʒ��
	int Item_code;//��Ʒ����
	char colour[20];//��Ʒ��ɫ
	int quantity;//��Ʒ����
	Brand brnd[3];//ÿ����Ʒ��3��Ʒ��
	int pin_zhong_shu;//�����ӵ�Ʒ������
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
	puts("\n=========��ȡƷ����Ϣ===========");
	printf("������Ʒ����");
    gets(brnd_name);
    printf("������Ʒ�Ʊ��");
    cin>>Brand_code;
    printf("����������");
    cin>>quantity;
    printf("������۸�");
    cin>>brnd_price;
	printf("\n=====��ȡƷ����Ϣ����=========\n");
}
void Brand::showdata()
{
	printf("\n========չʾƷ����Ϣ========\n");
	printf("����          :  "); cout<<brnd_name<<endl;
	printf("���          :  "); cout<<Brand_code<<endl;
	printf("����          :  "); cout<<quantity<<endl;
    printf("�۸�          :  "); cout<<brnd_price<<endl;
	printf("\n=====չʾƷ����Ϣ����=======\n");
}

void Item::getdata()
{
	if(pin_zhong_shu<0)
		pin_zhong_shu=0;
	pin_zhong_shu+=3;//Ʒ�������ۼ�
	cout<<"\n***********************��ȡ��Ʒ��Ϣ******************************"<<endl;
	printf("��������Ʒ��");
	gets(Item_name);
	printf("��������Ʒ�۸�");
	cin>>Item_code;
	printf("��������Ʒ��ɫ");
	gets(colour);
	printf("��������Ʒ����");
	cin>>quantity;
	printf("\n����Ʒ��1");
	brnd[0].getdata();
	printf("\n����Ʒ��2");
	brnd[1].getdata();
	printf("\n����Ʒ��3");
	brnd[2].getdata();
	printf("\n*********************��ȡ��Ʒ��Ϣ����***************************\n");
}
void Item::showdata()
{
	 printf("\n***********************��ʾ��Ʒ��Ϣ***********************\n");
	 printf("��Ʒ��    :  ");cout<<Item_name<<endl;
	 printf("��Ʒ���  :  ");cout<<Item_code<<endl;
	 printf("��Ʒ��ɫ  :  ");cout<<colour<<endl;
	 printf("��Ʒ����  :  ");cout<<quantity<<endl;
	 //���������ӵ�Ʒ���������
	 printf("��Ʒ��Ʒ����Ϊ : ");cout<<pin_zhong_shu<<endl;
	 printf("Brand 1\n"); brnd[0].showdata();
	 printf("Brand 2\n"); brnd[1].showdata();
	 printf("Brand 3\n"); brnd[2].showdata();
	 printf("\n*****************��ʾ��Ʒ��Ϣ����*************************\n");
}
void Item::add()//����µ���Ʒ��TIS�ļ���
{
	ofstream file( "TIS.txt", ios::app );
	//����ӵ����ļ�
	if(!file)
	{
		cout<<"Error Could Not Open File";
		exit(1);
	}
	//����һ�������������ݲ����뵽�ļ���
	Item p1;
	p1.getdata();
	file.write((char *)&p1,sizeof(p1));
	file.close();
}
void Item::showab()
{
	ifstream file( "TIS.txt" ,ios::in);  //�������ļ�
    if(!file)   //��������ļ��Ƿ����
    {
		cout<<"Error Could Not Open File";
        exit(1);
    }
	//����һ���������մ��ļ��ж�ȡ�����ݲ��������
    Item p1;
    file.read((char *)(&p1),sizeof(Item));
    while( !file.eof() ) 
    {
		p1.showdata() ;  //չʾ
        file.read((char *)(&p1),sizeof(Item)); //������һ������
     }
}
void Item::search()
{
	char name1[10];
    int code;
    int option;
	//���²���Ϊ���ü�������
    printf("\n(1)ͨ����Ʒ������\n(2)ͨ���������\n");
    cin>>option;
    if(option==1)
    {
		printf("��������Ʒ��");
        gets(name1);
        code=0;
    }
    else
    {
		printf("��������Ʒ���");
        cin>>code;
        strcpy(name1,"null");
    }
    fstream file( "TIS.txt" ,ios::in);  //���豻�������ļ�
    if(!file)  
    {
		cout<<"Error Could Not Open File";
        exit(1);
    }
    char flag='a';  //��������ж��Ƿ��и���Ʒ����Ϣ
    Item p1;;
    file.read((char *)(&p1),sizeof(Item));
	while( !file.eof() ) 
    {
		if((strcmp(p1.Item_name,name1)==0) || (p1.Item_code==code))  //���Ƚϳɹ����ʾ�ҵ�������Ʒ
		{															//����flag��ֵ����ʾ���ҵ�������Ʒ
			p1.showdata();
            flag='z';   
            break; //�ҵ�������Ʒ���ټ������ң�ֱ���˳�
        }
        file.read((char *)(&p1),sizeof(Item));
	}
    if(flag !='z')  //û���ҵ�������Ʒ
    {
		printf("Item Not Found\n");
    }
}
//����һ��ɾ���Ĳ���
//���ȴ��ļ��ж������ݣ�������������Ƿ�Ϊ����ɾ�������ݣ�������ɾ����������д��������ʱ�洢���ļ���
//���������ݶ�������һ��֮����ʱ�ļ��д洢�ľ�Ϊ�������ݣ���ɾ��������δ�洢������
//����ʱ�ļ��е��������ݸ���TIS�ļ�������
void Item::remove()
{
	char name1[10];
	int code;
    int option;
    printf("(1)ͨ����Ʒ��ɾ��\n(2)ͨ����Ʒ����ɾ��\n");
    cin>>option;
    if(option==1)
    {
		printf("��������Ʒ��");
        gets(name1);
        code=0;
    }
    else
    {
		printf("��������Ʒ����");
        cin>>code;
        strcpy(name1,"null");
    }
	//��TIS�ļ���������ʱ�洢���ļ�temp
    ifstream file( "TIS.txt" ,ios::in );
    ofstream temp( "delete.txt", ios::trunc);
    if( !file ||!temp)
    {
		cout<<"Could Not Open File";
        exit(1);
    }
    file.seekg(0);
    temp.seekp(0);
	//����һ���������ڴ洢����
    Item p1;
    file.read((char *)(&p1),sizeof(Item));
    while(  !file.eof() )
    {
		//��������ɾ������Ʒ����Ϣ��ֱ�Ӷ�����һ����Ʒ����Ϣ�����д洢
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
	//����ʱ�ļ�����Ϣ���뵽TIS�ļ���
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

class Warehouse {//�����ֿ�����ʵ��2
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
	//��_��,��_�����ǰ���Ϣ����Warehouse����
	void jin_huo()
	{
		/*������ÿ�ս����������ͳ�Ʊ�Ҫ�����������ֱ�Ϊ�����ı��ļ���
		�嵥���г����������ʱ�䡢Ʒ������������Ʒ�ƵĽ�����������
		����ǳ����嵥����ÿ�ʳ������嵥��Ҫ�иô���ȡ������ܼ۸�*/		
		printf("�������������Ʒ��Ϣ\n");
		Item good;
		good.getdata();
		printf("�������������\n");
		cin>>this->number;
		printf("���������ʱ��\n");
		gets(this->time);
		this->good=good;
	}
	void chu_huo(Item i,char t[],int n)
	{
		good=i;
		strcpy(time,t);
		number=n;
	}
	//�������������������ǽ�������Ϣ�ͽ�����Ϣ�洢���ļ���
	void chuhuo_output()
	{
		char name1[10];
		int code;
		int option;
		printf("(1)ͨ����Ʒ������\n(2)ͨ����Ʒ�������\n");
		cin>>option;
		if(option==1)
		{
			printf("��������Ʒ��");
			gets(name1);
			code=0;
		}
		else
		{
			printf("��������Ʒ����");
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
		//���ڳ���֮ǰҪ�д����������Ҫ�����Ƿ��л�
		while(  !file.eof() )
		{
			if( (strcmp(name1,p1.getname())==0)  || (code==p1.getcode()))
			{
				int k;char time[20];
				printf("�������������\n");
				cin>>k;
				printf("�������������\n"); 
				gets(time);
				Warehouse w;
				w.chu_huo(p1,time,k);
				file1.write((char *) (&w),sizeof(w) );
				d=1;//���д����ɳ�������d���б��
				//cout<<k*p1.getprice()<<endl;
				printf("�����ܼ�Ϊ %f\n",p1.getprice()*k);
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
			printf("����Ʒ������\n");
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
	//�������Զ����Ƶ���ʽ�洢���ļ��У�������Ҫ��һ����ʾ��������ʾ��Ϣ
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
struct cmp {//�������ȶ��е�����
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
	//��TIS������ȫ���ŵ����ȶ����У��������ȶ��е������ó�һ�������Item����
    while(  !file.eof() )
    {
		Q.push(p1);
		file.read((char *)(&p1),sizeof(Item));
    }
	file.close();
	//�����ȶ��������е�Ԫ�ص�����ʱ�ļ���
	while(!Q.empty())
	{
		temp.write((char *)(&Q.top()),sizeof(Item) );
		Q.pop();
	}
    temp.close();
	//����ʱ�ļ������ݵ��뵽TIS�ļ����������
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
		printf("\n\t��Ʒ����ϵͳ (TIS)\n");
       	printf("(1)������Ʒ\n(2)չʾ������Ʒ\n");
        printf("(3)Ѱ����Ʒ\n(4)ɾ����Ʒ\n");
		printf("(5)����\n(6)���\n(7)��Ʒ����\n");
		printf("(8)չʾ�����嵥\n(9)չʾ�����嵥\n");
		printf("(0)�˳�TIS");
        printf("\n������ѡ��");
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
