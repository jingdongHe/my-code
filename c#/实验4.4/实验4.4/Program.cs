using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　编写一个控制台程序，要求定义一个列表，
 * 用该列表接收用户输的五个姓名，判断用户输入的人名里有没有“张三”，
 * 如果有则将其删除，最后再把列表中的名字依次输出。（参考教材3.5节）*/
namespace 实验4._4
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> a=new List<string>();
            string s;
            for (int i = 0; i < 5; i++)
            {
                s = Console.ReadLine();
                a.Add(s);
            }
            a.Remove("zhangsan");
            for (int i = 0; i < a.Count; i++)
                Console.WriteLine(a[i]);
            Console.ReadKey();
        }
    }
}
