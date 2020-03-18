using System;

namespace alarm
{
    public delegate void AlarmHandeler(object sender, Alarmevent args);
    public class Alarmevent:EventArgs
    {
        public int Hour { get; set; }
        public int Min { get; set; }
        public int Sec { get; set; }
        public string AlarmTime { get; set; }
        public  Alarmevent(int hour, int minute, int second, string words)
        {
            this.Hour = hour; 
            this.Min = minute; 
            this.Sec = second;
            this.AlarmTime = words;
        }
    }
    public class Alarm
    {
        public event AlarmHandeler Tick;
        public event AlarmHandeler alarm;
        int Hour = 0;
        int Min = 0;
        int Sec = 0;
        public void ring()
        {
            while(!(DateTime.Now.Hour==Hour&& DateTime.Now.Minute==Min&& DateTime.Now.Second == Sec)) { }
            Alarmevent alarmevent = new Alarmevent(Hour, Min, Sec, "响铃");
            alarm(this, alarmevent);
        }
        public void Tick1()
        {
            while (!(DateTime.Now.Hour == Hour && DateTime.Now.Minute == Min && DateTime.Now.Second == Sec))
            {
                Alarmevent alarm2event = new Alarmevent(DateTime.Now.Hour, DateTime.Now.Minute, DateTime.Now.Second, "滴答...");
                Tick(this, alarm2event);
            }
        }
        public bool SetAlarm(int hour,int min,int sec)
        {
            if (hour > 24 || min > 60 || sec > 60)
                return false;
            Hour = hour;
            Min = min;
            Sec = sec;
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Alarm a = new Alarm();
            a.SetAlarm(10, 10, 10);
            a.Tick += new AlarmHandeler(AlarmTrigger);
            a.alarm += new AlarmHandeler(AlarmTrigger);
            a.Tick1();
            a.ring();
        }
        private static void AlarmTrigger(object sender, Alarmevent a)
        {
            string message = string.Format("{0}时{1}分{2}秒,{3}", a.Hour, a.Min, a.Sec, a.AlarmTime);
            Console.WriteLine(message);
        }
    }
}
