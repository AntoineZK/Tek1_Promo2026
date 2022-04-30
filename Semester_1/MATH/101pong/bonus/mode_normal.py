import pygame, sys, random

def bullet_movement():
    global ball_speed_x, ball_speed_y, player1_score, player2_score, score_time
    
    bullet.x += ball_speed_x
    bullet.y += ball_speed_y

    if bullet.top <= 0 or bullet.bottom >= wdw_height:
        ball_speed_y *= -1
        
    if bullet.left <= 0: 
        score_time = pygame.time.get_ticks()
        player1_score += 1

    if bullet.right >= wdw_width:
        score_time = pygame.time.get_ticks()
        player2_score += 1
        
    if bullet.colliderect(player1) and ball_speed_x > 0:
        if abs(bullet.right - player1.left) < 10:
            ball_speed_x *= -1
            ball_speed_x *= 1.1
        elif abs(bullet.bottom - player1.top) < 10 and ball_speed_y > 0:
            ball_speed_y *= -1
            ball_speed_y *= 1.1
        elif abs(bullet.top - player1.bottom) < 10 and ball_speed_y < 0:
            ball_speed_y *= -1
            ball_speed_y *= 1.1

    if bullet.colliderect(player2) and ball_speed_x < 0:
        if abs(bullet.left - player2.right) < 10:
            ball_speed_x *= -1
            ball_speed_x *= 1.1
        elif abs(bullet.bottom - player2.top) < 10 and ball_speed_y > 0:
            ball_speed_y *= -1
            ball_speed_y *= 1.1
        elif abs(bullet.top - player2.bottom) < 10 and ball_speed_y < 0:
            ball_speed_y *= -1
            ball_speed_y *= 1.1
        

def player1_movement():
    player1.y += player1_speed

    if player1.top <= 0:
        player1.top = 0
    if player1.bottom >= wdw_height:
        player1.bottom = wdw_height

def player2_movement():
    player2.y += player2_speed
    
    if player2.top <= 0:
        player2.top = 0
    if player2.bottom >= wdw_height:
        player2.bottom = wdw_height

def ball_initial():
    global ball_speed_x, ball_speed_y, ball_moving, score_time

    bullet.center = (wdw_width/2, wdw_height/2)
    act_time = pygame.time.get_ticks()

    if act_time - score_time < 700:
        text1 = basic_font.render("3",False,(255,255,255))
        window.blit(text1,(wdw_width/2 - 10, wdw_height/2 + 20))
    if 700 < act_time - score_time < 1400:
        text2 = basic_font.render("2",False,(255,255,255))
        window.blit(text2,(wdw_width/2 - 10, wdw_height/2 + 20))
    if 1400 < act_time - score_time < 2100:
        text3 = basic_font.render("1",False,(255,255,255))
        window.blit(text3,(wdw_width/2 - 10, wdw_height/2 + 20))

    if act_time - score_time < 2100:
        ball_speed_y, ball_speed_x = 0,0
    else:
        ball_speed_x = 7 * random.choice((1,-1))
        ball_speed_y = 7 * random.choice((1,-1))
        score_time = None

pygame.init()
FPS = pygame.time.Clock()

wdw_width = 1280
wdw_height = 960
window = pygame.display.set_mode((wdw_width,wdw_height))
pygame.display.set_caption('Pong')

bullet = pygame.Rect(wdw_width / 2 - 15, wdw_height / 2 - 15, 30, 30)
player1 = pygame.Rect(wdw_width - 20, wdw_height / 2 - 70, 10,140)
player2 = pygame.Rect(10, wdw_height / 2 - 70, 10,140)

ball_speed_x = 7 * random.choice((1,-1))
ball_speed_y = 7 * random.choice((1,-1))
player1_speed = 0
player2_speed = 0
ball_moving = False
score_time = True

player1_score = 0
player2_score = 0
basic_font = pygame.font.Font('freesansbold.ttf', 32)
def pong():
    global player1_speed, player2_speed
    run = True
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    run = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    player1_speed -= 7
                if event.key == pygame.K_DOWN:
                    player1_speed += 7
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_UP:
                    player1_speed += 7
                if event.key == pygame.K_DOWN:
                    player1_speed -= 7
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_z:
                    player2_speed -= 7
                if event.key == pygame.K_s:
                    player2_speed += 7                  
            if event.type == pygame.KEYUP:
                if event.key == pygame.K_z:
                    player2_speed += 7
                if event.key == pygame.K_s:
                    player2_speed -= 7
        
        bullet_movement()
        player1_movement()
        player2_movement()
        
        window.fill((0,0,0))
        pygame.draw.rect(window, (255,0,0), player1)
        pygame.draw.rect(window, (0,0,255), player2)
        pygame.draw.aaline(window, (255,255,255), (wdw_width / 2, 0),(wdw_width / 2, wdw_height))
        pygame.draw.ellipse(window, (0,255,0), bullet)
        
        if score_time:
            ball_initial()

        player1_text = basic_font.render(f'{player1_score}',False,(255,255,0))
        window.blit(player1_text,(660,470))

        player2_text = basic_font.render(f'{player2_score}',False,(255,255,0))
        window.blit(player2_text,(600,470))

        pygame.display.flip()
        FPS.tick(60)