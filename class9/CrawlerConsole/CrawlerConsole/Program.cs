using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace CrawlerConsole
{
    class Program
    {
        private Hashtable Url = new Hashtable();
        private int count = 0;
        private String StartUrl = "https://image.baidu.com/search/index?tn=baiduimage&ipn=r&ct=201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1590479989243_R&pv=&ic=&nc=1&z=&hd=&latest=&copyright=&se=1&showtab=0&fb=0&width=&height=&face=0&istype=2&ie=utf-8&sid=&word=nba";
        static void Main(string[] args)
        {
            Program MyCr = new Program();
            if (args.Length >= 1) MyCr.StartUrl = args[0];
            MyCr.Url.Add(MyCr.StartUrl, false);//加入初始页面
            new Thread(MyCr.Crawl).Start();
        }

        private void Crawl()
        {
            Console.WriteLine("开始爬行了 ");
            while (true)
            {
                string current = null;
                foreach (string url in Url.Keys)
                {
                    if ((bool)Url[url]) continue;
                    current = url;
                }
                
                if (current == null || count > 10 ) break;
                string html = DownLoad(current); 
                Console.WriteLine("爬行" + current );
                Url[current] = true;
                count++;
                Parse(html);
                Console.WriteLine("爬行结束");
            }
            Console.ReadKey();
        }

        public string DownLoad(string url)
        {
            
                WebClient WebClients = new WebClient();
                WebClients.Encoding = Encoding.UTF8;
                string html = WebClients.DownloadString(url);
                string fileName = count.ToString();
                File.WriteAllText(fileName, html, Encoding.UTF8);
                return html;
           
        }

        private void Parse(string html)
        {
            if(html.Contains("<!DOCTYPE html>"))
            {
                string strRef = @"(href|HREF)[]*=[]*[""'][^""'#>]+[""']";
                MatchCollection matches = new Regex(strRef).Matches(html);
                foreach (Match match in matches)
                {
                    strRef = match.Value.Substring(match.Value.IndexOf('=') + 1)
                              .Trim('"', '\"', '#', '>');
                    if (strRef.Length == 0) continue;
                    if (strRef.Contains(StartUrl))
                    {
                        if (Url[strRef] == null) Url[strRef] = false;
                    }
                }
            }

        }
    }
}
