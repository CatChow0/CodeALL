#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer 2D");

    // Créez un personnage
    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Blue);

    // Position initiale du joueur
    sf::Vector2f playerPosition(100, 570);
    player.setPosition(playerPosition);

    // Créé un pic
    sf::CircleShape Spick(30, 3);
    Spick.setFillColor(sf::Color::Yellow);

    sf::Vector2f SpickPosition(1200, 550);
	Spick.setPosition(SpickPosition);

    // Créez une plateforme rectangulaire pour le sol
    sf::RectangleShape platform(sf::Vector2f(1200, 20));  // Largeur de 800 pixels et hauteur de 20 pixels
    platform.setFillColor(sf::Color::Green); 

    // Position de la plateforme
    sf::Vector2f platformPosition(0, 580);  // Place la plateforme en bas de la fenêtre
    platform.setPosition(platformPosition);

    // Crée le sol qui vas se générer au bord de l'écran
    sf::RectangleShape NewPlatform(sf::Vector2f(1200, 20)); // Largeur de 800 pixels et hauteur de 20 pixels
	NewPlatform.setFillColor(sf::Color::White);

	sf::Vector2f NewPlatformPosition(1200, 580); // Place la plateforme a la suite de la première
    NewPlatform.setPosition(NewPlatformPosition);

    // Créez une plateforme rectangulaire en l'air
    sf::RectangleShape Floatform(sf::Vector2f(200, 20));  // Largeur de 800 pixels et hauteur de 20 pixels
    Floatform.setFillColor(sf::Color::Red);

	// Position de la plateforme flotante en l'air
    sf::Vector2f FloatformPosition(600, 400);  // Place la plateforme en bas de la fenêtre
    Floatform.setPosition(FloatformPosition);

    // Créez une plateforme rectangulaire en l'air
    sf::RectangleShape Floatform_2(sf::Vector2f(200, 20));  // Largeur de 800 pixels et hauteur de 20 pixels
    Floatform_2.setFillColor(sf::Color::Red);

    // Position de la plateforme flotante en l'air
    sf::Vector2f Floatform_2_Position(300, 300);  // Place la plateforme en bas de la fenêtre
    Floatform_2.setPosition(Floatform_2_Position);

    //Crée la vie
    sf::RectangleShape LifeBarBackground(sf::Vector2f(100, 20));
    LifeBarBackground.setFillColor(sf::Color::Red);

    sf::RectangleShape LifeBarForeground(sf::Vector2f(100, 20));
    LifeBarForeground.setFillColor(sf::Color::Green);

    sf::Vector2f LifeBarBackground_Position(20, 20);
    LifeBarBackground.setPosition(LifeBarBackground_Position);

	sf::Vector2f LifeBarForeground_position(20, 20);
    LifeBarForeground.setPosition(LifeBarForeground_position);


	sf::Clock clock;

    // Gravité
    float gravity = 1.0f;

    // Vitesse initiale du joueur
    sf::Vector2f playerVelocity(0, 0);

    // Indicateur pour le saut
    bool isJumping = false;

	bool isOnGround = false;

    bool isClip = false;

	bool isDamaged = false;

    float X, Y;

    //initialistation de la caméra
    sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));
    view.zoom(1.f);

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        sf::Event event;

        //caméra qui suit le joueur
        view.setCenter(playerPosition.x, playerPosition.y);
        window.setView(view); //séléctionne la cam en vue principale

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                // Change la caméra celon la taille de la fenêtre 
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        // Gestion des mouvements du joueur
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerVelocity.x = -500;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerVelocity.x = 500;
        }
        else
        {
            playerVelocity.x = 0.0f;
        }

		// Gestion du cliping des platformes
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			isClip = true;
			isOnGround = false;
        }

        // Gestion du saut
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !isJumping)
        {
            playerVelocity.y = -2000.0f;  // Saut vers le haut
            isJumping = true;
			isOnGround = false;
        }

        // Met à jour la position du joueur
        playerPosition += playerVelocity * deltaTime.asSeconds();

        if (isOnGround == false) {
            // Gestion de la gravité
            playerVelocity.y += gravity;
        }

        // Limite le joueur à l'écran
        if (playerPosition.x < 0)
            playerPosition.x = 0;
        if (playerPosition.x > 2400 - player.getSize().x)
            playerPosition.x = 2400 - player.getSize().x;
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
			playerVelocity.y = 0;  // Réinitialise la vitesse du joueur
			isOnGround = true;
			isClip = false;
        }

        if (player.getGlobalBounds().intersects(NewPlatform.getGlobalBounds())) {
			playerPosition.y = NewPlatform.getPosition().y - player.getSize().y;
            isJumping = false;
            playerVelocity.y = 0;
            isOnGround = true;
			isClip = false;
        }

        if (player.getGlobalBounds().intersects(Floatform.getGlobalBounds()) && !isClip)
        {
            // Si le joueur touche la plateforme, le joueur est sur le sol
            playerPosition.y = Floatform.getPosition().y - player.getSize().y ;
            isJumping = false;  // Réinitialise le saut
            playerVelocity.y = 0;  // Réinitialise la vitesse du joueur
            isOnGround = true;
        }

        if (player.getGlobalBounds().intersects(Floatform_2.getGlobalBounds()) && !isClip) {
			playerPosition.y = Floatform_2.getPosition().y - player.getSize().y;
			isJumping = false;  // Réinitialise le saut
			playerVelocity.y = 0;  // Réinitialise la vitesse du joueur
			isOnGround = true;
        }

        if (player.getGlobalBounds().intersects(Spick.getGlobalBounds()) && !isDamaged) {
            X = LifeBarForeground.getSize().x - 10;
			Y = LifeBarForeground.getSize().y;

			LifeBarForeground.setSize(sf::Vector2f(X,Y));

            isDamaged = true;
            if (LifeBarBackground.getSize().x<= 0) {
			    
            }
        }

        if (isDamaged == true) {

        }

        if (playerPosition.x != FloatformPosition.x) {
			isOnGround = false;
        }

        if (playerPosition.x != Floatform_2_Position.x) {
			isOnGround = false;
		}

		LifeBarBackground_Position.x = playerPosition.x - 400;
        LifeBarBackground_Position.y = playerPosition.y - 250;

        LifeBarForeground_position.x = playerPosition.x - 400;
		LifeBarForeground_position.y = playerPosition.y - 250;

		LifeBarBackground.setPosition(LifeBarBackground_Position);
		LifeBarForeground.setPosition(LifeBarForeground_position);

        

        // Applique la nouvelle position au joueur
        player.setPosition(playerPosition);

        window.clear();
        window.draw(LifeBarBackground);
		window.draw(LifeBarForeground);
        window.draw(Spick);
        window.draw(Floatform_2);
		window.draw(Floatform);
        window.draw(platform);
		window.draw(NewPlatform);
        window.draw(player);
        window.display();
    }

    return 0;
}
