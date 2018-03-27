using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace AutomatApp.MatFunctions
{
    //public class MatList<T> : INotifyCollectionChanged, IEnumerable<T>
    //{
    //    private HashSet<T> MatFiles = new HashSet<T>();
    //    public event NotifyCollectionChangedEventHandler CollectionChanged;

    //    public static int Size { get { return MatFiles.Count; } }


    //    public void Add(T item)
    //    {
    //        MatFiles.Add(item);
    //        OnCollectionChange(new NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction.Add, item));
    //    }

    //    public IEnumerator<T> GetEnumerator()
    //    {
    //        return MatFiles.GetEnumerator();
    //    }

    //    protected virtual void OnCollectionChange(NotifyCollectionChangedEventArgs e)
    //    {
    //        if (CollectionChanged != null)
    //            CollectionChanged(this, e);
    //    }

    //    IEnumerator IEnumerable.GetEnumerator()
    //    {
    //        return MatFiles.GetEnumerator();
    //    }
    //}
    class MatList
    {
        public MatFiles MatFiles {get; set;}

        public int Size { get { return MatFiles.Collection.Count; } }
    }

    class MatFiles
    {
        public ObservableCollection<string> Collection { get; set; }

        public MatFiles()
        {
            Console.WriteLine("WOOOOOW");
            Collection = new ObservableCollection<string>(Collection.Distinct());
        }

        private void SensorList_CollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
        {
            Console.WriteLine("UPDATE!! YAY");
        }
    }
}
