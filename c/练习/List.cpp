#include <list>
#include <iostream>
using namespace std;

typedef list<int> LISTINT;

int main()
{
    //����һ��list����
    LISTINT lInt;
	int iValCount;
    //��list������ĩβ�����Ԫ��
    cout << "------------------------------------------------" << endl << "�������Ӻ������Ԫ��" << endl;
    for (iValCount = 1; iValCount != 11; iValCount++)
        lInt.push_back(iValCount);
    for (LISTINT::iterator iter = lInt.begin(); iter != lInt.end(); iter++)
        cout << *iter << endl;
	cout << "------------------------------------------------" << endl << "������ɾ�����һ��Ԫ��" << endl;
        LISTINT::iterator delIter = lInt.end();
		delIter--;cout<<*delIter<<endl;
		delIter=lInt.erase(delIter);
		delIter--;
		cout<<*delIter<<endl;
		
		LISTINT::iterator inIter = lInt.end(),f=lInt.end(),l=lInt.begin();
		inIter--;iValCount=99;
		f--,f--;l++,l++;
		cout<<*l<<" "<<*f<<endl;cout<<"----------------------------------"<<endl;
		lInt.insert(inIter,l,f);
		cout<<"----------------------------------"<<endl;
		for (LISTINT::iterator iter1 = lInt.begin(); iter1 != lInt.end(); iter1++)
        cout << *iter1 << endl;
		
		/*lInt.clear();
		
		cout<<lInt.size()<<endl;
		LISTINT::iterator iter = lInt.begin();
		//for ( iter != lInt.end(); iter++)
        cout << *iter << endl;*/
	return 0;
}