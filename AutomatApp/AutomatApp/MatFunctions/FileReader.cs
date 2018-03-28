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
        public static string[] ReadFile(string fileName)
        {
            string file = File.ReadAllText(fileName);

            var pattern = @"([a-zA-Z0-9\\-\\_\\/]*\.mat)";

            return Regex.Matches(file, pattern)
            .Cast<Match>()
            .Select(m => m.Value)
            .ToArray();
        }
    }
}
