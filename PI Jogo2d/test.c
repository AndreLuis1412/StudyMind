/* 
ALLEGRO_BITMAP* ComoJogar = al_load_bitmap("./ComoJogar.png");
    ALLEGRO_BITMAP* Apresentacao = al_load_bitmap("./Apresentacao.png");
    ALLEGRO_BITMAP* Fundo = al_load_bitmap("./Fundo.png");
    ALLEGRO_BITMAP* FundoQ1 = al_load_bitmap("./Questao1.png");
    ALLEGRO_BITMAP* FundoQ2 = al_load_bitmap("./Questao2.png");
    ALLEGRO_BITMAP* FundoQ3 = al_load_bitmap("./Questao3.png");

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

    ALLEGRO_BITMAP* icon = al_load_bitmap("./studymind.png");

    ALLEGRO_BITMAP* acertou = al_load_bitmap("./acertou.png");
    ALLEGRO_BITMAP* errou = al_load_bitmap("./errou.png");

    ALLEGRO_FONT* font = al_create_builtin_font();

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    al_start_timer(timer);

    ALLEGRO_DISPLAY* display = al_create_display(1200, 720);
    al_set_display_icon(display, icon);
    al_set_window_title(display, "StudyMind - Fase de Artes");

    ALLEGRO_EVENT_QUEUE* event = al_create_event_queue();
    al_register_event_source(event, al_get_display_event_source(display));
    al_register_event_source(event, al_get_timer_event_source(timer));
    al_register_event_source(event, al_get_keyboard_event_source());;
    al_register_event_source(event, al_get_mouse_event_source());

    float frame = 0.f;

    struct Move { int pos_x, pos_y, w, h, frame_x, frame_y; };
    struct Move heroi, vilao;

    heroi.pos_x = 300;
    heroi.pos_y = 550;
    heroi.w = 96;
    heroi.h = 96;
    heroi.frame_x = 0;
    heroi.frame_y = 96;

    vilao.pos_x = 750;
    vilao.pos_y = 550;
    vilao.w = 96;
    vilao.h = 96;
    vilao.frame_x = 0;
    vilao.frame_y = 96;

    bool jogando = true;
    bool validar = false;

    int resposta = 0;
    int estadoTela = 0;
    int pergunta = 0;
    int score = 0;

    while (jogando) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(event, &evento);

        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE || evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            break;
        }   

        //COMEÇO
        al_clear_to_color(al_map_rgb(255, 255, 255));

        if (estadoTela == 0) {
            al_draw_bitmap(ComoJogar, 0, 0, 0);
            al_draw_rectangle(485.0, 540.0, 695.0, 640.0, al_map_rgb(0, 0, 0), 3.0);

            if (estadoTela == 0 && evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
                if (evento.mouse.x >= 485.0 &&
                    evento.mouse.y >= 540.0 &&
                    evento.mouse.x <= 695.0 &&
                    evento.mouse.y <= 640.0) {
                    validar = true;
                }
            }
        }


        if (estadoTela == 0 && evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && validar == true) {
            estadoTela = 1;
        }
            
        if (estadoTela == 1) {
            al_draw_bitmap(Apresentacao, 0, 0, 0);

            if (estadoTela == 1 && evento.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                estadoTela = 2;
            }
        }

        //PERGUNTAS
 
        //Q1

        int Questao = 0;

        if (estadoTela == 2) {
            
            al_draw_bitmap(FundoQ1, 0, 0, 0);
            al_draw_rectangle(200.0, 165.0, 350.0, 200.0, al_map_rgb(0, 0, 0), 3.0);

            if (estadoTela == 2 && evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
                Questao = 1;
                if (evento.mouse.x >= 200.0 &&
                evento.mouse.y >= 165.0 &&
                evento.mouse.x <= 350.0 &&
                evento.mouse.y <= 200.0) {
                resposta = 1;
                }
            }
        }

        if (estadoTela == 2 && evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP && resposta == 1 && Questao == 1) {
            score++;
            al_draw_bitmap_region(acertou, 0, 0, 350, 200, 450, 200, 0);
            //estadoTela = 3;
            //Questao = 2;
        }

        else if(estadoTela == 2 && resposta == 0 && Questao == 1) {
            al_draw_bitmap_region(errou, 0, 0, 350, 200, 450, 200, 0);
            //estadoTela = 3;
            //Questao = 2;
        }
        

        //FIM
        if (estadoTela == 3 && Questao == 2) { // == 6
            if (score >= 1) { // >= 3
                al_draw_bitmap(Ganhou, 0, 0, 0);
            }
            else if(score == 0){
                al_draw_bitmap(Perdeu, 0, 0, 0);
            }
        }

        al_rest(0.000001);
        al_flip_display();
    }


    al_destroy_font(font);

    al_destroy_event_queue(event);

    al_destroy_bitmap(Fundo);
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
   
    al_destroy_bitmap(icon);
    al_destroy_bitmap(acertou);
    al_destroy_bitmap(errou);

    return 0;
}
*/