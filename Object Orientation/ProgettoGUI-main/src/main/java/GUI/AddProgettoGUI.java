package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Objects;

public class AddProgettoGUI {
    private JPanel addProgMainPanel;
    private JPanel insPanel;
    private JTextField cupTextField;
    private JLabel cupLabel;
    private JLabel refSciLabel;
    private JComboBox seniorComboBox;
    private JPanel buttonsPanel;
    private JButton cancelBtn;
    private JButton okBtn;
    private JLabel nomeLabel;
    private JTextField nomeTextField;
    private JLabel respLabel;
    private JComboBox dirComboBox;
    private JFrame frame;

    public AddProgettoGUI(@NotNull Controller controller) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Progetti");
        frame.setContentPane(addProgMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setResizable(false);
        frame.setSize(new Dimension(500,280));
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA LISTA DEGLI IMPIEGATI SENIOR

        ArrayList<String> listaSenior = controller.getListaSenior();

        for (String s : listaSenior)
            seniorComboBox.addItem(s);

        // POPOLO LA LISTA DEGLI IMPIEGATI DIRIGENTI

        ArrayList<String> listaDirigenti = controller.getListaDirigenti();

        for (String s : listaDirigenti)
            dirComboBox.addItem(s);

        // SETTO TUTTI GLI ACTION LISTENER PER I PULSANTI

        okBtn.addActionListener(e -> {
            int risposta = JOptionPane.showConfirmDialog(null, "Vuoi aggiungere questo Progetto?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (risposta == JOptionPane.YES_OPTION) {
                String cupInserito = cupTextField.getText();
                String nomeInserito = nomeTextField.getText();
                String refSciInserito = Objects.requireNonNull(seniorComboBox.getSelectedItem()).toString();
                String respInserito = Objects.requireNonNull(dirComboBox.getSelectedItem()).toString();

                try {
                    controller.aggiungiProgetto(cupInserito, nomeInserito, refSciInserito, respInserito);
                    JOptionPane.showMessageDialog(null, "Progetto inserito con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        cancelBtn.addActionListener(e -> frame.dispose());
    }
}
