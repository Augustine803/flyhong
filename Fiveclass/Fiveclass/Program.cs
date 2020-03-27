using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fiveclass
{
    public class Order
    {
        private static int id;
        private string date;
        private string address;
        public Order(int id, string date, string address)
        {
            Order.id = id;
            this.date = date;
            this.address = address;


        }
        public static int ID
        {       
            get { return id; }
            set { id = value; }
        }
        public string Date
        {
            get { return date; }
            set { date = value; }

        }
        public string Address
        {
            get { return Address; }
            set { Address = value; }
        }
        public override bool Equals(object obj)
        {
            Order m = obj as Order;
            return m != null && m.date == date &&
                m.address == address;
        }
        public override int GetHashCode()
        {
            return id;
        }
        public override string ToString()
        {
            return id + "-" + date + "-" + address;
        }
    }
    public class OrderItems
    {
        private int id = Order.ID;
        public string clientName;
        public string clientPhoneNumber;
        public int goodsnumber;
        public double prices;
        public bool isIntransit;
        public bool isArrived;
        public bool isCancelled;

        public string ClientName
        {
            get { return clientName; }
            set { clientName = value; }
        }

        public string ClientPhoneNumber
        {
            get { return clientPhoneNumber; }
            set { clientPhoneNumber = value; }
        }

        public int GoodsNumber
        {
            get { return goodsnumber; }
            set { goodsnumber = value; }

        }
        public double Prices
        {
            get { return prices; }
            set { prices = value; }

        }

        public bool IsIntransit
        {
            get { return isIntransit; }
            set { isIntransit = value; }
        }
        public bool IsArrived
        {
            get { return isArrived; }
            set { isArrived = value; }
        }
        public bool IsCancelled
        {
            get { return isCancelled; }
            set { isCancelled = value; }
        }
        public override bool Equals(object obj)
        {
            OrderItems m = obj as OrderItems;
            return m != null && m.clientName == clientName && m.clientPhoneNumber == clientPhoneNumber &&
                m.goodsnumber == goodsnumber && m.prices == prices && m.isIntransit == isIntransit && m.isArrived
                == isArrived && m.isCancelled && isCancelled;
        }
        public override int GetHashCode()
        {
            return id;
        }
        public override string ToString()
        {
            return clientName + "-" + clientPhoneNumber + "-" + goodsnumber + "-" + prices + "-" + isIntransit + "-" +
                isArrived + "isArrived?" + "-" + isCancelled + "isCancelled?";
        }
    }
    public class OrderService:OrderItems
    {
        List<string> orderlist = new List<string>();
        public void addOrder()
        {
            OrderItems c = new OrderItems();
            orderlist.Add("name"+c.clientName+ "PhoneNumber" + c.ClientPhoneNumber+ "GoodsNumber:" + c.GoodsNumber+"prices"+c.prices);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
