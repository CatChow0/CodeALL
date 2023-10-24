#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mon Platformer 2D");
    window.setFramerateLimit(60);  // Limite le framerate à 60 FPS

    // Créez un personnage
    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Blue);

    // Position initiale du joueur
    sf::Vector2f playerPosition(100, 570);
    player.setPosition(playerPosition);

    // Créez une plateforme rectangulaire pour le sol
    sf::RectangleShape platform(sf::Vector2f(800, 20));  // Largeur de 800 pixels et hauteur de 20 pixels
    platform.setFillColor(sf::Color::Green); 

    // Position de la plateforme
    sf::Vector2f platformPosition(0, 580);  // Place la plateforme en bas de la fenêtre
    platform.setPosition(platformPosition);

    // Créez une plateforme rectangulaire pour le sol
    sf::RectangleShape Floatform(sf::Vector2f(800, 20));  // Largeur de 800 pixels et hauteur de 20 pixels
    Floatform.setFillColor(sf::Color::Red);

    // Position de la plateforme
    sf::Vector2f FloatformPosition(0, 500);  // Place la plateforme en bas de la fenêtre
    Floatform.setPosition(FloatformPosition);

	sf::Clock clock;

    // Gravité
    float gravity = 1.0f;

    // Vitesse initiale du joueur
    sf::Vector2f playerVelocity(0, 0);

    // Indicateur pour le saut
    bool isJumping = false;

	bool isOnGround = false;

    bool isClip = false;

    while (window.isOpen())
    {
        sf::Time delatTime= clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Gestion des mouvements du joueur
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerVelocity.x = -5.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerVelocity.x = 5.0f;
        }
        else
        {
            playerVelocity.x = 0.0f;
        }

		// Gestion du cliping des platformes
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			isClip = true;
			playerVelocity.y += 2.f;
        }

        // Gestion du saut
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !isJumping)
        {
            playerVelocity.y = -15.0f;  // Saut vers le haut
            isJumping = true;
			isOnGround = false;
        }

        // Met à jour la position du joueur
        playerPosition += playerVelocity;

        if (isOnGround == false) {
            // Gestion de la gravité
            playerVelocity.y += gravity;
        }

        // Limite le joueur à l'écran
        if (playerPosition.x < 0)
            playerPosition.x = 0;
        if (playerPosition.x > 750)
            playerPosition.x = 750;
        if (playerPosition.y > 550)
        {
            playerPosition.y = 550;
            playerVelocity.y = 0;
            isJumping = false;  // Réinitialise le saut lorsque le joueur touche le sol
        }

        if (player.getGlobalBounds().intersects(platform.getGlobalBounds()))
        {
            // Si le joueur touche la plateforme, le joueur est sur le sol
            playerPosition.y = platform.getPosition().y - player.getSize().y;
            isJumping = false;  // Réinitialise le saut
			playerVelocity.y = 0;  // R?initialise la vitesse du joueur
			isOnGround = true;
			isClip = false;
        }

        if (player.getGlobalBounds().intersects(Floatform.getGlobalBounds()) && !isClip)
        {
            // Si le joueur touche la plateforme, le joueur est sur le sol
            playerPosition.y = Floatform.getPosition().y - player.getSize().y;
            isJumping = false;  // Réinitialise le saut
            playerVelocity.y = 0;  // R?initialise la vitesse du joueur
            isOnGround = true;
        }

        // Applique la nouvelle position au joueur
        player.setPosition(playerPosition);

        window.clear();
		window.draw(Floatform);
        window.draw(platform);
        window.draw(player);
        window.display();
    }

    return 0;
}
