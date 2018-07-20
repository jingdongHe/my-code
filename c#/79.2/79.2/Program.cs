using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _79._2
{
    class MyClass {
        private int a;
        public int b;
        protected int c;
        public MyClass()
        {
            Console.WriteLine("构造");
        }
        private void A()
        {
            Console.WriteLine("私有函数");
        }
        public void B()
        {
            Console.WriteLine("共有函数");
        }
        protected void C()
        {
            Console.WriteLine("保护函数");
        }
    }
    class My : MyClass
    {
        public My()
        {
            Console.WriteLine(c);
        }
    }
    class Program 
    {
        static void Main(string[] args)
        {
            MyClass m=new MyClass();
           // Console.WriteLine("调用私有成员,{0}",m.a);
            Console.WriteLine("调用公有成员,{0}",m.b);
            //Console.WriteLine("调用保护成员,{0}",m.c);
            //m.A();
            m.B();
           // m.C();
            My my = new My();
            Console.Read();
        }
    }
}
