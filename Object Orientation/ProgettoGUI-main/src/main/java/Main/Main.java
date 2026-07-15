package Main;

import GUI.Home;
import com.formdev.flatlaf.IntelliJTheme;

public class Main {
    public static void main (String[] args) {
        IntelliJTheme.setup(Main.class.getResourceAsStream("/DarkPurple.theme.json"));

        new Home();
    }
}
