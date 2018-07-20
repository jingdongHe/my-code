using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　阅读教材P66页[例4-1]程序，了解Ｃ#中构造函数的重载和创建对象的方法。*/
namespace 实验5._1
{
    public class Child
    {
        private int age;
        private string name;
        public Child()
        {
            name = "none";
        }
        public Child(string name, int age)
        {
            this.name = name;
            this.age = age;
        }
        public void PrintChild()
        {
            Console.WriteLine("{0}，{1} years old.", name, age);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Child child1 = new Child("zhang san", 11);
            Child child2 = new Child("Li si", 10);
            Child child3 = new Child();

            Console.Write("Child #1:");
            child1.PrintChild();
            Console.Write("Child #2:");
            child2.PrintChild();
            Console.Write("Child #3:");
            child3.PrintChild();
            Console.ReadKey();
        }
    }
}
