using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace AutomatApp.Commands
{
    public static class CustomCommands
    {
        public static readonly RoutedUICommand Exit = new RoutedUICommand
        (
            "Exit",
            "Exit",
            typeof(CustomCommands),
            new InputGestureCollection()
            {
                new KeyGesture(Key.F4, ModifierKeys.Alt)
            }
         );

        public static readonly RoutedUICommand SetWorkingDir = new RoutedUICommand
        (
            "Set Base Directory",
            "Set Base Directory",
            typeof(CustomCommands),
            null
         //new InputGestureCollection()
         //{
         //     new KeyGesture(Key.B, ModifierKeys.Alt)
         //}
         );

        public static readonly RoutedUICommand OpenFile = new RoutedUICommand
        (
            "Open File",
            "Open File",
            typeof(CustomCommands),
            new InputGestureCollection()
            {
                new KeyGesture(Key.O, ModifierKeys.Control)
            }
         );

        public static readonly RoutedUICommand OpenDir = new RoutedUICommand
        (
           "Open Directory",
           "Open Directory",
           typeof(CustomCommands),
           new InputGestureCollection()
           {
                new KeyGesture(Key.F, ModifierKeys.Control)
           }
        );

        public static readonly RoutedUICommand SetMatDir = new RoutedUICommand
        (
           "Set .mat Directories",
           "Set .mat Directories",
           typeof(CustomCommands),
           null
        );

        public static readonly RoutedUICommand SetExportDirectory = new RoutedUICommand
        (
           "Set Export Directory",
           "Set Export Directory",
           typeof(CustomCommands),
           null
        );

        public static readonly RoutedUICommand Settings = new RoutedUICommand
        (
           "Settings",
           "Settings",
           typeof(CustomCommands),
           new InputGestureCollection()
           {
                new KeyGesture(Key.S, ModifierKeys.Alt)
           }
        );

        public static readonly RoutedUICommand Info = new RoutedUICommand
        (
           "Info",
           "Info",
           typeof(CustomCommands),
           null
        );


    }
}
