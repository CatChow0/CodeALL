import pygame
import pytmx 
import pyscroll
from player import Player
class Game:
    def __init__(self):
        #creer la fenetre du jeu
        self.screen = pygame.display.set_mode((1280, 720))
        pygame.display.set_caption("Jeu - Test")
        # charger la carte (tmx)
        tmx_data = pytmx.load_pygame('map.tmx')
        map_data = pyscroll.data.TiledMapData(tmx_data)
        map_layer = pyscroll.orthographic.BufferedRenderer(map_data, self.screen.get_size())
        map_layer.zoom = 2
        # genere un joueur
        player_position = tmx_data.get_object_by_name("player")
        self.player = Player(player_position.x, player_position.y)
        # dessiner le groupe de calque
        self.group = pyscroll.PyscrollGroup(map_layer=map_layer, default_layer=3)
        self.group.add(self.player)
    def handle_imput(self):
        pressed = pygame.key.get_pressed()
        if pressed[pygame.K_z]:
            self.player.move_up()
        elif pressed[pygame.K_s]:
            self.player.move_down()
        elif pressed[pygame.K_q]:
            self.player.move_left()
        elif pressed[pygame.K_d]:
            self.player.move_right()
    def run(self):
        clock = pygame.time.Clock()
        #boucle du jeu
        running = True
        while running:
            self.handle_imput()
            self.player.update_animation()
            self.group.update()
            self.group.center(self.player.rect)
            self.group.draw(self.screen)
            pygame.display.flip()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
            clock.tick(60)
        pygame.quit()