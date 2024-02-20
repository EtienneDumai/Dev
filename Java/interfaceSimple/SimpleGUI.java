import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleGUI extends JFrame {
    private JButton button;
    
    public SimpleGUI() {
        // Définit le titre de la fenêtre
        setTitle("Exemple d'interface graphique");
        // Définit la taille de la fenêtre
        setSize(300, 200);
        // Opération à réaliser lorsque la fenêtre est fermée
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Crée un bouton et ajoute un écouteur d'événement
        button = new JButton("Cliquez-moi");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                button.setText("Cliqué");
            }
        });
        
        // Ajoute le bouton à la fenêtre
        getContentPane().add(button);
    }
    
    public static void main(String[] args) {
        // Crée l'instance de la fenêtre et la rend visible
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SimpleGUI().setVisible(true);
            }
        });
    }
}
