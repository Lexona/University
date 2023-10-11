import java.util.ArrayList;

public class Corso {
    private String nome;
    private Docente docente;
    private ArrayList<Studente> listaIscritti;

    //costruttore del corso
    public Corso (String n, Docente d) {
        nome = n;
        docente = d;
        listaIscritti = new ArrayList<>();
    }

    //funzione di inserimento studenti al corso
    public void addStudente (Studente s) {
        listaIscritti.add(s);
    }

    public String visualizzaCorso () {
        return nome;
    }

    public void printStudents () {
        for (Studente s : listaIscritti)
            System.out.println(s.getLogin());
    }
}
