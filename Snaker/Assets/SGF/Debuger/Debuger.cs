using System;
using System.IO;
using UnityEngine;

namespace UnityEngine
{
    public class Debuger
    {
        public static bool EnableLog;
        public static bool EnableTime = true;
        public static bool EnableSave = false;
        public static bool EnableStack = false;
        public static string LogFileDir = Application.persistentDataPath + "/DebugerLog/";
        public static string LogFileName = "";
        public static string Prefix = "> ";
        public static StreamWriter LogFileWriter = null;

        public static void Log(string tag, string message = "")
        {
            if (!Debuger.EnableLog)
            {
                return;
            }
            string msg = GetLogText(tag, message);
            Debug.Log(Prefix + msg, null);
            LogToFile("[I]" + msg);
        }


        public static void Log(string tag, string format, params object[] args)
        {
            if (!Debuger.EnableLog)
            {
                return;
            }
            string msg = GetLogText(tag, string.Format(format, args));
            Debug.Log(Prefix + msg);
            LogToFile("[I]" + msg);
        }


        public static void LogWarning(string tag, string message)
        {
            string msg = GetLogText(tag, message);
            Debug.Log(Prefix + msg, null);
            LogToFile("[W]" + msg);
        }

        public static void LogWarning(string tag, string format, params object[] args)
        {
            string msg = GetLogText(tag, string.Format(format, args));
            Debug.Log(Prefix + msg);
            LogToFile("[W]" + msg);
        }



        public static void LogError(string tag, string message)
        {
            string msg = GetLogText(tag, message);
            Debug.Log(Prefix + msg);
            LogToFile("[E]" + msg, true);
        }

        public static void LogError(string tag, string format, params object[] args)
        {
            string msg = GetLogText(tag, string.Format(format, args));
            Debug.Log(Prefix + msg);
            LogToFile("[E]" + msg, true);
        }


        // -------------------------------------------------------
        private static string GetLogText(string tag, string message)
        {
            string str = "";
            if (Debuger.EnableTime)
            {
                DateTime now = DateTime.Now;
                str = now.ToString("HH:mm:ss.fff") + " ";
            }
            str = str + tag + "::"  + message;
            return str;
        }

        private static void LogToFile(string message, bool EnableStack = false)
        {
            if (!EnableSave)
            {
                return;
            }
            if (LogFileWriter == null)
            {
                DateTime now = DateTime.Now;
                LogFileName = now.GetDateTimeFormats('s')[0].ToString(); // 2015-11-05T14:06:25
                LogFileName = LogFileName.Replace("-", "_");
                LogFileName = LogFileName.Replace(":", "_");
                LogFileName = LogFileName.Replace(" ", "");
                string fullpath = LogFileDir + LogFileName;
                try
                {
                    if (!Directory.Exists(LogFileDir))
                    {
                        Directory.CreateDirectory(LogFileDir);
                    }

                    LogFileWriter = File.AppendText(fullpath);
                    LogFileWriter.AutoFlush = true;
                }
                catch (Exception e)
                {
                    LogFileWriter = null;
                    Debug.Log("LogToCache() " + e.Message + e.StackTrace);
                    return;
                }
            }

            if (LogFileWriter != null)
            {
                try
                {
                    LogFileWriter.Write(message);
                    if (EnableStack || Debuger.EnableStack)
                    {
                        LogFileWriter.WriteLine(StackTraceUtility.ExtractStackTrace());
                    }
                }
                catch (Exception)
                {
                    return;
                }
            }
        }
    }

}

