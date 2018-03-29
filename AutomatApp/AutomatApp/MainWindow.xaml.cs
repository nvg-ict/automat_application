using AutomatApp.MatFunctions;
using AutomatApp.Windows;
using Microsoft.Win32;
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

namespace AutomatApp
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Function to check wether it is possible to shut down the application
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ExitCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void ExitCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void WorkingDirCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void WorkingDirCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            string path = DirectoryManager.GetDirectoryPath();
            if (path != null)
            {
                FileManager.BaseDir = path;
            }
        }

        private void OpenFileCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void OpenFileCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            OneFileMatManager m = new OneFileMatManager();
            m.CollectFile();
            m.Execute();
            UserControls.OpenOneFile OOF = new UserControls.OpenOneFile(m.SizeMatPaths);
            CustomDialog window = new CustomDialog(OOF);
            window.Owner = this;
            window.ShowDialog();
        }

        private void OpenDirCommand_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void OpenDirCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            MultipleFileMatManager m = new MultipleFileMatManager();
            m.CollectFiles();
            m.Execute();
            UserControls.MultipleFile MF = new UserControls.MultipleFile(m.SizeFilePaths, m.SizeMatPaths);
            CustomDialog window = new CustomDialog(MF);
            window.Owner = this;
            window.ShowDialog();
        }

        private void SettingCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Console.WriteLine("Succes");
            SettingsWindow window = new SettingsWindow();
            window.Owner = this;
            window.ShowDialog();
        }

        private void ExportDirCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            string path = DirectoryManager.GetDirectoryPath();
            if (path != null)
            {
                FileManager.ExportDir = path;
            }
        }

        private void InfoCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            Console.WriteLine("INFO");
        }

        private void SetMatDirCommand_Executed(object sender, ExecutedRoutedEventArgs e)
        {
            MatDirsWindow window = new MatDirsWindow();
            window.Owner = this;
            window.ShowDialog();
        }
    }
}
