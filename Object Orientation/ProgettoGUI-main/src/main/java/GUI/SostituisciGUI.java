package GUI;

import Controller.Controller;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;

public class SostituisciGUI {
    private JPanel sostMainPanel;
    private JLabel titleLabel;
    private JScrollPane listScrollPanel;
    private JList impList;
    private JPanel buttonsPanel;
    private JButton cancelBtn;
    private JButton okBtn;
    JFrame frame;
    public SostituisciGUI(Controller controller, ArrayList<String> listaImpiegati, String vecchioCF) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Lista Afferenti");
        frame.setContentPane(sostMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(320,350));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA LISTA DEGLI AFFERENTI

        impList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) impList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        impList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) impList.getModel();

        for (String s : listaImpiegati)
            dfl.addElement(s);

        // IMPOSTO TUTTI GLI ACTION LISTENER

        cancelBtn.addActionListener(e -> frame.dispose());

        okBtn.addActionListener(e -> {
            int risultato = JOptionPane.showConfirmDialog(null, "Confermi la selezione?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (risultato == JOptionPane.YES_NO_OPTION) {
                String nuovoCF = impList.getSelectedValue().toString();

                try {
                    controller.sostituisciImpiegato(vecchioCF, nuovoCF);
                    JOptionPane.showMessageDialog(null, "Sostituzione avvenuta con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }
}
