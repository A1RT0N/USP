import javax.swing.*;
import java.awt.*;

public class CenteredTextField extends JTextField {
    public CenteredTextField() {
        super();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);  // Garante que o fundo seja sempre limpo

        if (getText().isEmpty()) {
            return;
        }
        
        Graphics2D g2d = (Graphics2D) g.create();
        int height = getHeight();
        int textY = (height - g2d.getFontMetrics().getHeight()) / 2 + g2d.getFontMetrics().getAscent();

        g2d.drawString(getText(), getInsets().left, textY);
        g2d.dispose();
    }

    @Override
    public void setText(String t) {
        super.setText(t);
        repaint();
    }
}
