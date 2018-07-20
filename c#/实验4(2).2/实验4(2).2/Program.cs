using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*从键盘输入你的生日，输出现在距离你的生日还多少日，以及生日那天是星期几；如果你的生日已过，给出相应提示。*/
namespace 实验4_2_._2
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            DateTime d = Convert.ToDateTime(s);
            DateTime birth = new DateTime(d.Year, 4, 17);
            TimeSpan time = birth - d;
            if (time.Days < 0)
                Console.WriteLine("已过");
            else
                Console.WriteLine(time.Days);
            Console.WriteLine(birth.DayOfWeek);
            Console.ReadKey();
        }
    }
}
