import pygame, sys, random
import mode_easy, mode_normal, mode_hard
pygame.init()
FPS = pygame.time.Clock()

win_width = 1280
win_height = 960
pygame.display.set_caption("Menu")
window = pygame.display.set_mode((win_width, win_height))

def menu():
    click = False
    while True:
        
        window.fill((100,100,100))
        
        mouse_x, mouse_y = pygame.mouse.get_pos()
        
        PONG = pygame.Rect(win_width /3 + 100, 50, 180, 80)
        easy = pygame.Rect(470, 250, 300, 150)
        normal = pygame.Rect(420, 420, 400, 150)
        hard = pygame.Rect(370, 590, 500, 150)
        exit = pygame.Rect(win_width /3 + 100, 800, 180, 80)
        if easy.collidepoint((mouse_x, mouse_y)):
            if click:
                mode_easy.pong()
        if normal.collidepoint((mouse_x,mouse_y)):
            if click:
                mode_normal.pong()
        if hard.collidepoint((mouse_x,mouse_y)):
            if click:
                mode_hard.pong()
        pygame.draw.rect(window, (239, 239, 239), PONG)
        pygame.draw.rect(window, (0, 127, 255), easy)
        pygame.draw.rect(window, (255, 127, 0), normal)
        pygame.draw.rect(window, (254, 27, 0), hard)
        pygame.draw.rect(window, (52, 201, 36), exit)
        label1 = pygame.font.SysFont("monospace", 50)
        text1 = label1.render("PONG", 1, (0,0,0))
        window.blit(text1, (win_width /2 -80, 60))
        label2 = pygame.font.SysFont("monospace", 50)
        text2 = label2.render("EASY", 1, (0,0,0))
        window.blit(text2, (win_width /2 -80, 300))
        label3 = pygame.font.SysFont("monospace", 50)
        text3 = label3.render("NORMAL", 1, (0,0,0))
        window.blit(text3, (win_width /2 -100, 470))
        label4 = pygame.font.SysFont("monospace", 50)
        text4 = label4.render("HARD", 1, (0,0,0))
        window.blit(text4, (win_width /2 -80, 630))
        label5 = pygame.font.SysFont("monospace", 50)
        text5 = label5.render("EXIT", 1, (0,0,0))
        window.blit(text5, (win_width /2 -80, 810))
        
        click = False
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                    click = True
            if exit.collidepoint((mouse_x, mouse_y)):
                if event.type == pygame.MOUSEBUTTONDOWN:
                    if event.button == 1:
                        pygame.quit()
                        sys.exit()
                        
        
        pygame.display.update()
        FPS.tick(140)

menu()