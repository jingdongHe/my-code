using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 实验5._4
{
    class Program
    {
        public static void add(int a)
        {
            a++;
        }
        public static void add2(ref int a)
        {
            a++;
        }
        static void Main(string[] args)
        {
            int x = 2;
            Console.WriteLine(x);
            add(x);
            Console.WriteLine(x);
            add2(ref x);
            Console.WriteLine(x);
            Console.ReadKey();
        }
    }
}
