  
////////////////////////////////////////////////////////////////////////// //* list容器测试 
//////////////////////////////////////////////////////////////////////////  
#include <list> 
#include <iostream> 
using namespace std;  
typedef list<int> LISTINT;  
int _tmain(int argc, _TCHAR* argv[]) { 
	　//创建一个list容器
	 LISTINT lInt;  


	  //在list容器的末尾，添加元素 
	  cout << "------------------------------------------------" << endl ;
	  cout << "操作：从后面添加元素" << endl;     
	  for (LISTINT::value_type iValCount = 1; iValCount != 11; iValCount++)         
		  lInt.push_back(iValCount); 
	  for (LISTINT::iterator iter = lInt.begin(); iter != lInt.end(); iter++)         
		  cout << *iter << endl; 
	  
	   
	  //在list容器的头部，添加元素 
	  cout << "------------------------------------------------" << endl;
	  cout << "操作：从前面添加元素" << endl;
	 for (LISTINT::value_type iValCount = 11; iValCount != 21; iValCount++)         
		 lInt.push_front(iValCount); 
	 for (LISTINT::iterator iter = lInt.begin(); iter != lInt.end(); iter++)         
		 cout << *iter << endl;  


	//取出最后一个元素 
	cout << "------------------------------------------------" << endl;
	cout << "操作：取出最后一个元素" << endl;     cout << lInt.back() << endl;  


	//取出最前一个元素 
	cout << "------------------------------------------------" << endl;
	cout << "操作：取出最前一个元素" << endl;     cout << lInt.front() << endl;


	//从后向前显示list中的元素(注意：迭代器，不可以同名，虽然在不同的作用域下) 
	cout << "------------------------------------------------" << endl;
	cout << "操作：从后向向前显示list中的元素" << endl; 
	for (LISTINT::reverse_iterator iter2 = lInt.rbegin(); iter2 != lInt.rend(); iter2++)
		cout << *iter2 << endl;  


	//删除一个元素 
	cout << "------------------------------------------------" << endl;
	cout << "操作：删除最后一个元素" << endl;     if (lInt.size() > 0)     
	{ 
		LISTINT::iterator delIter = lInt.end();         
		delIter--; 
		cout << *delIter << endl;         
		lInt.erase(delIter);         
		if (lInt.size() > 0)         
		{ 									 　            
			delIter = lInt.end();             
			delIter--; 															  　            
			cout << *delIter << endl;         
		}     
	} 

	//清空元素(并输入所有元素内容----正常输出为空。因为被清空了) 
	cout << "------------------------------------------------" << endl;
	cout << "操作：清空所有元素(并输入所有元素内容----正常输出为空。因为被清空了)" << endl;     
	lInt.clear(); 
	for (LISTINT::iterator iter3 = lInt.begin(); iter3 != lInt.end(); iter3++)     
		cout << *iter3 << endl;  

	//所有操作均已经结束 
	cout << "------------------------------------------------" << endl;
	cout << "操作：所有操作均已经结束" << endl; 
	cout << "------------------------------------------------" << endl;  
	return 0; 
} 