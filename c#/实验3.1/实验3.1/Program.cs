using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　1.编写一个控制台应用程序，要求用户输入5个大写字母，
 * 如果用户输入的信息不满足要求，提示帮助信息并要求重新输入。*/
namespace 实验3._1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s, s1;
            do
            {
                s = Console.ReadLine();
                s1 = s.ToUpper();
            } while (s != s1);
            Console.WriteLine(s);
            Console.ReadLine();
        }
    }
}
