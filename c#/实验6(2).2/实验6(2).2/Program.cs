using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*　　　2. 在一绘图程序当中，可以画出Draw()各种图形,包括直线、长方形等，
 * 请为这些图形抽象出共同的抽象基类Shape，其有一个关键点坐标（X,Y），
 * 图形名称Name和填充颜色(限红、黑、蓝、绿、黄)。
 * 具有画出图形和打印出图形名称的功能，设计接口ILine，IRegion，
 * 表示线性图形和封闭图形，分别具有求直线长度和求图形面积的功能，派生子类LineClass，RectClass，并在Main函数中测试。*/
namespace 实验6_2_._2
{
    enum Color {red,black,blue,green,yello};
    abstract class Shape
    {
        private int x, y;
        private string name;
        private Color yanse;
        public Shape()
        {
            name = "123";
            x = y = 0;
            yanse = Color.red;
        }
        public abstract void Drow();
        public void output()
        {
            Console.WriteLine(x + " " + y + " " + name + " " + yanse);
        }
    }
    class Line : Shape
    {
        public override void Drow()
        {
            Console.WriteLine("直线");
            output();
            //throw new NotImplementedException();
        }
    }
    public interface ILine
    {
        void Long();
    }
    public interface IRect
    {
        void area();
    }
    class Lineclass : ILine
    {
        public void Long()
        {
            Console.WriteLine("这是计算长度");
        }
    }
    class Rectclass : IRect
    {
        public void area()
        {
            Console.WriteLine("这是计算面积");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Lineclass i=new Lineclass();
            i.Long();
            Rectclass r = new Rectclass();
            r.area();
            Line L = new Line();
            L.Drow(); //L.output();
            Console.ReadKey();
        }
    }
}
