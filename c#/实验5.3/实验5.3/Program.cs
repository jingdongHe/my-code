using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
/*编写一个矩形类（Rect)与一个圆类(Circle),
 * 分别通过构造方法对一个矩形对象(rect1)与一个圆对象(circle1)进行初始化后，
 * 求出矩形与圆的面积。同时具有如下功能：可以设置和读取矩形的边长和圆的半径，
 * 但只能读取它们的面积，不能修改面积*/
namespace 实验5._3
{
    public class Rect
    {
        public int width{get;set;}
        public int height{get;set;}
        public Rect(int width, int height)
        {
            this.width = width;
            this.height = height;
        }
        public int area
        {
            get
            {
                return height * width;
            }
        }
    }
    public class Circle
    {
        private double r;
        public Circle(double r)
        {
            this.r = r;
        }
        public double getarea()
        {
            return r * r * Math.PI;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Rect r = new Rect(4,6);
            Circle c = new Circle(1.2);
            Console.WriteLine(r.area);
            Console.WriteLine(c.getarea());
            Console.ReadKey();
        }
    }
}
