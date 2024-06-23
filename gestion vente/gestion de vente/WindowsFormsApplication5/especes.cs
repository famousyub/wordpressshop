using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class especes : Form
    {
        public especes()
        {
            InitializeComponent();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 0.200;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_5_Click(object sender, EventArgs e)
        {

            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 5.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_10_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 10.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn20_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 20.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn50_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 50.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_5_m_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 0.050;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_100_m_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 0.100;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_500_m_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 0.500;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;
            }
        }

        private void btn_1_dinar_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 1.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;

            }
        }

        private void btn_2_dinar_Click(object sender, EventArgs e)
        {
            if (!textBox_saisie.Text.Equals(""))
            {
                double temp_dinar = double.Parse(textBox_saisie.Text);
                double somme = temp_dinar + 2.000;
                textBox_saisie.Text = somme.ToString("F3");
                //+dinar;

            }
        }



    }
}
