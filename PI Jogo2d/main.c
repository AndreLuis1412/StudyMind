#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h> //esse para adicionar fontes novas
#include <allegro5/allegro_image.h> 
#include <allegro5/keyboard.h>
#include <allegro5/allegro_primitives.h> // mexer com formas geometricas

int colidir(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh) {
    /*
    ?x = onde esta no X
    ?y = onde esta no Y
    ?w = comprimento
    ?h = altura
    */
    if (ax + aw > bx &&
        ax < bx + bw &&
        ay + ah > by &&
        ay < by + bh)
        return 1;
    return 0;
}

int colidir2(int ax, int ay, int aw, int ah, int bx, int by, int bxf, int byf) {
    if (ax + aw >= bx &&
        ax <= bxf &&
        ay + ah >= by &&
        ay + ah <= byf)
        return 1;
    return 0;
}

int colidirIni(int ax, int ay, int aw, int ah, int bx, int by, int bxf, int byf) {
    if (ax + aw >= bx)
        return 1;
    return 0;
}

int colidirIniEsq(int ax, int ay, int aw, int ah, int bx, int by, int bxf, int byf) {
    if (ax + aw >= bx &&
        ay + ah >= by &&
        ax + aw <= bx + 20 &&
        ay + ah <= byf)
        return 1;

    return 0;
}

int colidirIniDir(int ax, int ay, int aw, int ah, int bx, int by, int bxf, int byf) {
    if (ax <= bxf &&
        ay + ah >= by &&
        ax >= bxf - 20 &&
        ay + ah <= byf) 
        return 1;

    return 0;
}

int colidirIniUp(int ax, int ay, int aw, int ah, int bx, int by, int bxf, int byf) {
    if (ax + aw >= bx + 21 &&
        ay + ah >= by &&
        ax <= bxf - 21 &&
        ay + ah <= byf)
        return 1;

    return 0;
}

int escalar(ax, ay, aw, ah, bx, by, bxf, byf) {
    if (ax + aw >= bx &&
        ax <= bxf &&
        ay + ah >= by &&
        ay + ah <= byf)
        return 1;


    return 0;
}

int colidirBala(ax, ay, axf, ayf, bx, by, bxf, byf) {
    if (axf >= bx &&
        ax <= bxf &&
        ayf >= by &&
        ay <= byf)
        return 1;
    return 0;
}




