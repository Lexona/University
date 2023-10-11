import java.util.ArrayList;

public class CorsoDiLaurea {
    private String nome;
    private ArrayList<Corso> elencoCorsi;
    public CorsoDiLaurea (String n) {
        nome = n;
        elencoCorsi = new ArrayList<>();
    }

    public void addCorso (Corso c) {
        elencoCorsi.add(c);
    }
}
