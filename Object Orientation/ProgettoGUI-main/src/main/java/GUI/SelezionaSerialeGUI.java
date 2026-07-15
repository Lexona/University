package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.util.ArrayList;

public class SelezionaSerialeGUI {
    private JPanel serialeMainPanel;
    private JPanel listPanel;
    private JLabel serialeLabel;
    private JScrollPane serialeScrollPane;
    private JList serialeList;
    private JPanel buttonsPanel;
    private JButton cancelBtn;
    private JButton okBtn;
    private JFrame frame;

    public SelezionaSerialeGUI(@NotNull Controller controller, String labSelezionato) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Seleziona Seriale");
        frame.setContentPane(serialeMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(300,350));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA LISTA DEI SERIALI SELEZIONABILI

        serialeList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) serialeList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        ArrayList<String> listaSeriali = controller.getSerialiAttrezzature();

        serialeList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) serialeList.getModel();

        for (String s : listaSeriali)
            dfl.addElement(s);

        // IMPOSTO TUTTI GLI ACTION LISTENER

        cancelBtn.addActionListener(e -> frame.dispose());

        okBtn.addActionListener(e -> {
            int selezione = JOptionPane.showConfirmDialog(null, "Sicuro di voler acquistare questa Attrezzatura?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (selezione == JOptionPane.YES_OPTION) {
                String serialeSelezionato = serialeList.getSelectedValue().toString();

                try {
                    controller.acquistaAttrezzatura(serialeSelezionato, labSelezionato);
                    JOptionPane.showMessageDialog(null, "Acquisto avvenuto con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }
}
