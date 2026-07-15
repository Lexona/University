package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;

public class AddAfferenteGUI {
    private JPanel addAfferenteMainPanel;
    private JPanel listPanel;
    private JPanel buttonsPanel;
    private JLabel titleLabel;
    private JScrollPane listScrollPane;
    private JButton cancelBtn;
    private JButton okBtn;
    private JTable impTable;
    JFrame frame;

    public AddAfferenteGUI(@NotNull Controller controller, String laboratorioSelezionato) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Lista Impiegati");
        frame.setContentPane(addAfferenteMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(700,600));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA TABELLA CHE CONTIENE GLI IMPIEGATI CHE POSSONO ESSERE ASSOCIATI AL LABORATORIO

        ArrayList<String> listaCF = controller.getListaCF();
        ArrayList<String> listaNomi = controller.getListaNomi();
        ArrayList<String> listaCognomi = controller.getListaCognomi();

        String[] colonne = {"CF", "Nome", "Cognome"};
        String[][] righe = new String[listaCF.size()][3];

        for (int i = 0; i < listaCF.size(); i++) {
            righe[i][0] = listaCF.get(i);
            righe[i][1] = listaNomi.get(i);
            righe[i][2] = listaCognomi.get(i);
        }

        // RENDO I CAMPI DELLA TABELLA NON EDITABILI

        DefaultTableModel tableModel = new DefaultTableModel(righe, colonne) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };

        impTable.setFont(new Font("JetBrains Mono", Font.PLAIN, 16)); //setta il font delle celle della tabella
        impTable.setRowHeight(30);
        impTable.setModel(tableModel);

        impTable.getTableHeader().setReorderingAllowed(false); //fa in modo che le colonne non si spostino
        impTable.getTableHeader().setResizingAllowed(false); //fa in modo che la dimensione delle colenne non sia personalizzabile dall'utente

        Font headerFont = new Font("JetBrains Mono", Font.BOLD, 16);
        impTable.getTableHeader().setFont(headerFont);

        // SETTO TUTTI GLI ACTION LISTENER PER I PULSANTI

        cancelBtn.addActionListener(e -> frame.dispose());

        okBtn.addActionListener(e -> {
            int risposta = JOptionPane.showConfirmDialog(null, "Confermi di voler assumere questo impiegato?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (risposta == JOptionPane.YES_OPTION) {
                String cfSelezionato = impTable.getValueAt(impTable.getSelectedRow(), 0).toString();

                try {
                    controller.aggiungiAfferente(cfSelezionato, laboratorioSelezionato);
                    JOptionPane.showMessageDialog(null, "Associazione avvenuta con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }
}
