package ImplementazionePostgresDAO;

import DAO.LaboratorioDAO;
import Database.ConnessioneDatabase;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class ImplementazioneLaboratorioDAO implements LaboratorioDAO {
    private Connection connection;

    public ImplementazioneLaboratorioDAO() {
        try {
            connection = ConnessioneDatabase.getInstance().getConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void aggiungiLaboratorio(String nome, String resp_sci, String topic) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call add_laboratorio(?, ?, ?)");
        query.setString(1, nome);
        query.setString(2, resp_sci);
        query.setString(3, topic);
        query.executeUpdate();
    }

    @Override
    public void acquistaAttrezzatura(String seriale, String nomeLab) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call acquista_attrezzatura(?, ?)");
        query.setString(1, seriale);
        query.setString(2, nomeLab);
        query.executeUpdate();
    }

    @Override
    public void aggiungiAfferente(String cf, String nomeLab) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call add_utilizza(?, ?)");
        query.setString(1, cf);
        query.setString(2, nomeLab);
        query.executeUpdate();
    }

    @Override
    public void rimuoviLaboratorio(String nomeLab) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("delete from laboratorio where nome = ?");
        query.setString(1, nomeLab);

        query.executeUpdate();

    }
}
