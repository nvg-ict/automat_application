using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace AutomatApp.MatFunctions
{
    class MatList
    {
        public static HashSet<string> MatFiles;

        public static int Size { get { return MatFiles.Count; } }

        static MatList()
        {
            MatFiles = new HashSet<string>();
        }

        public static void AddMatFile()
        {

        }

        public static void RemoveMatFile()
        {

        }
    }
}
