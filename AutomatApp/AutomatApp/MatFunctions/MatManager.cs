using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutomatApp.MatFunctions
{
    class OneFileMatManager : MatManager
    {
        public OneFileMatManager() : base()
        {
        }

        public void CollectFile()
        {
            Files.Add(DirectoryManager.GetFilePath());
        }
    }

    class MultipleFileMatManager : MatManager
    {
        public MultipleFileMatManager() : base()
        {
        }

        public void CollectFiles()
        {
            Files.AddRange(DirectoryManager.GetAllFilesFromThisDir());
        }
    }

    class MatManager
    {
        protected List<string> Files { get; set;}

        public MatManager()
        {
            Files = new List<string>();
        }

        public void Execute()
        {
            List<string> MatPaths = new List<string>();
            //Get all mat files:
            foreach (string file in Files)
            {
                MatPaths.AddRange(FileReader.ReadFile(file));
            }

            foreach(var i in MatPaths)
            {
                Console.WriteLine(i);
            }
        }

    }
}
