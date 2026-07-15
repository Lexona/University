package GUI;

import Controller.Controller;

import javax.swing.*;

public class Home {
    private JPanel mainPanel;
    private JButton impiegatiBtn;
    private JButton laboratoriBtn;
    private JButton attrezzatureBtn;
    private JButton progettiBtn;
    private JLabel titleLabel;
    private JPanel titlePanel;
    private JPanel buttonsPPanel;

    public Home(){
        // INSTANZIO IL CONTROLLER

        Controller controller = new Controller();

        // IMPOSTO IL FRAME

        JFrame frame = new JFrame("Home");
        frame.setSize(800,500);
        frame.setLocationRelativeTo(null);
        frame.setContentPane(mainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        // IMPOSTO TUTTI GLI ACTION LISTENER

        impiegatiBtn.addActionListener(e -> {
            frame.setVisible(false);
            new ImpiegatoGUI(controller, frame);
        });

        laboratoriBtn.addActionListener(e -> {
            frame.setVisible(false);
            new LaboratorioGUI(controller, frame);
        });

        progettiBtn.addActionListener(e -> {
            frame.setVisible(false);
            new ProgettoGUI(controller, frame);
        });

        attrezzatureBtn.addActionListener(e -> {
            frame.setVisible(false);
            new AttrezzaturaGUI(controller, frame);
        });
    }
}
