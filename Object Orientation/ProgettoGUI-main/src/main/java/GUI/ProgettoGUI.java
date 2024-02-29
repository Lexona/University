package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.sql.SQLException;
import java.util.ArrayList;

public class ProgettoGUI {
    private JPanel progMainPanel;
    private JPanel buttonsPanel;
    private JPanel tablePanel;
    private JButton homeBtn;
    private JButton addBtn;
    private JButton removeBtn;
    private JButton acquistaButton;
    private JScrollPane tableScrollPane;
    private JTable progTable;
    private JButton sostBtn;
    private JFrame frame;

    public ProgettoGUI(@NotNull Controller controller, JFrame frameChiamante) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Progetti");
        frame.setContentPane(progMainPanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1200, 700);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA TABELLA DEI PROGETTI

        String[] colonne = {"CUP", "Nome", "Referente Scientifico", "Responsabile", "Budget"};

        ArrayList<String> listaCup = controller.getCupProgetti();
        ArrayList<String> listaNomi = controller.getListaNomiProgetti();
        ArrayList<String> listaRefSci = controller.getListaRefSci();
        ArrayList<String> listaResp = controller.getListaResponsabili();
        ArrayList<Float> listaBudget = controller.getListaBudget();

        Object[][] righe = new Object[listaCup.size()][5];

        for (int i = 0; i < listaCup.size(); i++) {
            righe[i][0] = listaCup.get(i);
            righe[i][1] = listaNomi.get(i);
            righe[i][2] = listaRefSci.get(i);
            righe[i][3] = listaResp.get(i);
            righe[i][4] = listaBudget.get(i) + "€";
        }

        DefaultTableModel tableModel = new DefaultTableModel(righe, colonne) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };

        progTable.setFont(new Font("JetBrains Mono", Font.PLAIN, 16)); //setta il font delle celle della tabella
        progTable.setModel(tableModel);
        progTable.setRowHeight(30);
        progTable.setPreferredScrollableViewportSize(new Dimension(950, 700));

        progTable.getTableHeader().setReorderingAllowed(false); //fa in modo che le colonne non si spostino
        progTable.getTableHeader().setResizingAllowed(false); //fa in modo che la dimensione delle colenne non sia personalizzabile dall'utente

        resizeWidthTable(progTable); //serve per settare la larghezza delle colonne

        Font headerFont = new Font("JetBrains Mono", Font.BOLD, 16);
        progTable.getTableHeader().setFont(headerFont);

        // SETTO TUTTI GLI ACTION LISTENER PER I PULSANTI

        homeBtn.addActionListener(e -> {
            frame.dispose();
            frameChiamante.setVisible(true);
        });

        addBtn.addActionListener(e -> {
            new AddProgettoGUI(controller);
            loadTable(controller, colonne);
            resizeWidthTable(progTable);
        });

        removeBtn.addActionListener(e -> {
            String cupSelezionato = progTable.getValueAt(progTable.getSelectedRow(), 0).toString();

            int selezione = JOptionPane.showConfirmDialog(null, "Sicuro di voler eliminare il Progetto?", "Conferma", JOptionPane.YES_NO_OPTION);
            if (selezione == JOptionPane.YES_OPTION) {
                try {
                    controller.rimuoviProgetto(cupSelezionato);
                    JOptionPane.showMessageDialog(null, "Eliminazione avvenuta con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    loadTable(controller, colonne);
                    resizeWidthTable(progTable);
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        sostBtn.addActionListener(e -> {
            String[] scelte = {"Responsabile", "Referente Scientifico", "Annulla"};
            int risposta = JOptionPane.showOptionDialog(null, "Vuoi sostituire il Responsabile o il Referente Scientifico?", "Scelta", JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, scelte, null);

            SostituisciGUI sostituisciGUI = null;

            if (risposta == 0) {
                ArrayList<String> listaDirigenti = controller.getListaDirigenti();
                String cfSelezionato = progTable.getValueAt(progTable.getSelectedRow(), 3).toString();

                sostituisciGUI = new SostituisciGUI(controller, listaDirigenti, cfSelezionato);
            } else if (risposta == 1){
                ArrayList<String> listaSenior = controller.getListaSenior();
                String cfSelezionato = progTable.getValueAt(progTable.getSelectedRow(), 2).toString();

                sostituisciGUI = new SostituisciGUI(controller, listaSenior, cfSelezionato);
            }

            sostituisciGUI.frame.addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosed(WindowEvent e) {
                    loadTable(controller, colonne);
                    resizeWidthTable(progTable);
                }
            });
        });
    }

    private void loadTable(@NotNull Controller controller, @NotNull String[] colonne) {
        ArrayList<String> listaCup = controller.getCupProgetti();
        ArrayList<String> listaNomi = controller.getListaNomiProgetti();
        ArrayList<String> listaRefSci = controller.getListaRefSci();
        ArrayList<String> listaResp = controller.getListaResponsabili();
        ArrayList<Float> listaBudget = controller.getListaBudget();

        Object[][] righe = new Object[listaCup.size()][5];

        for (int i = 0; i < listaCup.size(); i++) {
            righe[i][0] = listaCup.get(i);
            righe[i][1] = listaNomi.get(i);
            righe[i][2] = listaRefSci.get(i);
            righe[i][3] = listaResp.get(i);
            righe[i][4] = listaBudget.get(i) + "€";
        }

        DefaultTableModel dtm = (DefaultTableModel) progTable.getModel();
        dtm.setDataVector(righe, colonne);
    }

    private void resizeWidthTable(JTable table) {
        table.getColumnModel().getColumn(0).setPreferredWidth(200);
        table.getColumnModel().getColumn(1).setPreferredWidth(200);
        table.getColumnModel().getColumn(2).setPreferredWidth(200);
        table.getColumnModel().getColumn(3).setPreferredWidth(200);
        table.getColumnModel().getColumn(4).setPreferredWidth(200);

        table.getColumnModel().getColumn(0).setMinWidth(200);
        table.getColumnModel().getColumn(1).setMinWidth(200);
        table.getColumnModel().getColumn(2).setMinWidth(200);
        table.getColumnModel().getColumn(3).setMinWidth(200);
        table.getColumnModel().getColumn(4).setMinWidth(200);

        table.getColumnModel().getColumn(0).setMaxWidth(200);
        table.getColumnModel().getColumn(1).setMaxWidth(200);
        table.getColumnModel().getColumn(2).setMaxWidth(200);
        table.getColumnModel().getColumn(3).setMaxWidth(200);
        table.getColumnModel().getColumn(4).setMaxWidth(200);
    }
}
