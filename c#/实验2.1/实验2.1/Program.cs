using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　1．设计一个控制台程序，从键盘输入一个人的名字，
 * 在显示器中显示对输入姓名的问候。比如输入：张三；输出：张三，欢迎你！*/
namespace 实验2._1
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string s1 = s + ",welcom";
            Console.WriteLine(s1);
            Console.Read();
        }
    }
}
