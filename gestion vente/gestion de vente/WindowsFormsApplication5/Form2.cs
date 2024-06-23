using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
namespace WindowsFormsApplication5
{
    public partial class Form2 : Form
    {
        private string server;
        private string database;
        private string uid;
        private string password;
        private MySqlConnection connection;
      

        public Form2()
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

        private void Form2_Load(object sender, EventArgs e)
        {
            text_code.Focus();
            text_code.SelectAll();
        }

        


        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            




            
        }

        private void text_code_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                text_code.SelectAll();
            }
        }

        private void btn_sept_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "7";
        }

        private void btn_huite_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "8";
        }

        private void btn_neuf_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "9";
        }

        private void btn_quatre_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "4";
        }

        private void btn_cinq_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "5";
        }

        private void btn_six_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "6";
        }

        private void un_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "1";
        }

        private void btn_deux_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "2";
        }

        private void btn_trois_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "3";
        }

        private void zero_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += "0";
        }

        private void point_vi_Click(object sender, EventArgs e)
        {
            textBox_saisie.Text += ".";
        }

        private void btn_add_qte_Click(object sender, EventArgs e)
        {
            //selectionne last row
            //int last_row = dataGridView1.Rows.Count - 1;

            
            //MessageBox.Show(" requete : "+a);
            // value quantite
            int qte = Int32.Parse(dataGridView1.CurrentRow.Cells[2].Value.ToString());
            dataGridView1.CurrentRow.Cells[2].Value = 1 +qte;
            Calcule_prix();
            Calcule_qte();

        }

        private void btn_back_Click(object sender, EventArgs e)
        {
            int taille = textBox_saisie.Text.Length;
            String a = textBox_saisie.Text.Trim();



            if (taille != 0)
            {
                String ch = textBox_saisie.Text.Substring(0, taille - 1).Trim();
                textBox_saisie.Text = ch.Trim();

            }
        }

       

        private void btn_remove_qte_Click(object sender, EventArgs e)
        {
            int qte = Int32.Parse(dataGridView1.CurrentRow.Cells[2].Value.ToString());
            if (qte > 1)
            {

                dataGridView1.CurrentRow.Cells[2].Value = qte - 1;
                Calcule_prix();
                Calcule_qte();
            }
            else {

                int index = dataGridView1.CurrentCell.RowIndex;
                dataGridView1.Rows.RemoveAt(index); 
                Calcule_prix();
                Calcule_qte();
            }
        }

        private void btn_clear_grid_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            text_totale.Text = "0,00";
            label_quantite.Text = "0";
            label_designation.Text = "...........";
            label_prix.Text = "0,00";
            text_code.Text = "";


        }

        private void btn_supp_Click(object sender, EventArgs e)
        {
            int index = dataGridView1.CurrentCell.RowIndex;
            if (index > 0)
            {
                dataGridView1.Rows.RemoveAt(index);
                Calcule_prix();
                Calcule_qte();
            }
        }

        private void btn_up_Click(object sender, EventArgs e)
        {
            int index = dataGridView1.CurrentCell.RowIndex;
            if(index>0)
            {
                label_quantite.Text = index.ToString();
                dataGridView1.CurrentCell = dataGridView1.Rows[index-1].Cells[0];

               }
        }

        private void btn_down_Click(object sender, EventArgs e)
        {
            int last_row = dataGridView1.Rows.Count - 1;
            int index = dataGridView1.CurrentCell.RowIndex;
            if (index < last_row)
           {
                label_quantite.Text = index.ToString();
                dataGridView1.CurrentCell = dataGridView1.Rows[index + 1].Cells[0];

            }

        }

        private void btn_qte_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals("") && !textBox_saisie.Text.Equals("."))
            {
                dataGridView1.CurrentRow.Cells[2].Value = textBox_saisie.Text;
                textBox_saisie.Text = "";
                Calcule_prix();
                Calcule_qte();
            }
            else { textBox_saisie.Text = ""; }
        }

        

        private void text_code_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
              
              
                double prix_produit = 0;
                connection.Close();
                Boolean existe = false;
                int position = 0;
                connection.Open();
                string query = "SELECT CodeAbarre,Nom,Prix from produit where CodeAbarre='" + text_code.Text.Trim() + "'";

                MySqlCommand cmd = new MySqlCommand(query, connection);

                MySqlDataAdapter dataAdapter = new MySqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                dataAdapter.Fill(dt);





                foreach (DataRow row in dt.Rows)
                {


                    if (dataGridView1.Rows.Count == 0)
                    {

                        prix_produit = double.Parse(row[2].ToString());
                        dataGridView1.Rows.Add(row[0].ToString(), row[1].ToString(), "1", prix_produit.ToString("F3"));
                       
                        // afficher les donner de produit entrer
                        int last_row = dataGridView1.Rows.Count - 1;
                        label_designation.Text=dataGridView1.Rows[last_row].Cells[1].Value.ToString();
                        label_prix.Text=dataGridView1.Rows[last_row].Cells[3].Value.ToString();
                    }

                    else
                    {

                        for (int j = 0; j < dataGridView1.Rows.Count; j++)
                        {

                            if (double.Parse(text_code.Text) == double.Parse(dataGridView1.Rows[j].Cells[0].Value.ToString()))
                            {
                                existe = true;
                                position = j;

                                break;// exit loop  if condition is true
                            }

                            else
                            {
                                existe = false;


                            }

                        }//fin pour 
                        if (existe)
                        {
                            dataGridView1.Rows[position].Cells[2].Value = 1 + Int32.Parse(dataGridView1.Rows[position].Cells[2].Value.ToString());


                        }
                        else
                        {
                            prix_produit = double.Parse(row[2].ToString());

                            dataGridView1.Rows.Add(row[0].ToString(), row[1].ToString(), "1", prix_produit.ToString("F3"));
                            // afficher les donner de produit entrer
                            int last_row = dataGridView1.Rows.Count - 1;
                            label_designation.Text = dataGridView1.Rows[last_row].Cells[1].Value.ToString();
                            label_prix.Text = dataGridView1.Rows[last_row].Cells[3].Value.ToString();
                          
                          
                            dataGridView1.CurrentCell = dataGridView1.Rows[last_row].Cells[0];

                        }




                    }

                }// fin for each
                Calcule_prix();
                Calcule_qte();
            }
        }
// calculer les prix total /// A payer
        public void Calcule_prix()
        {
            double prix = 0;
           for (int c = 0; c < dataGridView1.Rows.Count; c++)
            {
                
                prix = prix + (double.Parse(dataGridView1.Rows[c].Cells[3].Value.ToString()) * double.Parse(dataGridView1.Rows[c].Cells[2].Value.ToString()));
            }
            // prix = prix / 1000;
            text_totale.Text = prix.ToString("F3");

        }
        // calculer qunatité total
        public void Calcule_qte()
        {
            double qte = 0;
            for (int c = 0; c < dataGridView1.Rows.Count; c++)
            {

                qte = qte + double.Parse(dataGridView1.Rows[c].Cells[2].Value.ToString()) ;
            }
            // prix = prix / 1000;
            label_quantite.Text = qte.ToString("");

        }

        private void btn_exit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btn_client_Click(object sender, EventArgs e)
        {
            Client client = new Client();
            client.Show();
        }

        private void btn_especes_Click(object sender, EventArgs e)
        {
            especes especes = new especes();
            especes.Show();
        }

        private void button16_Click(object sender, EventArgs e)
        {

        }



        //fin 
    }
}
