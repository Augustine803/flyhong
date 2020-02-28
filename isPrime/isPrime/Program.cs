using System;

namespace isPrime
{
    class Program
    {
        static void Main(string[] args)
        {
            bool[] isprime = new bool[101];
            for(int i = 0; i< isprime.Length; i++)
            {
                isprime[i] = true;
            }
            isprime[0] = false;
            isprime[1] = false;
            for(int i = 2; i* i<= 100; i++)
            {
                if(isprime[i])
                {
                    for(int j = i * 2; j <= 100; j=j+i)
                    {
                        isprime[j] = false;
                    }
                }
            }
            for(int i = 0; i < isprime.Length; i++)
            {
                if (isprime[i])
                {
                    Console.Write(i + " ");
                }
            }
        }
    }
}
