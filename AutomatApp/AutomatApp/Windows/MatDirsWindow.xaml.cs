using AutomatApp.MatFunctions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace AutomatApp.Windows
{
    /// <summary>
    /// Interaction logic for MatDirsWindow.xaml
    /// </summary>
    public partial class MatDirsWindow : Window
    {
        public MatDirsWindow()
        {
            InitializeComponent();
        }

        private void Button_Click_Add(object sender, RoutedEventArgs e)
        {
            string s = DirectoryManager.GetDirectoryPath();
            Console.WriteLine(s);
            if(s != null)
            {
                FileManager.MatDirs.Add(s);
            }
        }

        private void Button_Click_Remove(object sender, RoutedEventArgs e)
        {
            for (int i = MatGrid.SelectedItems.Count - 1; i >= 0; i--)
                FileManager.MatDirs.Remove((string)MatGrid.SelectedItems[i]);
        }
    }
}
