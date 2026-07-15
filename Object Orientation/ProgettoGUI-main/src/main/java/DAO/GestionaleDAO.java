package DAO;

import java.sql.Date;
import java.util.ArrayList;

public interface GestionaleDAO {
    /**
     * Ottiene i dati di tutti gli Impiegati dal Database e li inserisce nelle ArrayList apposite
     *
     * @param listaCF             Lista dei Codici Fiscali
     * @param listaNomi           Lista dei Nomi
     * @param listaCognomi        Lista dei Cognomi
     * @param listaDateNascita    Lista delle Date di Nascita
     * @param listaDateAssunzione Lista delle Date di Assunzione
     * @param listaEta            Lista dei Età
     * @param listaCategorie      Lista delle Categorie ('junior', 'middle', 'senior', 'dirigente')
     * @param listaSalari         Lista dei Salari
     * @param listaDateScadenza   Lista delle Date di Scadenza del contratto a Progetto
     * @param listaTipiContratto  Lista dei Tipi di Contratto ('indeterminato', 'progetto')
     */
    void getImpiegati(
            ArrayList<String> listaCF,
            ArrayList<String> listaNomi,
            ArrayList<String> listaCognomi,
            ArrayList<Date> listaDateNascita,
            ArrayList<Date> listaDateAssunzione,
            ArrayList<Integer> listaEta,
            ArrayList<String> listaCategorie,
            ArrayList<Float> listaSalari,
            ArrayList<Date> listaDateScadenza,
            ArrayList<String> listaTipiContratto
    );

    /**
     * Ottiene i dati di tutti i Laboratori dal Database e li inserisce nelle ArrayList apposite
     *
     * @param listaNomi       Lista dei Nomi
     * @param listaRespSci    Lista dei Responsabili Scientifici (la categoria dell'impiegato deve essere 'senior')
     * @param listaTopic      Lista dei Topic
     * @param listaNAfferenti Lista della quantità di afferenti per singolo Laboratorio
     */
    void getLaboratori(
            ArrayList<String> listaNomi,
            ArrayList<String> listaRespSci,
            ArrayList<String> listaTopic,
            ArrayList<Integer> listaNAfferenti,
            ArrayList<String> listaProgetti
    );

    /**
     * Ottiene i dati di tutte le Attrezzature dal Database e li inserisce nelle ArrayList apposite
     *
     * @param listaSeriali Lista dei Seriali
     * @param listaTipi    Lista dei Tipi (macro categoria della singola Attrezzatura: 'computer', 'tablet', etc.)
     * @param listaCosti   Lista dei Costi
     * @param listaNomiLab Lista dei Laboratori che possiedono l'Attrezzatura
     * @param listaCup     Lista dei Progetti che acquistano l'Attrezzatura
     */
    void getAttrezzature(
            ArrayList<String> listaSeriali,
            ArrayList<String> listaTipi,
            ArrayList<Float> listaCosti,
            ArrayList<String> listaNomiLab,
            ArrayList<String> listaCup
    );

    /**
     * Ottiene i dati di tutti i Progetti dal Database e li inserisce nelle ArrayList apposite
     *
     * @param listaCup    Lista dei CUP (Codice Unico Progetto)
     * @param listaRefSci Lista dei Referenti Scientifici (la categoria dell'impiegato deve essere 'senior')
     * @param listaResp   Lista dei Responsabili (la categoria dell'impiegato deve essere 'dirigente')
     * @param listaNomi   Lista dei Nomi
     * @param listaBudget Lista dei Budget
     */
    void getProgetti(
            ArrayList<String> listaCup,
            ArrayList<String> listaRefSci,
            ArrayList<String> listaResp,
            ArrayList<String> listaNomi,
            ArrayList<Float> listaBudget
    );

    /**
     * Ottiene i dati di tutte le Promozioni dal Database e li inserisce nelleArrayList apposite
     *
     * @param listaCF                 Lista dei Codici Fiscali
     * @param listaDatePassaggio      Lista delle Date di Passaggio
     * @param listaVecchieCategorie   Lista delle Vecchie Categorie
     * @param listaNuoveCategorie     Lista delle Nuove Categorie
     * @param listaPromotoriDirigenti Lista dei vari Promotori Dirigente
     */
    void getPromozioni(
            ArrayList<String> listaCF,
            ArrayList<Date> listaDatePassaggio,
            ArrayList<String> listaVecchieCategorie,
            ArrayList<String> listaNuoveCategorie,
            ArrayList<String> listaPromotoriDirigenti
    );

    /**
     * Ottiene la lista degli afferenti per un Progetto
     *
     * @param nomeLab        Nome del Laboratorio da elaborare
     * @param listaAfferenti Lista degli Afferenti
     */
    void getListaAfferenti(
            String nomeLab,
            ArrayList<String> listaAfferenti
    );
}
