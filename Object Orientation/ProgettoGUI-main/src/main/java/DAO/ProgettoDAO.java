package DAO;

import java.sql.SQLException;

public interface ProgettoDAO {
    /**
     * Aggiunge un progetto al database
     *
     * @param cup     Codice Identificativo del Progetto
     * @param ref_sci Referente Scientifico che si occupa del progetto
     * @param resp    Responsabile che coordina il progetto
     * @param nome    Nome del progetto
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void aggiungiProgetto(String cup, String ref_sci, String resp, String nome) throws SQLException;

    /**
     * Collega un laboratorio al progetto
     *
     * @param nomeLab Laboratorio da collegare
     * @param cup     Codice Identificativo del Progetto da collegare
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void collegaLaboratorio(String nomeLab, String cup) throws SQLException;

    /**
     * Elimina un progetto dal database
     *
     * @param cup CUP del Progetto da eliminare
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void eliminaProgetto(String cup) throws SQLException;
}
