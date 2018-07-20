using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace kaoshitext
{
    class Program
    {
        static void Main(string[] args)
        {
            int[][] myArray3 = new int[3][]
            {
                new int[3]{5,6,2},
                new int[5]{6,9,7,8,3},
                new int[2]{3,2}
            };
            for (int i = 0; i < myArray3.Rank; i++)
            {
                for (int j = 0; j < myArray3[i].Length; i++)
                    Console.Write("("+i+","+j+")"+myArray3[i][j] + " ");
                Console.WriteLine();
            }
        }
    }
}
