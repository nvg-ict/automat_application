using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutomatApp.MatFunctions
{
    class DirectoryManager
    {
        public static string ExportDirectory { get; set; }
        public static List<string> MatDirectories { get; set; }
        public static string BaseDirecotry { get; set; }

        static DirectoryManager()
        {
            MatDirectories = new List<string>();
        }
    }
}
