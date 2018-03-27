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
    /// Interaction logic for MultipleFile.xaml
    /// </summary>
    public partial class MultipleFile : UserControl
    {
        public MultipleFile(int amtOfFiles, int amtOfMatFiles)
        {
            InitializeComponent();
            FileInfo.Content = string.Format("Collected {0} files.", amtOfFiles);
            MatInfo.Content = string.Format("Collected {0} .mat files.", amtOfMatFiles);
        }
    }
}
