using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　编写一个控制台程序，输入一个日期，输出这一天是星期几。（参考教材3.3和3.6节）
　　　提示：定义一个枚举和日期型变量，利用日期类型的DayOfWeek属性获得该日期是一周的第几天
 * ，再用枚举值求得是星期几。注意DayOfWeek属性也是返回星期几的枚举常量，但是英文的，现在要求输出中文的星期几。
　　　核心代码：
　　　enum WeekDay {星期天,星期一,星期二,星期三,星期四,星期五,星期六};
　　　……
　　　//s的类型为string,其值是从键盘上输入的一个日期，注意输入正确的格式，比如：2011-02-10
      DateTime d = Convert.ToDateTime(s);            
      WeekDay wd =(WeekDay)d.DayOfWeek;*/
namespace 实验4._3
{
    class Program
    {
        enum WeekDay { 星期天, 星期一, 星期二, 星期三, 星期四, 星期五, 星期六 };
        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            DateTime d = Convert.ToDateTime(s);
            WeekDay wd = (WeekDay)d.DayOfWeek;
            Console.WriteLine(wd);
            Console.ReadKey();
        }
    }
}
