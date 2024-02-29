package GUI;

import Controller.Controller;
import Model.Attrezzatura;
import org.jetbrains.annotations.NotNull;

import javax.swing.*;
import java.awt.*;

public class ProfiloAttrezzaturaGUI {
    private JPanel profAttMainPanel;
    private JLabel titleLabel;
    private JLabel serialeLabel;
    private JLabel tipoLabel;
    private JLabel labLabel;
    private JLabel progLabel;
    private JLabel costoLabel;
    private JFrame frame;

    public ProfiloAttrezzaturaGUI(@NotNull Controller controller, String serialeSelezionato){
        // IMPOSTO IL FRAME

        frame = new JFrame("Profilo Attrezzatura");
        frame.setContentPane(profAttMainPanel);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(new Dimension(300,200));
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        // MOSTRO TUTTI I DATI NEI VARI LABEL

        Attrezzatura a = controller.getDatiAttrezzatura(serialeSelezionato);

        serialeLabel.setText(serialeLabel.getText() + a.getSeriale());
        tipoLabel.setText(tipoLabel.getText() + a.getTipo());
        labLabel.setText(labLabel.getText() + a.getNomeLab());
        progLabel.setText(progLabel.getText() + a.getCup());
        costoLabel.setText(costoLabel.getText() + a.getCosto() + "€");
    }
}
