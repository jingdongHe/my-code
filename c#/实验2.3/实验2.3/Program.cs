using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 实验2._3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("{0:D}", 10);
            Console.WriteLine("{0:D5}", 10);
            Console.WriteLine("{0:F}", 10);
            Console.WriteLine("{0:F4}", 10);
            Console.WriteLine("{0:00000}", 123);
            Console.WriteLine("{0:000}", 12345);
            Console.WriteLine("{0:0000}", 123.64);
            Console.WriteLine("{0:00.00}", 123.6484);
            Console.WriteLine("{0:####}", 123);
            Console.WriteLine("{0:####}", 123.64);
            Console.WriteLine("{0:####.###}", 123.640);
            Console.WriteLine("{0:####.##}", 0.0100);
            Console.WriteLine("{0:####.##}", 123.648);
            Console.WriteLine("{0}--{0:p}good", 12.34F);
            Console.WriteLine("{0}--{0:00000}good", 456);
            Console.Write("{0,-4}{1,-4}{2,-4}", 1, 2, 3);
            DateTime dt = new DateTime(2011, 3, 11);
            string s = string.Format("{0:yyyy年MM月dd日}", dt);
            Console.WriteLine(s);
            Console.ReadLine();
        }
    }
}
