import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class SnakeGame extends JPanel implements ActionListener {

    private final int WIDTH = 640;
    private final int HEIGHT = 640;
    private final int UNIT_SIZE = 20;
    private final int DELAY = 75;

    private int[] snakeX;
    private int[] snakeY;
    private int snakeLength;
    private int direction;

    private boolean running;
    private Timer timer;

    private boolean gameOver;

    private int foodX;
    private int foodY;

    private Random random;

    public SnakeGame() {
        initGame();
    }

    private void initGame() {
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setBackground(Color.black);
        setFocusable(true);
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_LEFT && direction != 0) {
                    direction = 2;
                }
                if (e.getKeyCode() == KeyEvent.VK_UP && direction != 1) {
                    direction = 3;
                }
                if (e.getKeyCode() == KeyEvent.VK_RIGHT && direction != 2) {
                    direction = 0;
                }
                if (e.getKeyCode() == KeyEvent.VK_DOWN && direction != 3) {
                    direction = 1;
                }
            }
        });
        startGame();
    }

    private void startGame() {
        running = true;
        snakeLength = 3;
        snakeX = new int[WIDTH / UNIT_SIZE];
        snakeY = new int[HEIGHT / UNIT_SIZE];
        direction = 2;
        gameOver = false;

        random = new Random();
        placeFood();

        timer = new Timer(DELAY, this);
        timer.start();
    }

    private void placeFood() {
        foodX = random.nextInt(WIDTH / UNIT_SIZE) * UNIT_SIZE;
        foodY = random.nextInt(HEIGHT / UNIT_SIZE) * UNIT_SIZE;
    }

    private void draw(Graphics g) {
        if (running) {
            Graphics2D ctx = (Graphics2D) g;
            ctx.setColor(Color.green);
            for (int i = 0; i < snakeLength; i++) {
                ctx.fillRect(snakeX[i], snakeY[i], UNIT_SIZE, UNIT_SIZE);
            }

            ctx.setColor(Color.red);
            ctx.fillRect(foodX, foodY, UNIT_SIZE, UNIT_SIZE);
        } else {
            gameOver(g);
        }
    }

    private void gameOver(Graphics g) {
        g.setColor(Color.white);
        g.setFont(new Font("Arial", Font.BOLD, 40));
        FontMetrics metrics = getFontMetrics(g.getFont());
        g.drawString("Game Over", (WIDTH - metrics.stringWidth("Game Over")) / 2, HEIGHT / 2);
    }

    private void move() {
        for (int i = snakeLength - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        if (direction == 0) {
            snakeX[0] += UNIT_SIZE;
        } else if (direction == 1) {
            snakeY[0] += UNIT_SIZE;
        } else if (direction == 2) {
            snakeX[0] -= UNIT_SIZE;
        } else if (direction == 3) {
            snakeY[0] -= UNIT_SIZE;
        }

        if (snakeX[0] < 0) {
            snakeX[0] = WIDTH - UNIT_SIZE;
        }
        if (snakeX[0] >= WIDTH) {
            snakeX[0] = 0;
        }
        if (snakeY[0] < 0) {
            snakeY[0] = HEIGHT - UNIT_SIZE;
        }
        if (snakeY[0] >= HEIGHT) {
            snakeY[0] = 0;
        }

        checkFoodCollision();
        checkCollision();
    }

    private void checkFoodCollision() {
        if (snakeX[0] == foodX && snakeY[0] == foodY) {
            snakeLength++;
            placeFood();
        }
    }

    private void checkCollision() {
        for (int i = 1; i < snakeLength; i++) {
            if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
                gameOver = true;
                break;
            }
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (running) {
            move();
            repaint();
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Snake Game");
        SnakeGame game = new SnakeGame();
        frame.add(game);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
