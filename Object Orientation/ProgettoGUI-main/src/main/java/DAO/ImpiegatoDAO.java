package DAO;

import java.sql.Date;
import java.sql.SQLException;
import java.util.ArrayList;

public interface ImpiegatoDAO {
    /**
     * Permette di inserire un impiegato a tempo indeterminato nel database
     *
     * @param cf             Codice Fiscale dell'impiegato
     * @param nome           Nome dell'impiegato
     * @param cognome        Cognome dell'impiegato
     * @param dataNascita    Data di Nascita dell'impiegato
     * @param dataAssunzione Data di Assunzione dell'impiegato
     * @param categoria      Categoria del contratto dell'impiegato
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void assumiImpiegato(String cf, String nome, String cognome, Date dataNascita, Date dataAssunzione, String categoria) throws SQLException;

    /**
     * Permette di inserire un impiegato con contratto a progetto nel database
     *
     * @param cf             Codice Fiscale dell'impiegato
     * @param nome           Nome dell'impiegato
     * @param cognome        Cognome dell'impiegato
     * @param dataNascita    Data di Nascita dell'impiegato
     * @param dataAssunzione Data di Assunzione dell'impiegato
     * @param dataScadenza   Data di Scadenza del contratto
     * @param cup            Codice Identificativo del Progetto
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void assumiImpiegatoProgetto(String cf, String nome, String cognome, Date dataNascita, Date dataAssunzione, Date dataScadenza, String cup) throws SQLException;

    /**
     * Permette di eliminare un impiegato dal database
     *
     * @param cf Codice Fiscale dell'impiegato da licenziare
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void licenziaImpiegato(String cf) throws SQLException;

    /**
     * Permette di sostituire un Responsabile Scientifico/Referente Scientifico/Responsabile
     *
     * @param vecchioCF Codice Fiscale dell'impiegato da sostituire
     * @param nuovoCF   Codice Fiscale dell'impiegato che sostituisce
     * @return Restituisce il successo o il fallimento dell'operazione
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    boolean sostituisciImpiegato(String vecchioCF, String nuovoCF) throws SQLException;

    /**
     * Permette di promuovere alla categoria successiva un impiegato
     *
     * @param cf                 Codice Fiscale dell'impiegato da promuovere
     * @param promotoreDirigente Dirigente che raccomanda un impiegato per essere Dirigente
     * @throws SQLException Lancia un'eccezione se fallisce l'operazione sul database
     */
    void promuoviImpiegato(String cf, String promotoreDirigente) throws SQLException;

    /**
     * Permette di ottenere i progetti a cui lavora l'impiegato
     *
     * @param cf              Codice Fiscale dell'impiegato da elaborare
     * @param listaLaboratori Lista dei Laboratori ai quali lavora l'impiegato
     * @return Restituisce il successo o il fallimento dell'operazione
     */
    boolean getAfferenze(String cf, ArrayList<String> listaLaboratori);
}
