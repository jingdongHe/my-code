using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　从键盘输入你认识的五个同学的学号和姓名，将这五个同学的这两项信息按照学号从小到大排序输出。
　　　提示：用SortedList泛型列表实现。*/
namespace 实验4_2_._3
{
    class Program
    {
        static void Main(string[] args)
        {
            SortedList<int,string> l = new SortedList<int,string>();
            string s;
            for (int i = 0; i < 3; i++)
            {
                s = Console.ReadLine();
                string[] a = s.Split(' ');
                
                l.Add(Convert.ToInt32(a[0]), a[1]);
            }
            IList<int> key = l.Keys;
            IList<string> value = l.Values;
            for (int i = 0; i < l.Count; i++)
                Console.WriteLine("{0},{1}", key[i], value[i]);
            Console.ReadKey();
        }
    }
}
