using System;

namespace number
{
    class Program
    {
        public static int Maxnum(int[] num)
        {
            int a = 0;
            for (int i = 0; i < num.Length; i++)
            {
                if (num[i] > a)
                { a = num[i]; }
            }
            return a;
        }
        public static int Minnum(int[] num)
        {
            int a = num[0];
            for (int i = 0; i < num.Length; i++)
            {
                if (num[i] < a)
                { a = num[i]; }
            }
            return a;
        }
        public static int Sumnum(int[] num)
        {
            int a = 0;
            for (int i = 0; i < num.Length; i++)
            {
                a = a + num[i];
            }
            return a;
        }

        static void Main(string[] args)
        {
            int[] num = {1,2};
            Console.WriteLine(Maxnum(num));
            Console.WriteLine(Minnum(num));
            Console.WriteLine(Sumnum(num));
            Console.WriteLine(((float)Sumnum(num) / (num.Length)));
        }
    }
}
