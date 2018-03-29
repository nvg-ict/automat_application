using System;
using System.Collections.Generic;
using System.IO;
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

        public static string[] GetAllFilesFromThisDir()
        {
            //string selectedDir = GetDirectoryPath();
            string selectedDir = "C:\\Users\\Engineer\\Documents\\Nico\\automat project\\automat_application\\test_data\\3\\model";

            return Directory.GetFiles(selectedDir, "*.pmd", SearchOption.AllDirectories);
        }

        public static string GetDirectoryPath()
        {
            System.Windows.Forms.FolderBrowserDialog folderDlg = new System.Windows.Forms.FolderBrowserDialog();

            folderDlg.ShowNewFolderButton = false;

            if (folderDlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                return folderDlg.SelectedPath;
            }
            return null;
        }

        public static string GetFilePath()
        {
            Microsoft.Win32.OpenFileDialog openFileDialog = new Microsoft.Win32.OpenFileDialog();
            openFileDialog.Filter = "PMD files (*.pmd)|*.pmd";
            openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            if (openFileDialog.ShowDialog() == true)
            {
                Console.WriteLine(openFileDialog.FileName);
            }

            return openFileDialog.FileName;
        }
    }
}
