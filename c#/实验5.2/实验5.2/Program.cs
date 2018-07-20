using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　编程实现一个图书类book，增加有参和无参数构造函数，
 * 同时具有如下功能：记录和访问图书信息，包括书名，作者，价格。
 * 用两种不同的构造函数创建两本书，使这两本书都具有各自的相关信息,最后将其信息输出。*/
namespace 实验5._2
{
    class Book {
        private double price;
        private string name,write;
        public Book()
        {
            name=write="none";
        }
        public Book(string name,string write,double price)
        {
            this.name=name;
            this.write=write;
            this.price=price;
        }
        public void print()
        {
            Console.WriteLine("{0},{1},{2}",name,write,price);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Book b1=new Book("12","asdf",12.3);
            Book b2=new Book();
            b1.print();
            b2.print();
        }
    }
}
