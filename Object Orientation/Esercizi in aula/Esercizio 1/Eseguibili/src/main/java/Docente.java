import java.util.Scanner;

public class Docente extends Utente{
    public Docente(String l, String p) {
        super(l, p);
    }

    public Corso creaCorso (Docente d) {
        String nomeCorso;
        System.out.println("Inserisci nome corso: ");
        Scanner obj = new Scanner(System.in);
        nomeCorso = obj.nextLine();

        Corso corso = new Corso(nomeCorso, d);
        return corso;
    }



}
