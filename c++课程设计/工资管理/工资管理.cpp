/*������5�����ʹ���
	����һ��Ա�����ʹ�����򡣹��ʹ���������ļ��д洢��Ա�������͹��ʣ��ó������¼�롢��ʾ���޸ġ�ɾ��������Ա���������͹��ʡ�
	�Ľ�Ҫ��
	1���������ʽ��д���򣬽������еĹ����������������ʽ��ţ�����һ�������࣬�����Ҫ�Ĳ���������
	2����ʾ���޸ġ�ɾ���������Ǵ�Сдͨ�á�
	3���������ݰ�����ֵ�Ĵ�С���������š�
	4���޸ġ�ɾ������ǰ������ʾ��Ϣ���û�ȷ�Ϻ���ܽ�һ���������������ȡ����
	5�����ӳ�����ļ�������빦�ܣ���ִ�г��������Ƚ��������ݴ��ļ��ж����ٽ��й����ڳ������ʱ�ܽ��������ݱ�����ԭ�ļ��С�*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
struct EMP {
char name[25]; 
float salary;  
int deleted;   
};
void main() {
	EMP e; //����Ա��
	strcpy(e.name,"NULL"); //����3�г�ʼ��Ա����Ϣ
	e.salary = 0;		   
	e.deleted = 0;
	while(1) {
		char c;            // ���ڽ���ĳ�����
	printf("\nDB >");   // ������ʾ��
		c = getch();        // ����������ַ�
		if(c == 'n') {        //����5��������Ϣ
			printf("\nName: ");		
			scanf("%s",e.name);
			printf("Salary: ");
			scanf("%f",&e.salary);
			e.deleted = 0;
		}else if(c == 's') {        //������Ϣ��txt�ļ�
	    	if((strcmp(e.name,"NULL")) == 0) { //δ����ְԱ��Ϣ
				printf("\nEnter employee data before trying to save");
				continue;
			}
			//������Ա����Ϣ
			FILE* file;//�����ļ�ָ��
			if((file = fopen("emp.txt","a"))==NULL) {//���ļ�Ϊ׷��д��
			printf("\nFailed to save data");//�޴��ļ�
			continue;
			}
			fwrite((char*)&e,sizeof(e),1,file);
			/*size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
			ע�⣺��������Զ�������ʽ���ļ����в��������������ı��ļ�
			����ֵ������ʵ��д������ݿ���Ŀ
			��1��buffer����һ��ָ�룬��fwrite��˵����Ҫ��ȡ���ݵĵ�ַ��
			��2��size��Ҫд�����ݵĵ��ֽ�����
			��3��count:Ҫ����д��size�ֽڵ�������ĸ�����
			��4��stream:Ŀ���ļ�ָ�룻
			��5������ʵ��д������������count��*/
			fclose(file);//�ر��ļ�
			printf("\nFile saved");
		
		}else if(c == 'l') {   //��ӡԱ����Ϣ
			FILE* file;//�����ļ�ָ��
			if((file = fopen("emp.txt","r")) == NULL) {//���ļ�
			printf("\nFailed to read file");
			continue;
			}
			long curpos, length; // Variables for finding file size
			curpos = ftell(file); //���ص�ǰָ���λ��
			fseek(file, 0L, SEEK_END);
			 /*fseek(fp, 0L,SEEK_END); len =ftell(fp)+1; ���Ƚ��ļ��ĵ�ǰλ���Ƶ��ļ���ĩβ
			 ��Ȼ����ú���ftell()��õ�ǰλ��������ļ��׵�λ�ƣ���λ��ֵ�����ļ������ֽ�����*/
			length = ftell(file);     // �ļ�����
			fseek(file, curpos, SEEK_SET); // ָ���ƻ��ļ�ͷ
			long num_recs = length / sizeof(e);// һ���ж���Ա��
			for(long l = 0;l<num_recs;l++) { // ����ÿһ��Ա������ӡ
				fread((char*)&e,sizeof(e),1,file);
				/*size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
				buffer���ڽ������ݵ��ڴ��ַ,��С������size*count�ֽ�.
				size����Ԫ�صĴ�С����λ���ֽ�
				countԪ�صĸ���,ÿ��Ԫ����size�ֽ�.
				stream������*/
				printf("\nName: %s",e.name);
				printf("\nSalary: %.2f",e.salary);
			}
			fclose(file);//�ر��ļ�
			printf("\n\n\tRecords: %d",num_recs);					
			
		}else if(c == 'h') { // ��ӡ����ѡ��
				printf("\nn - New\ns - Save\nl - List\nq - Quit");
		
		}else if(c == 'q') { // �˳�
			break;
		
		}else if(c == 'f') { // ����Ա��
			FILE* file;
			if((file = fopen("emp.txt","r")) == NULL) { //����3�д��ļ��Զ�ȡ
				printf("Failed to open file");
				continue;
			}
			//�������Ա������
			printf("Enter employee name: ");
			char f[25];
			scanf("%s",f);
			/*����Ϊ�����ļ�
			curposΪ�ļ�ͷ��lengthΪ�ļ�����*/
			long curpos, length;
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0; // ����ȷ���Ƿ��������Ա��
			for(long l = 0;l<num_recs;l++) {		
				fread((char*)&e,sizeof(e),1,file);
		 		if((strcmp(e.name,f))==0) {//��������Ա���������Ϣ
				printf("\nName: %s",e.name);
				printf("Salary: %f",e.salary);
				found = 1;
				}
			}
			if(found == 0)
				printf("Record not found.");
		}else if(c == 'd') {// ɾ��
			FILE* file;
			FILE* temp_file;
			if((file = fopen("emp.txt","r")) == NULL) {//����3�д��ļ��Զ�ȡ
				printf("Failed to load data");
				continue;
			}
			if((temp_file = fopen("emp_temp.txt","w")) == NULL) {//����3�д��ļ���д��
				printf("Failed to create temp file");
				continue;
			}
			printf("Enter employee name: ");//����Ա����������ɾ��
			char f[25];
			scanf("%s",f);
			long curpos, length;//��������Ա��
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0;
			for(long l = 0;l<num_recs;l++) {
				fread((char*)&e,sizeof(e),1,file);
				if((strcmp(e.name,f))==0) {
				e.deleted = 1; // ���ɾ����Ա��
				found = 1;
				}
				fwrite((char*)&e,sizeof(e),1,temp_file); //�����������ݵ���ʱ�ļ���
			}
			fclose(file);
			fclose(temp_file);
			if(found == 0) {
				printf("Record not found.");
			unlink("emp_temp.txt");//���û���ҵ����ݣ�ɾ����ʱ�ļ�
			continue;
			}
			//����ʱ�ļ��Զ��룬����ʽ�ļ���д��
			//������deleted==1ʱ����д����ʽ�ļ���
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
	
		}else if(c == 'e') { //�޸�Ա����Ϣ
			FILE* file;
			if((file = fopen("emp.txt","r")) == NULL) {
				printf("Failed to open file");
				continue;
			}
			printf("Enter employee name: ");
			char f[25];
			scanf("%s",f);
			//���ļ��������ļ�
			long curpos, length;
			curpos = ftell(file);
			fseek(file, 0L, SEEK_END);
			length = ftell(file);
			fseek(file, curpos, SEEK_SET);
			long num_recs = length / sizeof(e);
			int found = 0;
			char new_name[25];//�����������ڴ洢Ա����Ϣ
			float new_sal;
			EMP new_emp;
			long write_at;
			for(long l = 0;l<num_recs;l++) {
				fread((char*)&e,sizeof(e),1,file);
			   	if((strcmp(e.name,f))==0) {//�ҵ���Ա��
					printf("Enter new name: ");
					scanf("%s",new_name);
					printf("Enter new salary: ");
					scanf("%f",&new_sal);
					//Copies values to a new EMP object
					strcpy(new_emp.name,new_name);
					new_emp.salary = new_sal;
					new_emp.deleted = 0;
					found = 1;
					write_at = l; // ��λ�õ�Ա����Ϣ��Ҫ�޸�
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
				fseek(file,write_at,SEEK_SET);//ָ��ָ����Ҫ�޸ĵ�Ա����λ��
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
