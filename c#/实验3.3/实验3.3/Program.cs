using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*输入一个字符串，用foreach语句计算输入的字符串长度，
 * 根据此长度创建一个字符数组，将字符串中的每个字符转存到字符数组的每个元素中，并输出。*/
namespace 实验3._3
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            int i = 0;
            foreach (char a in s)
            {
                i++;
                Console.Write(a);
            }
            Console.WriteLine();
            char[] s1 = new char[i];
            i = 0;
            foreach(char a in s)
            {
                s1[i++]=a;
            }
            for (int d = 0; d < i; d++)
                Console.Write(s1[d]);
            Console.ReadLine();
        }
    }
}
