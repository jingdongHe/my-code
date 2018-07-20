using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*编写猜数字的小游戏：让系统产生一个两位的随机数，
 * 由用户去猜，根据用户所猜的数的大小给出相应的提示。
 * 如果用户输入的数太小了，输出“你输入的数太小，请重输：”；
 * 如果用户输入的数太大了，输出“你输入的数太大了，请重输”；
 * 如果用户输入的正好是系统产生的那个数，则输出“输入正确，恭喜你！”。*/
namespace 实验4_2_._4
{
    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            int d = r.Next(100);
            while (d < 10)
                d = r.Next(100);
            Console.WriteLine(d);
            int user;
            Console.WriteLine("请输入一个数");
            do
            {
                user = Convert.ToInt32(Console.ReadLine());
                if (user == d)
                { Console.WriteLine("right"); break; }
                else if (user < d)
                    Console.WriteLine("too small");
                else
                    Console.WriteLine("too big");
            } while (true);
        }
    }
}
