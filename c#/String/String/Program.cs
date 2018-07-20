using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace String
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            Console.WriteLine("{0}",s.Length);
            Console.WriteLine(s.IndexOf("a"));
            string s1 = s.Insert(3, "hello");
            Console.WriteLine(s1);
            s1=s1.Replace("hello", "me");
            Console.WriteLine(s1);
            string[] s2 = s1.Split('m');
            for (int i = 0; i < s2.Rank+1; i++)
                Console.WriteLine(s2[i]);
            Console.Read();
        }
    }
}
