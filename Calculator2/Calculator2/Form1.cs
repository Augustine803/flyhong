using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                double num1 = 0;
                double num2 = 0;
                double result;
                num1 = Convert.ToDouble(textBox1.Text);
                num2 = Convert.ToDouble(textBox2.Text);
                switch (comboBox1.Text)
                {
                    case "+":
                        result = num1 + num2; textBox3.Text = result.ToString();
                        break;
                    case "-":
                        result = num1 - num2; textBox3.Text = result.ToString();
                        break;
                    case "*":
                        result = num1 * num2; textBox3.Text = result.ToString();
                        break;
                    case "/":
                        if (num2 == 0)
                            textBox3.Text = "除数不能为0.";
                        result = num1 / num2; textBox3.Text = result.ToString();
                        break;
                    default:
                        textBox3.Text = "操作符错误.";
                        break;
                }
            }
            catch (FormatException) { textBox3.Text = "格式异常"; }
            catch (OverflowException) { textBox3.Text = "溢出"; }
        }
    }
}
