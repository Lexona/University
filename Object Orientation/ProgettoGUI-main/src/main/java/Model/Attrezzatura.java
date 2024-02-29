package Model;

public class Attrezzatura {
    private String seriale;
    private String tipo;
    private float costo;
    private String nomeLab;
    private String cup;

    public Attrezzatura(String seriale, String tipo, float costo, String nomeLab, String cup) {
        this.seriale = seriale;
        this.tipo = tipo;
        this.costo = costo;
        this.nomeLab = nomeLab;
        this.cup = cup;
    }

    public String getSeriale() {
        return seriale;
    }

    public void setSeriale(String seriale) {
        this.seriale = seriale;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public float getCosto() {
        return costo;
    }

    public void setCosto(float costo) {
        this.costo = costo;
    }

    public String getNomeLab() {
        return nomeLab;
    }

    public void setNomeLab(String nomeLab) {
        this.nomeLab = nomeLab;
    }

    public String getCup() {
        return cup;
    }

    public void setCup(String cup) {
        this.cup = cup;
    }
}
