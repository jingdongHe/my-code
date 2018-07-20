using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　编写一个控制台程序，连续输入一串数字，各数字以逗号隔开，然后按从小到大和从大到小的顺序排列输出。
　　　提示：首先利用String.Split()方法将输入的数字字符串中的数字分离出来，
 * 并保存到数组中，然后再对数组中的数字进行排序。
 * （参考教材3.1和3.2节中的Split( )方法、Sort（）方法和Reverse( )方法的使用）*/
namespace 实验4._2
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string[] a = s.Split(',');
            int [] math=new int[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                math[i] = Int32.Parse(a[i]);
            }
            Array.Sort(math);
            foreach (int c in math)
                Console.WriteLine(c);
            Array.Reverse(math);
            foreach (int c in math) 
                Console.WriteLine(c);
            Console.ReadKey();
        }
    }
}
