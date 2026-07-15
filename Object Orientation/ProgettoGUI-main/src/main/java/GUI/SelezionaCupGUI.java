package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.sql.SQLException;
import java.util.ArrayList;

public class SelezionaCupGUI {
    private JPanel selCupMainPanel;
    private JPanel listPanel;
    private JPanel buttonsPanel;
    private JLabel cupLabel;
    private JScrollPane cupScrollPane;
    private JList cupList;
    private JButton annullaButton;
    private JButton okButton;
    protected JFrame frame;

    public SelezionaCupGUI(@NotNull Controller controller, String labSelezionato) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Seleziona CUP");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setContentPane(selCupMainPanel);
        frame.setResizable(false);
        frame.setSize(new Dimension(300,350));
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // IMPOSTO LA LISTA DEI CUP E LA POPOLO

        cupList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) cupList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        ArrayList<String> listaCupProgetti = controller.getCupProgetti();

        cupList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) cupList.getModel();

        for (String s : listaCupProgetti)
            dfl.addElement(s);

        // IMPOSTO TUTTI GLI ACTION LISTENER

        okButton.addActionListener(e -> {
            String cupSelezionato = cupList.getSelectedValue().toString();

            try {
                controller.associaProgettoLaboratorio(cupSelezionato, labSelezionato);
                JOptionPane.showMessageDialog(null, "Associazione avvenuta con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                frame.dispose();
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
            }
        });

        annullaButton.addActionListener(e -> frame.dispose());
    }
}
