package GUI;

import Controller.Controller;
import Model.Impiegato;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class ProfiloImpiegatoGUI {

    private JPanel profiloMainPanel;
    private JPanel infContrPanel;
    private JPanel infCarPanel;
    private JPanel infPersPanel;
    private JPanel datiPanel;
    private JLabel nomeLabel;
    private JLabel cognomeLabel;
    private JLabel dataNascLabel;
    private JLabel etaLabel;
    private JLabel infCarLabel;
    private JLabel intContrlabel;
    private JLabel intPersLabel;
    private JList labList;
    private JScrollPane tableScrollPne;
    private JTable promTable;
    private JLabel dataAssLabel;
    private JLabel cateLabel;
    private JLabel salarioLabel;
    private JLabel contrattoLabel;
    private JLabel dataScadLabel;
    private JLabel labLabel;
    private JPanel infContrDatiPanel;
    private JLabel imgLabel;
    private JFrame frame;

    public ProfiloImpiegatoGUI(@NotNull Controller controller, String cfChiamante) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Profilo Utente");
        frame.setSize(1000, 800);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setContentPane(profiloMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setVisible(true);

        // IMPOSTO IL MODEL DELLA LISTA

        labList.setModel(new DefaultListModel());
        DefaultListModel dfl = (DefaultListModel) labList.getModel();

        // POPOLO LA TABELA CON I DATI DELLE VARIE PROMOZIONI

        DefaultListCellRenderer renderer =
                (DefaultListCellRenderer) labList.getCellRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        Impiegato i = controller.getDatiProfilo(cfChiamante);

        String[] colonne = {"Data di Passaggio", "Vecchia Categoria", "Nuova Categoria", "Promotore Dirigente"};

        Object[][] righe = new Object[i.getListaPromozioni().size()][4];

        for (int j = 0; j < i.getListaPromozioni().size(); j++) {
            righe[j][0] = i.getListaPromozioni().get(j).getDataPassaggio();
            righe[j][1] = i.getListaPromozioni().get(j).getVecchiaCategoria();
            righe[j][2] = i.getListaPromozioni().get(j).getNuovaCategoria();
            righe[j][3] = i.getListaPromozioni().get(j).getPromotoreDirigente();
        }

        promTable.setModel(new DefaultTableModel(righe, colonne));
        promTable.setRowHeight(30);
        promTable.setEnabled(false);

        promTable.setFont(new Font("JetBrains Mono", Font.PLAIN, 16)); //setta il font delle celle della tabella
        Font headerFont = new Font("JetBrains Mono", Font.BOLD, 16);
        promTable.getTableHeader().setFont(headerFont);

        promTable.getTableHeader().setReorderingAllowed(false); //fa in modo che le colonne non si spostino
        promTable.getTableHeader().setResizingAllowed(false); //fa in modo che la dimensione delle colenne non sia personalizzabile dall'utente

        //questa parte di codice serve per cambiare la larghezza delle celle della tabella
        promTable.getColumnModel().getColumn(0).setMinWidth(200);
        promTable.getColumnModel().getColumn(1).setMinWidth(200);
        promTable.getColumnModel().getColumn(2).setMinWidth(200);
        promTable.getColumnModel().getColumn(3).setMinWidth(200);

        promTable.getColumnModel().getColumn(0).setPreferredWidth(200);
        promTable.getColumnModel().getColumn(1).setPreferredWidth(200);
        promTable.getColumnModel().getColumn(2).setPreferredWidth(200);
        promTable.getColumnModel().getColumn(3).setPreferredWidth(200);

        promTable.getColumnModel().getColumn(0).setMaxWidth(200);
        promTable.getColumnModel().getColumn(1).setMaxWidth(200);
        promTable.getColumnModel().getColumn(2).setMaxWidth(200);
        promTable.getColumnModel().getColumn(3).setMaxWidth(200);

        // MOSTRO IL PROFILO TRAMITE I VARI LABEL

        nomeLabel.setText(nomeLabel.getText() + i.getNome());
        cognomeLabel.setText(cognomeLabel.getText() + i.getCognome());
        dataNascLabel.setText(dataNascLabel.getText() + i.getDataNascita());
        etaLabel.setText(etaLabel.getText() + i.getEta());
        dataAssLabel.setText(dataAssLabel.getText() + i.getDataAssunzione());
        cateLabel.setText(cateLabel.getText() + i.getCategoria());
        salarioLabel.setText(salarioLabel.getText() + i.getSalario() + '€');
        contrattoLabel.setText(contrattoLabel.getText() + i.getTipoContratto());

        if(i.getDataScadenza() != null)
            dataScadLabel.setText(dataScadLabel.getText() + i.getDataScadenza());
        else
            dataScadLabel.setVisible(false);

        // POPOLO LA LISTA DEI LABORATORI AI QUALI L'IMPIEGATO LAVORA

        String[] arrayLaboratori = i.getListaLaboratori().toArray(new String[0]);

        for (String s : arrayLaboratori) dfl.addElement(s);
    }
}
