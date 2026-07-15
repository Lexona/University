package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Objects;

public class AddLaboratorioGUI {
    private JPanel addLabMainPanel;
    private JPanel insPanel;
    private JTextField nomeTextField;
    private JLabel nomeLabel;
    private JLabel respSciLabel;
    private JTextField topicTextField;
    private JLabel topicLabel;
    private JPanel buttonsPanel;
    private JButton cancelBtn;
    private JButton okBtn;
    private JComboBox seniorComboBox;
    private JComboBox cupComboBox;
    protected JFrame frame;

    public AddLaboratorioGUI(@NotNull Controller controller) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Aggiungi Laboratorio");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setContentPane(addLabMainPanel);
        frame.setResizable(false);
        frame.setSize(new Dimension(500,280));
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA L'ELENCO A SCORRIMENTO DEGLI IMPIEGATI SENIOR

        ArrayList<String> listaSenior = controller.getListaSenior();

        for (String s : listaSenior)
            seniorComboBox.addItem(s);

        // SETTO TUTTI GLI ACTION LISTENER PER I PULSANTI

        okBtn.addActionListener(e -> {
            int risposta = JOptionPane.showConfirmDialog(null, "Vuoi aggiungere questo Laboratorio?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (risposta == JOptionPane.YES_OPTION) {
                String nome = nomeTextField.getText();
                String respSci = Objects.requireNonNull(seniorComboBox.getSelectedItem()).toString();
                String topic = topicTextField.getText();

                try {
                    controller.aggiungiLaboratorio(nome, respSci, topic);
                    JOptionPane.showMessageDialog(null, "Laboratorio inserito con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        cancelBtn.addActionListener(e -> frame.dispose());
    }
}
