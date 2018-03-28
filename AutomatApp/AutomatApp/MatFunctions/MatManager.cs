using System;
using System.Collections.Generic;
using System.IO;
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
        protected List<string> Files { get; set; }
        protected List<string> MatPaths { get; set; }
        public int SizeMatPaths { get { return MatPaths.Count; } }
        public int SizeFilePaths { get { return Files.Count; } }


        public MatManager()
        {
            Files = new List<string>();
            MatPaths = new List<string>();
        }

        public void Execute()
        {
            //Get all mat files:
            foreach (string file in Files)
            {
                MatPaths.AddRange(FileReader.ReadFile(file));
            }

            //foreach (var i in MatPaths)
            //{
            //    Console.WriteLine(i);
            //}

            int counterFound = 0;
            int counterNFound = 0;
            foreach (string file in MatPaths)
            {
                string root = "C:/Users/Engineer/Documents/Nico/automat project/automat_application/test_data/3";
                string export = "C:/Users/Engineer/Documents/Nico/automat project/automat_application/test_data/3/export";
                string path = root + file;
                path = path.Replace('/','\\');
                Console.WriteLine(path);
                if (!File.Exists(@path))
                {
                    ++counterNFound;
                }
                else
                {
                    ++counterFound;
                    string createPath = export + file;
                   string fileName = createPath.Substring(createPath.LastIndexOf("/"));

                    createPath = createPath.Substring(0, createPath.LastIndexOf("/") + 1);
                    DirectoryInfo di = Directory.CreateDirectory(createPath);
                    File.Copy(path,createPath + fileName,true);
                }
            }

            Console.WriteLine("Found: {0}" , counterFound);
            Console.WriteLine("Not Found: {0}", counterNFound);
            Console.WriteLine("Total: {0}", MatPaths.Count);
        }

    }
}
