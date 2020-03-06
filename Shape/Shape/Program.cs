using System;

namespace Shape
{
    interface graphics
    {
        double Area();
    } 
    public class triangle : graphics
    {
        public double a;
        public double b;
        public double c;
        public triangle(double a,double b, double c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public double Area()
        {
            double s = (a + b + c) / 2;
            
            if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
            {
                return (float)Math.Sqrt(s * (s - a) * (s - b) * (s - c));
            }
            else
            {
                Console.WriteLine("输入的不是三角形！");
                return 0.0;
            }

        }


    }
    public class rectangle : graphics
    {
        public double width;
        public double length;
        public rectangle(double width, double length)
        {
            this.length = length;
            this.width = width;
        }
        public double Area()
        {
            return length * width;
        }

    }
    public class circle : graphics
    {
        public double r;
        public double pi=3.14;
        public circle(double r)
        {
            this.r=r;
        }
        public double Area()
        {
            return (float)pi*r*r;
        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            circle t = new circle(3.0);
            rectangle re = new rectangle(3, 4);
            triangle tri = new triangle(3, 4, 5);
            Console.WriteLine( (float)t.Area());
            int i = 0;
            float sum = 0;
            while (i < 10)
            {
                Random r = new Random();
                int n = r.Next(1, 3);
                switch (n) 
                {
                    case(1):
                        t = new circle((new Random().NextDouble()*9+1));
                        Console.WriteLine((float)t.Area());
                        sum = sum + (float)t.Area();
                        break;
                    case (2):
                        re = new rectangle((new Random().NextDouble()*10+1.0), (new Random().NextDouble()*10)+1.0);
                        Console.WriteLine((float)re.Area());
                        sum = sum + (float)re.Area();
                        break;
                    case (3):
                        double a = 0.0;
                        double b = 0.0;
                        double c = 0.0;
                        while (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
                        {
                             a = new Random().NextDouble() * 10.0 + 1.0;
                             b = new Random().NextDouble() * 10.0 + 1.0;
                             c = new Random().NextDouble() * 10.0 + 1.0;
                        }
                        tri = new triangle((new Random().NextDouble() * 10 + 1), (new Random().NextDouble() * 10 + 1.0), (new Random().NextDouble() * 10 + 1));
                        Console.WriteLine((float)tri.Area());
                        sum = sum + (float)tri.Area();
                        break;
                    default:
                        break;
                }
                i++;

            }
            Console.WriteLine(sum);
        }
        
    }
}
