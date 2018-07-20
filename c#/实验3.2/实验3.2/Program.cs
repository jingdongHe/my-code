using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*编写一个控制台应用程序，求1000之内的所有“完数”。
 * 所谓“完数”是指一个数恰好等于它的所有因子之和。例如，6是完数，因为6=1+2+3。*/
namespace 实验3._2
{
    class W
    {
        int res;
        bool is_wan(int a)
        {
            res = 0;
            for (int i = 1; i < a; i++)
            {
                if (a % i == 0)
                    res += i;
            }
            if (res == a)
                return true;
            return false;
        }
        public void find_w()
        {
            for (int i = 1; i <= 1000; i++)
            {
                if (is_wan(i))
                    Console.WriteLine(i);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            W w = new W();
            w.find_w();
            Console.ReadLine();
        }
    }
}
