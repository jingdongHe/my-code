using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _79._1
{
    class A
    {
        public A()
        {
            Console.WriteLine("A");
        }
        public A(string a)
        {
            Console.WriteLine(a);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            A b = new A("This is a string");
            A[] c = new A[5];
            Console.Read();
        }
    }
}
