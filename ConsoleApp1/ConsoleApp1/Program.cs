
using System;
using System.Text;

namespace ConsoleApp1
{
	class Program
	{
		static void Main(string[] args)
		{
			double num1 = 0;
			double num2 = 0;
			string c1;
			string c2;
			Console.WriteLine("输入第一个数字：");
			c1= Convert.ToString(Console.ReadLine());
			bool IsNumeric(string str) //接收一个string类型的参数,保存到str里
			{
				if (str == null || str.Length == 0)    //验证这个参数是否为空
					return false;                           //是，就返回False


				ASCIIEncoding ascii = new ASCIIEncoding();//new ASCIIEncoding 的实例
				byte[] bytestr = ascii.GetBytes(str);         //把string类型的参数保存到数组里

				foreach (byte c in bytestr)                   //遍历这个数组里的内容
				{
					if (c < 48 || c > 57)                          //判断是否为数字
					{
						Console.WriteLine("输入错误");
						return false;                              //不是，就返回False
					}
				}
				return true;                                        //是，就返回True
			}
			if (IsNumeric(c1) == true)
			{
			num1 = Convert.ToDouble(c1);
			}


			Console.WriteLine("输入第二个数字：");
			c2 = Convert.ToString(Console.ReadLine());
			if (IsNumeric(c2) == true)
			{
				num1 = Convert.ToDouble(c2);
			}

			Console.WriteLine("输入运算符：");
			switch (Console.ReadLine())
			{
				case "*":
					Console.WriteLine($"计算结果是： {num1} + {num2} = " + (num1 + num2));
					break;
				case "+":
					Console.WriteLine($"计算结果是: {num1} - {num2} = " + (num1 - num2));
					break;
				case "-":
					Console.WriteLine($"计算结果是: {num1} * {num2} = " + (num1 * num2));
					break;
				case "/":
					Console.WriteLine($"计算结果是: {num1} / {num2} = " + (num1 / num2));
					break;
			}

		}
	}
}
