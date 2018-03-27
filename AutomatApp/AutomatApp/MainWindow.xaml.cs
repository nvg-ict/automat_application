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
            Console.WriteLine("Succes");
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
            MainContent.Children.Clear();
            UserControls.OpenOneFile OOF = new UserControls.OpenOneFile(m.SizeMatPaths);
            MainContent.Children.Add(OOF);
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
           // MainContent.Children.Clear();
            UserControls.MultipleFile MF = new UserControls.MultipleFile(m.SizeFilePaths,m.SizeMatPaths);
            //MainContent.Children.Add(MF);

            CustomDialog window = new CustomDialog(MF);
            window.Owner = this;
            window.ShowDialog();
            //foreach(var i in DirectoryManager.GetAllFilesFromThisDir())
            //{
            //    Console.WriteLine(i);
            //    FileReader.ReadFile(i);
            //}
            //string s = DirectoryManager.GetDirectoryPath();
            //Console.WriteLine(MatList.Size);
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
            Console.WriteLine("Succes");
        }


        //TRIAL AND ERROR CODE!!

        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    OpenFileDialog openFileDialog = new OpenFileDialog();
        //    openFileDialog.Multiselect = true;
        //    openFileDialog.ValidateNames = false;
        //    openFileDialog.CheckFileExists = false;
        //    openFileDialog.CheckPathExists = true;
        //    openFileDialog.Filter = "Text files (*.pmd)|*.pmd|All files (*.*)|*.*";
        //    openFileDialog.InitialDirectory = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
        //    if (openFileDialog.ShowDialog() == true)
        //    {
        //        foreach (string filename in openFileDialog.FileNames)
        //        {
        //            lbFiles.Items.Add(filename);
        //        }
        //    }
        //}

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            //CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            //dialog.InitialDirectory = "C:\\Users";
            //dialog.IsFolderPicker = true;
            //if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            //{
            //    MessageBox.Show("You selected: " + dialog.FileName);
            //}
        }

        private void btnExectute_Click(object sender, RoutedEventArgs e)
        {
            FileReader reader = new FileReader();
            //reader.ReadFile(lbFiles.SelectedItem.ToString());
            // lbFiles.SelectedItem;
        }
    }
}
