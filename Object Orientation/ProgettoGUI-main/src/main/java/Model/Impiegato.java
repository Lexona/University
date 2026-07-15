package Model;

import java.sql.Date;
import java.util.ArrayList;

public class Impiegato {
    private String cf;
    private String nome;
    private String cognome;
    private Date dataNascita;
    private Date dataAssunzione;
    private int eta;
    private String categoria;
    private float salario;
    private Date dataScadenza;
    private String tipoContratto;

    private ArrayList<Promozione> listaPromozioni = new ArrayList<>();
    private ArrayList<String> listaLaboratori = new ArrayList<>();

    public Impiegato(String cf, String nome, String cognome, Date dataNascita, Date dataAssunzione, int eta, String categoria, float salario, Date dataScadenza, String tipoContratto) {
        this.cf = cf;
        this.nome = nome;
        this.cognome = cognome;
        this.dataNascita = dataNascita;
        this.dataAssunzione = dataAssunzione;
        this.eta = eta;
        this.categoria = categoria;
        this.salario = salario;
        this.dataScadenza = dataScadenza;
        this.tipoContratto = tipoContratto;
    }

    public void addPromozione(Promozione p){
        listaPromozioni.add(p);
    }

    public void addLaboratorio(String l){
        listaLaboratori.add(l);
    }

    public void removePromozione(Promozione p){
        listaPromozioni.remove(p);
    }

    public void removeLaboratorio(String l){
        listaLaboratori.remove(l);
    }

    public String getCf() {
        return cf;
    }

    public void setCf(String cf) {
        this.cf = cf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public Date getDataNascita() {
        return dataNascita;
    }

    public void setDataNascita(Date dataNascita) {
        this.dataNascita = dataNascita;
    }

    public Date getDataAssunzione() {
        return dataAssunzione;
    }

    public void setDataAssunzione(Date dataAssunzione) {
        this.dataAssunzione = dataAssunzione;
    }

    public int getEta() {
        return eta;
    }

    public void setEta(int eta) {
        this.eta = eta;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public Date getDataScadenza() {
        return dataScadenza;
    }

    public void setDataScadenza(Date dataScadenza) {
        this.dataScadenza = dataScadenza;
    }

    public String getTipoContratto() {
        return tipoContratto;
    }

    public void setTipoContratto(String tipoContratto) {
        this.tipoContratto = tipoContratto;
    }

    public ArrayList<Promozione> getListaPromozioni() {
        return listaPromozioni;
    }

    public void setListaPromozioni(ArrayList<Promozione> listaPromozioni) {
        this.listaPromozioni = listaPromozioni;
    }

    public ArrayList<String> getListaLaboratori() {
        return listaLaboratori;
    }

    public void setListaLaboratori(ArrayList<String> listaLaboratori) {
        this.listaLaboratori = listaLaboratori;
    }
}
