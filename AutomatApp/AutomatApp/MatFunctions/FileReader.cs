using AutomatApp.MatFunctions;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace AutomatApp
{
    class FileReader
    {
        public static void ReadFile(string fileName)
        {
            Console.WriteLine("Open file");
            string file = File.ReadAllText(fileName);

            var pattern = @"([a-zA-Z0-9\\-\\_\\/]*\.mat)";

            foreach (Match ItemMatch in Regex.Matches(file, pattern))
            {
                //Console.WriteLine(ItemMatch);
                MatList.MatFiles.Add(ItemMatch.ToString());
            }
        }
    }
}
