/*　　　5、工资管理
	这是一个员工工资管理程序。工资管理的数据文件中存储有员工姓名和工资，该程序可以录入、显示、修改、删除、查找员工的姓名和工资。
	改进要求：
	1、用类的形式改写程序，将程序中的工资数据用链表的形式存放，定义一个链表类，封闭主要的操作函数。
	2、显示、修改、删除数据项是大小写通用。
	3、工资数据按工资值的大小进行排序存放。
	4、修改、删除数据前增加提示信息，用户确认后才能进一步操作，否则操作取消。
	5、增加程序的文件输出输入功能，在执行程序中首先将工资数据从文件中读出再进行管理，在程序结束时能将工资数据保存在原文件中。*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct EMP {
char name[25]; 
float salary;  
int deleted;   
};
void main() {
	EMP e; //创建员工
	strcpy(e.name,"NULL"); //以下3行初始化员工信息
	e.salary = 0;		   
	e.deleted = 0;
	while(1) {
		char c;            // 用于进入某项操作
	printf("\nDB >");   // 命令提示符
		c = getch();        // 输入操作项字符
		if(c == 'n') {        //以下5行输入信息
			printf("\nName: ");		
			scanf("%s",e.name);
			printf("Salary: ");
			scanf("%f",&e.salary);
			e.deleted = 0;
		}else if(c == 's') {        //保存信息至txt文件
	    	if((strcmp(e.name,"NULL")) == 0) { //未输入职员信息
				printf("\nEnter employee data before trying to save");
				continue;
			}
			//已输入员工信息
			FILE* file;//创建文件指针
			if((file = fopen("emp.txt","a"))==NULL) {//打开文件为追加写入
			printf("\nFailed to save data");//无打开文件
			continue;
			}
			fwrite((char*)&e,sizeof(e),1,file);
			/*size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
			注意：这个函数以二进制形式对文件进行操作，不局限于文本文件
			返回值：返回实际写入的数据块数目
			（1）buffer：是一个指针，对fwrite来说，是要获取数据的地址；
			（2）size：要写入内容的单字节数；
			（3）count:要进行写入size字节的数据项的个数；
			（4）stream:目标文件指针；
			（5）返回实际写入的数据项个数count。*/
			fclose(file);//关闭文件
			printf("\nFile saved");
		
		}else if(c == 'l') {   //打印员工信息
			FILE* file;//创建文件指针
			if((file = fopen("emp.txt","r")) == NULL) {//打开文件
			printf("\nFailed to read file");
			continue;
			}
			long curpos, length; // Variables for finding file size
			curpos = ftell(file); //返回当前指针的位置
			fseek(file, 0L, SEEK_END);
			 /*fseek(fp, 0L,SEEK_END); len =ftell(fp)+1; 首先将文件的当前位置移到文件的末尾
			 ，然后调用函数ftell()获得当前位置相对于文件首的位移，该位移值等于文件所含字节数。*/
			length = ftell(file);     // 文件长度
			fseek(file, curpos, SEEK_SET); // 指针移回文件头
			long num_recs = length / sizeof(e);// 一共有多少员工
			for(long l = 0;l<num_recs;l++) { // 遍历每一个员工并打印
				fread((char*)&e,sizeof(e),1,file);
				/*size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
				buffer用于接收数据的内存地址,大小至少是size*count字节.
				size单个元素的大小，单位是字节
				count元素的个数,每个元素是size字节.
				stream输入流*/
				printf("\nName: %s",e.name);
				printf("\nSalary: %.2f",e.salary);
			}
			fclose(file);//关闭文件
			printf("\n\n\tRecords: %d",num_recs);					
			
		}else if(c == 'h') { // 打印帮助选项
				printf("\nn - New\ns - Save\nl - List\nq - Quit");
		
		}else if(c == 'q') { // 退出
			break;
		
		}else if(c == 'f') { // 查找员工
			FILE* file;
			if((file = fopen("emp.txt","r")) == NULL) { //以下3行打开文件以读取
				printf("Failed to open file");
				continue;
			}
			//输入查找员工名称
			printf("Enter employee name: ");
			char f[25];
			scanf("%s",f);
			/*以下为遍历文件
			curpos为文件头，length为文件长度*/
			long curpos, length;
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0; // 用于确定是否遍历到该员工
			for(long l = 0;l<num_recs;l++) {		
				fread((char*)&e,sizeof(e),1,file);
		 		if((strcmp(e.name,f))==0) {//遍历到该员工，输出信息
				printf("\nName: %s",e.name);
				printf("Salary: %f",e.salary);
				found = 1;
				}
			}
			if(found == 0)
				printf("Record not found.");
		}else if(c == 'd') {// 删除
			FILE* file;
			FILE* temp_file;
			if((file = fopen("emp.txt","r")) == NULL) {//以下3行打开文件以读取
				printf("Failed to load data");
				continue;
			}
			if((temp_file = fopen("emp_temp.txt","w")) == NULL) {//以下3行打开文件以写入
				printf("Failed to create temp file");
				continue;
			}
			printf("Enter employee name: ");//输入员工姓名用于删除
			char f[25];
			scanf("%s",f);
			long curpos, length;//遍历查找员工
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0;
			for(long l = 0;l<num_recs;l++) {
				fread((char*)&e,sizeof(e),1,file);
				if((strcmp(e.name,f))==0) {
				e.deleted = 1; // 标记删除该员工
				found = 1;
				}
				fwrite((char*)&e,sizeof(e),1,temp_file); //读入所有数据到临时文件中
			}
			fclose(file);
			fclose(temp_file);
			if(found == 0) {
				printf("Record not found.");
			unlink("emp_temp.txt");//如果没有找到数据，删除临时文件
			continue;
			}
			//打开临时文件以读入，打开正式文件以写入
			//当遇到deleted==1时，不写入正式文件中
			file = fopen("emp.txt","w");
			temp_file = fopen("emp_temp.txt","r");
			curpos = ftell(temp_file);
			fseek(temp_file, 0L, SEEK_END);
			length = ftell(temp_file);
			fseek(temp_file, curpos, SEEK_SET);
			num_recs = length / sizeof(e);
			for(l = 0;l<num_recs;l++) {
			fread((char*)&e,sizeof(e),1,temp_file);
			if(e.deleted == 0) {
			fwrite((char*)&e,sizeof(e),1,file);
			}
		}
			fclose(file);
			fclose(temp_file);
			printf("Record deleted");
			unlink("emp_temp.txt");
	
		}else if(c == 'e') { //修改员工信息
			FILE* file;
			if((file = fopen("emp.txt","r")) == NULL) {
				printf("Failed to open file");
				continue;
			}
			printf("Enter employee name: ");
			char f[25];
			scanf("%s",f);
			//打开文件，遍历文件
			long curpos, length;
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0;
			char new_name[25];//以下两行用于存储员工信息
			float new_sal;
			EMP new_emp;
			long write_at;
			for(long l = 0;l<num_recs;l++) {
				fread((char*)&e,sizeof(e),1,file);
			   	if((strcmp(e.name,f))==0) {//找到该员工
					printf("Enter new name: ");
					scanf("%s",new_name);
					printf("Enter new salary: ");
					scanf("%f",&new_sal);
					//Copies values to a new EMP object
					strcpy(new_emp.name,new_name);
					new_emp.salary = new_sal;
					new_emp.deleted = 0;
					found = 1;
					write_at = l; // 该位置的员工信息需要修改
					break;
					}
				}
			fclose(file);
			if(found == 1) {
			//Calculates byte posiotn to write
				write_at = write_at * sizeof(new_emp);
				//Mode r+b opens a file to be writable & readable in binary
				if((file = fopen("emp.txt","r+b")) == NULL) {
					printf("Editing failed");
					continue;
				}
				fseek(file,write_at,SEEK_SET);//指针指向需要修改的员工的位置
				fwrite((char*)&new_emp,sizeof(new_emp),1,file);
				fclose(file);
				printf("Record edited");
			}else {
				printf("Record not found");
			}

		}else {
			printf("Type 'h' for valid commands ");
		}
	}
}
