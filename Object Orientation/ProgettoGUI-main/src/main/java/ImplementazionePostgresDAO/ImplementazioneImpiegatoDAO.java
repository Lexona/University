package ImplementazionePostgresDAO;

import DAO.ImpiegatoDAO;
import Database.ConnessioneDatabase;

import java.sql.*;
import java.util.ArrayList;

public class ImplementazioneImpiegatoDAO implements ImpiegatoDAO {
    private Connection connection;

    public ImplementazioneImpiegatoDAO() {
        try {
            connection = ConnessioneDatabase.getInstance().getConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void assumiImpiegato(String cf, String nome, String cognome, Date dataNascita, Date dataAssunzione, String categoria) throws SQLException {
        CallableStatement query;
        query = connection.prepareCall("call add_impiegato(?, ?, ?, ?, ?, ?)");
        query.setString(1, cf);
        query.setString(2, nome);
        query.setString(3, cognome);
        query.setDate(4, dataNascita);
        query.setDate(5, dataAssunzione);
        query.setString(6, categoria);
        query.execute();
    }

    @Override
    public void assumiImpiegatoProgetto(String cf, String nome, String cognome, Date dataNascita, Date dataAssunzione, Date dataScadenza, String cup) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call add_impiegato_progetto(?, ?, ?, ?, ?, ?, ?)");
        query.setString(1, cf);
        query.setString(2, nome);
        query.setString(3, cognome);
        query.setDate(4, dataNascita);
        query.setDate(5, dataAssunzione);
        query.setDate(6, dataScadenza);
        query.setString(7, cup);
        query.executeUpdate();
    }

    @Override
    public void licenziaImpiegato(String cf) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call delete_impiegato(?)");
        query.setString(1, cf);
        query.executeUpdate();
    }

    @Override
    public boolean sostituisciImpiegato(String vecchioCF, String nuovoCF) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call substitute_impiegato(?, ?)");
        query.setString(1, vecchioCF);
        query.setString(2, nuovoCF);
        int risultato = query.executeUpdate();
        return risultato == 1;
    }

    @Override
    public void promuoviImpiegato(String cf, String promotoreDirigente) throws SQLException {
        PreparedStatement query;
        query = connection.prepareCall("call add_promozione(?, ?)");
        query.setString(1, cf);
        query.setString(2, promotoreDirigente);
        query.executeUpdate();
    }

    @Override
    public boolean getAfferenze(String cf, ArrayList<String> listaLaboratori) {
        try {
            PreparedStatement query;
            query = connection.prepareStatement("SELECT nome_lab FROM utilizza WHERE cf = ?");
            query.setString(1, cf);

            ResultSet rs = query.executeQuery();

            while (rs.next())
                listaLaboratori.add(rs.getString(1));

            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }
}
