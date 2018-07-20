using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 实验4_2_._5
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            int a = r.Next(10);
            int b = r.Next(10);
            int c = r.Next(10);
            int x, y, z;
            Console.WriteLine("{0},{1},{2}", a, b, c);
            do
            {
                int k = 0;
                x = Convert.ToInt32(Console.ReadLine());
                y = Convert.ToInt32(Console.ReadLine());
                z = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("{0},{1},{2}", x, y, z);
                if (x == a) k++; if (y == b) k++; if (z == c) k++;
                if (k == 3)
                { Console.WriteLine("bingo"); break; }
                else
                    Console.WriteLine("有{0}个正确", k);
            } while (true);
        }
    }
}
