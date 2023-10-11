public class Main {
    public static void main (String[] args) {
        System.out.println("----Controllo Utente----");
        Utente u = new Utente("Marta", "1234");
        u.autenticate("Marta", "1234");

        Docente d = new Docente("Cazzi", "Culo");

        Corso c = d.creaCorso(d);
        System.out.println(c.visualizzaCorso());
        CorsoDiLaurea cdl = new CorsoDiLaurea("Informatica");
        cdl.addCorso(c);

        Studente s = new Studente("Marta", "lexa", "1234");
        s.iscrivi(c, s);
        s.iscrivi(c, s);

        s.elencoCorsiIscritto();
        c.printStudents();

    }
}
