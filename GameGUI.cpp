// GameGUI.cpp

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>  // Include for displaying messages

#include "GameState.hpp"
#include "GamePiece.hpp"

class GameGUI : public QWidget {
public:
    GameGUI(GameState& gameState) : gameState(gameState) {
        setupUI();
    }

private:
    GameState& gameState;  // Reference to the GameState object

    void setupUI() {
        // Create widgets
        QLabel* titleLabel = new QLabel("Board Game Simulator");
        QPushButton* startButton = new QPushButton("Start Game");

        // Add more widgets as needed

        // Create layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(titleLabel);
        layout->addWidget(startButton);

        // Set the layout for the main window
        setLayout(layout);

        // Connect signals and slots (event handling)
        connect(startButton, &QPushButton::clicked, this, &GameGUI::startGame);
    }

private slots:
    void startGame() {
        // Retrieve information about the game pieces
        int totalPieces = gameState.NumPieces();
        int warriorPower = GamePiece("TestPlayer", "Warrior", &gameState).GetPower();
        int scoutSpeed = GamePiece("TestPlayer", "Scout", &gameState).GetSpeed();

        // Display information using a message box (you can customize this part)
        QString message = QString("Total Pieces: %1\nWarrior Power: %2\nScout Speed: %3")
                              .arg(totalPieces)
                              .arg(warriorPower)
                              .arg(scoutSpeed);

        QMessageBox::information(this, "Game Information", message);
    }
};
