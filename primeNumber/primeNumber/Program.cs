using System;

namespace primeNumber
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("输入数字");
            int number = Convert.ToInt32(Console.ReadLine());
            if (number == 1)
            {
                Console.WriteLine("1没有素数因子");
            }
            for(int i = 2; i <= number/2; i++)
            {
                if (number % i == 0)
                {
                    Console.WriteLine($"{i}");
                    while (number % i == 0)
                    {
                        number /= i;
                    }
                }
                if (number == 1) break;

            }
        }
    }
}
