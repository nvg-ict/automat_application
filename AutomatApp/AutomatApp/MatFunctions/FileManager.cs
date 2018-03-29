using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutomatApp.MatFunctions
{
    class FileManager
    {
        public static string BaseDir { get; set; }
        public static string ExportDir { get; set; }
        public static ObservableCollection<string> MatDirs { get; set; }

        static FileManager()
        {
            MatDirs = new ObservableCollection<string>();
        }
    }
}
