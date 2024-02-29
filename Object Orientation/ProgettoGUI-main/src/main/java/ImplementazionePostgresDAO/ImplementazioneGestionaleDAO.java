package ImplementazionePostgresDAO;

import DAO.GestionaleDAO;
import Database.ConnessioneDatabase;
import Model.Promozione;

import java.sql.*;
import java.util.ArrayList;

public class ImplementazioneGestionaleDAO implements GestionaleDAO {
    Connection connection;

    public ImplementazioneGestionaleDAO() {
        try {
            connection = ConnessioneDatabase.getInstance().getConnection();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void getImpiegati(ArrayList<String> listaCF, ArrayList<String> listaNomi, ArrayList<String> listaCognomi, ArrayList<Date> listaDateNascita, ArrayList<Date> listaDateAssunzione, ArrayList<Integer> listaEta, ArrayList<String> listaCategorie, ArrayList<Float> listaSalari, ArrayList<Date> listaDateScadenza, ArrayList<String> listaTipiContratto) {
        try {
            PreparedStatement query;
            query = connection.prepareStatement("SELECT * FROM impiegato");
            ResultSet rs = query.executeQuery();

            while (rs.next()) {
                listaCF.add(rs.getString("cf"));
                listaNomi.add(rs.getString("nome"));
                listaCognomi.add(rs.getString("cognome"));
                listaDateNascita.add(rs.getDate("data_nascita"));
                listaDateAssunzione.add(rs.getDate("data_assunzione"));
                listaEta.add(rs.getInt("eta"));
                listaCategorie.add(rs.getString("categoria"));
                listaSalari.add(rs.getFloat("salario"));
                listaDateScadenza.add(rs.getDate("data_scadenza"));
                listaTipiContratto.add(rs.getString("tipo_contratto"));
            }

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura dei dati dal database.");
        }
    }

    @Override
    public void getLaboratori(ArrayList<String> listaNomi, ArrayList<String> listaRespSci, ArrayList<String> listaTopic, ArrayList<Integer> listaNAfferenti, ArrayList<String> listaProgetti) {
        try {
            PreparedStatement queryLab;
            queryLab = connection.prepareStatement("SELECT * FROM laboratorio");
            ResultSet rsLab = queryLab.executeQuery();

            PreparedStatement queryProg;
            queryProg = connection.prepareStatement("SELECT cup FROM lavora WHERE laboratorio = ?");
            ResultSet rsProg;


            while (rsLab.next()) {
                listaNomi.add(rsLab.getString("nome"));
                listaRespSci.add(rsLab.getString("resp_sci"));
                listaTopic.add(rsLab.getString("topic"));
                listaNAfferenti.add(rsLab.getInt("n_afferenti"));

                queryProg.setString(1, rsLab.getString("nome"));
                rsProg = queryProg.executeQuery();

                if (rsProg.next())
                    listaProgetti.add(rsProg.getString(1));
                else
                    listaProgetti.add(null);
            }

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura dei dati dal database.");
        }

    }

    @Override
    public void getAttrezzature(ArrayList<String> listaSeriali, ArrayList<String> listaTipi, ArrayList<Float> listaCosti, ArrayList<String> listaNomiLab, ArrayList<String> listaCup) {
        try {
            PreparedStatement query;

            query = connection.prepareStatement("SELECT * from attrezzatura");
            ResultSet rs = query.executeQuery();

            while (rs.next()) {
                listaSeriali.add(rs.getString("seriale"));
                listaTipi.add(rs.getString("tipo"));
                listaCosti.add(rs.getFloat("costo"));
                listaNomiLab.add(rs.getString("nome_lab"));
                listaCup.add(rs.getString("cup"));
            }

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura di dati dal database.");
        }
    }

    @Override
    public void getProgetti(ArrayList<String> listaCup, ArrayList<String> listaRefSci, ArrayList<String> listaResp, ArrayList<String> listaNomi, ArrayList<Float> listaBudget) {
        try {
            PreparedStatement query;

            query = connection.prepareStatement("SELECT * from progetto");
            ResultSet rs = query.executeQuery();

            while (rs.next()) {
                listaCup.add(rs.getString("cup"));
                listaRefSci.add(rs.getString("ref_sci"));
                listaResp.add(rs.getString("resp"));
                listaNomi.add(rs.getString("nome"));
                listaBudget.add(rs.getFloat("budget"));
            }

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura di dati dal database.");
        }
    }

    public void getPromozioni(ArrayList<String> listaCF, ArrayList<Date> listaDatePassaggio, ArrayList<String> listaVecchieCategorie, ArrayList<String> listaNuoveCategorie, ArrayList<String> listaPromotoriDirigenti) {
        try {
            PreparedStatement query;

            query = connection.prepareStatement("SELECT * from promozione");
            ResultSet rs = query.executeQuery();

            while (rs.next()) {
                listaCF.add(rs.getString("cf"));
                listaDatePassaggio.add(rs.getDate("data_passaggio"));
                listaVecchieCategorie.add(rs.getString("vecchia_categoria"));
                listaNuoveCategorie.add(rs.getString("nuova_categoria"));
                listaPromotoriDirigenti.add(rs.getString("promotore_dirigente"));
            }

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura di dati dal database.");
        }
    }

    @Override
    public void getListaAfferenti(String nomeLab, ArrayList<String> listaAfferenti) {
        try {
            PreparedStatement query;
            query = connection.prepareStatement("select cf from utilizza where nome_lab = ?");

            query.setString(1, nomeLab);

            ResultSet rs = query.executeQuery();

            while (rs.next())
                listaAfferenti.add(rs.getString(1));

            connection.close();
        } catch (SQLException e) {
            System.out.println("Errore nella lettura di dati dal database.");
        }
    }
}
