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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace AutomatApp.UserControls
{
    /// <summary>
    /// Interaction logic for OpenOneFile.xaml
    /// </summary>
    public partial class OpenOneFile : UserControl
    {
        MatManager manager;
        public OpenOneFile(MatManager manager)
        {
            InitializeComponent();
            this.manager = manager;
            MatInfo.Content = string.Format("Collected {0} .mat files.", manager.MatPaths.Count);
            PathInfo.Text = string.Format("Current paths set are: \nBase folder: {0}\nExport folder: {1} ",FileManager.BaseDir, FileManager.ExportDir);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            manager.MoveMatFiles();
        }
    }
}
