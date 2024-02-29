package Database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnessioneDatabase {
    private static ConnessioneDatabase instance;
    public Connection connection;

    private ConnessioneDatabase() {
        try {
            String url = "jdbc:postgresql://ep-muddy-feather-41247684.eu-central-1.aws.neon.tech/progetto";
            String user = "sorcho";
            String password = "OsDunIv40EUm";
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            System.out.println("Errore: " + e.getMessage());
        }
    }

    public static ConnessioneDatabase getInstance() throws SQLException {
        if (instance == null)
            instance = new ConnessioneDatabase();
        else if (instance.connection.isClosed())
            instance = new ConnessioneDatabase();
        return instance;
    }

    public Connection getConnection() throws SQLException {
        return connection;
    }
}
