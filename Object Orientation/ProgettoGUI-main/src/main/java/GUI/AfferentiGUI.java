package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class AfferentiGUI {
    private JPanel affMainPanel;
    private JLabel titleLabel;
    private JList afferentiList;
    private JScrollPane listScrollPanel;
    private JFrame frame;

    public AfferentiGUI (@NotNull Controller controller, String nomeLab) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Lista Afferenti");
        frame.setContentPane(affMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(320,350));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // POPOLO LA LISTA DEGLI AFFERENTI

        afferentiList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) afferentiList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        afferentiList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) afferentiList.getModel();

        ArrayList<String> listaAfferenti;

        listaAfferenti = controller.getListaAfferentiLaboratorio(nomeLab);

        for (String s : listaAfferenti)
            dfl.addElement(s);
    }
}
