using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　2．设计一个控制台程序，从键盘输入两个整数，
 * 输出这两个数的和、差、积、商（商要求为数学商，非整除商）。*/
namespace 实验2._2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            Console.WriteLine("{0},{1},{2},{3}", a + b, a - b, a * b, a / b);
            Console.Read();
        }
    }
}
