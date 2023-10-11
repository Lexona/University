public class Utente {
    protected String login;
    private String password;

    //costruttore
    public Utente (String l, String p) {
        login = l;
        password = p;
    }

    //metodo di autenticazione
    public boolean autenticate (String l, String p) {
        if (l.equals(login) && p.equals(password)) {
            System.out.println("Tutto ok");
            return true;
        } else {
            System.out.println("Autenticazione fallita");
            return false;
        }
    }
}
