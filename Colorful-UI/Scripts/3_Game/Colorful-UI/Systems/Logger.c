class CuiLogger
{
    protected static string LOG_FILE;
    protected static bool m_Initialized = false;

    static void Log(string message)
    {
        if (!CuiDebug) return;

        if (!m_Initialized)
        {
            InitCUILogger();
            m_Initialized = true;
        }

        FileHandle handle = OpenFile(LOG_FILE, FileMode.APPEND);
        if (handle)
        {
            FPrintln(handle, Timestamp() + " [" + RealDateTime() + "] - " + message);
            CloseFile(handle);
        }
    }

    protected static void InitCUILogger()
    {
        if (!CuiDebug) return;

        LOG_FILE = "$profile:\\ColorfulLogs\\cui_logs_" + DateAndHourMinute() + ".log";

        FileHandle file = OpenFile(LOG_FILE, FileMode.WRITE);
        if (file != 0)
        {
            string timestamp = HeaderTimestamp();
            FPrintln(file, "-----------------------------------------------------------");
            FPrintln(file, "Log " + LOG_FILE + " started at " + timestamp);
            FPrintln(file, "");
            CloseFile(file);
        }
    }

    protected static string Timestamp()
    {
        if (!GetGame()) return "[NULL_GAME]";
        float time = GetGame().GetTime();

        int seconds = Math.Floor(time / 1000);
        int minutes = seconds / 60;
        int hours = minutes / 60;
        minutes = minutes % 60;
        seconds = seconds % 60;

        return hours.ToStringLen(2) + ":" + minutes.ToStringLen(2) + ":" + seconds.ToStringLen(2);
    }

    protected static string HeaderTimestamp()
    {
        int year, month, day, hour, minute, second;

        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        return day.ToStringLen(2) + "." + month.ToStringLen(2) + ". " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
    }

    protected static string RealDateTime()
    {
        int year, month, day, hour, minute, second;
        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        return year.ToStringLen(4) + "-" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + " " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
    }

    protected static string DateAndHourMinute()
    {
        int year, month, day, hour, minute, second;
        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        return year.ToStringLen(4) + "-" + month.ToStringLen(2) + "-" + day.ToStringLen(2) + "_" + hour.ToStringLen(2) + "-" + minute.ToStringLen(2);
    }
}
