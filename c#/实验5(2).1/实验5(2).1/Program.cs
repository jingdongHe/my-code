using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*从键盘输入10个整数，输出10个数的最大值、最小值、平均值和总和。（要求分别用泛型列表和数组实现）*/
namespace 实验5_2_._1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> a = new List<int>();
            for (int i = 0; i < 10; i++)
                a.Add(Int32.Parse(Console.ReadLine()));
            Console.WriteLine(a.Sum());
            Console.WriteLine(a.Average());
            Console.WriteLine(a.Max());
            Console.WriteLine(a.Min());
            Console.ReadKey();
        }
    }
}
