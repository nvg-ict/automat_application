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
    /// Interaction logic for DragnDrop.xaml
    /// </summary>
    public partial class DragnDrop : UserControl
    {
        public DragnDrop()
        {
            InitializeComponent();
        }

        private void DropList_DragEnter(object sender, DragEventArgs e)
        {
            if (!e.Data.GetDataPresent(DataFormats.FileDrop) ||
                sender == e.Source)
            {
                e.Effects = DragDropEffects.None;
            }
        }

        private void DropList_Drop(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                // Note that you can have more than one file.
                string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

                // Assuming you have one file that you care about, pass it off to whatever
                // handling code you have defined.
                foreach (var file in files)
                {
                    Console.WriteLine(file);
                    FileReader.ReadFile(file);
                }

                foreach (var n in MatList.MatFiles)
                {
                    Console.WriteLine(MatList.Size);
                }
            }
        }
    }
}
