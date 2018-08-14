using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        string[] setup;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            System.Media.SoundPlayer sp = new System.Media.SoundPlayer(@"C:\Threads\Startup.wav");
            sp.PlayLooping();

        }

        private void Start_Click(object sender, EventArgs e)
        {
            setup = new string[2];
            setup[0] = nomeA.Text;
            setup[1] = this.classeA.GetItemText(this.classeA.SelectedItem);

            var arr = new string[] { setup[0], setup[1] };
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.CreateNoWindow = false;
            startInfo.UseShellExecute = false;
            const string path = @"C:\Threads\Threads.exe";
            const string argsSeparator = " ";
            string args = string.Join(argsSeparator, arr);
            Process.Start(path, args);
            System.Windows.Forms.Application.Exit();
        }
    }
}
