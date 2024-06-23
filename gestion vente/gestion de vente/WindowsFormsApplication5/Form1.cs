using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Diagnostics;
using MySql.Data.MySqlClient;



namespace WindowsFormsApplication5
{
    public partial class Form1 : Form
    {
       
       private MySqlConnection connection;
        private string server;
        private string database;
        private string uid;
        private string password;
        

        public Form1()
        {
            InitializeComponent();

             database = "test";
             uid = "root";
             password = "";
             server = "127.0.0.1";
             string connectionString;
             connectionString = "SERVER=" + server + ";" + "DATABASE=" +
             database + ";" + "Charset=utf8" + ";" + "UID=" + uid + ";" + "PASSWORD=" + password + ";";
           
             connection = new MySqlConnection(connectionString);
            


          
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Process.Start("C:/Users/HP/AppData/Local/Google/Chrome/Application/chrome.exe");


                connection.Open();
                string query = "INSERT INTO produit (CodeAbarre,Prix,Nom) VALUES('" + text_code.Text + "','" + text_prix.Text + "','" + text_nom.Text + "')";

            //open connection
           
                //create command and assign the query and connection from the constructor
                MySqlCommand cmd = new MySqlCommand(query, connection);
                
                //Execute command
                cmd.ExecuteNonQuery();

                //close connection
                connection.Close();
            



        }

       /* load_from(new Form2());
        public void load_from(Object frame)
        {
            if (this.panelside.Controls.Count > 0)
                this.panelside.Controls.RemoveAt(0);
            Form fh = frame as Form;
            fh.TopLevel = false;
            fh.Dock = DockStyle.Fill;
            this.panelside.Controls.Add(fh);
            this.panelside.Tag = fh;
            fh.Show();


         }*/




        

        private void Form1_Load(object sender, EventArgs e)
        {

        }

       


       
    }
}
