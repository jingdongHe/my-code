using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 实验think1
{

    class Program
    {
        static void Main(string[] args)
        {
            int n=0, m=0;
            n = Int32.Parse(Console.ReadLine());
            m = Int32.Parse(Console.ReadLine());
            Console.WriteLine("{0},{1}", n, m);
            int[,] array=new int[n,m];
            int[] aver = new int[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    array[i,j] = Int32.Parse(Console.ReadLine());
                    aver[i] += array[i,j];
                }
            }
            Array.Reverse(aver);
            foreach (int c in aver)
                Console.WriteLine(c);
            Console.ReadKey();
        }
    }
}
