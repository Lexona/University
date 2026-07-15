package GUI;

import Controller.Controller;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;
import java.sql.Date;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class AddImpiegatoGUI {
    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
    ButtonGroup bg = new ButtonGroup();
    private JPanel addImpMainPanel;
    private JPanel insPanel;
    private JPanel buttonsPanel;
    private JButton cancelBtn;
    private JButton okBtn;
    private JLabel cfLabel;
    private JLabel nomeLabel;
    private JLabel cognomeLabel;
    private JTextField cfTextField;
    private JTextField nomeTextField;
    private JTextField cognomeTextField;
    private JTextField dataNascitaTextField;
    private JTextField dataAssTextField;
    private JTextField dataScadTextField;
    private JLabel dataNascitaLabel;
    private JLabel dataAssLabel;
    private JLabel contrattoLabel;
    private JLabel dataScadLabel;
    private JRadioButton indRadioBtn;
    private JRadioButton progRadioBtn;
    private JLabel categoriaLabel;
    private JTextField categoriaTextField;
    private JLabel cupLabel;
    private JTextField cupTextField;
    JFrame frame;

    public AddImpiegatoGUI(@NotNull Controller controller) {
        // IMPOSTO IL FRAME

        frame = new JFrame("Impiegati");
        frame.setContentPane(addImpMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(500,480));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // AGGIUNGO I RADIOBUTTON AL BUTTONGROUP
        bg.add(indRadioBtn);
        bg.add(progRadioBtn);

        // IMPOSTO GLI ACTION LISTENER PER TUTTI I COMPONENTI

        indRadioBtn.addActionListener(e -> {
            dataScadTextField.setEnabled(false);
            cupTextField.setEnabled(false);
        });

        progRadioBtn.addActionListener(e -> {
            dataScadTextField.setEnabled(true);
            cupTextField.setEnabled(true);
        });

        cancelBtn.addActionListener(e -> frame.dispose());

        okBtn.addActionListener(e -> {
            int risposta = JOptionPane.showConfirmDialog(null, "Confermi di voler assumere questo impiegato?", "Conferma", JOptionPane.YES_NO_OPTION);

            if (risposta == JOptionPane.YES_OPTION) {
                String cf = cfTextField.getText();
                String nome = nomeTextField.getText();
                String cognome = cognomeTextField.getText();
                String dataNascitaTemp = dataNascitaTextField.getText();
                String dataAssunzioneTemp = dataAssTextField.getText();
                String dataScadenzaTemp = dataScadTextField.getText();
                String cup = cupTextField.getText();

                String categoria;

                Date dataNascita = null;
                Date dataAssunzione = null;
                Date dataScadenza = null;

                if (!categoriaTextField.getText().isEmpty())
                    categoria = categoriaTextField.getText();
                else
                    categoria = null;

                try {
                    dataNascita = new Date(sdf.parse(dataNascitaTemp).getTime());
                    dataAssunzione = new Date(sdf.parse(dataAssunzioneTemp).getTime());

                    if (!dataScadenzaTemp.isEmpty())
                        dataScadenza = new Date(sdf.parse(dataScadenzaTemp).getTime());
                } catch (ParseException ex) {
                    JOptionPane.showMessageDialog(null, "Errore nell'inserimento", "Errore", JOptionPane.ERROR_MESSAGE);
                }

                try {
                    controller.aggiungiImpiegato(cf, nome, cognome, dataNascita, dataAssunzione, dataScadenza, categoria, cup);
                    JOptionPane.showMessageDialog(null, "Inserimento avvenuto con successo!", "Successo", JOptionPane.INFORMATION_MESSAGE);
                    frame.dispose();
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(null, "Errore: " + ex.getMessage(), "Errore", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }
}
