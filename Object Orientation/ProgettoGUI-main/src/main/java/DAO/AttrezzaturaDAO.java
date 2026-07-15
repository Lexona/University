package DAO;

import java.sql.SQLException;

public interface AttrezzaturaDAO {
    /**
     * Permette di aggiungere un'attrezzatura al database
     *
     * @param seriale Seriale dell'attrezzatura
     * @param tipo    Tipologia dell'attrezzatura
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void aggiungiAttrezzatura(String seriale, String tipo) throws SQLException;

    /**
     * Permette di eliminare un'attrezzatura dal database
     *
     * @param seriale Seriale dell'attrezzatura
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void eliminaAttrezzatura(String seriale) throws SQLException;
}
