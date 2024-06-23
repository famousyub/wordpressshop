using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;
namespace WindowsFormsApplication5
{
    class ConnectBD
    {

        public static MySqlConnection connection = null;
        private string server;
        private string database;
        private string uid;
        private string password;
        public void Connect()
        {

            server = "localhost:3306";

            database = "test";
            uid = "root";
            password = "";
            string connectionString;
            connectionString = "SERVER=" + server + ";" + "DATABASE=" +
            database + ";" + "Charset=utf8" + ";" + "UID=" + uid + ";" + "PASSWORD=" + password + ";";

            connection = new MySqlConnection(connectionString);

        }

    }
}
