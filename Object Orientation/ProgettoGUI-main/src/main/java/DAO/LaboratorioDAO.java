package DAO;

import java.sql.SQLException;

public interface LaboratorioDAO {
    /**
     * Aggiunge un laboratorio al database
     *
     * @param nome     Nome del Laboratorio
     * @param resp_sci Responsabile Scientifico che si occupa del laboratorio
     * @param topic    Topic del laboratorio
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void aggiungiLaboratorio(String nome, String resp_sci, String topic) throws SQLException;

    /**
     * Aggiunge un afferente al laboratorio
     *
     * @param cf      Codice Fiscale dell'impiegato che deve lavorare nel Laboratorio
     * @param nomeLab Laboratorio al quale viene aggiunto un afferente
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void aggiungiAfferente(String cf, String nomeLab) throws SQLException;

    /**
     * Acquista un attrezzatura e la collega al laboratorio
     *
     * @param seriale Seriale dell'attrezzatura da acquistare
     * @param nomeLab Laboratorio che utilizza l'attrezzatura
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void acquistaAttrezzatura(String seriale, String nomeLab) throws SQLException;

    /**
     * Elimina un laboratorio dal database
     *
     * @param nomeLab Nome del laboratorio da eliminare
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void rimuoviLaboratorio(String nomeLab) throws SQLException;
}
