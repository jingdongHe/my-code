using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace @new.text
{
    class A
    {
        public A()
        {
            Console.WriteLine("==================================");
            Console.WriteLine("A构造");
            Console.WriteLine("==================================");
        }
        ~A()
        {
            Console.WriteLine("==================================");
            Console.WriteLine("A析构");
            Console.WriteLine("==================================");
        }
        public void text()
        {
            Console.WriteLine("A非虚测试");
        }
        public virtual void check()
        {
            Console.WriteLine("A虚测试");
        }
    }
    class B :A
    {
        public B()
        {
            Console.WriteLine("**********************************");
            Console.WriteLine("B构造");
            Console.WriteLine("**********************************");
        }
        ~B()
        {
            Console.WriteLine("**********************************");
            Console.WriteLine("B析构");
            Console.WriteLine("**********************************");
        }
        public void text1()
        {
            Console.WriteLine("B非虚测试");
        }
        public virtual new void check()
        {
            Console.WriteLine("B虚测试");
        }
    }
    class C:B
    {
        public C()
        {
            Console.WriteLine("----------------------------------");
            Console.WriteLine("C构造");
            Console.WriteLine("----------------------------------");
        }
        ~C()
        {
            Console.WriteLine("----------------------------------");
            Console.WriteLine("C析构");
            Console.WriteLine("----------------------------------");
        }
        public void text2()
        {
            Console.WriteLine("C非虚测试");
        }
        public override void check()
        {
            Console.WriteLine("C虚测试");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            B a = new B();
            B b = new C();
            A c = b;
            A d = new C();
            a.text1();
            a.check();
            b.text1();
            b.check();
            c.text();
            c.check();
            d.text();
            d.check();
            Console.ReadKey();
        }
    }
}
