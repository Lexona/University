import java.util.ArrayList;

public class Studente extends Utente{

    private String matricola;
    private ArrayList<Corso> corsiSeguiti;
    public Studente(String l, String p, String m) {
        super(l, p);
        matricola = m;
        corsiSeguiti = new ArrayList<>();
    }

    public void iscrivi (Corso c, Studente s) {
        corsiSeguiti.add(c);
        c.addStudente(s);
    }

    public void elencoCorsiIscritto () {
        for (Corso c : corsiSeguiti) {
            System.out.println(c.visualizzaCorso());
        }
    }

    public String getLogin () {
        return login;
    }
}
