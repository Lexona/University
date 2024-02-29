package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;

public class PromuoviGUI {
    private JPanel promMainPanel;
    private JPanel listPanel;
    private JPanel buttonsPanel;
    private JLabel titleLabel;
    private JList dirList;
    private JScrollPane listScrollPane;
    private JButton cancelBtn;
    private JButton okBtn;
    private JFrame frame;

    public PromuoviGUI(@NotNull Controller controller, String cfSelezionato) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Promuovi Senior");
        frame.setContentPane(promMainPanel);
        frame.setSize(new Dimension(300,350));
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // IMPOSTO IL MODEL DELLA LISTA

        dirList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) dirList.getModel();

        dirList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) dirList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        // POPOLO LA LISTA CON TUTTI I DIRIGENTI

        ArrayList<String> listaDirigenti = controller.getListaDirigenti();

        for (String s : listaDirigenti)
            dfl.addElement(s);

        // IMPOSTO TUTTI GLI ACTION LISTENER

        okBtn.addActionListener(e -> {
            String dirSelezionato = dirList.getSelectedValue().toString();
            try {
                controller.promuovi(cfSelezionato, dirSelezionato);
                JOptionPane.showMessageDialog(null, "Promozione avvenuta con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                frame.dispose();
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
            }
        });

        cancelBtn.addActionListener(e -> frame.dispose());
    }
}
