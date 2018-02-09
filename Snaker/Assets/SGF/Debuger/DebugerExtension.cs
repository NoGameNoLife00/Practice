using System.Reflection;
using System.Diagnostics;
using UnityEngine;

namespace SGF
{
    public static class DebugerExtension
    {
        // -------------Log------------------
        [Conditional("ENABLE_LOG")]
        public static void Log(this object obj, string message)
        {
            if (!Debuger.EnableLog)
            {
                return;
            }
            Debuger.Log(GetLogTag(obj), (string)message);
        }

        [Conditional("ENABLE_LOG")]
        public static void Log(this object obj, string format, params object[] args)
        {
            if (!Debuger.EnableLog)
            {
                return;
            }
            Debuger.Log(GetLogTag(obj), string.Format(format, args));
        }
        // -----------------Error----------------
        [Conditional("ENABLE_LOG")]
        public static void LogError(this object obj, string message)
        {
            Debuger.LogError(GetLogTag(obj), (string)message);
        }

        [Conditional("ENABLE_LOG")]
        public static void LogError(this object obj, string format, params object[] args)
        {
            Debuger.LogError(GetLogTag(obj), string.Format(format, args));
        }

        // ---------------Warning------------------------------
        [Conditional("ENABLE_LOG")]
        public static void LogWarning(this object obj, string message)
        {
            Debuger.LogWarning(GetLogTag(obj), (string)message);
        }

        [Conditional("ENABLE_LOG")]
        public static void LogWarning(this object obj, string format, params object[] args)
        {
            Debuger.LogWarning(GetLogTag(obj), string.Format(format, args));
        }

        // ----------------private---------------------
        private static string GetLogTag(object obj)
        {
            FieldInfo fi = obj.GetType().GetField("LOG_TAG");
            if (fi != null)
            {
                return (string)fi.GetValue(obj);
            }
            return obj.GetType().Name;
        }
    }
}

