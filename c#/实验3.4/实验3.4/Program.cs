using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　定义整型一维数组，从键盘输入数组元素数值后
 * ，用循环语句显示所有元素的值。（要求：根据用户输入的数据的个数动态创建数组的大小）*/
namespace 实验3._4
{
    class Program
    {
        static void Main(string[] args)
        {
            //string s= ;
            char[] a=Console.ReadLine().ToCharArray();
            foreach (char i in a)
                Console.Write(i);
            Console.ReadLine();
        }
    }
}
