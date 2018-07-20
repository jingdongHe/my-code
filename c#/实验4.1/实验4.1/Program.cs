using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　编写一个控制台程序，接收一个长度大于３的字符串，完成下列功能。（参考教材3.1节）
　　　（1）输出字符串的长度。
　　　（2）输出字符串中第一个出现字母a的位置。
　　　（3）在字符串的第３个字符后面插入子串“hello”，输出新字符串。
　　　（4）将字符串“hello”替换为“me”，输出新字符串。
　　　（5）以字符“m”为分隔符，将字符串分离，并输出分离后的字符串。*/
namespace 实验4._1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            Console.WriteLine(s.Length);
            Console.WriteLine(s.IndexOf("a"));
            s=s.Insert(3, "hello");
            Console.WriteLine(s);
            s=s.Replace("hello", "me");
            Console.WriteLine(s);
            string [] a=s.Split('m');
            Console.WriteLine(string.Join(Environment.NewLine,a));
            Console.ReadKey();
        }
    }
}
