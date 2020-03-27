using System;
using System.Collections.Generic;

namespace OrderControl
{
    public class Order
    {
        public static int OrderID;//订单号
        public string Cilentname;//客户名称
        public string ItemName;//物品名称

        public Order()
        {
        }

        public Order(int OrderID, string Cilentname, string ItemName)
        {
            this.Cilentname = Cilentname;
            Order.OrderID = OrderID;
            this.ItemName = ItemName;
        }
        public static int ID
        {        //属性
            get { return OrderID; }
            set { OrderID = value; }
        }
        public string name
        {
            get { return Cilentname; }
            set { Cilentname = value; }

        }
        public string item
        {
            get { return ItemName; }
            set { ItemName = value; }
        }
        public override bool Equals(object obj)
        {
            Order m = obj as Order;
            return m != null  &&
                m.Cilentname == Cilentname &&
                m.ItemName == ItemName;
        }
        public override string ToString()
        {
            return OrderID + "-" + Cilentname + "-" + ItemName;
        }
        public override int GetHashCode()
        {
            return OrderID;
        }

    }
    public class OrderItem
    {
        private int id = Order.OrderID;
        private string clientName;//客户名字
        private string clientPhoneNumber;//客户联系方式（电话/手机号码）
        private int goodsQuantity;//订购的物品数量
        private double prices;//订单价格
        private bool isIntransit;//货物是否正在运输
        private bool isArrived;//货物是否到达
        private bool isCancelled;//订单是否被取消

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

        public int GoodsQuantity
        {
            get { return goodsQuantity; }
            set { goodsQuantity = value; }

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
            OrderItem m = obj as OrderItem;
            return m != null && m.clientName == clientName && m.clientPhoneNumber == clientPhoneNumber &&
                m.goodsQuantity == goodsQuantity && m.prices == prices && m.isIntransit == isIntransit && m.isArrived
                == isArrived && m.isCancelled && isCancelled;
        }
        public override int GetHashCode()
        {
            return id;
        }
        public override string ToString()
        {
            return clientName + "-" + clientPhoneNumber + "-" + goodsQuantity + "-" + prices + "-" + isIntransit + "-" +
                isArrived + "isArrived?" + "-" + isCancelled + "isCancelled?";
        }
    }
    public class OrderService
    {
        List<string> orderlist = new List<string>();
        public void AddOrder()
        {
            Order s = new Order();
            orderlist.Add(s.Cilentname + s.ItemName + Order.OrderID);
        }
        public void Deleteorder()
        {
            Order s = new Order();
            orderlist.Remove(s.Cilentname + s.ItemName + Order.OrderID);
        }
       
    }


    class Program
    {
        static void Main(string[] args)
        {
            Order s = new Order();
            Console.WriteLine("输入物品名称，客户名称:用中文逗号隔开");
            string m = Console.ReadLine();
            string[] o = m.Split('，');
            o[1] = s.ItemName;
            o[2] = s.Cilentname;
            Order.OrderID = DateTime.Now.Second;
            OrderService orderService = new OrderService();
            orderService.AddOrder();
            
        }
    }
}