int main()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();

    ALLEGRO_TIMER* timer_menu = al_create_timer(1.0 / 30.0);
    ALLEGRO_DISPLAY* display_menu = al_create_display(1280, 720);
    ALLEGRO_FONT* font = al_create_builtin_font();

    //colocando imgns
    ALLEGRO_BITMAP* mapa = mapa = al_load_bitmap("./mapaFase1.png");//mapa fase1  nullptr
    ALLEGRO_BITMAP* boneco = al_load_bitmap("./ze_gotinha-pixelArt.png");//boneco fase1
    ALLEGRO_BITMAP* sumario = al_load_bitmap("./sumario_studymind.png");//menu
    ALLEGRO_BITMAP* inimigo1 = al_load_bitmap("./Idle.png");//Inimigo 1 parado
    ALLEGRO_BITMAP* inimigo2 = al_load_bitmap("./Idle.png");//Inimigo 2 parado 
    ALLEGRO_BITMAP* inimigo3 = al_load_bitmap("./Idle.png");//Inimigo 3 parado 
    ALLEGRO_BITMAP* inimigo4 = al_load_bitmap("./Idle.png");//Inimigo 4 parado 
    ALLEGRO_BITMAP* curado1 = al_load_bitmap("./IdleCurado.png");//Curado 1 parado
    ALLEGRO_BITMAP* curado2 = al_load_bitmap("./IdleCurado.png");//Curado 2 parado 
    ALLEGRO_BITMAP* curado3 = al_load_bitmap("./IdleCurado.png");//Curado 3 parado 
    ALLEGRO_BITMAP* curado4 = al_load_bitmap("./IdleCurado.png");//Curado 4 parado 
    ALLEGRO_BITMAP* vacina = al_load_bitmap("./vacina.png");//Vacina
    ALLEGRO_BITMAP* win = al_load_bitmap("./win.png");//win 
    ALLEGRO_BITMAP* lose = al_load_bitmap("./lose.png");//lose 
    ALLEGRO_BITMAP* instru = al_load_bitmap("./instrucoes.png");//instru 
    ALLEGRO_BITMAP* mechanic = al_load_bitmap("./mecanicas.png");//mechanics 
    ALLEGRO_BITMAP* cadeado = al_load_bitmap("./block.png");//mechanics 

    // imagens para fase 2
    ALLEGRO_BITMAP* ComoJogar = al_load_bitmap("./ComoJogar.png");
    ALLEGRO_BITMAP* Apresentacao = al_load_bitmap("./Apresentacao.png");
    ALLEGRO_BITMAP* FundoQ1 = al_load_bitmap("./Questao1.png");
    ALLEGRO_BITMAP* FundoQ2 = al_load_bitmap("./Questao2.png");
    ALLEGRO_BITMAP* FundoQ3 = al_load_bitmap("./Questao3.png");
    ALLEGRO_BITMAP* FundoQ4 = al_load_bitmap("./Questao4.png");
    ALLEGRO_BITMAP* Ganhou = al_load_bitmap("./VoceGanhou.png");
    ALLEGRO_BITMAP* Perdeu = al_load_bitmap("./VocePerdeu.png");
    //Warrior = 96x96
    ALLEGRO_BITMAP* Warrior3 = al_load_bitmap("./Warrior3_idle.png"); 
    ALLEGRO_BITMAP* Warrior3_Attack = al_load_bitmap("./Warrior3_attack.png"); 
    ALLEGRO_BITMAP* Warrior3_Hurt = al_load_bitmap("./Warrior3_hurt.png"); 
    ALLEGRO_BITMAP* Warrior3_Dead = al_load_bitmap("./Warrior3_dead.png"); 

    ALLEGRO_BITMAP* Warrior2 = al_load_bitmap("./Warrior2_idle.png");
    ALLEGRO_BITMAP* Warrior2_Attack = al_load_bitmap("./Warrior2_attack.png");
    ALLEGRO_BITMAP* Warrior2_Hurt = al_load_bitmap("./Warrior2_hurt.png");
    ALLEGRO_BITMAP* Warrior2_Dead = al_load_bitmap("./Warrior2_dead.png");

    ALLEGRO_BITMAP* acertou = al_load_bitmap("./acertou.png");
    ALLEGRO_BITMAP* errou = al_load_bitmap("./errou.png");
    ALLEGRO_BITMAP* Inicio1 = al_load_bitmap("./Inicio1.png"); 
    ALLEGRO_BITMAP* Inicio2 = al_load_bitmap("./Inicio2.png");
    ALLEGRO_BITMAP* Final = al_load_bitmap("./GanhouJogo.png");


    al_set_window_title(display_menu, "StudyMind");
    al_set_window_position(display_menu, 320, 150);

    ALLEGRO_EVENT_QUEUE* event_menu = al_create_event_queue();
    al_register_event_source(event_menu, al_get_display_event_source(display_menu));
    al_register_event_source(event_menu, al_get_timer_event_source(timer_menu));
    al_register_event_source(event_menu, al_get_keyboard_event_source());
    al_start_timer(timer_menu);

    //Mouse
    al_register_event_source(event_menu, al_get_mouse_event_source());

    float frame = 0.f;
    struct Boneco { int pos_x, pos_y, w, h; };
    struct Boneco ze, ini1, ini2, ini3, ini4;
    //Inimigo 1
    ini1.pos_x = 550, ini1.pos_y = 345;
    ini1.w = 128, ini1.h = 128;
    //Inimigo 2
    ini2.pos_x = 720, ini2.pos_y = 130;
    ini2.w = 128, ini2.h = 128;
    //Inimigo 3
    ini3.pos_x = 600, ini3.pos_y = 575;
    ini3.w = 128, ini3.h = 128;
    //Inimigo 4
    ini4.pos_x = 950, ini4.pos_y = 575;
    ini4.w = 128, ini4.h = 128;
    //Boneco
    ze.pos_x, ze.pos_y; // local do boneco
    ze.h = 30, ze.w = 50;
    int current_frame_y = 0, current_frame_x = 0; // para trocar as imagens dos bonecos

    //Poupicos
    struct Projeteis {
        int id, x, y, velocidade;
        bool onFire;
    };
    int NUM_BALAS = 0; //quantidade de muinicoes na tela
    struct Projeteis pipoco[5];

    //wariors
    struct Move { int pos_x, pos_y, w, h, frame_x, frame_y; }; 
    struct Move heroi, vilao; 

    //jogo 2
    int score = 0;
     
    heroi.pos_x = 300; 
    heroi.pos_y = 550; 
    heroi.w = 96; 
    heroi.h = 96; 
    heroi.frame_x = 96; 
    heroi.frame_y = 0;  

    vilao.pos_x = 750; 
    vilao.pos_y = 550; 
    vilao.w = 96; 
    vilao.h = 96; 
    vilao.frame_x = 96; 
    vilao.frame_y = 0; 

    //trocar imagens guerreiros
    int Hframe_atual = 0;
    int Vframe_atual = 0;
    int Wtempo_troca = 350;
    int WframeW = 96;
    int Wtimer_anima = 0;

    //Jogo 1
    bool inimigo1Vivo = true;
    bool inimigo2Vivo = true; 
    bool inimigo3Vivo = true; 
    bool inimigo4Vivo = true;

    //Para fazer pular
    int sai = 0;
    int dir = 0;
    int vly = 0;
    int vup = 15;
    int grv = 2;
    bool caindo = false;
    bool pulando = false;
    bool escadaOn = false;
    int pLimit = 0;
    bool porCima = false;
    bool jumpF = false;

    int vida;
    int botaoOver = 0;

    bool jogando = true;
    int estado = 15;
    int auxEstado = 0;
    bool curado = true;

    //varaveis para mduar imagem 
    int frames = 8; 
    int frame_atual = 0;
    int tempo_troca = 200;
    int frameW = 128;
    volatile int timer_anima = 0;

    //Tempo para tirar da tela
    int tempoDeTela = 0;

    while (jogando) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_menu, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // se clicar o X, fecha.
            jogando = false;
        }
        //Menu e Fase Biologia
        //printf("%d", botaoOver);
        if (estado == 0 && botaoOver != 2) {
            al_draw_bitmap(sumario, 0, 0, 0);
            if (!curado) {
            al_draw_bitmap_region(cadeado, 0, 0, 60, 60, 470, 340, 0);
            }
            //al_draw_rectangle(535, 230, 770, 308, al_map_rgb(0, 0, 0), 3.0);
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (event.mouse.x >= 535 &&
                    event.mouse.y >= 230 &&
                    event.mouse.x <= 770 &&
                    event.mouse.y <= 308) {
                    botaoOver = 1;
                }
                else {
                    botaoOver = 0;
                }
            } 
            if (botaoOver == 1 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                estado = 1;
            }
        }
        //Fase Historia
        if (estado == 0 && botaoOver != 1 && curado) {
            //para hist
            //al_draw_rectangle(535, 330, 770, 408, al_map_rgb(0, 0, 0), 3.0);
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (event.mouse.x >= 535 &&
                    event.mouse.y >= 330 &&
                    event.mouse.x <= 770 &&
                    event.mouse.y <= 408) {
                    botaoOver = 2;
                }
                else {
                    botaoOver = 0;
                }
            }

            if (botaoOver == 2 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                estado = 6;
                score = 0;
            }

        }
        //Tela instrucao
        if (estado == 1) {
            al_draw_bitmap(instru, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                estado = 2;
            }
        }
        //Tela mechanics 
        if (estado == 2) {
            al_draw_bitmap(mechanic, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_C) {
                estado = 3; 
                vida = 3; 
                ze.pos_x = 1200, ze.pos_y = 600; 
                pulando = false; 
            }

        }
        //Jogo 1
        if (estado == 3) {
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // se clicar o X, fecha.
                jogando = false;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {// se clicar o esc, vai pro menu
                estado = 0;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_D) {// movimentar para a direita
                current_frame_x = 0;
                ze.pos_x += 3;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_A) {// movimentar para a esquerda
                current_frame_y = 0;
                ze.pos_x -= 3;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE && !pulando && !vly) {
                pLimit = ze.pos_y;
                pulando = true;
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_L && pulando && vly) {
                if (pulando) {
                    ze.pos_x += 70;
                }
            }
            else if (event.keyboard.keycode == ALLEGRO_KEY_J && pulando && vly) {
                if (pulando) {
                    ze.pos_x -= 70;
                }
            }
            if (pulando && ze.pos_y > pLimit - 40 && !porCima) {
                    ze.pos_y += vly; 
                    vly = -vup; 
                    caindo = false;
                    //if (jumpF) {
                    //    ze.pos_x += 60;
                    //    jumpF = false;
                    //}
            }
            else if (caindo && !escadaOn) {
                pulando = false;
                vly += grv;
                ze.pos_y += vly;

            }
            else {
                vly = 0;
            }
            caindo = true;

            //fazendo a tela aparecer
            al_draw_bitmap(mapa, 0, 0, 0);
            
            /*
            //chao 1
            al_draw_filled_rectangle(213, 588, 417, 607, al_map_rgb(255, 255, 255), 3.0);
            //chao 2                                                       
            al_draw_filled_rectangle(386, 473, 791, 491, al_map_rgb(255, 255, 255), 3.0);
            //chao 3                                                      
            al_draw_filled_rectangle(834, 440, 877, 459, al_map_rgb(255, 255, 255), 3.0);
            //chao 4
            al_draw_filled_rectangle(926, 409, 1000, 428, al_map_rgb(255, 255, 255), 3.0);
            //chao 5                 
            al_draw_filled_rectangle(1028, 371, 1232, 389, al_map_rgb(255, 255, 255), 3.0);
            //chao 6                     
            al_draw_filled_rectangle(437, 256, 1232, 274, al_map_rgb(255, 255, 255), 3.0);
            //chao 7                     
            al_draw_filled_rectangle(357, 208, 400, 226, al_map_rgb(255, 255, 255), 3.0);
            //chao 8                     
            al_draw_filled_rectangle(180, 165, 317, 183, al_map_rgb(255, 255, 255), 3.0);
            //chao 9                     
            al_draw_filled_rectangle(0, 84, 201, 102, al_map_rgb(255, 255, 255), 3.0);

            //chao principal
            al_draw_filled_rectangle(0, 703, 1280, 740, al_map_rgb(255, 255, 255), 3.0); 

            //teste para fazer escada
            al_draw_filled_rectangle(212, 593, 242, 725, al_map_rgb(255, 255, 255), 3.0);//1
            al_draw_filled_rectangle(387, 490, 412, 608, al_map_rgb(255, 255, 255), 3.0);//2
            al_draw_filled_rectangle(1202, 264, 1230, 390, al_map_rgb(255, 255, 255), 3.0);//3 
            al_draw_filled_rectangle(181, 94, 201, 180, al_map_rgb(255, 255, 255), 3.0);//4 

            //inimigos
            al_draw_filled_rectangle(587, 440, 637, 490, al_map_rgb(255, 255, 255), 3.0);//1
            al_draw_filled_rectangle(757, 225, 807, 275, al_map_rgb(255, 255, 255), 3.0);//2
            al_draw_filled_rectangle(637, 669, 687, 722, al_map_rgb(255, 255, 255), 3.0);//3
            al_draw_filled_rectangle(987, 669, 1037, 722, al_map_rgb(255, 255, 255), 3.0);//4
            //x: 50 
            //y: 50
            */

            //Inimigo
            frame_atual = (timer_anima / tempo_troca) % frames;
            al_draw_bitmap_region(inimigo1, frame_atual * frameW, 0, ini1.h, ini1.w, ini1.pos_x, ini1.pos_y, 0);
            al_draw_bitmap_region(inimigo2, frame_atual * frameW, 0, ini2.h, ini2.w, ini2.pos_x, ini2.pos_y, 0);
            al_draw_bitmap_region(inimigo3, frame_atual * frameW, 0, ini3.h, ini3.w, ini3.pos_x, ini3.pos_y, 0);
            al_draw_bitmap_region(inimigo4, frame_atual * frameW, 0, ini4.h, ini4.w, ini4.pos_x, ini4.pos_y, 0);
            timer_anima += 100;

            //vacina 
            al_draw_bitmap_region(vacina, 0, 0, 15, 64, 30, 17, 0); 

            //pipoco
            if (curado) {
                if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) { 
                    pipoco[NUM_BALAS].x = ze.pos_x - 15; 
                    pipoco[NUM_BALAS].y = ze.pos_y + 20;
                    pipoco[NUM_BALAS].velocidade = 15;
                    pipoco[NUM_BALAS].onFire = true;
                }
            }
            if (curado) {
                if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    pipoco[NUM_BALAS].x = ze.pos_x + ze.w;
                    pipoco[NUM_BALAS].y = ze.pos_y + 20;
                    pipoco[NUM_BALAS].velocidade = -15;
                    pipoco[NUM_BALAS].onFire = true;
                }


                if (pipoco[NUM_BALAS].onFire) {
                    al_draw_filled_rectangle(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y,
                        pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2,
                        al_map_rgb(219, 174, 52), 3.0);
                    pipoco[NUM_BALAS].x -= pipoco[NUM_BALAS].velocidade;
                }
                NUM_BALAS++;
                if (NUM_BALAS >= 5) {
                    NUM_BALAS = 0;
                }
            }
            //colisao com inimigo 1 bala
            if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 587, 440, 637, 490) && inimigo1Vivo) { // inimigo 1
                pipoco[NUM_BALAS].onFire = false;
                inimigo1Vivo = false;
                inimigo1 = curado1;
            }
            else if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 587, 440, 637, 490) && inimigo1Vivo) {
                pipoco[NUM_BALAS].onFire = false;
                inimigo1Vivo = false;
                inimigo1 = curado1;
            }
            //colisao com inimigo 2 bala
            if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 757, 225, 807, 275) && inimigo2Vivo) { // inimigo 2
                pipoco[NUM_BALAS].onFire = false;
                inimigo2Vivo = false;
                inimigo2 = curado2;
            }
            else if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 757, 225, 807, 275) && inimigo2Vivo) {
                pipoco[NUM_BALAS].onFire = false;
                inimigo2Vivo = false;
                inimigo2 = curado2;
            }
            //colisao com inimigo 3 bala
            if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 637, 669, 687, 722) && inimigo3Vivo) { // inimigo 3
                pipoco[NUM_BALAS].onFire = false;
                inimigo3Vivo = false;
                inimigo3 = curado3;
            }
            else if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 637, 669, 687, 722) && inimigo3Vivo) {
                pipoco[NUM_BALAS].onFire = false;
                inimigo3Vivo = false;
                inimigo3 = curado3;
            }
            //colisao com inimigo 4 bala
            if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS]. x + 4, pipoco[NUM_BALAS].y + 2, 987, 669, 1037, 722) && inimigo4Vivo) { // inimigo 4
                pipoco[NUM_BALAS].onFire = false;
                inimigo4Vivo = false;
                inimigo4 = curado4;
            }
            else if (colidirBala(pipoco[NUM_BALAS].x, pipoco[NUM_BALAS].y, pipoco[NUM_BALAS].x + 4, pipoco[NUM_BALAS].y + 2, 987, 669, 1037, 722) && inimigo4Vivo) {
                pipoco[NUM_BALAS].onFire = false;
                inimigo4Vivo = false;
                inimigo4 = curado4;
            }


            //boneco
            al_draw_bitmap_region(boneco, current_frame_x, current_frame_y, ze.h, ze.w, ze.pos_x, ze.pos_y, 0);
             
            al_draw_textf(font, al_map_rgb(255, 0, 0), 10, 680, 0, "vida %d", vida); 

            //inicio hitbox chao 0-9
            if (colidir(ze.pos_x, ze.pos_y , 30, 50, 0, 703, 1280, 740)) { // hit box do chao
                ze.pos_y = 703 - 50 + 1; 
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 213, 588, 417, 607)) { // hit box do chao 1
                ze.pos_y = 588 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 386, 473, 791, 491)) { // hit box do chao 2
                ze.pos_y = 473 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 834, 440, 877, 459)) { // hit box do chao 3
                ze.pos_y = 440 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 926, 409, 1000, 428)) { // hit box do chao 4
                ze.pos_y = 409 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 1028, 371, 1232, 389)) { // hit box do chao 5
                ze.pos_y = 371 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 437, 256, 1232, 274)) { // hit box do chao 6
                ze.pos_y = 256 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 357, 208, 400, 226)) { // hit box do chao 7
                ze.pos_y = 208 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 180, 165, 317, 183)) { // hit box do chao 8
                ze.pos_y = 165 - 50 + 1;
                caindo = false;
            }
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 0, 84, 201, 102)) { // hit box do chao 9
                ze.pos_y = 84 - 50 + 1;
                caindo = false;
            }
            //fim hitbox 0-9

            //inicio hitbox escada
            if (escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 212, 593, 242, 725)) { // hit box escada 1
                    escadaOn = true;
                if (escadaOn && event.keyboard.keycode == ALLEGRO_KEY_W) {// movimentar para a cima
                    caindo = false;
                    ze.pos_y -= 10;
                }
            }
            if (!escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 212, 593, 242, 725) && escadaOn == true) {
                escadaOn = false;
            }

            if (escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 387, 490, 412, 608)) { // hit box escada 2
                    escadaOn = true;
                if (escadaOn && event.keyboard.keycode == ALLEGRO_KEY_W) {// movimentar para a cima
                    caindo = false;
                    ze.pos_y -= 10;
                }
            }
            if (!escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 387, 490, 412, 608) && escadaOn == true) {
                escadaOn = false;
            }

            if (escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 1202, 264, 1230, 390)) { // hit box escada 3
                    escadaOn = true;
                if (escadaOn && event.keyboard.keycode == ALLEGRO_KEY_W) {// movimentar para a cima
                    caindo = false;
                    ze.pos_y -= 10;
                }
            }
            if (!escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 1202, 264, 1230, 390) && escadaOn == true) {
                escadaOn = false;
            }

            if (escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 181, 94, 201, 180)) { // hit box escada 4
                    escadaOn = true;
                if (escadaOn && event.keyboard.keycode == ALLEGRO_KEY_W) {// movimentar para a cima
                    caindo = false;
                    ze.pos_y -= 10;
                }
            }
            if (!escalar(ze.pos_x, ze.pos_y, ze.h, ze.w, 181, 94, 201, 180) && escadaOn == true) {
                escadaOn = false;
            }
            
            //colisao com inimigo 1
            if (colidirIniEsq(ze.pos_x, ze.pos_y, ze.h, ze.w, 587, 440, 637, 490) && inimigo1Vivo) { // inimigo 1
                ze.pos_x -= 30;
                vida--;
            }
            else if (colidirIniDir(ze.pos_x, ze.pos_y, ze.h, ze.w, 587, 440, 637, 490) && inimigo1Vivo) {
                ze.pos_x += 30;
                vida--;
            }
            if (colidirIniUp(ze.pos_x, ze.pos_y, ze.h, ze.w, 587, 440, 637, 490) && inimigo1Vivo) {
                caindo = false;
            }

            //colisao com inimigo 2
           if (colidirIniEsq(ze.pos_x, ze.pos_y, ze.h, ze.w, 757, 225, 807, 275) && inimigo2Vivo) { // inimigo 2
               ze.pos_x -= 30;
               vida--;
           }
           else if (colidirIniDir(ze.pos_x, ze.pos_y, ze.h, ze.w, 757, 225, 807, 275) && inimigo2Vivo) {
               ze.pos_x += 30;
               vida--;
           }
           if (colidirIniUp(ze.pos_x, ze.pos_y, ze.h, ze.w, 757, 225, 807, 275) && inimigo2Vivo) {
               caindo = false;
           }

           //colisao com inimigo 3
           if (colidirIniEsq(ze.pos_x, ze.pos_y, ze.h, ze.w, 637, 669, 687, 722) && inimigo3Vivo) { // inimigo 3
               ze.pos_x -= 30;
               vida--;
           }
           else if (colidirIniDir(ze.pos_x, ze.pos_y, ze.h, ze.w, 637, 669, 687, 722) && inimigo3Vivo) {
               ze.pos_x += 30;
               vida--;
           }
           if (colidirIniUp(ze.pos_x, ze.pos_y, ze.h, ze.w, 637, 669, 687, 722) && inimigo3Vivo) {
               caindo = false;
           }

           //colisao com inimigo 4
           if (colidirIniEsq(ze.pos_x, ze.pos_y, ze.h, ze.w, 987, 669, 1037, 722) && inimigo4Vivo) { // inimigo 4
               ze.pos_x -= 30;
               vida--;
           }
           else if (colidirIniDir(ze.pos_x, ze.pos_y, ze.h, ze.w, 987, 669, 1037, 722) && inimigo4Vivo) {
               ze.pos_x += 30;
               vida--;
           }
           else if (vida <= 0) {
               estado = 4;
           }
           if (colidirIniUp(ze.pos_x, ze.pos_y, ze.h, ze.w, 987, 669, 1037, 722) && inimigo4Vivo){
               caindo = false;
           }

            //ganhou
            if (colidir2(ze.pos_x, ze.pos_y, ze.h, ze.w, 25, 18, 48, 85)) {
                estado = 5;
            }
        }
        //Tela perdeu
        if (estado == 4) {
            al_draw_bitmap(lose, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_T) {
                estado = 1;
            }
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {  
                estado = 0;
            }
        }
        //Tela win
        if (estado == 5) {
            al_draw_bitmap(win, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { 
                estado = 0;
                curado = true;
            }
        }
        //Instrucao fase 2
        if (estado == 6) {
            al_draw_bitmap(ComoJogar, 0, 0, 0);
            //al_draw_rectangle(485.0, 540.0, 695.0, 640.0, al_map_rgb(0, 0, 0), 3.0);
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (event.mouse.x >= 485 &&
                    event.mouse.y >= 540 &&
                    event.mouse.x <= 695 &&
                    event.mouse.y <= 640) {
                    botaoOver = 3;
                }
                else {
                    botaoOver = 0;
                }
            }

            if (botaoOver == 3 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                estado = 7;
            }
        }
        //Apresentacao fase 2
        if (estado == 7) {
            al_draw_bitmap(Apresentacao, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                estado = 10;
            }
        }
        //Acertou
            Wtimer_anima += 100; 
        if (estado == 8) {
            al_draw_bitmap_region(acertou, 0, 0, 350, 370, 450, 370, 0); 
            tempoDeTela++;
            if (tempoDeTela >= 500) {
                estado = auxEstado + 1;
                tempoDeTela = 0; 
                score++;
            }
            Hframe_atual = (Wtimer_anima / 400) % 4; 
            Vframe_atual = (Wtimer_anima / 400) % 3; 
            al_draw_bitmap_region(Warrior3_Attack, Hframe_atual* WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
            al_draw_bitmap_region(Warrior2_Hurt, Vframe_atual* WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);           
        } 
        //Errou
        if (estado == 9) {
            al_draw_bitmap_region(errou, 0, 0, 350, 370, 450, 370, 0);
            tempoDeTela++; 
            if (tempoDeTela >= 500) {
                estado = auxEstado + 1;
                tempoDeTela = 0; 
            }
            Hframe_atual = (Wtimer_anima / 400) % 2;
            Vframe_atual = (Wtimer_anima / 400) % 4;
            al_draw_bitmap_region(Warrior3_Hurt, Hframe_atual* WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
            al_draw_bitmap_region(Warrior2_Attack, Vframe_atual* WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);
        }
        //Questao 1
        if (estado == 10) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {// se clicar o esc, vai pro menu
                estado = 0;
            }
            al_draw_bitmap(FundoQ1, 0, 0, 0);
            if (estado != 9 && estado != 8) { 
               Hframe_atual = (Wtimer_anima / Wtempo_troca) % 5;  
               Vframe_atual = (Wtimer_anima / Wtempo_troca) % 5;  
               al_draw_bitmap_region(Warrior3, Hframe_atual * WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
               al_draw_bitmap_region(Warrior2, Vframe_atual * WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);
            }
           //al_draw_rectangle(200, 165, 350, 200, al_map_rgb(0, 0, 0), 3.0);
            if (event.mouse.x >= 200 &&
                event.mouse.y >= 165 &&
                event.mouse.x <= 350 &&
                event.mouse.y <= 200) {
                botaoOver = 4;
            }
            else {
                botaoOver = 0;
            }
            if (botaoOver == 4 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                auxEstado = estado; 
                estado = 8;
            }
            else if (botaoOver != 4 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && estado == 10) {
                auxEstado = estado; 
                estado = 9;
            }
        }
        //Questao 2
        if (estado == 11) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {// se clicar o esc, vai pro menu
                estado = 0;
            }
            al_draw_bitmap(FundoQ2, 0, 0, 0); 
            if (estado != 9 && estado != 8) {
                Hframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                Vframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                al_draw_bitmap_region(Warrior3, Hframe_atual * WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
                al_draw_bitmap_region(Warrior2, Vframe_atual * WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);
            }
            //al_draw_rectangle(200, 165, 450, 205, al_map_rgb(0, 0, 0), 3.0);
            if (event.mouse.x >= 200 && 
                event.mouse.y >= 165 && 
                event.mouse.x <= 450 && 
                event.mouse.y <= 205) { 
                botaoOver = 5; 
            }
            else {
                botaoOver = 0; 
            }
            if (botaoOver == 5 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                auxEstado = estado;
                estado = 8;
            }
            else if (botaoOver != 5 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && estado == 11) { 
                auxEstado = estado; 
                estado = 9; 
            }
        }
        //Questao 3
        if (estado == 12) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {// se clicar o esc, vai pro menu
                estado = 0;
            }
            al_draw_bitmap(FundoQ3, 0, 0, 0);
            if (estado != 9 && estado != 8) {
                Hframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                Vframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                al_draw_bitmap_region(Warrior3, Hframe_atual * WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
                al_draw_bitmap_region(Warrior2, Vframe_atual * WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);
            }
            //al_draw_rectangle(200, 210, 540, 245, al_map_rgb(0, 0, 0), 3.0);
            if (event.mouse.x >= 200 &&
                event.mouse.y >= 210 &&
                event.mouse.x <= 540 &&
                event.mouse.y <= 245) {
                botaoOver = 6;
            }
            else {
                botaoOver = 0;
            }
            if (botaoOver == 6 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                auxEstado = estado;
                estado = 8;
            }
            else if (botaoOver != 5 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && estado == 12) {
                auxEstado = estado;
                estado = 9;
            }
        }
        //Questao 4
        if (estado == 13) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {// se clicar o esc, vai pro menu
                estado = 0;
            }
            al_draw_bitmap(FundoQ4, 0, 0, 0);
            if (estado != 9 && estado != 8) {
                Hframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                Vframe_atual = (Wtimer_anima / Wtempo_troca) % 5;
                al_draw_bitmap_region(Warrior3, Hframe_atual * WframeW, 0, heroi.h, heroi.w, heroi.pos_x, heroi.pos_y, 0);
                al_draw_bitmap_region(Warrior2, Vframe_atual * WframeW, 0, vilao.h, vilao.w, vilao.pos_x, vilao.pos_y, 0);
            }
            //al_draw_rectangle(200, 250, 400, 290, al_map_rgb(0, 0, 0), 3.0);
            if (event.mouse.x >= 200 &&
                event.mouse.y >= 250 &&
                event.mouse.x <= 400 &&
                event.mouse.y <= 290) {
                botaoOver = 7;
            }
            else {
                botaoOver = 0;
            }
            if (botaoOver == 7 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                auxEstado = estado;
                estado = 8;
            }
            else if (botaoOver != 7 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && estado == 13) {
                auxEstado = estado;
                estado = 9;
            }
        }
        //Final Fase 2
        if (estado == 14) {
            if (score >= 3) {
                al_draw_bitmap(Ganhou, 0, 0, 0);
                //al_draw_rectangle(492, 565, 710, 665, al_map_rgb(0, 0, 0), 3.0);
                if (event.mouse.x >= 492 &&
                    event.mouse.y >= 565 &&
                    event.mouse.x <= 710 &&
                    event.mouse.y <= 665) {
                    botaoOver = 8;
                }
                else {
                    botaoOver = 0;
                }
                if (botaoOver == 8 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    estado = 17;
                }
            }
            else {
                al_draw_bitmap(Perdeu, 0, 0, 0);
                //al_draw_rectangle(480, 565, 695, 665, al_map_rgb(0, 0, 0), 3.0);
                if (event.mouse.x >= 480 &&
                    event.mouse.y >= 565 &&
                    event.mouse.x <= 695 &&
                    event.mouse.y <= 665) {
                    botaoOver = 9;
                }
                else {
                    botaoOver = 0;
                }
                if (botaoOver == 9 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    estado = 0;
                }
            }
        }
        //Quadrinhos
        if (estado == 15) {
            al_draw_bitmap(Inicio1, 0, 0, 0);
           // al_draw_rectangle(945, 40, 1239, 131, al_map_rgb(0, 0, 0), 3.0);
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (event.mouse.x >= 945 &&
                    event.mouse.y >= 40 &&
                    event.mouse.x <= 1239 &&
                    event.mouse.y <= 131) {
                    botaoOver = 10;
                }
                else {
                    botaoOver = 0;
                }
            }

            if (botaoOver == 10 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                estado = 16;
            }
        }
        //Continuacao quadrinhos
        if (estado == 16) {
            al_draw_bitmap(Inicio2, 0, 0, 0);
            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                estado = 0;
            }
        }
        //Final
        if (estado == 17) {
            al_draw_bitmap(Final, 0, 0, 0);
            //al_draw_rectangle(40, 35, 335, 131, al_map_rgb(0, 0, 0), 3.0);
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (event.mouse.x >= 40 &&
                    event.mouse.y >= 35 &&
                    event.mouse.x <= 335 &&
                    event.mouse.y <= 131) {
                    botaoOver = 11;
                }
                else {
                    botaoOver = 0;
                }
            }

            if (botaoOver == 11 && event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                estado = 0;
            }
        }
        
        al_flip_display();
    }

    al_destroy_font(font);
    al_destroy_timer(timer_menu);
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(boneco);
    al_destroy_bitmap(sumario);
    al_destroy_bitmap(inimigo1);
    al_destroy_bitmap(inimigo2); 
    al_destroy_bitmap(inimigo3); 
    al_destroy_bitmap(inimigo4);
    al_destroy_bitmap(curado1); 
    al_destroy_bitmap(curado2); 
    al_destroy_bitmap(curado3); 
    al_destroy_bitmap(curado4); 
    al_destroy_bitmap(vacina);
    //Destroy da fase 2
    al_destroy_bitmap(acertou); 
    al_destroy_bitmap(errou); 
    al_destroy_bitmap(FundoQ1); 
    al_destroy_bitmap(FundoQ2); 
    al_destroy_bitmap(FundoQ3); 
    al_destroy_bitmap(Warrior3); 
    al_destroy_bitmap(Warrior3_Attack); 
    al_destroy_bitmap(Warrior3_Hurt); 
    al_destroy_bitmap(Warrior3_Dead); 
    al_destroy_bitmap(Warrior2); 
    al_destroy_bitmap(Warrior2_Attack); 
    al_destroy_bitmap(Warrior2_Hurt); 
    al_destroy_bitmap(Warrior2_Dead); 

    return 0;
}
